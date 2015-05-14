#pragma once 
#include "game/common/Prop.h"
class FeiProp : public Prop{


public:
	FeiProp(XiYangYang * xiYangYang);
	~FeiProp(){};
	// 
	void collisionListener();
	// ÃÌº”¿¡—Û—Û
	void addFei();

};