#ifndef __SELECTSCENE_H__
#define __SELECTSCENE_H__
#include "cocos2d.h"
#include "ui/CocosGUI.h"
using namespace std;
USING_NS_CC;
using namespace ui;

class SelectScene :public Scene
{
public:
	~SelectScene() override;
	CREATE_FUNC(SelectScene);
	bool init() override;
	void changeSprite(PageView* pPageView, int nIndex, float detal);
private:
	int m_nSelectIndex;
	SelectScene();
};
#endif
