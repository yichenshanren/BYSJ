#pragma once
#include<vector>
#include "cocos2d.h"
using namespace std;
USING_NS_CC;

class BackGround {
private :
	vector<Sprite *> backGrounds; // 背景
	float moveSpeed;// 移动速度
	Sprite * bg0;
	Sprite * bg1;

public :
	BackGround();
	~BackGround();
	// 滚动背景
	void move();
	// 设置滚动速度
	void setMoveSpeed();
	// 添加背景到场景
	void addTo(Layer * layer);
};