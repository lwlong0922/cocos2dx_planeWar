#ifndef __DATACLASS_H__
#define __DATACLASS_H__
#include "DataBase.h"
class CLoader
{
public:
	static void loadConfig();
};

class CAnimationDt
{
public:
	string name;
	int startId;
	int endId;
	float delayPerUnit;
	string imageBaseName;
};

class CAnimateDt :public CDataBase
{
public:
	CAnimateDt()
	{
	};
	~CAnimateDt()
	{
	};
	string roleName;
	map<string, CAnimationDt*> mapAnimation;
};

class CAnimateDtMgr :public CDataBaseMgr
{
public:
	CAnimateDtMgr()
	{
	};
	~CAnimateDtMgr()override
	{
	};
	void parse(const Document& pDoc) override;
	Animate* getAnimateByName(const string roleName, const string animationName);
private:
	map<string, CAnimateDt*> m_mapAnimation;
};

class CGameMapDt :public CDataBase
{
public:
	string mapName;
};

class CGameMapDtMgr :public CDataBaseMgr
{
public:
	CGameMapDtMgr()
	{
	}
	~CGameMapDtMgr()override
	{
	}
	void parse(const Document& pDoc) override;
};

class CBulletDt :public CDataBase
{
public:
	int id;
	string mapName;
	int width;
	int height;
};

class CBulletDtMgr : public CDataBaseMgr
{
public:
	CBulletDtMgr()
	{
	}
	~CBulletDtMgr() override
	{
	};
	void parse(const Document& pDoc) override;
};


#endif
