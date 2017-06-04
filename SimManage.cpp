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
	const char *dirname = "./libpath/";
	struct dirent **namelist;
	QStringList str = QStringList();
	QRegExp reg(".so$");
	int r = scandir(dirname, &namelist, NULL, alphasort);
	if(r != -1) {
		for (int i=0; i<r; ++i) {
			if (namelist[i]!=NULL && (reg.indexIn(namelist[i]->d_name) >= 0)){
				str << namelist[i]->d_name;
			}
			free(namelist[i]);
		}
		free(namelist);
	}
	return str;
}

QStringList SimManage::getMazefileList(){
	const char *dirname = "./maze/";
	struct dirent **namelist;
	QStringList str = QStringList();
	QRegExp reg(".maze$");
	int r = scandir(dirname, &namelist, NULL, alphasort);
	if(r != -1) {
		for (int i=0; i<r; ++i) {
			if (namelist[i]!=NULL && (reg.indexIn(namelist[i]->d_name) >= 0)){
				str << namelist[i]->d_name;
			}
			free(namelist[i]);
		}
		free(namelist);
	}
	return str;
}
