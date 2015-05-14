#include "LanProp.h"

LanProp::LanProp(XiYangYang * xiYangYang) : Prop(xiYangYang, "paopao.csb", "paopao_1"){
	setScale(1.1f);
	setSize(180, 180);
	setPositionY(400);
	start(0, 50);
	addLan();
}
// 添加懒洋洋
void LanProp::addLan(){
	Texture2D* texture = TextureCache::sharedTextureCache()->addImage("map/function_lanyangyang.png");
	((Sprite *)this->node->getChildByName("sprite"))->setTexture(texture);
}
void LanProp::collisionListener(){
	setMoveDown(true);
	GameData::getInstance()->playEffect(GameData::PROP_MUSIC);
}
// 向下移动
void LanProp::moveDown(){
	this->node->setPosition(xiYangYang->getPosition().x, xiYangYang->getPosition().y + 100);

}
