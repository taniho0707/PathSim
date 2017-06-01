/*
 * SimManage.cpp
 */

#include "SimManage.h"

SimManage::SimManage(QObject *parent) : QObject(parent){
	m_map = Map();
}

void SimManage::test(){
	std::cout << "Hello Qt!" << std::endl;
}

QStringList SimManage::getPathfileList(){
	QStringList str = QStringList();
	QRegExp reg(".so$");
	DIR* dp=opendir("./libpath/");
	if (dp!=NULL){
		struct dirent* dent;
		int i=0;
		do{
			dent = readdir(dp);
			if (dent!=NULL && (reg.indexIn(dent->d_name) >= 0)){
				str << dent->d_name;
			}
			++i;
		} while(dent!=NULL);
		closedir(dp);
	}
	return str;
}

QStringList SimManage::getMazefileList(){
	QStringList str = QStringList();
	QRegExp reg(".maze$");
	DIR* dp=opendir("./maze/");
	if (dp!=NULL){
		struct dirent* dent;
		int i=0;
		do{
			dent = readdir(dp);
			if (dent!=NULL && (reg.indexIn(dent->d_name) >= 0)){
				str << dent->d_name;
			}
			++i;
		} while(dent!=NULL);
		closedir(dp);
	}
	return str;
}
