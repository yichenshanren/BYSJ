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
	// ���ؼ��ص�����
	virtual void onBackKeyDown(EventKeyboard::KeyCode keyCode, Event * pEvent);
	// ���� ����
	void setPopWindow(BaseScene * pop);
	// ��õ���
	BaseScene * getPopWindow();
};