#include "HelloWorldScene.h"
#include "LoginScene.h"


Scene* HelloWorld::createScene()
{
	return HelloWorld::create();
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Scene::init())
	{
		return false;
	}
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("image/login.plist");
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("image/GameMap/gameMapBg.plist");


	auto pLogo = Sprite::createWithSpriteFrameName("tencentlogo.png");
	pLogo->setAnchorPoint(Vec2::ZERO);
	pLogo->setContentSize(Director::getInstance()->getVisibleSize());
	addChild(pLogo);

	scheduleOnce([=](float)
	{
		Director::getInstance()->replaceScene(CLoginScene::create());
	}, 1.0f, "gotoLogin");

	return true;
}
