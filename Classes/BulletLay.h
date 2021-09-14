﻿#ifndef __CBULLETLAY__H_
#define __CBULLETLAY__H_
#include "cocos2d.h"
USING_NS_CC;
class CBulletLay :public Node
{
public:
	CBulletLay();
	~CBulletLay() override;
	bool init() override;
	void addBullet(Vec2 startPos, int nBulletId);
	CREATE_FUNC(CBulletLay)

};



#endif