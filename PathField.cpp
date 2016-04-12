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
	return lib;
}

void PathField::loadPath(QString lib){
	const auto loadlib = loadLibOrDie("./libpath/libpathbasic1.so");
	// const auto loadlib = loadLibOrDie(lib.toStdString());
	const auto createPathClass = (create_p*)(loadFuncOrDie(loadlib, "CreateMyPath"));
	
	Path* p = createPathClass();

	Pathdata a;
	Map b;
	pair<uint32_t, uint32_t> c;
	
	cout << p->getPath(a, b, c) << endl;

	dlclose(loadlib);
	// PathData m_path;
	
}

void PathField::paint(QPainter *painter){
	
}

