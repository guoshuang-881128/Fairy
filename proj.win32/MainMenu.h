#ifndef MAINMENU_H
#define MAINMENU_H
#include "cocos2d.h"
//主菜单类
class MainMenu:public cocos2d::CCLayer
{
public:
	MainMenu();
	~MainMenu();
	virtual bool init();
	static cocos2d::CCScene * scene();
	void StarGame(cocos2d::CCObject* pSender);//开始游戏
	void ContinueGame(cocos2d::CCObject *pSender);//继续游戏
	void Appreciate1(cocos2d::CCObject *pSender);//图鉴欣赏
	void Store(cocos2d::CCObject *pSender);//商城
	void Seting(cocos2d::CCObject *pSender);//设置
	void Music(cocos2d::CCObject *pSender);//音乐
	void Sound(cocos2d::CCObject *pSender);//音效
	CREATE_FUNC(MainMenu);
private:
	cocos2d::CCSize winsize;
	//CCMenu Setmenu;
	cocos2d::CCMenu *menuhide;
};
#endif