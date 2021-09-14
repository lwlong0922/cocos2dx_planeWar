#ifndef __OPTIONLAYER_H__
#define __OPTIONLAYER_H__
#include "cocos2d.h"
USING_NS_CC;
class OptionLayer final :public Layer
{
public:
	CREATE_FUNC(OptionLayer);
	bool init() override;
	~OptionLayer() override;
private:
	OptionLayer();
};
#endif
