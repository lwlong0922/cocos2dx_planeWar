#include "Player.h"
#include "DataMgr.h"
#include "DataClass.h"
#include "GameMapScene.h"
bool Player::init()
{
	if (!Node::init())
	{
		return false;
	}
	m_model = Sprite::createWithSpriteFrameName("player1_1.png");

	m_bMove = false;

	m_model->setPosition(Vec2::ZERO);
	addChild(m_model);




	// auto animimation = Animation::create();
	// for (int i = 1; i <= 11; i++)
	// {
	// 	auto imageName = StringUtils::format("player1_%d.png", i);
	// 	auto spriteFrame = SpriteFrameCache::getInstance()->getSpriteFrameByName(imageName);
	// 	spriteFrame->setOriginalSize(spriteFrame->getOriginalSize()*0.5f);
	// 	animimation->addSpriteFrame(spriteFrame);
	// }
	// animimation->setDelayPerUnit(0.1f);
	// const auto ainimate = Animate::create(animimation);


	auto animateDtMgr = static_cast<CAnimateDtMgr*> (CDataMgr::getInstance()->getMgr("animateDtMgr"));
	auto ainimate = animateDtMgr->getAnimateByName("Player", "player1");
	m_model->setScale(0.5f);
	m_model->runAction(RepeatForever::create(ainimate));

	auto  physicsBody = PhysicsBody::createBox(Size(50, 50),
											   PhysicsMaterial(0.1f, 1.0f, 0.0f));
	physicsBody->setGravityEnable(false);
	physicsBody->setCategoryBitmask(0x01);
	physicsBody->setCollisionBitmask(0x4);
	//physicsBody->setContactTestBitmask(0x02);
	setPhysicsBody(physicsBody);




	auto progress = Node::create();
	progress->setPosition(Vec2(0, m_model->getContentSize().height / 4));
	addChild(progress);


	m_progressBackground = Sprite::createWithSpriteFrameName("blood_back.png");
	m_progressBackground->setScaleX(0.25f);
	m_progressBackground->setScaleY(0.5f);
	progress->addChild(m_progressBackground);

	m_progress = LoadingBar::create("blood_progress.png", TextureResType::PLIST);
	m_progress->setScaleX(0.25f);
	m_progress->setScaleY(0.5f);
	m_progress->setDirection(LoadingBar::Direction::LEFT);
	m_progress->setPercent(100);
	progress->addChild(m_progress);

	// scheduleOnce([=](float)
	// {
	// 	m_progress->setPercent(100);
	// }, 1.0f, "test");


	addEvent();
	fire();
	return true;
}


void Player::addEvent()
{
	auto touchEvent = EventListenerTouchOneByOne::create();
	touchEvent->onTouchBegan = [=](Touch* touch, Event* event)->bool
	{
		const auto clickPos = touch->getLocation();
		auto rectModelBoudingBox = m_model->getBoundingBox();
		rectModelBoudingBox.origin = this->convertToWorldSpace(rectModelBoudingBox.origin);

		if (rectModelBoudingBox.containsPoint(clickPos))
		{
			CCLOG("click");
			m_bMove = true;
		}
		return true;
	};

	touchEvent->onTouchMoved = [=](Touch* touch, Event* event)
	{
		if (m_bMove)
		{
			const Vec2 movePos = touch->getLocation();
			const Vec2 prePos = touch->getPreviousLocation();
			const Vec2 deltaPos = movePos - prePos;
			this->setPosition(getPosition() + deltaPos);
		}
	};

	touchEvent->onTouchEnded = [=](Touch* touch, Event* event)
	{
		m_bMove = false;
	};
	_eventDispatcher->addEventListenerWithSceneGraphPriority(touchEvent, this);


}

void Player::fire()
{
	this->schedule(
		[=](float) {
			//获取子弹层，调用添加子弹接口。
			//导演类.getRunningScene
			//主场景设置成单例。
			//CGameScene::getInstance()->拿到子弹层（不想用getChildByName，创建的时候要设置名字，拿到之后是node类型，还要转换类型CBulletLayer*）
			GameMapScene::getInstance()->getBulletLayer()->addBullet(getPosition(), 3001, 3);
		}, 0.2f, "addBullet");
}

Sprite* Player::getModel()
{
	return m_model;
}

Player::~Player()
{
}

Player::Player()
{
}
