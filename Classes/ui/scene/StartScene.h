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
	// 场景必须实现的函数
	virtual bool init();
	static cocos2d::Scene * createScene();
	CREATE_FUNC(StartScene);
	// 用户函数
	// 菜单按钮事件回掉函数
	void menuCallback(cocos2d::Ref * pSender);
	// 关闭弹窗
	void removePop();
	// 获取弹窗
	PopWindow * getQuitPopWindow();
	// 弹出 确认退出窗口
	void showQuitWindow();
	// 弹出 设置窗口
	void showSettingWindow();
	// 重写 返回键
	void onBackKeyDown(EventKeyboard::KeyCode keyCode, Event * pEvent);
};
