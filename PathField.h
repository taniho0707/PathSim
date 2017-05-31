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
#include <QClipboard>

#include <dlfcn.h>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <memory>

#include "Map.h"
#include "Path.h"
#include "ParseHmaze.h"
#include "libpathbasic1.hpp"

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
	void plotLine(QPainter *painter, int x1, int y1, int x2, int y2);
	void plotLineMetric(QPainter *painter, float x1, float y1, float x2, float y2);

	Q_INVOKABLE void updateMapFromClpbrd();
	void updateGoal(uint32_t newx, uint32_t newy);
	void drawPath(QPainter *painter);

	void paint(QPainter *painter);

private:
	std::vector<Motion> m_path;

	ClassType field_type;
	int size_trout;
	int size_trout_metric;

	Path loaded_path;
	Map loaded_map;
	std::pair<uint32_t, uint32_t> loaded_goal;

	const int size_x = 1020;
	const int size_y = 1020;

	void* loadLibOrDie(const std::string& path);
	void* loadFuncOrDie(void* lib, const std::string& func_name);

};

