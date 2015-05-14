#pragma once
#define GAME_PAUSE
#include "ui/common/MLayer.h"
#include "PopWindow.h"
#include "StartScene.h"
#include "data/MConstant.h"
#include "data/GameData.h"

class GamePauseScene : MLayer{
public :
	bool init();
	static Scene * createScene(RenderTexture * rt);
	CREATE_FUNC(GamePauseScene);
	// 退出确认/暂停窗口
	PopWindow * pausePopWindow();
	// 返回键
	void onBackKeyDown(EventKeyboard::KeyCode keyCode, Event * pEvent);
};