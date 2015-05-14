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
	// �Ƴ��Ӹ��ڵ�
	//void remove(float t);
	//��д��������������true�����������㣬�ﵽ��ģ̬��Ч��
	bool onTouchBegan(Touch *touch, Event *event);
	void onTouchMoved(Touch* touch, Event* event);
	void onTouchEnded(Touch* touch, Event* event);
	// 
	void setIAmAChild(bool b);
	bool getIAmAChild();
};