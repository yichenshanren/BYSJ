#pragma once 
#include "game/common/Prop.h"
class LanProp : public Prop{


public:
	LanProp(XiYangYang * xiYangYang);
	~LanProp(){};
	// 
	void collisionListener();
	// ���������
	void addLan();
	// �����ƶ�
	void moveDown();

};