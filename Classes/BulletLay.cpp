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

void CBulletLay::addBullet(Vec2 startPos, int nBulletId, int count, int angle)
{
	int nTemp = count;
	nTemp /= 2;
	for (int i = -nTemp; i <= nTemp; i++)
	{
		if (count % 2 == 0 && i == 0)
		{
			continue;
		}
		auto pBulletDt = (CDataMgr::getInstance()->getMgr("bulletDtMgr"))->getDataByID<CBulletDt*>(nBulletId);
		auto bullet = CBullet::createWithBulletDt(pBulletDt);
		bullet->setPosition(startPos);
		m_vecBullet.push_back(bullet);
		addChild(bullet);

		bullet->setAck(10);
		float fAngle = angle;
		fAngle += i * 10;
		bullet->getMoveBase()->setAngle(CC_DEGREES_TO_RADIANS(fAngle));
		//pBullet->getMoveBase()->setCenter(pFireNode->getPosition());
		//pBullet->getMoveBase()->setFireNode(pFireNode);
	}


}
