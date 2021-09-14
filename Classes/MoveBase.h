#ifndef __MOVEBASE_H__
#define __MOVEBASE_H__
#include "cocos2d.h"
USING_NS_CC;

class CMoveBase
{
public:
	CMoveBase();
	~CMoveBase();
	virtual void onUpdate(float fDelta);
	void setProperty(float fSpeel, float fAccel, float fAngle);
	CC_SYNTHESIZE(Node*, m_pOwner, Owner);
	CC_SYNTHESIZE(float, m_fSpeed, Speed);
	CC_SYNTHESIZE(float, m_fAccel, Accel);
	CC_SYNTHESIZE(float, m_fAngle, Angle);
	CC_SYNTHESIZE(Node*, m_pTarget, Target);
};

#endif
