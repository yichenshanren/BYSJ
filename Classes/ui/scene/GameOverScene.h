#include "PopWindow.h"
#include "StartScene.h"
#include "data/MConstant.h"
#include "data/GameData.h"
class GameOverScene : MLayer{
public:
	bool init();
	static Scene * createScene(RenderTexture * rt);
	CREATE_FUNC(GameOverScene);
	// ������Ϸ����
	PopWindow * pausePopWindow();
	// ���ؼ�
	void onBackKeyDown(EventKeyboard::KeyCode keyCode, Event * pEvent);
};