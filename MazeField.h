/*
 * MazeField.h
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
#include <QStaticText>
#include <QDataStream>

#include <iostream>

#include "Map.h"
#include "ParseHmaze.h"

class MazeField : public QQuickPaintedItem{
    Q_OBJECT

    Q_PROPERTY(int mazesize READ getSize WRITE setSize)
	Q_PROPERTY(int mode WRITE loadMaze)

	Q_DISABLE_COPY(MazeField)

public:
    explicit MazeField(QQuickItem *parent = 0);

	void setParams();
    int getSize() const { return m_size; }
    void setSize(const int &mazesize);
	Q_INVOKABLE Map getMap() const { return m_map; }
	Q_INVOKABLE void setGoals(int x1, int y1, int x2, int y2);

	void loadMaze(const int& m);
	Q_INVOKABLE void loadMazeFromClpbrd();
	Q_INVOKABLE void loadMazeFromFile(QString filename);
	void loadMazeFromNFC(const int& m);

	Q_INVOKABLE void saveMazeToFile(QString filename);

    void paint(QPainter *painter);

private:
    int m_size;

	Map m_map;

};
