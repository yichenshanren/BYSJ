#pragma once 
#include "game/common/Prop.h"

class Lang : public Prop{

public:
	Lang(XiYangYang * xiYangYang);
	~Lang(){};
	// 
	void collisionListener();
};