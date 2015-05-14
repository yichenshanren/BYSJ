#include "GameScene.h"

LabelTTF * label;

Scene * GameScene::createScene(){
	auto scene = Scene::create(); // 创建场景
	auto layer = GameScene::create(); // 创建图层
	scene->addChild(layer);

	return scene;
}
bool GameScene::init(){
	if (! MLayer::init() ){ // 判断祖类的init() 是否成功
		return false;
	} 

	// 添加滚动 背景-------------------------------------------
	auto bg0 = Sprite::create("game_bg_0.png"); // 通过精灵创建背景
	bg0->setPosition(Point::ZERO);
	bg0->setAnchorPoint(Point::ZERO);//753
	bg0->setTag(10);
	auto bg1 = Sprite::create("game_bg_0.png"); // 通过精灵创建背景
	bg1->setPosition(Point::ZERO);
	bg1->setAnchorPoint(Point::ZERO);//753
	bg1->setTag(11);
	bg1->setPositionX(bg0->getPositionX() + 1825);
	this->addChild(bg0);
	this->addChild(bg1);
	this->schedule(schedule_selector(GameScene::moveBackground), 0.002f);
	// 添加 menu 按钮---------------------------------------------------------
	auto menuBtn  = MenuItemImage::create(
		"menu_btn.png",
		"menu_btn_press.png",
		CC_CALLBACK_1(GameScene::menuBtnCallBack, this));
	menuBtn->setPosition(ccp(120, 590));
	auto menu = Menu::create(menuBtn, NULL);
	menu->setPosition(Point::ZERO);
	this->addChild(menu, 1);
	/* 添加分数 */
	auto score = Sprite::create("score.png");
	score->setPosition(ccp(550, 590));
	score->setScale(0.8f);
	this->addChild(score, 1);
	scoreText = LabelTTF::create("0000", "Marker Felt.ttf", 30);
	scoreText->setPosition(ccp(570, 590));
	this->addChild(scoreText, 1);
	/* 添加记录 */
	auto mi = Sprite::create("mi.png");
	mi->setPosition(ccp(800, 590));
	mi->setScale(0.8f);
	this->addChild(mi, 1);
	miText = LabelTTF::create("0000000", "Marker Felt.ttf", 30);
	miText->setPosition(ccp(790, 590));
	miText->setTag(14);
	this->addChild(miText, 1);
	
	// 添加地图--------------------------------------------------
	map = SMap::createMap();
	map->setPosition(Point::ZERO);
	map->setAnchorPoint(Point::ZERO);
	this->addChild(map, 1);
	
	// 触摸事件 ------------------------------------------------
	// 单点触控
	auto jumpEvent = EventListenerTouchOneByOne::create();
	jumpEvent->setSwallowTouches(true);
	jumpEvent->onTouchBegan = CC_CALLBACK_2(GameScene::onTouchBegan, this);
	jumpEvent->onTouchMoved = CC_CALLBACK_2(GameScene::onTouchMoved, this);
	jumpEvent->onTouchEnded = CC_CALLBACK_2(GameScene::onTouchEnded, this);
	// 事件分发器中注册
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
// 将游戏当前画面截图
RenderTexture * GameScene::getTexture(){
	auto size = Director::getInstance()->getWinSize();
	//创建CCRenderTexture，纹理画布大小为窗口大小()
	auto renderTexture = RenderTexture::create(size.width, size.height);
	//遍历Game类的所有子节点信息，画入renderTexture中。
	//这里类似截图。
	renderTexture->begin();
	this->visit();
	renderTexture->end();
	GameData::getInstance()->stopMusic();
	return renderTexture;
}
/* 游戏暂停 
// 将当前场景压栈，弹出游戏暂停场景，并以截图作为背景
*/
void GameScene::gamePause(){

	//将游戏界面暂停，压入场景堆栈。并切换到GamePause界面
	Director::getInstance()->pushScene(GamePauseScene::createScene(getTexture()));
	// 
}
/*
  游戏结束界面
*/
void GameScene::gameOver(){
	Director::getInstance()->pushScene(GameOverScene::createScene(getTexture()));
}
/* 返回键
   返回键按下，弹出游戏暂停场景
*/
void GameScene::onBackKeyDown(EventKeyboard::KeyCode  keycode, Event * pEvent){
	this->gamePause();
}
/* 触摸事件 ---------------------
*  触摸屏幕，羊跳
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
	// 测试----------------------
	/*char cc[7] = "";
	_itoa_s(GameData::getInstance()->getMi(), cc, 7, 10);
	*/
	if (map->getCharacter()->getPosition().x < 0 || map->getCharacter()->getPosition().y < 0){
		map->getCharacter()->setAlive(false);
	}
	/* 设置跑的距离 */
	miText->setString(GameData::getInstance()->getMi());
	/* 设置分数 */
	scoreText->setString(GameData::getInstance()->getScore());
	/* 结束游戏 */
	if ( ! map->getCharacter()->getAlive() ){
		this->gameOver();
	}
	
	
}