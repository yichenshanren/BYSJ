#pragma once 
#include "cocos2d.h"
#include "MConstant.h"
#include "SimpleAudioEngine.h"
#include "cocos-ext.h"
using namespace cocos2d::extension;
using namespace CocosDenshion;
USING_NS_CC;

class GameData {
private :
	static GameData * single ; // ����
	int totalScore; // �ܷ���
	int totalMi; // �ܾ���
	int scoreData; // ��������
	bool musicEnable;
	Layer * layer; // ͼ��
	
public :
	static const char * START_MUSIC;
	static const char * COIN_MUSIC;
	static const char * PROP_MUSIC;
	static const char * BTN_MUSIC;
	static const char * POP_MUSIC;
	static const char * DIED_MUSIC;
	static const char * LAUNCHER_MUSIC;
	static const char * JUMP_MUSIC;
	static const char * JUMPSEC_MUSIC;
	GameData();
	static GameData * getInstance();
	// �����Ͷ��ܵľ���
	void setScore(int score);
	void setMi(int mi);
	// ��ȡ�ܷ����;���
	string getScore();
	string getMi();
	int getLeve();
	// �رյ���
	void close();
	// ����layer
	void initLayer(Layer * layer);
	// ��ͼ�����������
	void addParticle(float x, float y, int type);
	// ������Ч
	void playMusic();
	void stopMusic();
	void playEffect(const char * id);
	void playEffect(const char * id, bool loop);
	void stopEffect(int id);
	void setMusicEnable(bool m);
};