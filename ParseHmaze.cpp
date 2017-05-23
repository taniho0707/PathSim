/*
 * ParseHmaze.h
 */

#include "ParseHmaze.h"

ParseHmaze::ParseHmaze(){
	m_map = Map();
	for (int i=0; i<16; i++)
		for (int j=0; j<16; j++)
			m_hmap[i][j] = 0;
}
ParseHmaze::~ParseHmaze(){
		
}

int ParseHmaze::loadHmap(const QString& str){
	int ite = 0;
	bool ok;
	QString testcase = "map[][]=";
	ite = str.indexOf(testcase);
	testcase = "{";
	for(int i=0; i<16; ++i){
		for(int j=0; j<16; ++j){
			ite = str.indexOf(testcase, ite);
			if(str.at(ite+1) == QChar('{')) ite += 1;
			++ ite;
			if(str.at(ite+1) == QChar(',') || str.at(ite+1) == QChar('}')){
				m_hmap[i][j] = (str.at(ite++)).digitValue();
			} else {
				m_hmap[i][j] = (str.at(ite++)).digitValue()*10 + (str.at(ite++)).digitValue();
			}
			testcase = ",";
		}
	}
	return 0;
}

bool ParseHmaze::isExistWall(int x, int y, MazeAngle angle){
	if(angle == MazeAngle::NORTH && ((m_hmap[x][y])&0x1)) return true;
	if(angle == MazeAngle::EAST && ((m_hmap[x][y] >> 1)&0x1)) return true;
	if(angle == MazeAngle::SOUTH && ((m_hmap[x][y] >> 2)&0x1)) return true;
	if(angle == MazeAngle::WEST && ((m_hmap[x][y] >> 3)&0x1)) return true;
	return false;
}

int ParseHmaze::convToMap(){
	for (int i=0; i<16; i++) {
		for (int j=0; j<16; j++) {
			if(isExistWall(i, j, MazeAngle::NORTH)) m_map.addSingleWall(i, j, MazeAngle::NORTH);
			if(isExistWall(i, j, MazeAngle::EAST)) m_map.addSingleWall(i, j, MazeAngle::EAST);
		}
	}
	return 0;
}

int ParseHmaze::getMap(const QString& str, Map& m){
	int ret;
	std::cout << "* Loaded clipboard text" << std::endl;
	std::cout << str.toStdString() << std::endl << std::endl;
	if(ret = loadHmap(str)) return ret;
	if(ret = convToMap()) return ret;
	m = m_map;
	return 0;
}
