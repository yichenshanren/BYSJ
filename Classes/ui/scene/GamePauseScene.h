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
	// �˳�ȷ��/��ͣ����
	PopWindow * pausePopWindow();
	// ���ؼ�
	void onBackKeyDown(EventKeyboard::KeyCode keyCode, Event * pEvent);
};