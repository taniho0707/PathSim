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

