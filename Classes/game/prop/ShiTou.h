#pragma once 
#include "game/common/Prop.h"

class ShiTou : public Prop{


public:
	ShiTou(XiYangYang * xiYangYang);
	~ShiTou(){};
	// 
	void collisionListener();
	// 

};