#include "BulletLay.h"

CBulletLay::CBulletLay()
{
}

CBulletLay::~CBulletLay()
{
}

bool CBulletLay::init()
{
	if (!Node::init())
	{
		return false;
	}


	return true;
}

void CBulletLay::addBullet(Vec2 startPos, int nBulletId)
{
}
