#pragma once
#define START_SECNE
#include "cocos2d.h"
#include "cocos-ext.h"
#include "PopWindow.h"
#include "ui/common/MLayer.h"
#include "SettingScene.h"
#include "PopWindow.h"
using namespace cocos2d;
using namespace extension;
class StartScene :public MLayer{
private :
	SettingScene * settingScene;
	PopWindow * popWindow;
public :
	StartScene();
	~StartScene();
	// ��������ʵ�ֵĺ���
	virtual bool init();
	static cocos2d::Scene * createScene();
	CREATE_FUNC(StartScene);
	// �û�����
	// �˵���ť�¼��ص�����
	void menuCallback(cocos2d::Ref * pSender);
	// �رյ���
	void removePop();
	// ��ȡ����
	PopWindow * getQuitPopWindow();
	// ���� ȷ���˳�����
	void showQuitWindow();
	// ���� ���ô���
	void showSettingWindow();
	// ��д ���ؼ�
	void onBackKeyDown(EventKeyboard::KeyCode keyCode, Event * pEvent);
};
