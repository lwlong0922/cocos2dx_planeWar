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
		//字符串跟某个回调函数绑定。 回调函数里面创建跟字符串一样的移动类对象。
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
