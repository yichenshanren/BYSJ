#include "XiYangYang.h"

XiYangYang::XiYangYang() : Role ("xiyangyang.csb", "xiyangyang_body_0"){
	/*bodyX = 17.57f;
	bodyY = 30.46f;*/
	isRunning = false;
	isJump = false;
	isJumpSec = false;
	isAlive = true; // 设置
	setAlive(true);
	setSpeed(8.0f); // 设置默认的地图速度
	setScale(0.5f);
	setSize(230, 350);
	setDefualtPositon();
	run();
}
XiYangYang::~XiYangYang(){

}
//// 从文件加载ui
//void XiYangYang::create(){
//	// 加载ui
//	this->node = CSLoader::createNode("xiyangyang.csb");
//	// 加载动画
//	this->action = CSLoader::createTimeline("xiyangyang.csb");
//	this->node->setPosition(300, 150);
//	this->node->setScale(scale);
//	this->node->runAction(action);
//	run();
//}
// 运行跑的动画
void XiYangYang::run(){
	
	this->action->setTimeSpeed(1.2f);
	this->action->gotoFrameAndPlay(0, 30, true);	isRunning = true;
	isJump = false;
	isJumpSec = false;
}
// 运行跳的动画
void XiYangYang::jump(){
	
	if (!isJump){
		this->action->setTimeSpeed(1.0f); // 设置动画播放速度
		this->action->gotoFrameAndPlay(36, 115, false); // 动画区间
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
		this->action->setTimeSpeed(1.0f); // 设置动画播放速度
		this->action->gotoFrameAndPlay(115, 200, false); // 动画区间
		isJumpSec = true;
		GameData::getInstance()->playEffect(GameData::JUMPSEC_MUSIC);
	}
}
void XiYangYang::drop(){
	this->node->setPosition(getPosition());
	this->action->setTimeSpeed(1.0f); // 设置动画播放速度
	this->action->gotoFrameAndPlay(90, 115, false); // 动画区间
}
// 获取 ui节点
//Node * XiYangYang::getNode(){
//	return this->node;
//}
// 是否处于跳的状态
bool XiYangYang::isJumping(){
	return this->isJump;
}
void XiYangYang::setNoJump(){
	if (isJumpSec){
		isJumpSec = false;
	}
}
// 获得node坐标
//Vec2 XiYangYang::getPosition(){
//	// 获取 子节点“xiyangyang_body_0”的坐标
//	Vec2 position0 = this->node->getChildByName("xiyangyang_body_0")->getPosition();
//	Vec2 position;
//	// 根据node的子节点的坐标，换算成node坐标
//	// 字节点的坐标 乘 缩放系数 加 node的坐标 加 子节点的原始坐标 乘 缩放系数 
//	position.x = position0.x * scale + this->node->getPositionX() + bodyX * scale;
//	position.y = position0.y * scale + this->node->getPositionY() - bodyX * scale;
//	return position;
//}
// 设置node的坐标
//void XiYangYang::setPosition(Vec2 point){
//	this->node->setPosition(point);
//}
void XiYangYang::setDefualtPositon(){
	node->setPosition(300, 130);
}
// 设置node的Y坐标
//void XiYangYang::setPositionY(float y){
//	this->node->setPositionY(y);
//}
// 设置获取speed
void XiYangYang::setSpeed(float sp){
	this->speed = sp;
}
float XiYangYang::getSpeed(){
	return speed;
}
// 判断是否还活着
bool XiYangYang::getAlive(){
	return this->isAlive;
}
void XiYangYang::setAlive(bool alive){
	this->isAlive = alive;
}
// 移动
void XiYangYang::move(bool back){
	if (back){
		this->node->setPositionX(this->node->getPositionX() - speed);
	}
	else {
		this->node->setPositionX(this->node->getPositionX() + speed);
	}
}
