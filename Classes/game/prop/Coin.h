#pragma once 
#include "game/common/Prop.h"
#include "data/GameData.h"
class Coin : public Prop{


public:
	Coin(XiYangYang * xiYangYang);
	~Coin(){};
	// 
	void collisionListener();
	// 
	
};