/**
 * @file libpath.h
 * @brief 最短パス生成のテンプレートクラス
 */

#ifndef INCLUDED_LIBPATH_H
#define INCLUDED_LIBPATH_H

#include "Pair.h"
#include "Pathdata.h"
#include "Map.h"

class Path{
private:
	Pathdata pathdata;
	
public:
	Path(){
		pathdata = Pathdata();
	}

	virtual int getPath(Pathdata& path, const Map& map, const Pair<int>& pair);

	~Path();
};

#endif
