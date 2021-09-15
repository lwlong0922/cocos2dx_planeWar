#ifndef __MOVELINE_H__
#define __MOVELINE_H__
#include "cocos2d.h"
#include "MoveBase.h"
USING_NS_CC;
class CMoveLine :public CMoveBase
{
public:
	CMoveLine();
	~CMoveLine();
	void onUpdate(float fDelta) override;
};

#endif // !__MOVELINE__H_
