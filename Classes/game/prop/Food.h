#pragma once 
#include "game/common/Prop.h"
class Food : public Prop{


private:
	int foods; // 食物
public:
	static const int FOOD_BREAD = 5; // 面包
	static const int FOOD_ICE = 10; // 冰淇淋
	static const int FOOD_DRINK = 15; // 饮料

	Food(XiYangYang * xiYangYang, int food);
	~Food(){};
	// 
	void collisionListener();
	// 添加十五精灵
	void addFood(int food);

};