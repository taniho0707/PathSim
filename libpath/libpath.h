/**
 * @file libpath.h
 * @brief 最短パス生成のテンプレートクラス
 */

#pragma once

#include "Pathdata.h"
#include "Map.h"

extern "C" int getPath(Pathdata& p, const Map& m);

