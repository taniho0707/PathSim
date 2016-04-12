/**
 * @file libpath.h
 * @brief 最短パス生成のテンプレートクラス
 */

#pragma once

#include <utility>
#include <memory>

#include "Pathdata.h"
#include "Map.h"

class Path{
private:
	
public:
	Path();
	
	virtual int getPath(Pathdata& path, const Map& map, const std::pair<uint32_t, uint32_t>& pair);

	virtual ~Path();
};

typedef Path* create_p();
