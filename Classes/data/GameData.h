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
	static GameData * single ; // 单例
	int totalScore; // 总分数
	int totalMi; // 总距离
	int scoreData; // 分数增量
	bool musicEnable;
	Layer * layer; // 图层
	
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
	// 分数和饿跑的距离
	void setScore(int score);
	void setMi(int mi);
	// 获取总分数和距离
	string getScore();
	string getMi();
	int getLeve();
	// 关闭单利
	void close();
	// 传入layer
	void initLayer(Layer * layer);
	// 在图层中添加粒子
	void addParticle(float x, float y, int type);
	// 音乐音效
	void playMusic();
	void stopMusic();
	void playEffect(const char * id);
	void playEffect(const char * id, bool loop);
	void stopEffect(int id);
	void setMusicEnable(bool m);
};