/**
 * @file Graph.h
 */

#ifndef INCLUDED_GRAPH_H
#define INCLUDED_GRAPH_H

#include <utility>
#include <map>

#include "Node.h"
// #include "Edge.h"
#include "Map.h"

class Graph{
private:
	std::map<int, Node> nodes;
//	map<int, Edge> edges;
	

public:
	Graph();
	~Graph();

	int connectNodes(const int coor1, const int coor2);
	int disconnectNodes(const int coor1, const int coor2);
};

#endif
