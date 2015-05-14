#pragma once
#include "Role.h"
#include "game/character/XiYangYang.h"
class Prop : public Role{
protected :
	XiYangYang * xiYangYang;
	float moveSpeed; // 移动速度
	float aSpeed; // 速率
	bool enable; // 
	bool isCollision;
	bool down; // 是否向下移动
	int funcPropTime;
public :
	Prop(){};
	Prop(XiYangYang * xiYangYang, const std::string& filename, const std::string& name);
	Prop(XiYangYang * xiYangYang, Sprite * sprite);
	~Prop();
	// 初始化
	void init();
	// run action
	void start(int startFrame, int stopFrame);
	//void start();
	// stop action
	void stop();
	// 检测是否碰撞
	void collision();
	// 碰撞后执行
	virtual void collisionListener(){};
	// 设置播放速度
	void setSpeed();
	// 向左移动
	void move();
	virtual void moveDown();
	// 设置移动速度
	void setMoveSpeed();
	void setASpeed(float a);
	// 
	float getXi();
	void setEnable(bool b);
	bool getEnable();
	void setMoveDown(bool l);
	void setFuncPropTime(int time);
};