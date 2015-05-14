#include "AboutScene.h"
USING_NS_CC;

bool AboutScene::init(){
	if (!Layer::init()){
		return false;
	}
	auto spriteBackground = Sprite::create("setting_bg.png");
	spriteBackground->setPosition(Point::ZERO); //设置精灵的坐标为原点
	spriteBackground->setAnchorPoint(Point::ZERO); // 设置精灵锚点的坐标为原点
	this->addChild(spriteBackground);
	// 添加单点触控侦听器
	EventListenerTouchOneByOne * touch = EventListenerTouchOneByOne::create();
	return true;
}

Scene * AboutScene::createScene(){
	auto scene = Scene::create();
	auto layer = AboutScene::create();
	scene->addChild(layer);
	return scene;
}
