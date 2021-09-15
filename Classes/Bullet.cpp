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

}
