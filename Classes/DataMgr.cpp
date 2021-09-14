
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
	//��insert������=��
	//��������Ѿ����ˣ��ڶ����ᱻ�ĵ���
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
	//������ֲ��ڣ��᷵�ؿ�ָ�룬���ǲ���һ�����ݡ�
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
