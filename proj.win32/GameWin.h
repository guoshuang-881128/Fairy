#ifndef GAME_WIN_H
#define GAME_WIN_H
#include "cocos2d.h"
class GameWin:public cocos2d::CCLayer
{
public:
	static cocos2d::CCScene *scene();
	virtual bool init();
	void callback(CCObject *pseder);
	CREATE_FUNC(GameWin);
};
#endif