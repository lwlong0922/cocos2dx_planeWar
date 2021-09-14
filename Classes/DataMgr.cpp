
#include "DataMgr.h"

CDataMgr* CDataMgr::m_spInstance = nullptr;
CDataMgr::CDataMgr()
{
}


CDataMgr::~CDataMgr()
{
}

void CDataMgr::addMgr(string strName, CDataBaseMgr* pDataBaseMgr)
{
	if (strName.empty() || !pDataBaseMgr)
	{
		return;
	}
	/*"MapDtMgr"
	Mapdtmgr*/
	//用insert还是用=？
	//如果名字已经在了，第二个会被改掉。
	//m_mapDataBaseMgr[strName] = pDataBaseMgr;
	m_mapDataBaseMgr.insert(pair<string, CDataBaseMgr*>(strName, pDataBaseMgr));
}

CDataBaseMgr* CDataMgr::getMgr(string strName)
{
	if (strName.empty())
	{
		return nullptr;
	}
	if (!m_mapDataBaseMgr.count(strName))
	{
		return nullptr;
	}
	//如果名字不在，会返回空指针，但是插入一个数据。
	return m_mapDataBaseMgr.at(strName);
}

CDataMgr* CDataMgr::getInstance()
{
	if (!m_spInstance)
	{
		m_spInstance = new CDataMgr();
	}
	return m_spInstance;
}
