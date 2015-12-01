/*
 * SimManage.h
 */

#ifndef INCLUDED_SIMMANAGE_H
#define INCLUDED_SIMMANAGE_H

#include <iostream>

#include <QObject>
#include <QPainter>

#include "Map.h"

class SimManage : public QObject{
	Q_OBJECT

    Q_DISABLE_COPY(SimManage)

    /* Q_PROPERTY(QString post WRITE postTweet) */
    /* Q_PROPERTY(QString regAct READ regAccount) */
    /* Q_PROPERTY(QString postPin WRITE postPincode) */
    /* Q_PROPERTY(QString user READ userInfo NOTIFY userChanged) */

public:
	explicit SimManage(QObject *parent = 0);

	Q_INVOKABLE void test();

private:
	Map m_map;

};

#endif
