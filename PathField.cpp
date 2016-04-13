/**
 * @file PathField.cpp
 */
#include "PathField.h"

using namespace std;

PathField::PathField(QQuickItem *parent) : QQuickPaintedItem(parent){
	
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
	cout << "loaded library " << path << endl;
	return lib;
}

void PathField::loadPath(QString lib){
	const auto loadlib = loadLibOrDie(lib.toStdString());
	typedef int (*func_getpath)(Pathdata&, Map&);
	auto loadFunction = (func_getpath)(loadFuncOrDie(loadlib, "getPath"));

	Pathdata p;
	Map m;
	
	cout << loadFunction(p, m) << endl;
	
	dlclose(loadlib);
	// PathData m_path;
	
	PathField::update();
}

void PathField::paint(QPainter *painter){
	QPen pen(QColor("gold"), 2);
	QBrush brush(QColor("gold"));
	QLine line(0, 0, 1, 1);
	painter->setPen(pen);
	painter->setRenderHints(QPainter::Antialiasing, true);
	painter->drawLine(line);
}

