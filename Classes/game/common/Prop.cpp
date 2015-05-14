#include "Prop.h"
Prop::Prop(XiYangYang * xiYangYang, const std::string& filename, const std::string& name) 
: Role(filename, name){
	this->xiYangYang = xiYangYang;
	init();
}
Prop::Prop(XiYangYang * xiYangYang, Sprite * sprite)
: Role(sprite){
	this->xiYangYang = xiYangYang;
	init();
}
Prop::~Prop(){
	stop();
	delete this;
}
// 
void Prop::init(){
	
	setASpeed(1.0f);
	isCollision = false;
	setEnable(false);
	setPositionX(1100);
	setMoveDown(false);
	setFuncPropTime(300);
}
// run action
void Prop::start(int startFrame, int stopFrame){
	this->action->gotoFrameAndPlay(startFrame, stopFrame, true);
}
// stop action
void Prop::stop(){
	this->action->stop();
}
void Prop::setASpeed(float a){
	this->aSpeed = a;
	setMoveSpeed();
}
// 碰撞检测
void Prop::collision(){
	
	Rect xiyangyang(xiYangYang->getPosition().x, xiYangYang->getPosition().y, xiYangYang->getSize().x * 0.8f, xiYangYang->getSize().y * 0.8f);
	Rect propRect(this->getPosition().x, this->getPosition().y, this->getSize().x * 0.8f, this->getSize().y * 0.8f);
	if (xiyangyang.intersectsRect(propRect)){
		collisionListener();
	}
}
// 设置播放速度
void Prop::setSpeed(){
	this->action->setTimeSpeed(xiYangYang->getSpeed());
}
// 向左移动
void Prop::move(){
	if (enable){
		if (this->node->getPositionX() < - this->size.x * 0.5f){
			this->node->setPositionX(960 + size.x );
			setEnable(false);
			isCollision = false;
		}
		else if (down){
			if (funcPropTime > 0){
				moveDown();
				funcPropTime -= moveSpeed;
			}
			else {
				this->node->setPositionX(960 + size.x);
				setEnable(false);
				isCollision = false;
				funcPropTime = 300;
			}
		}
		this->collision();
        this->node->setPositionX(this->node->getPositionX() - this->moveSpeed);
	}
	
}
// 向下移动
void Prop::moveDown(){

}
// 设置移动速度
void Prop::setMoveSpeed(){
	this->moveSpeed = xiYangYang->getSpeed() * aSpeed;
}
float Prop::getXi(){
	return xiYangYang->getPosition().y;
}
void Prop::setEnable(bool b)
{
	this->enable = b;
}
bool Prop::getEnable(){
	return this->enable;
}
// 
void Prop::setMoveDown(bool l){
	this->down = l;
}
// 设置功能道具时间
void Prop::setFuncPropTime(int time){
	this->funcPropTime = time;
}
