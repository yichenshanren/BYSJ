#include "Lang.h"

Lang::Lang(XiYangYang * xiYangYang) : Prop(xiYangYang, Sprite::create("map/huitailang.png")){
	setSize(128, 120);
	this->node->setPositionY(50);
}
void Lang::collisionListener(){
	if (!isCollision){
		if (!xiYangYang->isJumping()){ // 
			// ����ײ����
			// ����ϲ����alive = false��
			xiYangYang->setAlive(false);
		}
		else {
			xiYangYang->setNoJump();
			xiYangYang->jump();
			setEnable(false);
			setPositionX(960 + size.x);
			// �ȵ���̫�� ��20��
			GameData::getInstance()->setScore(20);
			GameData::getInstance()->playEffect(GameData::PROP_MUSIC);
		}
	}
}
