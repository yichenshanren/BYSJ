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
	// ���ؼ�
	//���ֻ����ؼ��ļ��� 
	auto listener = EventListenerKeyboard::create();
	//�ͻص������� 
	listener->onKeyReleased = CC_CALLBACK_2(MLayer::onBackKeyDown, this);
	//��ӵ��¼��ַ����� 
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);

	return true;
}
void MLayer::onBackKeyDown(EventKeyboard::KeyCode keyCode, Event * pEvent){

}
// ���õ���
void MLayer::setPopWindow(BaseScene * pop){
	this->popWindow = pop;
}
// ��ȡ����
BaseScene * MLayer::getPopWindow(){
	return this->popWindow;
}