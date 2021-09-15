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
	//auto pBulletDt = CDataMgr::getInstance()->getMgr("bulletDtMgt")->getDataByID<CBulletDt>(nBulletId);


}
