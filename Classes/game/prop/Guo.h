#pragma once 
#include "game/common/Prop.h"

class Guo : public Prop{


public:
	Guo(XiYangYang * xiYangYang);
	~Guo(){};
	// 
	void collisionListener();
	// 

};