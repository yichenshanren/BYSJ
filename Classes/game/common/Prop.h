#pragma once
#include "Role.h"
#include "game/character/XiYangYang.h"
class Prop : public Role{
protected :
	XiYangYang * xiYangYang;
	float moveSpeed; // �ƶ��ٶ�
	float aSpeed; // ����
	bool enable; // 
	bool isCollision;
	bool down; // �Ƿ������ƶ�
	int funcPropTime;
public :
	Prop(){};
	Prop(XiYangYang * xiYangYang, const std::string& filename, const std::string& name);
	Prop(XiYangYang * xiYangYang, Sprite * sprite);
	~Prop();
	// ��ʼ��
	void init();
	// run action
	void start(int startFrame, int stopFrame);
	//void start();
	// stop action
	void stop();
	// ����Ƿ���ײ
	void collision();
	// ��ײ��ִ��
	virtual void collisionListener(){};
	// ���ò����ٶ�
	void setSpeed();
	// �����ƶ�
	void move();
	virtual void moveDown();
	// �����ƶ��ٶ�
	void setMoveSpeed();
	void setASpeed(float a);
	// 
	float getXi();
	void setEnable(bool b);
	bool getEnable();
	void setMoveDown(bool l);
	void setFuncPropTime(int time);
};