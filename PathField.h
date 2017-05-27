/**
 * @file PathField.h
 */

#pragma once

#include <QQuickPaintedItem>
#include <QApplication>
#include <QColor>
#include <QPen>
#include <QBrush>
#include <QPainter>
#include <QRect>

#include <dlfcn.h>
#include <iostream>
#include <cstdlib>
#include <string>
#include <memory>

#include "Map.h"
#include "Pathdata.h"
#include "libpath.hpp"

enum class ClassType : uint8_t {
	CLASSIC,
	HALF,
	QUARTER,
};

class PathField : public QQuickPaintedItem{
	Q_OBJECT

	Q_DISABLE_COPY(PathField)

public:
	explicit PathField(QQuickItem *parent = 0);

	Q_INVOKABLE void loadPath(QString lib);

	void setClass(ClassType type);
	void plotDot(QPainter *painter, int x, int y, int d = 1);
	void plotMetric(QPainter *painter, float x, float y, int d = 1);

	void paint(QPainter *painter);

private:
	Pathdata m_path;

	ClassType field_type;
	int size_trout;
	int size_trout_metric;

	const int size_x = 1020;
	const int size_y = 1020;

	void* loadLibOrDie(const std::string& path);
	void* loadFuncOrDie(void* lib, const std::string& func_name);

};

