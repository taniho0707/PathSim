/*
 * MazeField.cpp
 */

#include "MazeField.h"

MazeField::MazeField(QQuickItem *parent) : QQuickPaintedItem(parent){
	m_size = 32;
	m_map = Map();
}

void MazeField::paint(QPainter *painter){
	QPen pen(QColor("mintcream"), 2);
	QBrush brush(QColor("tomato"));
	QRect rect(0, 0, 1024, 1024);
	painter->setPen(pen);
	painter->setRenderHints(QPainter::Antialiasing, true);
	painter->fillRect(rect, QColor("dimgray"));
	rect.setSize(QSize(6, 26));
	for(int i=0; i<33; ++i){
		for(int j=0; j<32; ++j){
			rect.moveTo(32*i-3, 32*j+3);
			if(i == 0 || i == 32
			   || m_map.isExistWall(i-1, 31-j, E_AngleRight) )
				painter->fillRect(rect, brush);
		}
	}
	rect.setSize(QSize(26, 6));
	for(int j=0; j<33; ++j){
		for(int i=0; i<32; ++i){
			rect.moveTo(32*i+3, 32*j-3);
			if(j == 0 || j == 32
			   || m_map.isExistWall(i, 31-j, E_AngleUp) )
				painter->fillRect(rect, brush);
		}
	}
}

void MazeField::setSize(const int &mazesize){
	MazeField::m_size = mazesize;
}

void MazeField::loadMaze(const int& m){
	if(m == 1000) MazeField::loadMazeFromClpbrd();
	else if(m == 2000) MazeField::loadMazeFromFile();
	else MazeField::loadMazeFromNFC(m);
}

void MazeField::loadMazeFromClpbrd(){
	QString str = QApplication::clipboard()->text();
	QString testcase;

	// 1. maze output(in text)
	testcase = "map[][]=";
	if(str.indexOf(testcase) != 0){
		ParseHmaze ps = ParseHmaze();
		int ret = ps.getMap(str, m_map);
	}
	MazeField::update();
}

void MazeField::loadMazeFromFile(){
	
}

void MazeField::loadMazeFromNFC(const int& m){
	
}
