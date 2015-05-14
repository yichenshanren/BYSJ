#pragma once 
#include "game/common/Prop.h"
class LanProp : public Prop{


public:
	LanProp(XiYangYang * xiYangYang);
	~LanProp(){};
	// 
	void collisionListener();
	// 添加懒洋洋
	void addLan();
	// 向下移动
	void moveDown();

};