#ifndef __LOGINSCENE_H__
#define __LOGINSCENE_H__
#include "cocos2d.h"
USING_NS_CC;
class CLoginScene :public Scene
{
public:
	CREATE_FUNC(CLoginScene);
	bool init() override;
	~CLoginScene() override;
private:
	CLoginScene();
};


#endif
