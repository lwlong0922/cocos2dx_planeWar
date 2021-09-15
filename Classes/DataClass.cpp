#include "DataClass.h"
#include "DataMgr.h"
void CLoader::loadConfig()
{
	CAnimateDtMgr* cAnimateDtMgr = new CAnimateDtMgr();
	cAnimateDtMgr->LoadFile("data/AnimateDt.json");
	CDataMgr::getInstance()->addMgr("animateDtMgr", cAnimateDtMgr);

	CGameMapDtMgr* cGameMapDtMgr = new CGameMapDtMgr();
	cGameMapDtMgr->LoadFile("data/GameMapDt.json");
	CDataMgr::getInstance()->addMgr("gameMapDtMgr", cGameMapDtMgr);

	CBulletDtMgr* cBulletDtMgr = new CBulletDtMgr();
	cBulletDtMgr->LoadFile("data/BulletDt.json");
	CDataMgr::getInstance()->addMgr("bulletDtMgr", cBulletDtMgr);
}

void CAnimateDtMgr::parse(const Document& pDoc)
{
	for (int i = 0; i < pDoc.Size(); i++)
	{
		const rapidjson::Value& animate = pDoc[i];
		string path = animate["path"].GetString();
		SpriteFrameCache::getInstance()->addSpriteFramesWithFile(path);
		CAnimateDt* animateDt = new CAnimateDt();
		animateDt->nID = animate["nId"].GetInt();
		animateDt->roleName = animate["RoleName"].GetString();
		const rapidjson::Value& animations = animate["Animation"];
		for (int j = 0; j < animations.Size(); j++)
		{
			CAnimationDt* animationDt = new CAnimationDt();
			animationDt->name = animations[j]["name"].GetString();
			animationDt->startId = animations[j]["startId"].GetInt();
			animationDt->endId = animations[j]["endId"].GetInt();
			animationDt->delayPerUnit = animations[j]["delayPerUnit"].GetFloat();
			animationDt->imageBaseName = animations[j]["ImageName"].GetString();
			animateDt->mapAnimation[animationDt->name] = animationDt;
		}
		m_mapAnimation[animateDt->roleName] = animateDt;
	}
}

Animate* CAnimateDtMgr::getAnimateByName(const string roleName, const string animationName)
{
	auto animateDt = m_mapAnimation.at(roleName);
	const auto animationDt = animateDt->mapAnimation.at(animationName);
	Animation* animation = Animation::create();
	animation->setDelayPerUnit(animationDt->delayPerUnit);
	for (int i = animationDt->startId; i <= animationDt->endId; i++)
	{
		string imgName = StringUtils::format(animationDt->imageBaseName.c_str(), i);
		SpriteFrame* spriteFrame = SpriteFrameCache::getInstance()->getSpriteFrameByName(imgName);
		animation->addSpriteFrame(spriteFrame);
	}
	Animate* animate = Animate::create(animation);
	return animate;
}

void CGameMapDtMgr::parse(const Document& pDoc)
{
	for (int i = 0; i < pDoc.Size(); i++)
	{
		auto gameMapDt = new CGameMapDt();
		gameMapDt->nID = pDoc[i]["id"].GetInt();
		gameMapDt->mapName = pDoc[i]["mapImg"].GetString();
		m_vecDatas.push_back(gameMapDt);
	}

}

void CBulletDtMgr::parse(const Document& pDoc)
{
	for (int i = 0; i < pDoc.Size(); i++)
	{
		auto bulletDt = new CBulletDt();
		bulletDt->nID = pDoc[i]["id"].GetInt();
		bulletDt->mapName = pDoc[i]["imgName"].GetString();
		bulletDt->width = pDoc[i]["width"].GetInt();
		bulletDt->height = pDoc[i]["height"].GetInt();
		m_vecDatas.push_back(bulletDt);
	}
}
