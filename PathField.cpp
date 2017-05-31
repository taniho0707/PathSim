/**
 * @file PathField.cpp
 */
#include "PathField.h"

using namespace std;

PathField::PathField(QQuickItem *parent) : QQuickPaintedItem(parent){
	setClass(ClassType::HALF);
	updateGoal(7, 7);
}

void* PathField::loadFuncOrDie(void *lib, const string& func_name) {
	const auto func = dlsym(lib, func_name.c_str());
	const auto dlsym_error = dlerror();
	if (dlsym_error) {
		cerr << "Cannot load symbol create: " << dlsym_error << endl;
		dlclose(lib);
		exit(EXIT_FAILURE);
	}
	return func;
}

void* PathField::loadLibOrDie(const string& path) {
	const auto lib = dlopen(path.c_str(), RTLD_NOW);
	if (!lib) {
		cerr << "Cannot load library: " << dlerror() << endl;
		exit(EXIT_FAILURE);
	}
	return lib;
}

void PathField::loadPath(QString lib){
	const auto loadlib = loadLibOrDie("./libpath/" + lib.toStdString());
	const auto libGetPath = (int(*)(Path&, const Map&, const std::pair<uint32_t, uint32_t>&))(loadFuncOrDie(loadlib, "CreateMyPath"));

	int p = libGetPath(loaded_path, loaded_map, loaded_goal);
	
	cout << p << endl;
	
	dlclose(loadlib);

	PathField::update();
}


void PathField::setClass(ClassType type){
	field_type = type;
	if (field_type == ClassType::CLASSIC) {
		size_trout = 16;
		size_trout_metric = 180;
	} else if (field_type == ClassType::HALF) {
		size_trout = 32;
		size_trout_metric = 90;
	} else if (field_type == ClassType::QUARTER) {
		size_trout = 32;
		size_trout_metric = 45;
	}
}

void PathField::plotDot(QPainter *painter, int x, int y, int d){
	if (d == 1){
		painter->drawPoint(x-static_cast<float>(d-1)/2.0f+30, 1020-(y-static_cast<float>(d-1)/2.0f)-30);
	} else {
		painter->drawEllipse(x-(d-1)/2+30, 1020-(y-(d-1)/2)-30, d, d);
	}
}

void PathField::plotMetric(QPainter *painter, float x, float y, int d){
	plotDot(painter,
			static_cast<int>(static_cast<float>(x-1) * static_cast<float>(size_x/(size_trout+2)) / (size_trout_metric)),
			static_cast<int>(static_cast<float>(y)	 * static_cast<float>(size_y/(size_trout+2)) / (size_trout_metric)),
			d);
}


void PathField::updateMapFromClpbrd(){
	QString str = QApplication::clipboard()->text();
	QString testcase;

	// 1. maze output(in text)
	testcase = "map[][]=";
	if(str.indexOf(testcase) != 0){
		ParseHmaze ps = ParseHmaze();
		int ret = ps.getMap(str, loaded_map);
		if(ret) std::cout << "Load Error" << std::endl;
	}
	for (int i=0; i<32; ++i) {
		for (int j=0; j<32; ++j) {
			loaded_map.setReached(i, j);
		}
	}
}

void PathField::updateGoal(uint32_t newx, uint32_t newy){
	loaded_goal.first = newx;
	loaded_goal.second = newy;
}


void PathField::drawPath(QPainter *painter){
	loaded_path.updatePositions();
	for(int i=0; i<=loaded_path.getPathLength(); ++i){
		plotMetric(painter, loaded_path.getPosition(i).first, loaded_path.getPosition(i).second, 1);
		printf("%2d(%2d): %5f, %5f\n", static_cast<int>(loaded_path.getMotion(i).type), loaded_path.getMotion(i).length, loaded_path.getPosition(i).first, loaded_path.getPosition(i).second);
	}
}


void PathField::paint(QPainter *painter){
	QPen pen(QColor("palegreen"), 2);
	painter->setPen(pen);
	painter->setRenderHints(QPainter::Antialiasing, true);

	if (loaded_path.getPathLength()!=0) {
		cout << "Path exist" << endl;
	} else {
		cout << "Path NOT exist" << endl;
	}
	if (loaded_path.getPathLength() != 0){
		drawPath(painter);
	}
}

