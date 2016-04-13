#include "Graph.h"


Graph::Graph(){
	nodes.reserve(500);
	is_classic = false;
}

Graph::~Graph(){}


bool Graph::connectNodes(
	const int16_t x1, const int16_t y1, const WallAngle a1,
	const int16_t x2, const int16_t y2, const WallAngle a2){
	return nodes.at(getNodeNumFromCoord(x1,y1,a1)).connectTo( nodes.at(getNodeNumFromCoord(x2,y2,a2)) );
}

bool Graph::disconnectNodes(
	const int16_t x1, const int16_t y1, const WallAngle a1,
	const int16_t x2, const int16_t y2, const WallAngle a2){
	return nodes.at(getNodeNumFromCoord(x1,y1,a1)).disconnectTo( nodes.at(getNodeNumFromCoord(x2,y2,a2)) );
}

Node Graph::getNode(const int16_t x, const int16_t y, const WallAngle a){
	return nodes.at(getNodeNumFromCoord(x,y,a));
}

uint16_t Graph::getNodeNumFromCoord(const int16_t x, const int16_t y, const WallAngle a){
	if(is_classic){
		if(a == WallAngle::SOUTH) return getNodeNumFromCoord(x, y-1, WallAngle::NORTH);
		else if(a == WallAngle::WEST) return getNodeNumFromCoord(x-1, y, WallAngle::EAST);
		else if(a == WallAngle::NORTH) return x+(y*16);
		else return 120+x+(y*15);
	} else {
		return 0;
	}
}
