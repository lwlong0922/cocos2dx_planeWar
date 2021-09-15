#include "LoginScene.h"
#include "ui/CocosGUI.h"
#include "OptionLayer.h"
#include "GameMapScene.h"
#include "SelectScene.h"
using namespace ui;


inline bool CLoginScene::init()
{
	if (!Scene::init())
	{
		return false;
	}

	Size visibleSize = Director::getInstance()->getVisibleSize();



	auto pBgImg = Sprite::createWithSpriteFrameName("login_bg_img.jpg");
	pBgImg->setContentSize(visibleSize);
	pBgImg->setAnchorPoint(Vec2::ZERO);
	addChild(pBgImg);

	auto pLogoImg = Sprite::createWithSpriteFrameName("logo.png");
	pLogoImg->setContentSize(pLogoImg->getContentSize() * 0.5f);
	pLogoImg->setPosition(Vec2(visibleSize.width / 2, visibleSize.height * 2 / 3));
	addChild(pLogoImg);

	auto pStartBtn = Button::create("login_start_game_btn.png", "", "", TextureResType::PLIST);
	pStartBtn->setContentSize(pStartBtn->getContentSize() * 0.5f);
	pStartBtn->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 3));
	pStartBtn->addClickEventListener([=](Ref* sender)
									 {
										 Director::getInstance()->replaceScene(SelectScene::create());
									 });
	addChild(pStartBtn);

	auto pMenuBtn = Button::create("login_info_btn.png", "", "", TextureResType::PLIST);
	pMenuBtn->setContentSize(pMenuBtn->getContentSize() * 0.5f);
	pMenuBtn->setAnchorPoint(Vec2::ANCHOR_TOP_LEFT);
	pMenuBtn->setPosition(Vec2(0, visibleSize.height));
	pMenuBtn->addClickEventListener([=](Ref* sender)
									{
										addChild(OptionLayer::create());
									});


	addChild(pMenuBtn);

	return true;
}

CLoginScene::~CLoginScene()
{
}

CLoginScene::CLoginScene()
{
}
