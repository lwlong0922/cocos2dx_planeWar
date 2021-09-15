#include "BulletLay.h"
#include "DataMgr.h"
#include "DataClass.h"

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
	auto pBulletDt = (CDataMgr::getInstance()->getMgr("bulletDtMgr"))->getDataByID<CBulletDt*>(nBulletId);
	auto bullet = CBullet::createWithBulletDt(pBulletDt);
	bullet->setPosition(startPos);
	m_vecBullet.push_back(bullet);

	addChild(bullet);
}
