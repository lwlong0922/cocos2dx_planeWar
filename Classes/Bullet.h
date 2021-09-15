#ifndef __CBULLET_H__
#define __CBULLET_H__
#include "cocos2d.h"
#include "DataClass.h"
USING_NS_CC;
using namespace std;
class CBullet :public Sprite
{
public:
	static CBullet* createWithBulletDt(CBulletDt* pBulletDt);
	void init(CBulletDt* pBulletDt);

};


#endif // !__CBULLET_H__

