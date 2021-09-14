#include "DataBase.h"
CDataBaseMgr::CDataBaseMgr()
{
}

CDataBaseMgr::~CDataBaseMgr()
{
}

void CDataBaseMgr::LoadFile(string strPath)
{
	//通过路径获取json文件里面的字符串
	string strData = FileUtils::getInstance()->getStringFromFile(strPath);
	//解析数据到doc里面
	Document pDoc;
	pDoc.Parse(strData.c_str());
	this->parse(pDoc);
}

