#include "StartScene.h"
#include "GameScene.h"
#include "AboutScene.h"
#include "SettingScene.h"
#include "PopWindow.h"
#include "ui/CocosGUI.h"//UI相关的头文件 
#include "cocostudio/CocoStudio.h" 
#include "data/GameData.h"


using namespace cocos2d;//CSLoader位于cocos2d命名空间。 
using namespace cocostudio::timeline;//动画相关的类位于cocostuio::timeline当中 
USING_NS_CC;

StartScene::StartScene(){
	settingScene = NULL;
	popWindow = NULL;
}
StartScene::~StartScene(){

}
bool StartScene::init(){
	if (!MLayer::init()){
		return false;
	}
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
   // 添加菜单条目
	// 开始游戏按钮
	auto startGame = MenuItemImage::create(
		 "start_btn_0.png",
	     "start_btn_1.png",
		 CC_CALLBACK_1(StartScene::menuCallback, this));
	// 设置按钮
	auto setting = MenuItemImage::create(
		"setting_btn_0.png",
		"setting_btn_1.png",
		CC_CALLBACK_1(StartScene::menuCallback, this));
	// 退出按钮
	auto quit = MenuItemImage::create(
		"quit_btn_0.png",
		"quit_btn_1.png",
		CC_CALLBACK_1(StartScene::menuCallback, this));
    // 给菜单条目设置位置
	startGame->setPosition(ccp(1000, 250));
	setting->setPosition(ccp(1000, 640 - 507));
	quit->setPosition(ccp(1000, 640 - 595));
	// g给菜单条目添加动画
	auto moveTo = MoveTo::create(0.5f, ccp(802, 250));
	auto easeBounceOut = EaseBackOut::create(moveTo);
	startGame->runAction(easeBounceOut);

	moveTo = MoveTo::create(0.9f, ccp(845, 640 - 507));
	easeBounceOut = EaseBackOut::create(moveTo);
	setting->runAction(easeBounceOut);

	moveTo = MoveTo::create(1.5f, ccp(855, 640 - 595));
	easeBounceOut = EaseBackOut::create(moveTo);
	quit->runAction(easeBounceOut);
	// 给菜单条目设置 标识
	startGame->setTag(MConstant::START_START);
	setting->setTag(MConstant::START_SETTING);
	quit->setTag(MConstant::START_QUIT);
	//// 将菜单条目添加到菜单中
	 auto menu = Menu::create(startGame, setting, quit, NULL);
	 menu->setPosition(Vec2::ZERO);
	 this->addChild(menu, 1);
	 // 添加相片
	 auto spriteC = Sprite::create("game_start_c.png");
	 spriteC->setPosition(ccp(-400, 300));
	 moveTo = MoveTo::create(0.6f, ccp(338, 640 - 348));
	 easeBounceOut = EaseBackOut::create(moveTo);
	 spriteC->runAction(easeBounceOut);
	 this->addChild(spriteC, 1);
	// 设置背景
	auto spriteBG = Sprite::create("game_start_bg.png");
	spriteBG->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	this->addChild(spriteBG, 0);
	
	this->setPopWindow(NULL);
	this->getQuitPopWindow();
	SettingScene::createLayer();

	GameData::getInstance()->playEffect(GameData::START_MUSIC, true);
	return true;
}

Scene * StartScene::createScene(){
	auto scene = Scene::create();
	auto layer = StartScene::create();
	scene->addChild(layer);
	return scene;
}

void StartScene::menuCallback(cocos2d::Ref * pSender){
	MenuItem * nowItem = (MenuItem *)pSender;
	switch (nowItem->getTag()){
		// 开始游戏 按钮
	case MConstant::START_START: 
		GameData::getInstance()->stopEffect(0);
		Director::getInstance()->replaceScene(GameScene::createScene());
		
		break;
		// 设置 按钮
	case MConstant::START_SETTING:
		showSettingWindow();
		break;
		// 退出按钮
	case MConstant::START_QUIT: 
	{
        // 添加退出确认层
		showQuitWindow();
	}
		break;
	default:
		removePop();
		break;
	}
}

// 获取退出确认弹窗
PopWindow * StartScene::getQuitPopWindow(){
	auto  pop = PopWindow::createLayer();
	// 设置标题 此处“是否退出游戏”
	pop->setTitle(Sprite::create("quit_text.png"));
	// 添加确定按钮
	auto confirm = MenuItemImage::create(
		"confirm_btn_normal.png",
		"confirm_btn_press.png",
		[&](Ref *){
		exit(0);
	});
	pop->addButton(confirm);
	// 设置取消按钮
	pop->setCancelBtn(
		Sprite::create("cancel_btn_normal.png"),
		Sprite::create("cancel_btn_press.png"),
		CC_CALLBACK_1(StartScene::menuCallback, this));
	// 设置弹窗内容
	auto content = Sprite::create("xiaohuihui.png");
	content->setPosition(ccp(400, MConstant::WINDOW_HEIGHT - 397));
	pop->setContent(content);
	return pop;
}
void StartScene::onBackKeyDown(EventKeyboard::KeyCode keyCode, Event * pEvent){
	if (this->getPopWindow() != NULL){
		removePop();
	}
	else {
		showQuitWindow();
	}
}
// 弹出退出 确认窗口
void StartScene::showQuitWindow(){
	popWindow = getQuitPopWindow();
	this->addChild(popWindow, 2);
	this->setPopWindow(popWindow);
}
void StartScene::showSettingWindow(){
    settingScene = SettingScene::createLayer();
	settingScene->setCloseCallBack(CC_CALLBACK_1(StartScene::menuCallback, this));
	this->addChild(settingScene, 2);
	this->setPopWindow(settingScene);
}
// 移除弹窗
void StartScene::removePop(){
	this->getPopWindow()->close();
	this->setPopWindow(NULL);
}