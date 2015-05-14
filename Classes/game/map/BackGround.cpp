#include "BackGround.h"

BackGround::BackGround(){
	srand((int)time(NULL));
	/* 设置默认的滚动速度 */
	moveSpeed = 7.0f;
	// 将背景树加入背景树集合中
	backGrounds.push_back(Sprite::create("map/shu_0.png"));
	backGrounds.push_back(Sprite::create("map/shu_1.png"));
	backGrounds.push_back(Sprite::create("map/shu_2.png"));
	backGrounds.push_back(Sprite::create("map/shu_3.png"));
	backGrounds.push_back(Sprite::create("map/shu_4.png"));
	backGrounds.push_back(Sprite::create("map/shu_5.png"));
	/* 设置背景树的默认坐标 */
	for (int i = 0; i < 6; i ++) {
		backGrounds.at(i)->setPositionY(-80 + backGrounds.at(i)->getContentSize().height / 2.0f);
		backGrounds.at(i)->setPositionX(100 + i * 400);
	}
}
BackGround::~BackGround(){

}
/*
  添加背景到场景中
*/
void BackGround::addTo(Layer *layer){
//	layer->addChild(bg0);
	for (auto bg : backGrounds){
		layer->addChild(bg);
	}
	
}
/*
  滚动背景

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
  设置滚动速度
*/
void BackGround::setMoveSpeed(){

}