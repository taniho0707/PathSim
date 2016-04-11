/**
 * @file PathField.h
 */

#ifndef INCLUDED_PATHFIELD_H
#define INCLUDED_PATHFIELD_H

#include <QQuickPaintedItem>
#include <QApplication>
#include <QColor>
#include <QPen>
#include <QBrush>
#include <QPainter>
#include <QRect>

#include "Map.h"
#include "Pathdata.h"

class PathField : public QQuickPaintedItem{
	Q_OBJECT

	Q_DISABLE_COPY(PathField)

public:
	explicit PathField(QQuickItem *parent = 0);

	Q_INVOKABLE void loadPath(QString lib);

	void paint(QPainter *painter);

private:
	Pathdata m_path;

};

#endif
