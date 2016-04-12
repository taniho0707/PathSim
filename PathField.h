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
#include "libpath/libpath.h"

class PathField : public QQuickPaintedItem{
	Q_OBJECT

	Q_DISABLE_COPY(PathField)

public:
	explicit PathField(QQuickItem *parent = 0);

	Q_INVOKABLE void loadPath(QString lib);

	void paint(QPainter *painter);

private:
	Pathdata m_path;

	void* loadLibOrDie(const std::string& path);
	void* loadFuncOrDie(void* lib, const std::string& func_name);

};

