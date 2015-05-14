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
	// ��Ӳ˵���ť
	// ���˵�ѡ����ӵ��˵���
	auto menu = Menu::create();
	menu->setPosition(Point::ZERO);
	menu->setTag(MConstant::POP_WINDOW_MENU);
	this->addChild(menu, 1);
	// ���ȡ����ť
	cancelBtn = MenuItemImage::create();
	cancelBtn->setPosition(ccp(960, MConstant::WINDOW_HEIGHT - 271));
	  // Ϊȡ����ť��Ӷ���
	auto moveTo = MoveTo::create(1.0f, ccp(603, MConstant::WINDOW_HEIGHT - 271));
	auto easeBounceOut = EaseBackOut::create(moveTo);
	cancelBtn->runAction(easeBounceOut);
	 menu->addChild(cancelBtn);
	// ��ӱ���
	auto spriteBg = Sprite::create("popwindow_bg.png");
	spriteBg->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	this->addChild(spriteBg);
	// ���и���ĵ�������
	this->open();
	return true;
}

// ���õ����ı���
void PopWindow::setTitle(Sprite * titleImage){
	titleImage->setPosition(ccp(591, 640 - 150));
	this->addChild(titleImage, 1);
}
// ��Ӱ�ť
void PopWindow::addButton(MenuItemImage * btn){
	// 
	auto menu = this->getChildByTag(MConstant::POP_WINDOW_MENU);
	// ���ð�ťλ��
	btn->setPosition(ccp(960, 640 - 370));
	// ����ť��Ӷ���
	auto moveTo = MoveTo::create(0.8f, ccp(610, 640 - 370));
	auto easeBounceOut = EaseBackOut::create(moveTo);
	btn->runAction(easeBounceOut);
	menu->addChild(btn);
}
void PopWindow::remove(){
	this->close();
}
// Ϊ��������ȡ����ť
void PopWindow::setCancelBtn(Sprite *normal, Sprite *press){
	cancelBtn->setNormalImage(normal);
	cancelBtn->setSelectedImage(press);
	cancelBtn->setCallback([&](Ref *){
		// �жϵ�ǰ���� �Ƿ�Ϊ��Ϸ��ͣ������ 
		// ��Ϸ��ͣ������ ����ǰ�����ӳ�����ջ�е���
		if (Director::getInstance()->getRunningScene()->getTag() == MConstant::GAMESCENE){
			Director::getInstance()->popScene();
			this->close();
		}
		// ������Ϸ��ͣ������ ��������رգ� ���йرն���
		else this->close();
	});
}
void PopWindow::setCancelBtn(Sprite *normal, Sprite *press,  const ccMenuCallback& callback){
	cancelBtn->setNormalImage(normal);
	cancelBtn->setSelectedImage(press);
	cancelBtn->setCallback(callback);
}
// ���õ�������
void PopWindow::setContent(Sprite *content){
	this->addChild(content);
}

