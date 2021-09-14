#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
USING_NS_CC;

class HelloWorld : public Scene
{
public:
	static Scene* createScene();

	virtual bool init();



	// implement the "static create()" method manually
	CREATE_FUNC(HelloWorld);
};

#endif // __HELLOWORLD_SCENE_H__
