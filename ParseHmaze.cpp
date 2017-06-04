/*
 * ParseHmaze.h
 */

#include "ParseHmaze.h"

ParseHmaze::ParseHmaze(){
	m_map = Map();
	for (int i=0; i<32; i++)
		for (int j=0; j<32; j++)
			m_hmap[i][j] = 0;
}
ParseHmaze::~ParseHmaze(){
		
}

int ParseHmaze::loadHmap(const QString& str){
	int ite = 0;
	bool ok;
	QString testcase = "{";
	QString simplified = str;
	simplified.simplified();
	simplified.remove(QChar(' '));
	ite = simplified.indexOf(testcase);
	for(int i=0; i<32; ++i){
		for(int j=0; j<33; ++j){
			++ ite;
			if(simplified.at(ite) == QChar('{') || simplified.at(ite) == QChar(',')) {
				-- j;
				continue;
			} else if(simplified.at(ite) == QChar(';')) {
				return 0;
			} else if(simplified.at(ite) == QChar('}')) {
				++ ite;
				++ ite;
				break;
			}
			if(simplified.at(ite+1) == QChar(',') || simplified.at(ite+1) == QChar('}')){
				m_hmap[i][j] = (simplified.at(ite)).digitValue();
			} else {
				m_hmap[i][j] = (simplified.at(ite++)).digitValue()*10 + (simplified.at(ite)).digitValue();
			}
		}
	}
	for(int i=0; i<32; ++i){
		for(int j=0; j<32; ++j){
			std::cout << m_hmap[j][31-i] << ", ";
		}
		std::cout << std::endl;
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
	for (int i=0; i<32; i++) {
		for (int j=0; j<32; j++) {
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
