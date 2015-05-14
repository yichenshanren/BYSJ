#pragma once
#include "PopWindow.h"
#include "data/MConstant.h"

PopWindow * PopWindow::createLayer(){
	PopWindow * popWindow = PopWindow::create();
	return popWindow;
}
bool PopWindow::init(){
	if (!BaseScene::init()){
		return false;
	}
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	// 添加菜单按钮
	// 将菜单选项添加到菜单中
	auto menu = Menu::create();
	menu->setPosition(Point::ZERO);
	menu->setTag(MConstant::POP_WINDOW_MENU);
	this->addChild(menu, 1);
	// 添加取消按钮
	cancelBtn = MenuItemImage::create();
	cancelBtn->setPosition(ccp(960, MConstant::WINDOW_HEIGHT - 271));
	  // 为取消按钮添加动画
	auto moveTo = MoveTo::create(1.0f, ccp(603, MConstant::WINDOW_HEIGHT - 271));
	auto easeBounceOut = EaseBackOut::create(moveTo);
	cancelBtn->runAction(easeBounceOut);
	 menu->addChild(cancelBtn);
	// 添加背景
	auto spriteBg = Sprite::create("popwindow_bg.png");
	spriteBg->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	this->addChild(spriteBg);
	// 运行父类的弹出动画
	this->open();
	return true;
}

// 设置弹窗的标题
void PopWindow::setTitle(Sprite * titleImage){
	titleImage->setPosition(ccp(591, 640 - 150));
	this->addChild(titleImage, 1);
}
// 添加按钮
void PopWindow::addButton(MenuItemImage * btn){
	// 
	auto menu = this->getChildByTag(MConstant::POP_WINDOW_MENU);
	// 设置按钮位置
	btn->setPosition(ccp(960, 640 - 370));
	// 给按钮添加动画
	auto moveTo = MoveTo::create(0.8f, ccp(610, 640 - 370));
	auto easeBounceOut = EaseBackOut::create(moveTo);
	btn->runAction(easeBounceOut);
	menu->addChild(btn);
}
void PopWindow::remove(){
	this->close();
}
// 为弹窗设置取消按钮
void PopWindow::setCancelBtn(Sprite *normal, Sprite *press){
	cancelBtn->setNormalImage(normal);
	cancelBtn->setSelectedImage(press);
	cancelBtn->setCallback([&](Ref *){
		// 判断当前场景 是否为游戏暂停场景， 
		// 游戏暂停场景则 将当前场景从场景客栈中弹出
		if (Director::getInstance()->getRunningScene()->getTag() == MConstant::GAMESCENE){
			Director::getInstance()->popScene();
			this->close();
		}
		// 不是游戏暂停场景则 将弹窗层关闭， 运行关闭动画
		else this->close();
	});
}
void PopWindow::setCancelBtn(Sprite *normal, Sprite *press,  const ccMenuCallback& callback){
	cancelBtn->setNormalImage(normal);
	cancelBtn->setSelectedImage(press);
	cancelBtn->setCallback(callback);
}
// 设置弹窗内容
void PopWindow::setContent(Sprite *content){
	this->addChild(content);
}

