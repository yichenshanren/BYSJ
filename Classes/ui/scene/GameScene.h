#ifndef GAME_SCENE // �ж���������Ƿ����
#define GAME_SCENE // ����������˳���


#include "PopWindow.h"
#include "ui/common/MLayer.h"
#include "StartScene.h"
#include "GamepauseScene.h"
#include "data/MConstant.h"
#include "ui/CocosGUI.h"//UI��ص�ͷ�ļ� 
#include "cocostudio/CocoStudio.h" 
#include "game/map/map.h"
#include "data/GameData.h"
#include "GameOverScene.h"

using namespace cocos2d;//CSLoaderλ��cocos2d�����ռ䡣 
using namespace cocostudio::timeline;//������ص���λ��cocostuio::timeline���� 
USING_NS_CC;
class GameScene : public MLayer{
private :
	SMap * map; // ��ͼ
	LabelTTF * scoreText;
	LabelTTF * miText;
	GameScene(){};
public :
	virtual bool init(); //ʵ�ֳ����ĳ�ʼ��
	CREATE_FUNC(GameScene); // ʵ�ִ�������
	static Scene * createScene(); // ��������

	void moveBackground(float tiem); //
    // �˵���ť�Ļص�����
	void menuBtnCallBack(Ref * pSender);
	// ��Ϸ��ͣ
	void gamePause();
	// ��Ϸ����
	void gameOver();
	// ���ؼ�
	void onBackKeyDown(EventKeyboard::KeyCode keyCode, Event * pEvent);
	void jumpToRun();
	void update(float t);
	// ��ȡ��Ļ��ͼ
	RenderTexture * getTexture();
	// �����¼�
	 bool onTouchBegan(Touch *touch, Event *unused_event);
	 void onTouchMoved(Touch *touch, Event *unused_event);
	 void onTouchEnded(Touch *touch, Event *unused_event);
};

#endif