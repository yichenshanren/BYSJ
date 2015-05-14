#ifndef GAME_SCENE // 判断这个场景是否存在
#define GAME_SCENE // 不存在则定义此场景


#include "PopWindow.h"
#include "ui/common/MLayer.h"
#include "StartScene.h"
#include "GamepauseScene.h"
#include "data/MConstant.h"
#include "ui/CocosGUI.h"//UI相关的头文件 
#include "cocostudio/CocoStudio.h" 
#include "game/map/map.h"
#include "data/GameData.h"
#include "GameOverScene.h"

using namespace cocos2d;//CSLoader位于cocos2d命名空间。 
using namespace cocostudio::timeline;//动画相关的类位于cocostuio::timeline当中 
USING_NS_CC;
class GameScene : public MLayer{
private :
	SMap * map; // 地图
	LabelTTF * scoreText;
	LabelTTF * miText;
	GameScene(){};
public :
	virtual bool init(); //实现场景的初始化
	CREATE_FUNC(GameScene); // 实现创建函数
	static Scene * createScene(); // 创建场景

	void moveBackground(float tiem); //
    // 菜单按钮的回调函数
	void menuBtnCallBack(Ref * pSender);
	// 游戏暂停
	void gamePause();
	// 游戏结束
	void gameOver();
	// 返回键
	void onBackKeyDown(EventKeyboard::KeyCode keyCode, Event * pEvent);
	void jumpToRun();
	void update(float t);
	// 获取屏幕截图
	RenderTexture * getTexture();
	// 触摸事件
	 bool onTouchBegan(Touch *touch, Event *unused_event);
	 void onTouchMoved(Touch *touch, Event *unused_event);
	 void onTouchEnded(Touch *touch, Event *unused_event);
};

#endif