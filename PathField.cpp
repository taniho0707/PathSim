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
	const auto libGetPath = (int(*)(std::vector<Motion>&, const Map&, const std::pair<uint32_t, uint32_t>&))(loadFuncOrDie(loadlib, "CreateMyPath"));
	
	vector<Motion> a;
	Map b;
	pair<uint32_t, uint32_t> c;
	
	int p = libGetPath(a, b, c);
	
	cout << p << endl;
	
	dlclose(loadlib);
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
		painter->drawPoint(x-(d-1)/2+30, 1020-(y-(d-1)/2)-30);
	} else {
		painter->drawEllipse(x-(d-1)/2+30, 1020-(y-(d-1)/2)-30, d, d);
	}
}

void PathField::plotMetric(QPainter *painter, float x, float y, int d){
	plotDot(painter, static_cast<int>((x-1)*static_cast<float>(size_x/size_trout)/(size_trout_metric)), static_cast<int>(y*static_cast<float>(size_y/size_trout)/(size_trout_metric)), d);
}


void PathField::paint(QPainter *painter){
	QPen pen(QColor("palegreen"), 2);
	painter->setPen(pen);
	painter->setRenderHints(QPainter::Antialiasing, true);
	plotMetric(painter, 90, 90);
}

