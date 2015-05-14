#pragma once
#include "cocos2d.h"
#include "ui/CocosGUI.h"//UI相关的头文件 
#include "cocostudio/CocoStudio.h" 
#include "data/GameData.h"
USING_NS_CC;
using namespace cocos2d;//CSLoader位于cocos2d命名空间。 
using namespace cocostudio::timeline;//动画相关的类位于cocostuio::timeline当中 

class Role {
protected :
	Node * node; // 从文件加载的节点
	ActionTimeline * action; // 节点中的动画
	Node * keyNode; // node中的关键子节点
	float bodyX; // node中某一子节点的初始坐标
	float bodyY; // node中某一子节点的初始坐标
	float scale; // node的缩放系数
	Vec2 size; // node的size
	int type; // 构造类型
public :
	Role(){};
	Role(Sprite * sprite);
	Role(const std::string& filename, const std::string& name);
	~Role();
	// 初始化
	void init();
	// 从文件中加载node
	void create(const std::string& filename, const std::string& name);
	void create(Sprite * sprite);
	// 获取node
	Node * getNode();
	// 设置坐标
	void setPositionY(float y);
	void setPositionX(float x);
	void setPosition(Vec2 potin);
	// 获取节点坐标
	Vec2 getPosition();
	// 获取node的size
	Vec2 getSize();
	void setSize(float width, float hight);
	// 设置缩放
	void setScale(float scale);

};