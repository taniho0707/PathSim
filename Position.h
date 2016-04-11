#ifndef INCLUDED_POSITION_H_
#define INCLUDED_POSITION_H_
/**
 * @file Position.h
 */

#include <utility>

#include "const.h"
#include "Map.h"


/**
 * @brief マウスの現在座標と向きを管理するクラスです。
 */
class Position{
private:



public:

	unsigned char x;
	unsigned char y;

	EMouseAngle angle;

	Position();

	void setPosition(std::pair<char, char>, EMouseAngle);
	void setNextAngle(EMotion);
	std::pair<char, char> getCoordinate();
	EMouseAngle getAngle();
	EMouseAngle getReverseAngle(EMouseAngle);
	void moveStraight();
	void moveRight();
	void moveLeft();
	void moveTurn();

	char isInGoal();

};

#endif
