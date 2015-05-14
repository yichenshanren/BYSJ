#pragma once
#include "cocos2d.h"
USING_NS_CC;

class BaseScene : public cocos2d::Layer{
private :
	bool iAmAChild;
public :
	BaseScene(void);
	virtual ~BaseScene(void);

    bool init();
	// open
	void open();
	void close();
	// 移除从父节点
	//void remove(float t);
	//重写触摸函数，返回true，屏蔽其它层，达到“模态”效果
	bool onTouchBegan(Touch *touch, Event *event);
	void onTouchMoved(Touch* touch, Event* event);
	void onTouchEnded(Touch* touch, Event* event);
	// 
	void setIAmAChild(bool b);
	bool getIAmAChild();
};