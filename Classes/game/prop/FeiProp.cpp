#include "FeiProp.h"

FeiProp::FeiProp(XiYangYang * xiYangYang) : Prop(xiYangYang, "paopao.csb", "paopao_1"){
	setScale(1.1f);
	setSize(180, 180);
	setPositionY(400);
	start(0, 50);
	addFei();
}
// Ìí¼ÓÀÁÑóÑó
void FeiProp::addFei(){
	Texture2D* texture = TextureCache::sharedTextureCache()->addImage("map/function_feiyangyang.png");
	((Sprite *)this->node->getChildByName("sprite"))->setTexture(texture);
}
void FeiProp::collisionListener(){
	GameData::getInstance()->addParticle(this->getPosition().x, this->getPosition().y, 0);
	this->setPositionX(960 + 180);
	this->setEnable(false);
	GameData::getInstance()->playEffect(GameData::PROP_MUSIC);
}
// 