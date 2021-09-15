#include "MoveLine.h"

CMoveLine::CMoveLine()
{
}

CMoveLine::~CMoveLine()
{
}

void CMoveLine::onUpdate(float fDelta)
{
	//�ٶ� =ԭ�ٶ�+���ٶ�*ʱ��
	m_fSpeed += m_fAccel * fDelta;
	float fDistance = m_fSpeed * fDelta;
	//��ǰ��һ֡xy��ƫ��
	//����
	float fDeltaX = fDistance * sin(m_fAngle);
	float fDeltaY = fDistance * cos(m_fAngle);
	//�õ�����
	Vec2 pos = m_pOwner->getPosition();
	pos.y += fDeltaY;
	pos.x += fDeltaX;
	m_pOwner->setPosition(pos);
}
