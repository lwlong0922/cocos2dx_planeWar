#ifndef __GAMEMAPSCENE_H__
#define __GAMEMAPSCENE_H__
#include "cocos2d.h"
USING_NS_CC;

class GameMapScene :public Scene
{
public:
	~GameMapScene() override;
	CREATE_FUNC(GameMapScene);
	bool init() override;
	void addBg(std::string strBackGroundName);
	void addPlayer();
	void update(float delta) override;
private:
	Sprite* m_backgrounds[2];
	int m_backSpeed;
	GameMapScene();
};

#endif
