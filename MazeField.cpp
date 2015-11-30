/*
 * MazeField.cpp
 */

#include "MazeField.h"

MazeField::MazeField(QQuickItem *parent) : QQuickPaintedItem(parent){
	m_size = 32;
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
			painter->fillRect(rect, brush);
		}
	}
	rect.setSize(QSize(26, 6));
	for(int j=0; j<34; ++j){
		for(int i=0; i<33; ++i){
			rect.moveTo(32*i+3, 32*j-3);
			painter->fillRect(rect, brush);
		}
	}
}

void MazeField::setSize(const int &mazesize){
	MazeField::m_size = mazesize;
}
