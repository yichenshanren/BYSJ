#ifndef ABOUT_SCENE
#define ABOUT_SCENE

#include "cocos2d.h"
using namespace cocos2d;

class AboutScene : public cocos2d::Layer{

public :
	virtual bool init();
	static Scene * createScene();
	CREATE_FUNC(AboutScene);

};

#endif