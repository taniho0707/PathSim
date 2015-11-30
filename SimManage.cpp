/*
 * SimManage.cpp
 */

#include "SimManage.h"

SimManage::SimManage(QObject *parent) : QObject(parent){
	
}

void SimManage::test(){
	std::cout << "Hello Qt!" << std::endl;
}

