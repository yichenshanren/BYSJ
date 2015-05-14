#pragma once
#include "cocos2d.h"
#include "ui/CocosGUI.h"//UI��ص�ͷ�ļ� 
#include "cocostudio/CocoStudio.h" 
#include "data/GameData.h"
USING_NS_CC;
using namespace cocos2d;//CSLoaderλ��cocos2d�����ռ䡣 
using namespace cocostudio::timeline;//������ص���λ��cocostuio::timeline���� 

class Role {
protected :
	Node * node; // ���ļ����صĽڵ�
	ActionTimeline * action; // �ڵ��еĶ���
	Node * keyNode; // node�еĹؼ��ӽڵ�
	float bodyX; // node��ĳһ�ӽڵ�ĳ�ʼ����
	float bodyY; // node��ĳһ�ӽڵ�ĳ�ʼ����
	float scale; // node������ϵ��
	Vec2 size; // node��size
	int type; // ��������
public :
	Role(){};
	Role(Sprite * sprite);
	Role(const std::string& filename, const std::string& name);
	~Role();
	// ��ʼ��
	void init();
	// ���ļ��м���node
	void create(const std::string& filename, const std::string& name);
	void create(Sprite * sprite);
	// ��ȡnode
	Node * getNode();
	// ��������
	void setPositionY(float y);
	void setPositionX(float x);
	void setPosition(Vec2 potin);
	// ��ȡ�ڵ�����
	Vec2 getPosition();
	// ��ȡnode��size
	Vec2 getSize();
	void setSize(float width, float hight);
	// ��������
	void setScale(float scale);

};