#include "GameData.h"

GameData * GameData::single = NULL;
 const char * GameData::START_MUSIC = "music/start.mp3";
 const char * GameData::COIN_MUSIC = "music/jinbi.wav";
 const char * GameData::PROP_MUSIC = "music/Prop.wav";
 const char * GameData::BTN_MUSIC = "music/open.mp3";
 const char * GameData::POP_MUSIC = "music/guanbi.mp3" ;
 const char * GameData::DIED_MUSIC = "music/fail.mp3" ;
 const char * GameData::LAUNCHER_MUSIC = "music/launcher.mp3";
 const char * GameData::JUMP_MUSIC = "music/jump.wav";
 const char * GameData::JUMPSEC_MUSIC = "music/dianji.mp3";

GameData::GameData(){
	this->totalMi = 0;
	this->totalScore = 0;
	this->scoreData = 0;
	SimpleAudioEngine::sharedEngine()->preloadBackgroundMusic("music/game.mp3");
	SimpleAudioEngine::getInstance()->setBackgroundMusicVolume(10);
	//预加载音效
	SimpleAudioEngine::getInstance()->preloadEffect(START_MUSIC);
	SimpleAudioEngine::getInstance()->preloadEffect(COIN_MUSIC);
	SimpleAudioEngine::getInstance()->preloadEffect(PROP_MUSIC);
	SimpleAudioEngine::getInstance()->preloadEffect(BTN_MUSIC);
	SimpleAudioEngine::getInstance()->preloadEffect(POP_MUSIC);
	SimpleAudioEngine::getInstance()->preloadEffect(DIED_MUSIC);
	SimpleAudioEngine::getInstance()->preloadEffect(LAUNCHER_MUSIC);
	SimpleAudioEngine::getInstance()->preloadEffect(JUMP_MUSIC);
	SimpleAudioEngine::getInstance()->preloadEffect(JUMPSEC_MUSIC);
	SimpleAudioEngine::getInstance()->setEffectsVolume(1);
}
GameData * GameData::getInstance(){
	if (single == NULL){
		single = new GameData();
	}
	return single;
}

// 设置文本的文字
void GameData::setScore(int scor){
	this->totalScore += scor;
}
void GameData::setMi(int m){
	this->totalMi += m;
}
// 获取总分数和距离
string GameData::getScore(){
	/*if (scoreData != 0){
		totalScore++;
		scoreData--;
	}*/
	return MConstant::toString(this->totalScore);
}
string GameData::getMi(){
	//return this->totalMi;
	return MConstant::toString(this->totalMi);
}
int GameData::getLeve(){
	if (totalMi <= 500){
		return 0;
	} else if (totalMi <= 1000 && totalMi > 500){
		return 3;
	} else if (totalMi > 1000 && totalMi <= 1500){
		return 6;
	}else if(totalMi > 1500 && totalMi <= 2000 ) {
		return 9;
	}
	else {
		return 15;
	}
	return 0;
}
// 添加图层
void GameData::initLayer(Layer * layer){
	this->layer = layer;
}
// 在图层中添加粒子
void GameData::addParticle(float x, float y, int type){
	// 添加粒子
	ParticleSystemQuad *emitter = NULL;
	if (type == 0){
		emitter = ParticleSystemQuad::create("Default/12563.plist");
		emitter->setScale(0.4f);
	}
	else{
		emitter = ParticleSystemQuad::create("Default/defaultParticle.plist");
	}
	emitter->setBlendAdditive(false);//是否添加混合
	emitter->setPosition(Vec2(x, y));//设置发射粒子的位置
	//emitter->setScale(size);
	emitter->setDuration(0.1);
	emitter->setAutoRemoveOnFinish(true);//完成后移除

	//将粒子系统添加到节点(也可以直接将其添加到一个背景精灵CCSprite里面)

	//parent1->addChild(emitter, 0, 1);
	//然后在添加到层里面
	this->layer->addChild(emitter, 10);
}
// 关闭单利
void GameData::close(){
	if (single != NULL){
		single = NULL;
	}
}
// 音乐音效
void GameData::playMusic(){
	if (!SimpleAudioEngine::getInstance()->isBackgroundMusicPlaying()){
		SimpleAudioEngine::getInstance()->playBackgroundMusic("music/game.mp3", true);
	}
}
void GameData::stopMusic(){
	if (SimpleAudioEngine::getInstance()->isBackgroundMusicPlaying()){
		SimpleAudioEngine::getInstance()->stopBackgroundMusic();
	}
}
void GameData::playEffect(const char * id){
	this->playEffect(id, false);
}
void GameData::playEffect(const char * id, bool loop){
	SimpleAudioEngine::getInstance()->playEffect(id, loop);
}
void GameData::stopEffect(int id){
	SimpleAudioEngine::getInstance()->stopAllEffects();
}
void GameData::setMusicEnable(bool m){
	this->musicEnable = m;
}
