#pragma once
#include "SettingScene.h"


SettingScene::SettingScene(void){}
SettingScene::~SettingScene(void){}

bool SettingScene::init(){
	if (!BaseScene::init()){
		return false;
	}
	// 获取一些屏幕的常量
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
    // 添加菜单条目
	// 创建菜单条目
	// 开关按钮
	closeBtn = MenuItemImage::create(
		"close_btn_normal.png",
		"close_btn_press.png");
	// 关于按钮
	auto aboutBtn = MenuItemImage::create(
		"about_btn_normal.png",
		"about_btn_press.png", 
		CC_CALLBACK_1(SettingScene::eventCallBack, this));
	// 分享按钮
	auto shareBtn = MenuItemImage::create(
		"share_btn_normal.png",
		"share_btn_press.png",
		CC_CALLBACK_1(SettingScene::eventCallBack, this));
	  // 音乐按钮------------
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
	 // 设置菜单条目的坐标
	closeBtn->setPosition(ccp(845, 560));
	aboutBtn->setPosition(ccp(960, 220));
	shareBtn->setPosition(ccp(960, 640 - 306));
	musicBtn->setPosition(ccp(960, 440));
	// 设置菜单条目的id
	closeBtn->setTag(MConstant::SET_CLOSE);
	aboutBtn->setTag(MConstant::SET_ABOUT);
	shareBtn->setTag(MConstant::SET_SHARE);
	// 为菜单条目添加动画
	// 音乐按钮 动画
	auto moveTo = MoveTo::create(0.6f, ccp(553, 440));
	auto easeBounceOut = EaseBackOut::create(moveTo);
	musicBtn->runAction(easeBounceOut);
	// 分享按钮动画
	moveTo = MoveTo::create(0.8f, ccp(542, 640 - 306));
	 easeBounceOut = EaseBackOut::create(moveTo);
	shareBtn->runAction(easeBounceOut);
	// 关于按钮动画
	moveTo = MoveTo::create(1.0f, ccp(542, 220));
	easeBounceOut = EaseBackOut::create(moveTo);
	aboutBtn->runAction(easeBounceOut);
	// 菜单条目添加到菜单中
	auto menu = Menu::create(closeBtn, aboutBtn, shareBtn,musicBtn, NULL);
	menu->setPosition(Point::ZERO);
	this->addChild(menu, 1);
	// 创建背景
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
// 事件回掉函数
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
// 设置 关闭按钮的回掉函数
void SettingScene::setCloseCallBack(const ccMenuCallback& callback){
	closeBtn->setCallback(callback);
}