#include "Coin.h"

Coin::Coin(XiYangYang * xiYangYang) : Prop(xiYangYang, "coin.csb", "coins"){
	setScale(1.5f);
	setSize(50, 50);
	setPositionY(400);
	start(0, 80);
	
}
void Coin::collisionListener(){

	GameData::getInstance()->addParticle(this->getPosition().x, this->getPosition().y, 1);
	this->setPositionX(960 + 75);
	this->setEnable(false);
	GameData::getInstance()->setScore(5);
	GameData::getInstance()->playEffect(GameData::COIN_MUSIC);
}
// 
