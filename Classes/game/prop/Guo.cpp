#include "Guo.h"

Guo::Guo(XiYangYang * xiYangYang) : Prop(xiYangYang, "pingdiguo.csb", "pingdiguo_1"){
	
	setSize(70, 50);
	setPositionY(400);
	start(0, 15);
	setASpeed(1.5f);

}
void Guo::collisionListener(){
	xiYangYang->setAlive(false);
}
// 