#ifndef __CBULLET_H__
#define __CBULLET_H__
#include "cocos2d.h"
#include "DataClass.h"
#include "MoveBase.h"
USING_NS_CC;
using namespace std;
class CBullet :public Sprite
{
public:
	static CBullet* createWithBulletDt(CBulletDt* pBulletDt);
	void init(CBulletDt* pBulletDt);
	void update(float delta);
	CC_SYNTHESIZE(CMoveBase*, m_pMoveBase, MoveBase);
	CC_SYNTHESIZE(int, m_nAck, Ack);
};


#endif // !__CBULLET_H__

