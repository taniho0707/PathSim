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
	virtual int getPath(Pathdata& path, const Map& map, const std::pair<uint32_t, uint32_t>& pair) = 0;

	virtual ~Path() = 0;
};

typedef std::unique_ptr<Path> create_p();
