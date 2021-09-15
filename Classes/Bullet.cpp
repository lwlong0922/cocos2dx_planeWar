#include "Bullet.h"


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
	//physicsBody->setContactTestBitmask(0x01);
	setPhysicsBody(physicsBody);


	//if ((shapeA->getCategoryBitmask() & shapeB->getCollisionBitmask()) == 0
	//	|| (shapeB->getCategoryBitmask() & shapeA->getCollisionBitmask()) == 0)
	//{
	//	// shapes can't collide
	//	ret = false;
	//}

}
