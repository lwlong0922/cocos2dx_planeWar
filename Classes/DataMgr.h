#ifndef __CONFIGMGR_H__
#define __CONFIGMGR_H__
#include "DataBase.h"
class CDataMgr
{
public:
	CDataMgr();
	~CDataMgr();
	//存储接口，用于存储具体数据管理者基类指针。
	//到时候存储指针的时候，还需要传一个名字。
	void addMgr(string strName, CDataBaseMgr* pDataBaseMgr);
	//获取接口，用于获取具体数据管理者基类指针。
	CDataBaseMgr* getMgr(string strName);
	static CDataMgr* getInstance();

private:
	//存储容器，应该是名字跟基类指针绑定
	map<string, CDataBaseMgr*> m_mapDataBaseMgr;
	static CDataMgr* m_spInstance;

};

#endif