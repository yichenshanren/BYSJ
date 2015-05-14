#pragma once
#include "SettingScene.h"


SettingScene::SettingScene(void){}
SettingScene::~SettingScene(void){}

bool SettingScene::init(){
	if (!BaseScene::init()){
		return false;
	}
	// ��ȡһЩ��Ļ�ĳ���
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
    // ��Ӳ˵���Ŀ
	// �����˵���Ŀ
	// ���ذ�ť
	closeBtn = MenuItemImage::create(
		"close_btn_normal.png",
		"close_btn_press.png");
	// ���ڰ�ť
	auto aboutBtn = MenuItemImage::create(
		"about_btn_normal.png",
		"about_btn_press.png", 
		CC_CALLBACK_1(SettingScene::eventCallBack, this));
	// ����ť
	auto shareBtn = MenuItemImage::create(
		"share_btn_normal.png",
		"share_btn_press.png",
		CC_CALLBACK_1(SettingScene::eventCallBack, this));
	  // ���ְ�ť------------
	auto musicOn = MenuItemImage::create(
		"music_btn_on.png",
		"music_btn_on.png");
	auto musicOff = MenuItemImage::create(
		"music_btn_off.png",
		"music_btn_off.png");
	auto musicBtn = MenuItemToggle::createWithCallback(
		CC_CALLBACK_1(SettingScene::eventCallBack, this),
		musicOn,
		musicOff,
		NULL);
	 // ���ò˵���Ŀ������
	closeBtn->setPosition(ccp(845, 560));
	aboutBtn->setPosition(ccp(960, 220));
	shareBtn->setPosition(ccp(960, 640 - 306));
	musicBtn->setPosition(ccp(960, 440));
	// ���ò˵���Ŀ��id
	closeBtn->setTag(MConstant::SET_CLOSE);
	aboutBtn->setTag(MConstant::SET_ABOUT);
	shareBtn->setTag(MConstant::SET_SHARE);
	// Ϊ�˵���Ŀ��Ӷ���
	// ���ְ�ť ����
	auto moveTo = MoveTo::create(0.6f, ccp(553, 440));
	auto easeBounceOut = EaseBackOut::create(moveTo);
	musicBtn->runAction(easeBounceOut);
	// ����ť����
	moveTo = MoveTo::create(0.8f, ccp(542, 640 - 306));
	 easeBounceOut = EaseBackOut::create(moveTo);
	shareBtn->runAction(easeBounceOut);
	// ���ڰ�ť����
	moveTo = MoveTo::create(1.0f, ccp(542, 220));
	easeBounceOut = EaseBackOut::create(moveTo);
	aboutBtn->runAction(easeBounceOut);
	// �˵���Ŀ��ӵ��˵���
	auto menu = Menu::create(closeBtn, aboutBtn, shareBtn,musicBtn, NULL);
	menu->setPosition(Point::ZERO);
	this->addChild(menu, 1);
	// ��������
	auto spriteBG = Sprite::create("setting_bg.png");
	spriteBG->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	this->addChild(spriteBG, 0);
	
	return true;
}

SettingScene * SettingScene::createLayer(){
	SettingScene * settingScene = SettingScene::create();
	settingScene->open();
	return settingScene;
}
// �¼��ص�����
void SettingScene::eventCallBack(Ref * pSender){
	MenuItem * nowItem = (MenuItem *) pSender;
	switch (nowItem->getTag()){
	case MConstant::SET_CLOSE:
		this->close();
		this->setIAmAChild(false);
		break;
	case MConstant::SET_ABOUT:

		break;
	case MConstant::SET_SHARE:

		break;
	default:
		break;
	}

}
// ���� �رհ�ť�Ļص�����
void SettingScene::setCloseCallBack(const ccMenuCallback& callback){
	closeBtn->setCallback(callback);
}