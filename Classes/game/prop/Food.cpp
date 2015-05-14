#include "Food.h"

Food::Food(XiYangYang * xiYangYang, int food) : Prop(xiYangYang, "paopao.csb", "paopao_1"){
	setSize(120, 120);
	setPositionY(400);
	start(0, 50);
	addFood(food);
}
void Food::collisionListener(){
	/* 吃到食物加分 */
	GameData::getInstance()->addParticle(this->getPosition().x, this->getPosition().y, 0);
	GameData::getInstance()->setScore(this->foods);
	this->setPositionX(960 + 120);
	this->setEnable(false);
	GameData::getInstance()->playEffect(GameData::PROP_MUSIC);
}
// 添加食物精灵
void Food::addFood(int food){
	this->foods = food;
	string foodSprite = "map/food_bread.png";
	switch (food){
	case FOOD_BREAD:
		foodSprite = "map/food_bread.png";
		break;
	case FOOD_ICE:
		foodSprite = "map/food_ice.png";
		break;
	case FOOD_DRINK:
		foodSprite = "map/food_drink.png";
		break;
	}
	Texture2D* texture = TextureCache::sharedTextureCache()->addImage(foodSprite);

	((Sprite * )this->node->getChildByName("sprite"))->setTexture(texture);
	((Sprite *)this->node->getChildByName("sprite"))->setScale(2.0f);
	//this->node->addChild(foodSprite);
}
