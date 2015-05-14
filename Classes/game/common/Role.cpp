#include "Role.h"

Role::Role(const std::string& filename, const std::string& name){
	// ��ʼ������
	init();
	type = 0;
	// �����ڵ�
	create(filename, name);
}
Role::Role(Sprite * sprite){
	// ��ʼ������
	init();
	type = 1;
	// �����ڵ�
	create(sprite);
}
Role::~Role(){

}
// ��ʼ��
void Role::init(){
	node = NULL;
	action = NULL;
	keyNode = NULL;
	bodyX = 0;
	bodyY = 0;
	scale = 1.0f;
}
// ����ڵ�
void Role::create(Sprite * sprite){
	this->node = Node::create();
	this->node->addChild(sprite, 1);
}
// ���ļ��д����ڵ�
void Role::create(const std::string& filename, const std::string& name){
	// ���ļ�����node
	this->node = CSLoader::createNode(filename);
	// ���ض���
	this->action = CSLoader::createTimeline(filename);
	this->node->setScale(scale);
	this->node->runAction(action);
	// ���ùؼ�node
	this->keyNode = this->node->getChildByName(name);
	// ����ؼ�node������
	this->bodyX = this->keyNode->getPositionX();
	this->bodyY = this->keyNode->getPositionY();

}
// ��ȡnode
Node * Role::getNode(){
	return this->node;
}
// ��������
void Role::setPositionY(float y){
	this->node->setPositionY(y);
}
void Role::setPositionX(float x){
	this->node->setPositionX(x);
}
void Role::setPosition(Vec2 point){
	this->node->setPosition(point);
}
// ��������
void Role::setScale(float scale){
	this->scale = scale;
	this->node->setScale(this->scale);
}
// ��ȡ�ڵ�����
Vec2 Role::getPosition(){
	
	Vec2 position;
	if (type == 0) {
		Vec2 point = this->keyNode->getPosition();
		// ����node���ӽڵ�����꣬�����node����
		// �ֽڵ������ �� ����ϵ�� �� node������ - �ӽڵ��ԭʼ���� �� ����ϵ�� 
		position.x = this->node->getPositionX() + point.x * scale - bodyX * scale;
		position.y = this->node->getPositionY() + point.y * scale - bodyY * scale;
	}
	else {
		position.x = this->node->getPositionX();
		position.y = this->node->getPositionY();
	}
	
	return position;
}
// ��ȡ������node��size
Vec2 Role::getSize(){
	return this->size;
}
void Role::setSize(float width, float hight){
	this->size.x = width * this->scale;
	this->size.y = hight * this->scale;
}
