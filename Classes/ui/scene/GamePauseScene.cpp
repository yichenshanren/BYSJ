#include "GamePauseScene.h"


Scene * GamePauseScene::createScene(RenderTexture * rt){
	auto scene = Scene::create(); // ��������
	auto layer = GamePauseScene::create(); // ����ͼ��
	scene->addChild(layer);
	// backGround image ����Ϸ�����еĽ�ͼ��Ϊ�˳����еı���
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	auto bg = Sprite::createWithTexture(rt->getSprite()->getTexture());
	bg->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	// ����ͼ��ת180��
	bg->setRotationX(180);
	layer->addChild(bg);
	// Ϊ�������� tag
	scene->setTag(MConstant::GAMESCENE);
	return scene;
}
bool GamePauseScene::init(){
	if (! MLayer::init() ){
		return false;
	}
	
	// �������� ��ӵ���ǰ������
	this->addChild(pausePopWindow(), 1);
	return true;
}
// ��ͣ����
PopWindow * GamePauseScene::pausePopWindow(){
	auto popWindow = PopWindow::createLayer();
	// ���ñ��⡰��Ϸ��ͣ�С�
	popWindow->setTitle(Sprite::create("game_pause_title.png"));
	// ��Ӽ�����Ϸ��ť
	auto continueBtn = MenuItemImage::create(
		"menu_btn.png",
		"menu_btn_press.png",
		[&](Ref *){
		GameData::getInstance()->close();
		Director::getInstance()->popScene();
		Director::getInstance()->replaceScene(StartScene::createScene());
	});

	popWindow->addButton(continueBtn);
	// ����ȡ����ť�İ�ťͼƬ
	popWindow->setCancelBtn(
		Sprite::create("continue_btn_normal.png"),
		Sprite::create("continue_btn_press.png"));

	return popWindow;
}
// ���ؼ�
void GamePauseScene::onBackKeyDown(EventKeyboard::KeyCode keyCode, Event * pEvent){
	Director::getInstance()->popScene();
}