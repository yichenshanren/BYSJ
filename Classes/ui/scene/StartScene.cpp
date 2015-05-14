#include "StartScene.h"
#include "GameScene.h"
#include "AboutScene.h"
#include "SettingScene.h"
#include "PopWindow.h"
#include "ui/CocosGUI.h"//UI��ص�ͷ�ļ� 
#include "cocostudio/CocoStudio.h" 
#include "data/GameData.h"


using namespace cocos2d;//CSLoaderλ��cocos2d�����ռ䡣 
using namespace cocostudio::timeline;//������ص���λ��cocostuio::timeline���� 
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
   // ��Ӳ˵���Ŀ
	// ��ʼ��Ϸ��ť
	auto startGame = MenuItemImage::create(
		 "start_btn_0.png",
	     "start_btn_1.png",
		 CC_CALLBACK_1(StartScene::menuCallback, this));
	// ���ð�ť
	auto setting = MenuItemImage::create(
		"setting_btn_0.png",
		"setting_btn_1.png",
		CC_CALLBACK_1(StartScene::menuCallback, this));
	// �˳���ť
	auto quit = MenuItemImage::create(
		"quit_btn_0.png",
		"quit_btn_1.png",
		CC_CALLBACK_1(StartScene::menuCallback, this));
    // ���˵���Ŀ����λ��
	startGame->setPosition(ccp(1000, 250));
	setting->setPosition(ccp(1000, 640 - 507));
	quit->setPosition(ccp(1000, 640 - 595));
	// g���˵���Ŀ��Ӷ���
	auto moveTo = MoveTo::create(0.5f, ccp(802, 250));
	auto easeBounceOut = EaseBackOut::create(moveTo);
	startGame->runAction(easeBounceOut);

	moveTo = MoveTo::create(0.9f, ccp(845, 640 - 507));
	easeBounceOut = EaseBackOut::create(moveTo);
	setting->runAction(easeBounceOut);

	moveTo = MoveTo::create(1.5f, ccp(855, 640 - 595));
	easeBounceOut = EaseBackOut::create(moveTo);
	quit->runAction(easeBounceOut);
	// ���˵���Ŀ���� ��ʶ
	startGame->setTag(MConstant::START_START);
	setting->setTag(MConstant::START_SETTING);
	quit->setTag(MConstant::START_QUIT);
	//// ���˵���Ŀ��ӵ��˵���
	 auto menu = Menu::create(startGame, setting, quit, NULL);
	 menu->setPosition(Vec2::ZERO);
	 this->addChild(menu, 1);
	 // �����Ƭ
	 auto spriteC = Sprite::create("game_start_c.png");
	 spriteC->setPosition(ccp(-400, 300));
	 moveTo = MoveTo::create(0.6f, ccp(338, 640 - 348));
	 easeBounceOut = EaseBackOut::create(moveTo);
	 spriteC->runAction(easeBounceOut);
	 this->addChild(spriteC, 1);
	// ���ñ���
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
		// ��ʼ��Ϸ ��ť
	case MConstant::START_START: 
		GameData::getInstance()->stopEffect(0);
		Director::getInstance()->replaceScene(GameScene::createScene());
		
		break;
		// ���� ��ť
	case MConstant::START_SETTING:
		showSettingWindow();
		break;
		// �˳���ť
	case MConstant::START_QUIT: 
	{
        // ����˳�ȷ�ϲ�
		showQuitWindow();
	}
		break;
	default:
		removePop();
		break;
	}
}

// ��ȡ�˳�ȷ�ϵ���
PopWindow * StartScene::getQuitPopWindow(){
	auto  pop = PopWindow::createLayer();
	// ���ñ��� �˴����Ƿ��˳���Ϸ��
	pop->setTitle(Sprite::create("quit_text.png"));
	// ���ȷ����ť
	auto confirm = MenuItemImage::create(
		"confirm_btn_normal.png",
		"confirm_btn_press.png",
		[&](Ref *){
		exit(0);
	});
	pop->addButton(confirm);
	// ����ȡ����ť
	pop->setCancelBtn(
		Sprite::create("cancel_btn_normal.png"),
		Sprite::create("cancel_btn_press.png"),
		CC_CALLBACK_1(StartScene::menuCallback, this));
	// ���õ�������
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
// �����˳� ȷ�ϴ���
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
// �Ƴ�����
void StartScene::removePop(){
	this->getPopWindow()->close();
	this->setPopWindow(NULL);
}