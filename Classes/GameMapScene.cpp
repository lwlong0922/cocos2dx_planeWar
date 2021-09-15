#include "GameMapScene.h"
#include "Player.h"
#include "BulletLay.h"

GameMapScene* GameMapScene::m_spInstance = nullptr;
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

	addBulletLayer();
	addPlayer();
	scheduleUpdate();

	return true;
}

GameMapScene* GameMapScene::getInstance()
{
	if (!m_spInstance)
	{
		m_spInstance = GameMapScene::create();//这里跟c++不一样，用create
	}
	return m_spInstance;
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

void GameMapScene::addBulletLayer()
{
	m_pBulletLayer = CBulletLay::create();
	//bulletlayer->addBullet(Director::getInstance()->getVisibleSize() / 2, 3001);
	addChild(m_pBulletLayer);
}

void GameMapScene::addPlayer()
{
	const auto visibleSize = Director::getInstance()->getVisibleSize();
	auto player = Player::create();

	player->setPosition(visibleSize.width / 2, visibleSize.height / 4);
	//player->getBoundingBox().size = Size(50, 50);
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

void GameMapScene::onEnter()
{
	//物理碰撞
	Scene::onEnter();
	auto eventPhysics = EventListenerPhysicsContact::create();
	eventPhysics->onContactBegin = [=](PhysicsContact& contact)->bool {
		auto shapeA = contact.getShapeA();
		auto shapeB = contact.getShapeB();
		auto temp1 = shapeA->getCategoryBitmask() & shapeB->getCollisionBitmask();
		auto temp2 = shapeB->getCategoryBitmask() & shapeA->getCollisionBitmask();
		if ((shapeA->getCategoryBitmask() & shapeB->getCollisionBitmask()) == 0
			|| (shapeB->getCategoryBitmask() & shapeA->getCollisionBitmask()) == 0)
		{
			log("collision!!!!");
			//res = false;
		}
		return true;
	};
	_eventDispatcher->addEventListenerWithSceneGraphPriority(eventPhysics, this);
}

GameMapScene::GameMapScene()
{
}
