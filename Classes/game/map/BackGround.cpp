#include "BackGround.h"

BackGround::BackGround(){
	srand((int)time(NULL));
	/* ����Ĭ�ϵĹ����ٶ� */
	moveSpeed = 7.0f;
	// �����������뱳����������
	backGrounds.push_back(Sprite::create("map/shu_0.png"));
	backGrounds.push_back(Sprite::create("map/shu_1.png"));
	backGrounds.push_back(Sprite::create("map/shu_2.png"));
	backGrounds.push_back(Sprite::create("map/shu_3.png"));
	backGrounds.push_back(Sprite::create("map/shu_4.png"));
	backGrounds.push_back(Sprite::create("map/shu_5.png"));
	/* ���ñ�������Ĭ������ */
	for (int i = 0; i < 6; i ++) {
		backGrounds.at(i)->setPositionY(-80 + backGrounds.at(i)->getContentSize().height / 2.0f);
		backGrounds.at(i)->setPositionX(100 + i * 400);
	}
}
BackGround::~BackGround(){

}
/*
  ��ӱ�����������
*/
void BackGround::addTo(Layer *layer){
//	layer->addChild(bg0);
	for (auto bg : backGrounds){
		layer->addChild(bg);
	}
	
}
/*
  ��������

*/
void BackGround::move(){
	for (auto bg : backGrounds){
		if (bg->getPositionX() <= -bg->getContentSize().width / 2.0f){
			bg->setPositionX(960 + 400 * random(1, 10));
		}
		bg->setPositionX(bg->getPositionX() - moveSpeed);
	}
}
/*
  ���ù����ٶ�
*/
void BackGround::setMoveSpeed(){

}