#pragma once
#include "BaseScene.h"
#include "data/GameData.h"
USING_NS_CC;

BaseScene::BaseScene(void){
	setIAmAChild(false);
}
BaseScene::~BaseScene(void){
	setIAmAChild(false);
}

bool BaseScene::init(){
	if (!Layer::init()){
		return false;
	}
	// 获取触摸事件 屏蔽下层触摸
	auto listener = EventListenerTouchOneByOne::create();
	listener->setSwallowTouches(true);

	listener->onTouchBegan = CC_CALLBACK_2(BaseScene::onTouchBegan, this);
	listener->onTouchMoved = CC_CALLBACK_2(BaseScene::onTouchMoved, this);
	listener->onTouchEnded = CC_CALLBACK_2(BaseScene::onTouchEnded, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
	return true;
}
void BaseScene::open(){
	//层弹出动画  
	   auto visibleSize = Director::getInstance()->getVisibleSize();
       auto origin = Director::getInstance()->getVisibleOrigin();
	   this->setPosition(Point(origin.x + visibleSize.width , origin.y - visibleSize.height));
	   auto moveTo = MoveTo::create(0.5, Point::ZERO);
	   auto easeBounceOut = EaseBackOut::create(moveTo);
	   this->runAction(easeBounceOut);
	   setIAmAChild(true);
	   GameData::getInstance()->playEffect(GameData::BTN_MUSIC);
}

void BaseScene::close(){
	//消失动画，消失后移除自身  
	    auto visibleSize = Director::getInstance()->getVisibleSize();
	    auto origin = Director::getInstance()->getVisibleOrigin();
	
		auto moveTo = MoveTo::create(0.5, Point(origin.x + visibleSize.width / 2, origin.y - visibleSize.height / 2));
	    auto easeBounceIn = EaseBackIn::create(moveTo);
	    Sequence* seq = Sequence::create(easeBounceIn, RemoveSelf::create(true), NULL);
	    this->runAction(seq);
		setIAmAChild(false);
		GameData::getInstance()->playEffect(GameData::POP_MUSIC);
//		this->scheduleOnce(schedule_selector(BaseScene::remove), 0.5f);
		
}
//触摸函数ccTouchBegan ，返回 true
bool BaseScene::onTouchBegan(Touch *pTouch, Event *pEvent)
{
	return true;
}
void BaseScene::onTouchMoved(Touch * pTouch, Event* pEvent){

}
void BaseScene::onTouchEnded(Touch *pTouch, Event *pEvent){

}
//void BaseScene::remove(float t){
//	this->removeFromParent();
//}
void BaseScene::setIAmAChild(bool b){
	this->iAmAChild = b;
}
bool BaseScene::getIAmAChild(){
	return this->iAmAChild;
}