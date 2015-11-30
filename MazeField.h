/*
 * MazeField.h
 */

#ifndef INCLUDED_MAZEFIELD_H
#define INCLUDED_MAZEFIELD_H

#include <QQuickPaintedItem>
#include <QColor>
#include <QPen>
#include <QBrush>
#include <QPainter>
#include <QRect>

class MazeField : public QQuickPaintedItem{
    Q_OBJECT
    Q_PROPERTY(int mazesize READ getSize WRITE setSize)

public:
    MazeField(QQuickItem *parent = 0);

    int getSize() const { return m_size; }
    void setSize(const int &mazesize);

	

    void paint(QPainter *painter);

private:
    int m_size;
};

#endif
