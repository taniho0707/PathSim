/**
 * @file Graph.h
 * @brief 迷路データを構成するノードの集合体
 *        迷路とノード番号の管理も担う
 */

#pragma once

#include <utility>
#include <vector>

#include "Node.h"
#include "Map.h"

enum class WallAngle : uint8_t {
	NORTH,
	EAST,
	SOUTH,
	WEST,
};

class Graph{
private:
	std::vector<Node> nodes;

	bool is_classic;

public:
	Graph();
	~Graph();

	bool connectNodes(
		const int16_t x1, const int16_t y1, const WallAngle a1,
		const int16_t x2, const int16_t y2, const WallAngle a2);
	bool disconnectNodes(
		const int16_t x1, const int16_t y1, const WallAngle a1,
		const int16_t x2, const int16_t y2, const WallAngle a2);

	Node getNode(const int16_t x, const int16_t y, const WallAngle a);

	uint16_t getNodeNumFromCoord(const int16_t x, const int16_t y, const WallAngle a);
};
