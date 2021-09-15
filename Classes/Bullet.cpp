#include "Bullet.h"
#include "MoveCtrl.h"

CBullet* CBullet::createWithBulletDt(CBulletDt* pBulletDt)
{
	SpriteFrame* frame = SpriteFrameCache::getInstance()->getSpriteFrameByName(pBulletDt->mapName);
	CBullet* sprite = new (std::nothrow) CBullet();
	if (sprite && frame && sprite->initWithSpriteFrame(frame))
	{
		sprite->autorelease();
		sprite->init(pBulletDt);
		return sprite;
	}
	CC_SAFE_DELETE(sprite);
	return nullptr;
}

void CBullet::init(CBulletDt* pBulletDt)
{
	this->setContentSize(Size(pBulletDt->width, pBulletDt->height));
	auto  physicsBody = PhysicsBody::createBox(Size(pBulletDt->width, pBulletDt->height),
											   PhysicsMaterial(0.1f, 1.0f, 0.0f));
	physicsBody->setGravityEnable(false);
	physicsBody->setCategoryBitmask(0x02);
	physicsBody->setCollisionBitmask(0x04);
	setPhysicsBody(physicsBody);


	m_pMoveBase = CMoveCtrl::getInstance()->createMove(pBulletDt->moveType);
	m_pMoveBase->setOwner(this);
	m_pMoveBase->setProperty(pBulletDt);
	this->scheduleUpdate();
	//physicsBody->setContactTestBitmask(0x01);



	//if ((shapeA->getCategoryBitmask() & shapeB->getCollisionBitmask()) == 0
	//	|| (shapeB->getCategoryBitmask() & shapeA->getCollisionBitmask()) == 0)
	//{
	//	// shapes can't collide
	//	ret = false;
	//}

}

void CBullet::update(float delta)
{
	//调用移动控制器的onUpdate
	m_pMoveBase->onUpdate(delta);
	Vec2 pos = getPosition();
	Size winSize = Director::getInstance()->getVisibleSize();
	//移除。
	if (pos.x <= -100
		|| pos.y <= -100
		|| pos.x > winSize.width + 100
		|| pos.y > winSize.height + 100)
	{
		removeFromParent();
	}
}