#include <iostream>
#include <QApplication>
#include <QQmlApplicationEngine>
#include <QtQml>
#include <QTextCodec>
#include <QQuickView>
#include "SimManage.h"
#include "MazeField.h"
#include "PathField.h"

using namespace std;


int main(int argc, char **argv){
	QApplication app(argc, argv);
	QTextCodec::setCodecForLocale(QTextCodec::codecForLocale());

	qmlRegisterType<MazeField>("MazeField", 1, 0, "MazeField");
	qmlRegisterType<PathField>("PathField", 1, 0, "PathField");
	QQmlApplicationEngine engine("main.qml");

	SimManage manage;
	engine.rootContext()->setContextProperty("manage", &manage);
	
	return app.exec();
}
