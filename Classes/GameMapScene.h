#ifndef __GAMEMAPSCENE_H__
#define __GAMEMAPSCENE_H__
#include "cocos2d.h"
#include "BulletLay.h"
USING_NS_CC;

class GameMapScene :public Scene
{
public:
	~GameMapScene() override;
	CREATE_FUNC(GameMapScene);
	bool init() override;
	static GameMapScene* getInstance();
	void addBg(std::string strBackGroundName);
	void addBulletLayer();
	void addPlayer();
	void update(float delta) override;
	void onEnter()override;
	CC_SYNTHESIZE(CBulletLay*, m_pBulletLayer, BulletLayer);

	//CC_SYNTHESIZE(CEnemyLayer*, m_pEnemyLayer, EnemyLayer);
private:
	Sprite* m_backgrounds[2];
	int m_backSpeed;
	static GameMapScene* m_spInstance;
	GameMapScene();
};

#endif
