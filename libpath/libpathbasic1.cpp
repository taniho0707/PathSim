/**
 * @file libpathbasic1.cpp
 */
#include "libpath.h"


class MyPath : public Path{
private:
	

public:
	MyPath(){
		
	}

	int getPath(Pathdata& path, const Map& map, const std::pair<uint32_t, uint32_t>& pair) override{
		return 0;
	}

	~MyPath(){
		
	}
};

extern "C" Path* CreateMyPath() {
	return new MyPath;
}
