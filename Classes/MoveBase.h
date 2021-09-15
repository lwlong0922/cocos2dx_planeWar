#ifndef __MOVEBASE_H__
#define __MOVEBASE_H__
#include "cocos2d.h"
#include "DataClass.h"
USING_NS_CC;

class CMoveBase
{
public:
	CMoveBase();
	~CMoveBase();
	virtual void onUpdate(float fDelta);
	void setProperty(CBulletDt* pBulletDt);
	//控制的目标
	CC_SYNTHESIZE(Node*, m_pOwner, Owner);
	CC_SYNTHESIZE(float, m_fSpeed, Speed);
	CC_SYNTHESIZE(float, m_fAccel, Accel);
	CC_SYNTHESIZE(float, m_fAngle, Angle);
	CC_SYNTHESIZE(float, m_fRadius, Radius);
	CC_SYNTHESIZE(float, m_fAngleSpeed, AngleSpeed);
	CC_SYNTHESIZE(Vec2, m_vCenter, Center);

	CC_SYNTHESIZE(bool, m_fFollow, Follow);
	CC_SYNTHESIZE(Node*, m_pFireNode, FireNode);

	//追踪目标
	CC_SYNTHESIZE(Node*, m_pTarget, Target);
	CC_SYNTHESIZE(float, m_fScope, Scope);
};

#endif
