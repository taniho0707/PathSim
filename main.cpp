#include <iostream>
#include <QApplication>
#include <QQmlApplicationEngine>
#include <QtQml>
#include <QTextCodec>
#include <QQuickView>
#include "SimManage.h"
#include "MazeField.h"

// #include "const.h"
// #include "Map.h"
// #include "Algorithm.h"

// using namespace std;


int main(int argc, char **argv){
	QApplication app(argc, argv);
	QTextCodec::setCodecForLocale(QTextCodec::codecForLocale());

	qmlRegisterType<MazeField>("MazeField", 1, 0, "MazeField");
	QQmlApplicationEngine engine("main.qml");

	SimManage manage;
	engine.rootContext()->setContextProperty("manage", &manage);
	
	return app.exec();
}
