#pragma once
#include<vector>
#include "cocos2d.h"
using namespace std;
USING_NS_CC;

class BackGround {
private :
	vector<Sprite *> backGrounds; // ����
	float moveSpeed;// �ƶ��ٶ�
	Sprite * bg0;
	Sprite * bg1;

public :
	BackGround();
	~BackGround();
	// ��������
	void move();
	// ���ù����ٶ�
	void setMoveSpeed();
	// ��ӱ���������
	void addTo(Layer * layer);
};