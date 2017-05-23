/*
 * ParseHmaze.h
 */

#pragma once

#include <QString>
#include "Map.h"

#include <iostream>

class ParseHmaze{
private:
	Map m_map;
	int m_hmap[16][16];

public:
	ParseHmaze();
	~ParseHmaze();
	
	int loadHmap(const QString& str);

	bool isExistWall(int x, int y, MazeAngle angle);
	
	int convToMap();
	
	int getMap(const QString& str, Map& m);

};

