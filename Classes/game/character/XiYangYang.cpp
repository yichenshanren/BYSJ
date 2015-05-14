#include "XiYangYang.h"

XiYangYang::XiYangYang() : Role ("xiyangyang.csb", "xiyangyang_body_0"){
	/*bodyX = 17.57f;
	bodyY = 30.46f;*/
	isRunning = false;
	isJump = false;
	isJumpSec = false;
	isAlive = true; // ����
	setAlive(true);
	setSpeed(8.0f); // ����Ĭ�ϵĵ�ͼ�ٶ�
	setScale(0.5f);
	setSize(230, 350);
	setDefualtPositon();
	run();
}
XiYangYang::~XiYangYang(){

}
//// ���ļ�����ui
//void XiYangYang::create(){
//	// ����ui
//	this->node = CSLoader::createNode("xiyangyang.csb");
//	// ���ض���
//	this->action = CSLoader::createTimeline("xiyangyang.csb");
//	this->node->setPosition(300, 150);
//	this->node->setScale(scale);
//	this->node->runAction(action);
//	run();
//}
// �����ܵĶ���
void XiYangYang::run(){
	
	this->action->setTimeSpeed(1.2f);
	this->action->gotoFrameAndPlay(0, 30, true);	isRunning = true;
	isJump = false;
	isJumpSec = false;
}
// �������Ķ���
void XiYangYang::jump(){
	
	if (!isJump){
		this->action->setTimeSpeed(1.0f); // ���ö��������ٶ�
		this->action->gotoFrameAndPlay(36, 115, false); // ��������
		isRunning = false;
		isJump = true;
	//	log("jump11");
		GameData::getInstance()->playEffect(GameData::JUMP_MUSIC);
	}
	else {
		jumpSec();
	}
}
void XiYangYang::jumpSec(){
	if (!isJumpSec){
        //log("jump22");
		this->node->setPosition(getPosition());
		this->action->setTimeSpeed(1.0f); // ���ö��������ٶ�
		this->action->gotoFrameAndPlay(115, 200, false); // ��������
		isJumpSec = true;
		GameData::getInstance()->playEffect(GameData::JUMPSEC_MUSIC);
	}
}
void XiYangYang::drop(){
	this->node->setPosition(getPosition());
	this->action->setTimeSpeed(1.0f); // ���ö��������ٶ�
	this->action->gotoFrameAndPlay(90, 115, false); // ��������
}
// ��ȡ ui�ڵ�
//Node * XiYangYang::getNode(){
//	return this->node;
//}
// �Ƿ�������״̬
bool XiYangYang::isJumping(){
	return this->isJump;
}
void XiYangYang::setNoJump(){
	if (isJumpSec){
		isJumpSec = false;
	}
}
// ���node����
//Vec2 XiYangYang::getPosition(){
//	// ��ȡ �ӽڵ㡰xiyangyang_body_0��������
//	Vec2 position0 = this->node->getChildByName("xiyangyang_body_0")->getPosition();
//	Vec2 position;
//	// ����node���ӽڵ�����꣬�����node����
//	// �ֽڵ������ �� ����ϵ�� �� node������ �� �ӽڵ��ԭʼ���� �� ����ϵ�� 
//	position.x = position0.x * scale + this->node->getPositionX() + bodyX * scale;
//	position.y = position0.y * scale + this->node->getPositionY() - bodyX * scale;
//	return position;
//}
// ����node������
//void XiYangYang::setPosition(Vec2 point){
//	this->node->setPosition(point);
//}
void XiYangYang::setDefualtPositon(){
	node->setPosition(300, 130);
}
// ����node��Y����
//void XiYangYang::setPositionY(float y){
//	this->node->setPositionY(y);
//}
// ���û�ȡspeed
void XiYangYang::setSpeed(float sp){
	this->speed = sp;
}
float XiYangYang::getSpeed(){
	return speed;
}
// �ж��Ƿ񻹻���
bool XiYangYang::getAlive(){
	return this->isAlive;
}
void XiYangYang::setAlive(bool alive){
	this->isAlive = alive;
}
// �ƶ�
void XiYangYang::move(bool back){
	if (back){
		this->node->setPositionX(this->node->getPositionX() - speed);
	}
	else {
		this->node->setPositionX(this->node->getPositionX() + speed);
	}
}
