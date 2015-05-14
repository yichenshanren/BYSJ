#include "HelloWorldScene.h"
#include "GameScene.h"
#include "AboutScene.h"
#include "StartScene.h"
#include "ui/CocosGUI.h"//UI相关的头文件 
#include "data/GameData.h"
#include "cocostudio/CocoStudio.h" 
using namespace cocos2d;//CSLoader位于cocos2d命名空间。 
using namespace cocostudio::timeline;//动画相关的类位于cocostuio::timeline当中 

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
	GameData::getInstance();
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
	// 加载ui
	auto node = CSLoader::createNode("lanucher.csb");
	auto size = Director::getInstance()->getVisibleSize();

	auto action = CSLoader::createTimeline("lanucher.csb");
	node->runAction(action);
	action->gotoFrameAndPlay(0, 165, false);

	this->addChild(node, 1);
	
	//计划任务
	this->scheduleOnce(schedule_selector(HelloWorld::moveToGame), 5.0f); //在2.0f之后执行，并且只执行一次。
	this->scheduleOnce(schedule_selector(HelloWorld::playEffect), 0.5f); //在1.0f之后执行，并且只执行一次。
    return true;
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
	MenuItem * nowItem = (MenuItem *)pSender;
	switch (nowItem->getTag()){
	case 10: // 游戏开始按钮
		Director::getInstance()->replaceScene(GameScene::createScene());
		break;
	case 11: // 游戏关于按钮
		Director::getInstance()->replaceScene(AboutScene::createScene());
		break; 
	case 12: // 游戏退出按钮
        #if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
		exit(0);
		return;
        #endif
		Director::getInstance()->end();
        #if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
		exit(0);
        #endif
		break;
	default:
		break;
	}

}
/**
* 3秒后自动跳转到 游戏开始界面
* 游戏内容加载完成后 跳转到游戏开始界面
*/
void HelloWorld::moveToGame(float dt){
	// 将当前的场景替换为游戏开始场景
	
	Director::getInstance()->pushScene(StartScene::createScene());
	
}
// 1秒后播放音效
void HelloWorld::playEffect(float t){
	// 播放音效
	GameData::getInstance()->playEffect(GameData::LAUNCHER_MUSIC);
}

