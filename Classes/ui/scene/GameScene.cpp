#include "GameScene.h"

LabelTTF * label;

Scene * GameScene::createScene(){
	auto scene = Scene::create(); // ��������
	auto layer = GameScene::create(); // ����ͼ��
	scene->addChild(layer);

	return scene;
}
bool GameScene::init(){
	if (! MLayer::init() ){ // �ж������init() �Ƿ�ɹ�
		return false;
	} 

	// ��ӹ��� ����-------------------------------------------
	auto bg0 = Sprite::create("game_bg_0.png"); // ͨ�����鴴������
	bg0->setPosition(Point::ZERO);
	bg0->setAnchorPoint(Point::ZERO);//753
	bg0->setTag(10);
	auto bg1 = Sprite::create("game_bg_0.png"); // ͨ�����鴴������
	bg1->setPosition(Point::ZERO);
	bg1->setAnchorPoint(Point::ZERO);//753
	bg1->setTag(11);
	bg1->setPositionX(bg0->getPositionX() + 1825);
	this->addChild(bg0);
	this->addChild(bg1);
	this->schedule(schedule_selector(GameScene::moveBackground), 0.002f);
	// ��� menu ��ť---------------------------------------------------------
	auto menuBtn  = MenuItemImage::create(
		"menu_btn.png",
		"menu_btn_press.png",
		CC_CALLBACK_1(GameScene::menuBtnCallBack, this));
	menuBtn->setPosition(ccp(120, 590));
	auto menu = Menu::create(menuBtn, NULL);
	menu->setPosition(Point::ZERO);
	this->addChild(menu, 1);
	/* ��ӷ��� */
	auto score = Sprite::create("score.png");
	score->setPosition(ccp(550, 590));
	score->setScale(0.8f);
	this->addChild(score, 1);
	scoreText = LabelTTF::create("0000", "Marker Felt.ttf", 30);
	scoreText->setPosition(ccp(570, 590));
	this->addChild(scoreText, 1);
	/* ��Ӽ�¼ */
	auto mi = Sprite::create("mi.png");
	mi->setPosition(ccp(800, 590));
	mi->setScale(0.8f);
	this->addChild(mi, 1);
	miText = LabelTTF::create("0000000", "Marker Felt.ttf", 30);
	miText->setPosition(ccp(790, 590));
	miText->setTag(14);
	this->addChild(miText, 1);
	
	// ��ӵ�ͼ--------------------------------------------------
	map = SMap::createMap();
	map->setPosition(Point::ZERO);
	map->setAnchorPoint(Point::ZERO);
	this->addChild(map, 1);
	
	// �����¼� ------------------------------------------------
	// ���㴥��
	auto jumpEvent = EventListenerTouchOneByOne::create();
	jumpEvent->setSwallowTouches(true);
	jumpEvent->onTouchBegan = CC_CALLBACK_2(GameScene::onTouchBegan, this);
	jumpEvent->onTouchMoved = CC_CALLBACK_2(GameScene::onTouchMoved, this);
	jumpEvent->onTouchEnded = CC_CALLBACK_2(GameScene::onTouchEnded, this);
	// �¼��ַ�����ע��
	_eventDispatcher->addEventListenerWithSceneGraphPriority(jumpEvent, this);
	// 
	this->scheduleUpdate();
	/*label = LabelTTF::create("woaini", "arial.ttf", 20);
	label->setTag(0);
	
	label->setPosition(ccp(800, 500));
	this->addChild(label, 1);*/
	GameData::getInstance()->playMusic();
	return true;
}

void GameScene::moveBackground(float time){
	auto bg0 = getChildByTag(10);
	auto bg1 = getChildByTag(11);

       bg0->setPositionX(bg0->getPositionX() - 2);
	   bg1->setPositionX(bg0->getPositionX() + 1713);
	   if (bg0->getPositionX() < -1713){
		   bg0->setPositionX(0);
	   }
}
// 
void GameScene::menuBtnCallBack(Ref * pSender){
	this->gamePause();
}
// ����Ϸ��ǰ�����ͼ
RenderTexture * GameScene::getTexture(){
	auto size = Director::getInstance()->getWinSize();
	//����CCRenderTexture����������СΪ���ڴ�С()
	auto renderTexture = RenderTexture::create(size.width, size.height);
	//����Game��������ӽڵ���Ϣ������renderTexture�С�
	//�������ƽ�ͼ��
	renderTexture->begin();
	this->visit();
	renderTexture->end();
	GameData::getInstance()->stopMusic();
	return renderTexture;
}
/* ��Ϸ��ͣ 
// ����ǰ����ѹջ��������Ϸ��ͣ���������Խ�ͼ��Ϊ����
*/
void GameScene::gamePause(){

	//����Ϸ������ͣ��ѹ�볡����ջ�����л���GamePause����
	Director::getInstance()->pushScene(GamePauseScene::createScene(getTexture()));
	// 
}
/*
  ��Ϸ��������
*/
void GameScene::gameOver(){
	Director::getInstance()->pushScene(GameOverScene::createScene(getTexture()));
}
/* ���ؼ�
   ���ؼ����£�������Ϸ��ͣ����
*/
void GameScene::onBackKeyDown(EventKeyboard::KeyCode  keycode, Event * pEvent){
	this->gamePause();
}
/* �����¼� ---------------------
*  ������Ļ������
*/
bool GameScene::onTouchBegan(Touch *touch, Event *unused_event){
	map->getCharacter()->jump();
		
	return true;
}
void GameScene::onTouchMoved(Touch *touch, Event *unused_event){

}
void GameScene::onTouchEnded(Touch *touch, Event *unused_event){

}
// 
void GameScene::jumpToRun(){
}
void GameScene::update(float t){
	// ����----------------------
	/*char cc[7] = "";
	_itoa_s(GameData::getInstance()->getMi(), cc, 7, 10);
	*/
	if (map->getCharacter()->getPosition().x < 0 || map->getCharacter()->getPosition().y < 0){
		map->getCharacter()->setAlive(false);
	}
	/* �����ܵľ��� */
	miText->setString(GameData::getInstance()->getMi());
	/* ���÷��� */
	scoreText->setString(GameData::getInstance()->getScore());
	/* ������Ϸ */
	if ( ! map->getCharacter()->getAlive() ){
		this->gameOver();
	}
	
	
}