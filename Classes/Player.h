#ifndef __PLAYER_H__
#define __PLAYER_H__
#include "cocos2d.h"
#include "ui/CocosGUI.h"
USING_NS_CC;
using namespace ui;

class Player :public Node
{
public:
	CREATE_FUNC(Player);
	bool init() override;
	Sprite* getModel();
	~Player() override;
	void addEvent();
private:
	Player();
	Sprite* m_model;
	LoadingBar* m_progress;
	Sprite* m_progressBackground;
	bool m_bMove;
};
#endif
