#pragma once
#include "cocos2d.h"
#include "BaseScene.h"
using namespace cocos2d;

class MLayer : public cocos2d::Layer{
private :
	BaseScene * popWindow;
public :
	MLayer();
	~MLayer();
	bool init();
	// 返回键回调函数
	virtual void onBackKeyDown(EventKeyboard::KeyCode keyCode, Event * pEvent);
	// 设置 弹窗
	void setPopWindow(BaseScene * pop);
	// 获得弹窗
	BaseScene * getPopWindow();
};