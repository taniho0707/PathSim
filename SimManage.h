/*
 * SimManage.h
 */

#ifndef INCLUDED_SIMMANAGE_H
#define INCLUDED_SIMMANAGE_H

#include <iostream>

#include <QObject>
#include <QPainter>


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
};

#endif
