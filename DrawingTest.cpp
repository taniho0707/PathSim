/*
 * DrawingTest.cpp
 */

#include "DrawingTest.h"

DrawingTest::DrawingTest(QQuickItem *parent) : QQuickPaintedItem(parent){
	
}

void DrawingTest::paint(QPainter *painter){
    QPen pen(DrawingTest::m_color, 2);
    // painter->setPen(pen);
    // painter->setRenderHints(QPainter::Antialiasing, true);
    // painter->drawPie(boundingRect().adjusted(1, 1, -1, -1), 90 * 16, 290 * 16);
	QRect rect(0, 0, 100, 80);
	painter->setPen(pen);
	painter->fillRect(rect, DrawingTest::m_color);
}

void DrawingTest::setName(const QString &name){
	DrawingTest::m_name = name;
}

void DrawingTest::setColor(const QColor &color){
	DrawingTest::m_color = color;
}
