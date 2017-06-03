/**
 * @file PathField.cpp
 */
#include "PathField.h"

using namespace std;

PathField::PathField(QQuickItem *parent) : QQuickPaintedItem(parent){
	setClass(ClassType::HALF);
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


void PathField::setParams(){
	field_type = loaded_map.getType();
	setClass(field_type);
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

void PathField::setGoals(int x1, int y1, int x2, int y2){
	if (x1 < x2 || y1 < y2) return;
	loaded_map.goals.clear();
	for (int i=x1; i<=x2; ++i) {
		for (int j=y1; j<=y2; ++j) {
			loaded_map.addGoal(i, j);
		}
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

void PathField::plotLine(QPainter *painter, int x1, int y1, int x2, int y2){
	painter->drawLine(x1-0.5f+30, 1020-(y1-0.5f)-30, x2-0.5f+30, 1020-(y2-0.5f)-30);
}

void PathField::plotLineMetric(QPainter *painter, float x1, float y1, float x2, float y2){
	plotLine(painter,
			 static_cast<int>(static_cast<float>(x1-1) * static_cast<float>(size_x/(size_trout+2)) / (size_trout_metric)),
			 static_cast<int>(static_cast<float>(y1-1) * static_cast<float>(size_x/(size_trout+2)) / (size_trout_metric)),
			 static_cast<int>(static_cast<float>(x2-1) * static_cast<float>(size_x/(size_trout+2)) / (size_trout_metric)),
			 static_cast<int>(static_cast<float>(y2-1) * static_cast<float>(size_x/(size_trout+2)) / (size_trout_metric))
		);
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
	setParams();
}

void PathField::updateMapFromFile(QString filename){
	QFile file(filename);
	file.open(QIODevice::ReadOnly);
	QDataStream in(&file);
	loaded_map.format();
	uint8_t tmp8;
	in >> tmp8;
	loaded_map.setType(static_cast<ClassType>(tmp8));
	in >> tmp8;
	int16_t tmp16x, tmp16y;
	for (int i=0; i<tmp8; ++i) {
		in >> tmp16x;
		in >> tmp16y;
		loaded_map.addGoal(tmp16x, tmp16y);
	}
	/// @todo 任意のゴール座標に対応させる
	loaded_goal.first = 7;
	loaded_goal.second = 7;
	for (int i=0; i<31; ++i) {
		in >> loaded_map.column[i];
	}
	for (int i=0; i<31; ++i) {
		in >> loaded_map.row[i];
	}
	for (int i=0; i<32; ++i) {
		in >> loaded_map.reached[i];
	}
	setParams();
}


void PathField::drawPath(QPainter *painter){
	QPen pendot(QColor("palegreen"), 2);
	QPen penline(QColor("moccasin"), 1);
	loaded_path.updatePositions();
	pair<float, float> lastpos{45, 45};
	for(int i=0; i<=loaded_path.getPathLength() + 1; ++i){
		painter->setPen(pendot);
		plotMetric(painter, loaded_path.getPosition(i).first, loaded_path.getPosition(i).second, 1);
		painter->setPen(penline);
		plotLineMetric(painter, lastpos.first, lastpos.second, loaded_path.getPosition(i).first, loaded_path.getPosition(i).second);
		lastpos = loaded_path.getPosition(i);
		printf("%2d(%2d): %5f, %5f\n", static_cast<int>(loaded_path.getMotion(i).type), loaded_path.getMotion(i).length, loaded_path.getPosition(i).first, loaded_path.getPosition(i).second);
	}
}


void PathField::paint(QPainter *painter){
	QPen pen(QColor("palegreen"), 1);
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

