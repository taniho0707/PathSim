/*
 * DrawingTest.h
 */

#ifndef INCLUDED_DRAWINGTEST_H
#define INCLUDED_DRAWINGTEST_H

#include <QQuickPaintedItem>
#include <QColor>
#include <QPen>
#include <QPainter>
#include <QRect>

class DrawingTest : public QQuickPaintedItem{
    Q_OBJECT
    Q_PROPERTY(QString name READ name WRITE setName)
    Q_PROPERTY(QColor color READ color WRITE setColor)

public:
    DrawingTest(QQuickItem *parent = 0);

    QString name() const { return m_name; }
    void setName(const QString &name);

    QColor color() const { return m_color; }
    void setColor(const QColor &color);

    void paint(QPainter *painter);

private:
    QString m_name;
    QColor m_color;
};

#endif
