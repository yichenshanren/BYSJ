#pragma once 
#include "game/common/Prop.h"

class Road : public Prop{

public :
	Road(XiYangYang * xiYangYang);
	~Road(){};
	// 
	void collisionListener();
	void setNormalY();
	void setButtomY();
	void setDefaultY();
};