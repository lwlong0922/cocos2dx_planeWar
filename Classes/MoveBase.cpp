#include "MoveBase.h"

CMoveBase::CMoveBase()
	:m_pOwner(nullptr),
	m_fAccel(0),
	m_fSpeed(0),
	m_fAngle(0),
	m_pTarget(nullptr)
{
}

CMoveBase::~CMoveBase()
{
}

void CMoveBase::onUpdate(float fDelta)
{

}

void CMoveBase::setProperty(CBulletDt* pBulletDt)
{

	m_fSpeed = pBulletDt->moveSpeed;
	m_fAccel = pBulletDt->fBulletAccel;
	//m_fAngle = CC_DEGREES_TO_RADIANS(pRoleDt->fBulletAngle);
	m_fAngleSpeed = pBulletDt->fBulletAngleSpeed;
	m_fRadius = pBulletDt->fBulletRadius;
}
