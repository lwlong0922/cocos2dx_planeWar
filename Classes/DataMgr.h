#ifndef __CONFIGMGR_H__
#define __CONFIGMGR_H__
#include "DataBase.h"
class CDataMgr
{
public:
	CDataMgr();
	~CDataMgr();
	//�洢�ӿڣ����ڴ洢�������ݹ����߻���ָ�롣
	//��ʱ��洢ָ���ʱ�򣬻���Ҫ��һ�����֡�
	void addMgr(string strName, CDataBaseMgr* pDataBaseMgr);
	//��ȡ�ӿڣ����ڻ�ȡ�������ݹ����߻���ָ�롣
	CDataBaseMgr* getMgr(string strName);
	static CDataMgr* getInstance();

private:
	//�洢������Ӧ�������ָ�����ָ���
	map<string, CDataBaseMgr*> m_mapDataBaseMgr;
	static CDataMgr* m_spInstance;

};

#endif