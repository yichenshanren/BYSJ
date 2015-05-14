#pragma once 
#include "game/common/Prop.h"
class Food : public Prop{


private:
	int foods; // ʳ��
public:
	static const int FOOD_BREAD = 5; // ���
	static const int FOOD_ICE = 10; // �����
	static const int FOOD_DRINK = 15; // ����

	Food(XiYangYang * xiYangYang, int food);
	~Food(){};
	// 
	void collisionListener();
	// ���ʮ�徫��
	void addFood(int food);

};