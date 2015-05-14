#include "ShiTou.h"

ShiTou::ShiTou(XiYangYang * xiYangYang) : Prop(xiYangYang, Sprite::create("map/shitou.png")){
	setSize(140, 103);
	setPositionY(70);

}
// ÖØĞ´Åö×²ÕìÌıº¯Êı
void ShiTou::collisionListener(){
	if (!isCollision){
		if (!xiYangYang->isJumping()){
			xiYangYang->move(true);
		}
		else {
			isCollision = true;
			xiYangYang->setNoJump();
			xiYangYang->jump();
		}
	}
}
// 