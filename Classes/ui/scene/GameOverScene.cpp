#include "GameOverScene.h"


Scene * GameOverScene::createScene(RenderTexture * rt){
	auto scene = Scene::create(); // 创建场景
	auto layer = GameOverScene::create(); // 创建图层
	scene->addChild(layer);
	// backGround image 将游戏场景中的截图作为此场景中的背景
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	auto bg = Sprite::createWithTexture(rt->getSprite()->getTexture());
	bg->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	// 将截图旋转180°
	bg->setRotationX(180);
	layer->addChild(bg);
	GameData::getInstance()->playEffect(GameData::DIED_MUSIC);
	return scene;
}
bool GameOverScene::init(){
	if (!MLayer::init()){
		return false;
	}

	// 将弹窗层 添加到当前场景中
	this->addChild(pausePopWindow(), 1);
	return true;
}
// 暂停窗口
PopWindow * GameOverScene::pausePopWindow(){
	auto popWindow = PopWindow::createLayer();
	// 设置标题“游戏暂停中”
	popWindow->setTitle(Sprite::create("game_over_title.png"));
	// 添加继续游戏按钮
	auto continueBtn = MenuItemImage::create(
		"retry_normal.png",
		"retry_press.png",
		[&](Ref *){ // 事件回掉
		GameData::getInstance()->close();
		Director::getInstance()->popScene();
		Director::getInstance()->replaceScene(StartScene::createScene());
	});
	popWindow->addButton(continueBtn);
	/* 添加分数帮 */
	auto bang = Sprite::create("game_over_bang.png");
	bang->setPosition(Vec2(381, 640));
	auto moveTo = MoveTo::create(0.7f, ccp(387, 640 - 300));
	// 给分数帮设置动画
	auto easeBounceOut = EaseBackOut::create(moveTo);
	bang->runAction(easeBounceOut);
	popWindow->setContent(bang);
	/* 添加分数 */
	// 分数背景图片
	auto score = Sprite::create("score.png");
	score->setPosition(ccp(181, 640 - 340));
	score->setScale(0.8f);
	score->setScaleX(0.6f);
	popWindow->setContent(score);
	// 给分数背景添加动画
	moveTo = MoveTo::create(1.0f, ccp(391, 640 - 340));
	easeBounceOut = EaseBackOut::create(moveTo);
	score->runAction(easeBounceOut);
	// 添加分数文本
	auto scoreText = LabelTTF::create(GameData::getInstance()->getScore(), "Marker Felt.ttf", 20);
	scoreText->setPosition(Vec2(181, 640 - 340));
	// 给分数文本添加动画
	moveTo = MoveTo::create(1.0f, ccp(411, 640 - 340));
	easeBounceOut = EaseBackOut::create(moveTo);
	scoreText->runAction(easeBounceOut);
	popWindow->addChild(scoreText, 2);
	/* 添加记录 */
	// 添加距离背景图片
	auto mi = Sprite::create("mi.png");
	mi->setPosition(ccp(181, 640 - 255));
	mi->setScale(0.8f);
	mi->setScaleX(0.6f);
	popWindow->setContent(mi);
	// 给背景图片添加动画
	moveTo = MoveTo::create(0.8f, ccp(391, 640 - 255));
	easeBounceOut = EaseBackOut::create(moveTo);
	mi->runAction(easeBounceOut);
	// 添加距离文本
	auto miText = LabelTTF::create(GameData::getInstance()->getMi(), "Marker Felt.ttf", 20);
	miText->setPosition(Vec2(181, 640 - 255));
	// 给距离文本添加动画
	moveTo = MoveTo::create(0.8f, ccp(371, 640 - 255));
	easeBounceOut = EaseBackOut::create(moveTo);
	miText->runAction(easeBounceOut);
	popWindow->addChild(miText, 2);
	// 添加灰太狼图片
	auto lang = Sprite::create("game_over_lang.png");
	lang->setPosition(Vec2(558, 640 - 290));
	popWindow->setContent(lang);
	return popWindow;
}
// 返回键
void GameOverScene::onBackKeyDown(EventKeyboard::KeyCode keyCode, Event * pEvent){
	Director::getInstance()->popScene();
	Director::getInstance()->replaceScene(StartScene::createScene());
}