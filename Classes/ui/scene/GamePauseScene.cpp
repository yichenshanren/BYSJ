#include "GamePauseScene.h"


Scene * GamePauseScene::createScene(RenderTexture * rt){
	auto scene = Scene::create(); // 创建场景
	auto layer = GamePauseScene::create(); // 创建图层
	scene->addChild(layer);
	// backGround image 将游戏场景中的截图作为此场景中的背景
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	auto bg = Sprite::createWithTexture(rt->getSprite()->getTexture());
	bg->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	// 将截图旋转180°
	bg->setRotationX(180);
	layer->addChild(bg);
	// 为场景设置 tag
	scene->setTag(MConstant::GAMESCENE);
	return scene;
}
bool GamePauseScene::init(){
	if (! MLayer::init() ){
		return false;
	}
	
	// 将弹窗层 添加到当前场景中
	this->addChild(pausePopWindow(), 1);
	return true;
}
// 暂停窗口
PopWindow * GamePauseScene::pausePopWindow(){
	auto popWindow = PopWindow::createLayer();
	// 设置标题“游戏暂停中”
	popWindow->setTitle(Sprite::create("game_pause_title.png"));
	// 添加继续游戏按钮
	auto continueBtn = MenuItemImage::create(
		"menu_btn.png",
		"menu_btn_press.png",
		[&](Ref *){
		GameData::getInstance()->close();
		Director::getInstance()->popScene();
		Director::getInstance()->replaceScene(StartScene::createScene());
	});

	popWindow->addButton(continueBtn);
	// 设置取消按钮的按钮图片
	popWindow->setCancelBtn(
		Sprite::create("continue_btn_normal.png"),
		Sprite::create("continue_btn_press.png"));

	return popWindow;
}
// 返回键
void GamePauseScene::onBackKeyDown(EventKeyboard::KeyCode keyCode, Event * pEvent){
	Director::getInstance()->popScene();
}