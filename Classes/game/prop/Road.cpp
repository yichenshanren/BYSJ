#include "Road.h"

Road::Road(XiYangYang * xiYangYang) : Prop(xiYangYang, Sprite::create("map/map_road.png")){
	setSize(80, 300);
	this->node->setPositionY(50);
}
void Road::collisionListener(){
	
		if (xiYangYang->isJumping()){
			if ((int)xiYangYang->getPosition().y <= this->getPosition().y + 80){
				xiYangYang->setPositionY(this->getPosition().y + 80);
				xiYangYang->run();

			}
		}
		else {
			if ((int)xiYangYang->getPosition().y > this->getPosition().y + 85){
				isCollision = true;
				xiYangYang->drop();
			}
		}
}
void Road::setNormalY(){
	/* 跟据游戏进度，调整难度 */
	int max = 20 - GameData::getInstance()->getLeve();
	if (random(1, 10) == 5){
			setPositionY(-100);
			return;
	}
	setPositionY(50);
}
void Road::setButtomY(){

}
void Road::setDefaultY(){

}
