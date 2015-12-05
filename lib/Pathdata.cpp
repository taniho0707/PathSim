/**
 * @file Pathdata.cpp
 */
#include "Pathdata.h"

Pathdata::Pathdata(){
	currentPos = 0;
	for(int i=0; i<256; ++i){
		data[i] = 0;
		division[i] = 0;
	}
}


MouseMotion Pathdata::getNext(){
	MouseMotion next_motion = {
		EMotion_null,
		0,
		0.5,
		EMotion_null
	};
	if(currentPos > 255){
		return next_motion;
	}
	next_motion.division = division[currentPos];
	unsigned char next_motion_type = data[currentPos];
//		next_motion.currentMotion = data[currentPos];
	if(next_motion_type == EMotion_Straight){
		next_motion.currentMotion = EMotion_Straight;
	} else if(next_motion_type == EMotion_null){
		next_motion.currentMotion = EMotion_null;
	} else if(next_motion_type == EMotion_Right90){
		next_motion.currentMotion = EMotion_Right90;
	} else if(next_motion_type == EMotion_Left90){
		next_motion.currentMotion = EMotion_Left90;
	} else if(next_motion_type == EMotion_Turn180){
		next_motion.currentMotion = EMotion_Turn180;
	} else if(next_motion_type == EMotion_BigRight90){
		next_motion.currentMotion = EMotion_BigRight90;
	} else if(next_motion_type == EMotion_BigLeft90){
		next_motion.currentMotion = EMotion_BigLeft90;
	} else if(next_motion_type == EMotion_BigRight180){
		next_motion.currentMotion = EMotion_BigRight180;
	} else if(next_motion_type == EMotion_BigLeft180){
		next_motion.currentMotion = EMotion_BigLeft180;
	} else if(next_motion_type == EMotion_Right45i){
		next_motion.currentMotion = EMotion_Right45i;
	} else if(next_motion_type == EMotion_Left45i){
		next_motion.currentMotion = EMotion_Left45i;
	} else if(next_motion_type == EMotion_Right135i){
		next_motion.currentMotion = EMotion_Right135i;
	} else if(next_motion_type == EMotion_Left135i){
		next_motion.currentMotion = EMotion_Left135i;
	} else if(next_motion_type == EMotion_Right45o){
		next_motion.currentMotion = EMotion_Right45o;
	} else if(next_motion_type == EMotion_Left45o){
		next_motion.currentMotion = EMotion_Left45o;
	} else if(next_motion_type == EMotion_Right135o){
		next_motion.currentMotion = EMotion_Right135o;
	} else if(next_motion_type == EMotion_Left135o){
		next_motion.currentMotion = EMotion_Left135o;
	} else if(next_motion_type == EMotion_ObliqueRight90){
		next_motion.currentMotion = EMotion_ObliqueRight90;
	} else if(next_motion_type == EMotion_ObliqueLeft90){
		next_motion.currentMotion = EMotion_ObliqueLeft90;
	} else if(next_motion_type == EMotion_Oblique){
		next_motion.currentMotion = EMotion_Oblique;
	} else {
		next_motion.currentMotion = EMotion_null;
	}
	++ currentPos;
	return next_motion;
	/// @todo 次の動きを用意する
//		return data[currentPos-1];
}

void Pathdata::setNext(EMotion next){
	if(currentPos > 255) return;
	data[currentPos] = next;
	++ currentPos;
	return;
}

void Pathdata::resetPos(){
	currentPos = 0;
}

Pathdata::~Pathdata(){

}
	
