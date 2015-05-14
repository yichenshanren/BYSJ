#include "HelloWorldScene.h"
#include "GameScene.h"
#include "AboutScene.h"
#include "StartScene.h"
#include "ui/CocosGUI.h"//UI��ص�ͷ�ļ� 
#include "data/GameData.h"
#include "cocostudio/CocoStudio.h" 
using namespace cocos2d;//CSLoaderλ��cocos2d�����ռ䡣 
using namespace cocostudio::timeline;//������ص���λ��cocostuio::timeline���� 

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
	// ����ui
	auto node = CSLoader::createNode("lanucher.csb");
	auto size = Director::getInstance()->getVisibleSize();

	auto action = CSLoader::createTimeline("lanucher.csb");
	node->runAction(action);
	action->gotoFrameAndPlay(0, 165, false);

	this->addChild(node, 1);
	
	//�ƻ�����
	this->scheduleOnce(schedule_selector(HelloWorld::moveToGame), 5.0f); //��2.0f֮��ִ�У�����ִֻ��һ�Ρ�
	this->scheduleOnce(schedule_selector(HelloWorld::playEffect), 0.5f); //��1.0f֮��ִ�У�����ִֻ��һ�Ρ�
    return true;
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
	MenuItem * nowItem = (MenuItem *)pSender;
	switch (nowItem->getTag()){
	case 10: // ��Ϸ��ʼ��ť
		Director::getInstance()->replaceScene(GameScene::createScene());
		break;
	case 11: // ��Ϸ���ڰ�ť
		Director::getInstance()->replaceScene(AboutScene::createScene());
		break; 
	case 12: // ��Ϸ�˳���ť
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
* 3����Զ���ת�� ��Ϸ��ʼ����
* ��Ϸ���ݼ�����ɺ� ��ת����Ϸ��ʼ����
*/
void HelloWorld::moveToGame(float dt){
	// ����ǰ�ĳ����滻Ϊ��Ϸ��ʼ����
	
	Director::getInstance()->pushScene(StartScene::createScene());
	
}
// 1��󲥷���Ч
void HelloWorld::playEffect(float t){
	// ������Ч
	GameData::getInstance()->playEffect(GameData::LAUNCHER_MUSIC);
}

