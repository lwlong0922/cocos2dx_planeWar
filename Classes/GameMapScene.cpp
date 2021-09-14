#include "GameMapScene.h"
#include "Player.h"
GameMapScene::~GameMapScene()
{

}

bool GameMapScene::init()
{
	if (!Scene::init())
	{
		return false;
	}
	if (!Scene::initWithPhysics())
	{
		return false;

	}
	this->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);

	addBg("img_bg_level_1.jpg");
	addPlayer();
	scheduleUpdate();
	return true;
}

void GameMapScene::addBg(std::string strBackGroundName)
{
	const auto visibleSize = Director::getInstance()->getVisibleSize();
	m_backSpeed = 100;
	m_backgrounds[0] = Sprite::createWithSpriteFrameName(strBackGroundName);
	m_backgrounds[0]->setAnchorPoint(Vec2::ZERO);
	m_backgrounds[0]->setContentSize(visibleSize);
	m_backgrounds[1] = Sprite::createWithSpriteFrameName(strBackGroundName);
	m_backgrounds[1]->setAnchorPoint(Vec2::ZERO);
	m_backgrounds[1]->setContentSize(visibleSize);
	m_backgrounds[1]->setPosition(Vec2(0, visibleSize.height));
	addChild(m_backgrounds[0], -1);
	addChild(m_backgrounds[1], -1);
}

void GameMapScene::addPlayer()
{
	const auto visibleSize = Director::getInstance()->getVisibleSize();
	auto player = Player::create();

	auto  physicsBody = PhysicsBody::createBox(Size(50, 50),
											   PhysicsMaterial(0.1f, 1.0f, 0.0f));
	physicsBody->setGravityEnable(false);
	player->setPhysicsBody(physicsBody);
	player->setPosition(visibleSize.width / 2, visibleSize.height / 4);
	player->getBoundingBox().size = Size(50, 50);
	addChild(player);

}

void GameMapScene::update(float delta)
{
	auto y0 = m_backgrounds[0]->getPosition().y;
	auto y1 = m_backgrounds[1]->getPosition().y;
	y0 -= m_backSpeed * delta;
	y1 -= m_backSpeed * delta;
	if (y0 < -m_backgrounds[0]->getContentSize().height)
	{
		y0 = y1 + m_backgrounds[1]->getContentSize().height;
	}
	if (y1 < -m_backgrounds[1]->getContentSize().height)
	{
		y1 = y0 + m_backgrounds[0]->getContentSize().height;
	}
	m_backgrounds[0]->setPosition(Vec2(0, y0));
	m_backgrounds[1]->setPosition(Vec2(0, y1));
}

GameMapScene::GameMapScene()
{
}
