/*
 * MazeField.h
 */

#ifndef INCLUDED_MAZEFIELD_H
#define INCLUDED_MAZEFIELD_H

#include <QQuickPaintedItem>
#include <QApplication>
#include <QColor>
#include <QPen>
#include <QBrush>
#include <QPainter>
#include <QRect>
#include <QClipboard>

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

    int getSize() const { return m_size; }
    void setSize(const int &mazesize);

	void loadMaze(const int& m);
	Q_INVOKABLE void loadMazeFromClpbrd();
	void loadMazeFromFile();
	void loadMazeFromNFC(const int& m);

	/* /// @todo */
	/* void setClass(ClassType); */
	/* void drawWalls(Map); */
	/* void plotDot(int x, int y); */
	/* void plotMetric(int, int); */

    void paint(QPainter *painter);

private:
    int m_size;

	Map m_map;


};
