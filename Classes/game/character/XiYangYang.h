#pragma once
#include "game/common/Role.h"

class XiYangYang : public Role {
private :
	
	//float bodyX; // ����node�ӽڵ㣩��ԭʼX����
	//float bodyY; // ����node�ӽڵ㣩��ԭʼY����

	//Node * node; // ϲ���򶯻��ڵ�
	//float scale; // node������ϵ��
	//ActionTimeline * action; // ϲ���򶯻�
	bool isRunning; // �Ƿ���
	bool isJump; // �Ƿ���
	bool isJumpSec; // ������
	bool isAlive; // �Ƿ����
	float speed; // ��ͼ�ƶ��ٶ�

public :
	// ������
	XiYangYang();
	~XiYangYang();
	// ���ض���
	bool getAlive();
	void setAlive(bool alive);
	// ����������
	void jump();
	void jumpSec();
	// �����ܵĶ���
	void run();
	// ��ȡ�ڵ�
//	Node * getNode();
	// 
	bool isJumping();
	// ����
	/*void setPositionY(float y);
	Vec2 getPosition();
	void setPosition(Vec2 potin);*/
	void setDefualtPositon();
	// ���û�ȡspeed
	void setSpeed(float sp);
	float getSpeed();
	// �ƶ�
	void move(bool back);
	void setNoJump();
	void drop();
};