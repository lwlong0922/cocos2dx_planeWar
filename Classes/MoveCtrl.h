#ifndef __MOVECTOR__H_
#define __MOVECTOR__H_
#include "MoveLine.h"
//#include "MoveTrack.h"
//#include "MoveCircle.h"

#include <functional>
#include <string>
using namespace std;
class CMoveCtrl
{
public:
	CMoveCtrl();
	~CMoveCtrl();
	static CMoveCtrl* getInstance();
	//�������ʹ�����ͬ���ƶ���
	CMoveBase* createMove(string strMoveType);

private:
	static CMoveCtrl* m_pInstance;
	map<string, function<CMoveBase* ()>> m_mapCallBack;

};


#endif
