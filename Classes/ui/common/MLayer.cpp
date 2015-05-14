#include "MLayer.h"
#include "BaseScene.h"
USING_NS_CC;

MLayer::MLayer(){
	setPopWindow(NULL);
}
MLayer::~MLayer(){

}
bool MLayer::init(){
	if (!Layer::init()){
		return false;
	}
	// 返回键
	//对手机返回键的监听 
	auto listener = EventListenerKeyboard::create();
	//和回调函数绑定 
	listener->onKeyReleased = CC_CALLBACK_2(MLayer::onBackKeyDown, this);
	//添加到事件分发器中 
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);

	return true;
}
void MLayer::onBackKeyDown(EventKeyboard::KeyCode keyCode, Event * pEvent){

}
// 设置弹窗
void MLayer::setPopWindow(BaseScene * pop){
	this->popWindow = pop;
}
// 获取弹窗
BaseScene * MLayer::getPopWindow(){
	return this->popWindow;
}