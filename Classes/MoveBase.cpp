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

void CMoveBase::setProperty(float fSpeed, float fAccel, float fAngle)
{
	m_fSpeed = fSpeed;
	m_fAccel = fAccel;
	m_fAngle = fAngle;
}
