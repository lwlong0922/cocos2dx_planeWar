#include "DataBase.h"
CDataBaseMgr::CDataBaseMgr()
{
}

CDataBaseMgr::~CDataBaseMgr()
{
}

void CDataBaseMgr::LoadFile(string strPath)
{
	//ͨ��·����ȡjson�ļ�������ַ���
	string strData = FileUtils::getInstance()->getStringFromFile(strPath);
	//�������ݵ�doc����
	Document pDoc;
	pDoc.Parse(strData.c_str());
	this->parse(pDoc);
}

