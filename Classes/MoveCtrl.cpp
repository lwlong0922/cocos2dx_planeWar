#include "MoveCtrl.h"


CMoveCtrl* CMoveCtrl::m_pInstance = nullptr;
CMoveCtrl::CMoveCtrl()
{
}

CMoveCtrl::~CMoveCtrl()
{
}

CMoveCtrl* CMoveCtrl::getInstance()
{
	if (!m_pInstance)
	{
		m_pInstance = new CMoveCtrl();
		//�ַ�����ĳ���ص������󶨡� �ص��������洴�����ַ���һ�����ƶ������
		m_pInstance->m_mapCallBack["moveLine"] = [=]() {
			return new CMoveLine();
		};
		//mapCallBack["moveTrack"] = [=]() {
		//	return new CMoveTrack();
		//};
		//mapCallBack["moveCircle"] = [=]() {
		//	return new CMoveCircle();
		//};
	}
	return m_pInstance;
}

CMoveBase* CMoveCtrl::createMove(string strMoveType)
{
	return  m_mapCallBack[strMoveType]();
}
