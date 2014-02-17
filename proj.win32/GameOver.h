#ifndef GAMEOVER_H
#define GAMEOVER_H
#include "cocos2d.h"

class GameOver:public cocos2d::CCLayer
{
public:
	static cocos2d::CCScene *scene();
	virtual bool init();
	GameOver();
	~GameOver();
	void backmenu(CCObject * pSender);
	CREATE_FUNC(GameOver);

};
#endif