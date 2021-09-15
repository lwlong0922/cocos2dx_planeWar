#include "MoveLine.h"

CMoveLine::CMoveLine()
{
}

CMoveLine::~CMoveLine()
{
}

void CMoveLine::onUpdate(float fDelta)
{
	//速度 =原速度+加速度*时间
	m_fSpeed += m_fAccel * fDelta;
	float fDistance = m_fSpeed * fDelta;
	//当前这一帧xy的偏移
	//弧度
	float fDeltaX = fDistance * sin(m_fAngle);
	float fDeltaY = fDistance * cos(m_fAngle);
	//拿到坐标
	Vec2 pos = m_pOwner->getPosition();
	pos.y += fDeltaY;
	pos.x += fDeltaX;
	m_pOwner->setPosition(pos);
}
