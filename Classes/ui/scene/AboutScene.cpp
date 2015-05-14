#include "AboutScene.h"
USING_NS_CC;

bool AboutScene::init(){
	if (!Layer::init()){
		return false;
	}
	auto spriteBackground = Sprite::create("setting_bg.png");
	spriteBackground->setPosition(Point::ZERO); //���þ��������Ϊԭ��
	spriteBackground->setAnchorPoint(Point::ZERO); // ���þ���ê�������Ϊԭ��
	this->addChild(spriteBackground);
	// ��ӵ��㴥��������
	EventListenerTouchOneByOne * touch = EventListenerTouchOneByOne::create();
	return true;
}

Scene * AboutScene::createScene(){
	auto scene = Scene::create();
	auto layer = AboutScene::create();
	scene->addChild(layer);
	return scene;
}
