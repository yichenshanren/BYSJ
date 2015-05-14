#pragma once
#include "game/common/Role.h"

class XiYangYang : public Role {
private :
	
	//float bodyX; // 羊身（node子节点）的原始X坐标
	//float bodyY; // 羊身（node子节点）的原始Y坐标

	//Node * node; // 喜羊羊动画节点
	//float scale; // node的缩放系数
	//ActionTimeline * action; // 喜羊羊动画
	bool isRunning; // 是否跑
	bool isJump; // 是否跳
	bool isJumpSec; // 二级跳
	bool isAlive; // 是否活着
	float speed; // 地图移动速度

public :
	// 构造器
	XiYangYang();
	~XiYangYang();
	// 加载动画
	bool getAlive();
	void setAlive(bool alive);
	// 运行跳动画
	void jump();
	void jumpSec();
	// 运行跑的动画
	void run();
	// 获取节点
//	Node * getNode();
	// 
	bool isJumping();
	// 坐标
	/*void setPositionY(float y);
	Vec2 getPosition();
	void setPosition(Vec2 potin);*/
	void setDefualtPositon();
	// 设置获取speed
	void setSpeed(float sp);
	float getSpeed();
	// 移动
	void move(bool back);
	void setNoJump();
	void drop();
};