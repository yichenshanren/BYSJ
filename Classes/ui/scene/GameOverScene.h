#include "PopWindow.h"
#include "StartScene.h"
#include "data/MConstant.h"
#include "data/GameData.h"
class GameOverScene : MLayer{
public:
	bool init();
	static Scene * createScene(RenderTexture * rt);
	CREATE_FUNC(GameOverScene);
	// 重新游戏窗口
	PopWindow * pausePopWindow();
	// 返回键
	void onBackKeyDown(EventKeyboard::KeyCode keyCode, Event * pEvent);
};