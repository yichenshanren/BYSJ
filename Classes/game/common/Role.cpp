#include "Role.h"

Role::Role(const std::string& filename, const std::string& name){
	// 初始化变量
	init();
	type = 0;
	// 创建节点
	create(filename, name);
}
Role::Role(Sprite * sprite){
	// 初始化变量
	init();
	type = 1;
	// 创建节点
	create(sprite);
}
Role::~Role(){

}
// 初始化
void Role::init(){
	node = NULL;
	action = NULL;
	keyNode = NULL;
	bodyX = 0;
	bodyY = 0;
	scale = 1.0f;
}
// 精灵节点
void Role::create(Sprite * sprite){
	this->node = Node::create();
	this->node->addChild(sprite, 1);
}
// 从文件中创建节点
void Role::create(const std::string& filename, const std::string& name){
	// 从文件常见node
	this->node = CSLoader::createNode(filename);
	// 加载动画
	this->action = CSLoader::createTimeline(filename);
	this->node->setScale(scale);
	this->node->runAction(action);
	// 设置关键node
	this->keyNode = this->node->getChildByName(name);
	// 保存关键node的坐标
	this->bodyX = this->keyNode->getPositionX();
	this->bodyY = this->keyNode->getPositionY();

}
// 获取node
Node * Role::getNode(){
	return this->node;
}
// 设置坐标
void Role::setPositionY(float y){
	this->node->setPositionY(y);
}
void Role::setPositionX(float x){
	this->node->setPositionX(x);
}
void Role::setPosition(Vec2 point){
	this->node->setPosition(point);
}
// 设置缩放
void Role::setScale(float scale){
	this->scale = scale;
	this->node->setScale(this->scale);
}
// 获取节点坐标
Vec2 Role::getPosition(){
	
	Vec2 position;
	if (type == 0) {
		Vec2 point = this->keyNode->getPosition();
		// 根据node的子节点的坐标，换算成node坐标
		// 字节点的坐标 乘 缩放系数 加 node的坐标 - 子节点的原始坐标 乘 缩放系数 
		position.x = this->node->getPositionX() + point.x * scale - bodyX * scale;
		position.y = this->node->getPositionY() + point.y * scale - bodyY * scale;
	}
	else {
		position.x = this->node->getPositionX();
		position.y = this->node->getPositionY();
	}
	
	return position;
}
// 获取和设置node的size
Vec2 Role::getSize(){
	return this->size;
}
void Role::setSize(float width, float hight){
	this->size.x = width * this->scale;
	this->size.y = hight * this->scale;
}
