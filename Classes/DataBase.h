#ifndef __DATABASE_H__
#define __DATABASE_H__
#include <vector>
#include "cocos2d.h"
#include "json/rapidjson.h"
#include "json/document.h"
using namespace rapidjson;
using namespace std;
USING_NS_CC;

class CDataBase
{
public:
	int nID;
};

class CDataBaseMgr
{
public:
	CDataBaseMgr();
	virtual ~CDataBaseMgr();
	void LoadFile(string strPath);
	virtual void parse(const Document& pDoc) = 0;
	template <class T>
	T getDataByID(int nID)
	{
		for (int i = 0; i < m_vecDatas.size(); i++)
		{
			if (nID == m_vecDatas[i]->nID)
			{
				return static_cast<T>(m_vecDatas[i]);
			}
		}
		return nullptr;
	}
	vector<CDataBase*> getAllDatas() const
	{
		return m_vecDatas;
	}
	int getSize()
	{
		return m_vecDatas.size();
	}
protected:
	vector<CDataBase*> m_vecDatas;
};


#endif