#include "OptionLayer.h"
#include "ui/CocosGUI.h"
using namespace ui;

bool OptionLayer::init()
{
	if (!Layer::init())
	{
		return false;
	}
	const Size visibleSize = Director::getInstance()->getVisibleSize();
	auto exitBtn = Button::create("option_exit_btn.png", "", "", TextureResType::PLIST);
	exitBtn->setContentSize(exitBtn->getContentSize() * 0.15f);
	exitBtn->setAnchorPoint(Vec2::ANCHOR_TOP_RIGHT);
	exitBtn->setPosition(Vec2(visibleSize.width, visibleSize.height));
	exitBtn->addClickEventListener([=](Ref* sender)
								   {
									   _eventDispatcher->removeEventListenersForTarget(this);
									   removeFromParent();
								   });
	addChild(exitBtn, 1);
	auto pBg = Scale9Sprite::createWithSpriteFrameName("option_bg_img.png");
	pBg->setContentSize(visibleSize);
	pBg->setAnchorPoint(Vec2::ZERO);
	pBg->setOpacity(200);
	addChild(pBg);

	auto touchEvent = EventListenerTouchOneByOne::create();
	touchEvent->setSwallowTouches(true);
	touchEvent->onTouchBegan = [=](Touch* touch, Event* event)->bool {return true; };
	_eventDispatcher->addEventListenerWithSceneGraphPriority(touchEvent, this);

	return true;
}

OptionLayer::~OptionLayer()
{
}

OptionLayer::OptionLayer()
{
}
