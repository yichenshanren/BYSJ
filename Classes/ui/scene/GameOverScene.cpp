#include "GameOverScene.h"


Scene * GameOverScene::createScene(RenderTexture * rt){
	auto scene = Scene::create(); // ��������
	auto layer = GameOverScene::create(); // ����ͼ��
	scene->addChild(layer);
	// backGround image ����Ϸ�����еĽ�ͼ��Ϊ�˳����еı���
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	auto bg = Sprite::createWithTexture(rt->getSprite()->getTexture());
	bg->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	// ����ͼ��ת180��
	bg->setRotationX(180);
	layer->addChild(bg);
	GameData::getInstance()->playEffect(GameData::DIED_MUSIC);
	return scene;
}
bool GameOverScene::init(){
	if (!MLayer::init()){
		return false;
	}

	// �������� ��ӵ���ǰ������
	this->addChild(pausePopWindow(), 1);
	return true;
}
// ��ͣ����
PopWindow * GameOverScene::pausePopWindow(){
	auto popWindow = PopWindow::createLayer();
	// ���ñ��⡰��Ϸ��ͣ�С�
	popWindow->setTitle(Sprite::create("game_over_title.png"));
	// ��Ӽ�����Ϸ��ť
	auto continueBtn = MenuItemImage::create(
		"retry_normal.png",
		"retry_press.png",
		[&](Ref *){ // �¼��ص�
		GameData::getInstance()->close();
		Director::getInstance()->popScene();
		Director::getInstance()->replaceScene(StartScene::createScene());
	});
	popWindow->addButton(continueBtn);
	/* ��ӷ����� */
	auto bang = Sprite::create("game_over_bang.png");
	bang->setPosition(Vec2(381, 640));
	auto moveTo = MoveTo::create(0.7f, ccp(387, 640 - 300));
	// �����������ö���
	auto easeBounceOut = EaseBackOut::create(moveTo);
	bang->runAction(easeBounceOut);
	popWindow->setContent(bang);
	/* ��ӷ��� */
	// ��������ͼƬ
	auto score = Sprite::create("score.png");
	score->setPosition(ccp(181, 640 - 340));
	score->setScale(0.8f);
	score->setScaleX(0.6f);
	popWindow->setContent(score);
	// ������������Ӷ���
	moveTo = MoveTo::create(1.0f, ccp(391, 640 - 340));
	easeBounceOut = EaseBackOut::create(moveTo);
	score->runAction(easeBounceOut);
	// ��ӷ����ı�
	auto scoreText = LabelTTF::create(GameData::getInstance()->getScore(), "Marker Felt.ttf", 20);
	scoreText->setPosition(Vec2(181, 640 - 340));
	// �������ı���Ӷ���
	moveTo = MoveTo::create(1.0f, ccp(411, 640 - 340));
	easeBounceOut = EaseBackOut::create(moveTo);
	scoreText->runAction(easeBounceOut);
	popWindow->addChild(scoreText, 2);
	/* ��Ӽ�¼ */
	// ��Ӿ��뱳��ͼƬ
	auto mi = Sprite::create("mi.png");
	mi->setPosition(ccp(181, 640 - 255));
	mi->setScale(0.8f);
	mi->setScaleX(0.6f);
	popWindow->setContent(mi);
	// ������ͼƬ��Ӷ���
	moveTo = MoveTo::create(0.8f, ccp(391, 640 - 255));
	easeBounceOut = EaseBackOut::create(moveTo);
	mi->runAction(easeBounceOut);
	// ��Ӿ����ı�
	auto miText = LabelTTF::create(GameData::getInstance()->getMi(), "Marker Felt.ttf", 20);
	miText->setPosition(Vec2(181, 640 - 255));
	// �������ı���Ӷ���
	moveTo = MoveTo::create(0.8f, ccp(371, 640 - 255));
	easeBounceOut = EaseBackOut::create(moveTo);
	miText->runAction(easeBounceOut);
	popWindow->addChild(miText, 2);
	// ��ӻ�̫��ͼƬ
	auto lang = Sprite::create("game_over_lang.png");
	lang->setPosition(Vec2(558, 640 - 290));
	popWindow->setContent(lang);
	return popWindow;
}
// ���ؼ�
void GameOverScene::onBackKeyDown(EventKeyboard::KeyCode keyCode, Event * pEvent){
	Director::getInstance()->popScene();
	Director::getInstance()->replaceScene(StartScene::createScene());
}