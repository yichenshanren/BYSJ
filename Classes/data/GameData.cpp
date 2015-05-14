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
	//Ԥ������Ч
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

// �����ı�������
void GameData::setScore(int scor){
	this->totalScore += scor;
}
void GameData::setMi(int m){
	this->totalMi += m;
}
// ��ȡ�ܷ����;���
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
// ���ͼ��
void GameData::initLayer(Layer * layer){
	this->layer = layer;
}
// ��ͼ�����������
void GameData::addParticle(float x, float y, int type){
	// �������
	ParticleSystemQuad *emitter = NULL;
	if (type == 0){
		emitter = ParticleSystemQuad::create("Default/12563.plist");
		emitter->setScale(0.4f);
	}
	else{
		emitter = ParticleSystemQuad::create("Default/defaultParticle.plist");
	}
	emitter->setBlendAdditive(false);//�Ƿ���ӻ��
	emitter->setPosition(Vec2(x, y));//���÷������ӵ�λ��
	//emitter->setScale(size);
	emitter->setDuration(0.1);
	emitter->setAutoRemoveOnFinish(true);//��ɺ��Ƴ�

	//������ϵͳ��ӵ��ڵ�(Ҳ����ֱ�ӽ�����ӵ�һ����������CCSprite����)

	//parent1->addChild(emitter, 0, 1);
	//Ȼ������ӵ�������
	this->layer->addChild(emitter, 10);
}
// �رյ���
void GameData::close(){
	if (single != NULL){
		single = NULL;
	}
}
// ������Ч
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
