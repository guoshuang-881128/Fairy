//图鉴欣赏界面


#ifndef APPRECIATE_H
#define APPRECIATE_H
#include "cocos2d.h"
#include "resource1.h"


class Appreciate:public cocos2d::CCLayer
{
public:
	virtual bool init();
	cocos2d::CCScene *scene();
	Appreciate();
	~Appreciate();

	void Up(CCObject *pSender);//上一页
	void Down(CCObject *pSender);//下一页
	void Back(CCObject *pSender);//返回
	void Store(CCObject *pSender);//商城
	void Picture1(int row,int line,CCNode *pra);//画拼图
	void Picture2(int row,int line,CCNode *pra);
    void Picture3(int row,int line,CCNode *pra);
	void Picture4(int row,int line,CCNode *pra);
	void Picture5(int row,int line,CCNode *pra);
	void Changebackg(char *p);
	CREATE_FUNC(Appreciate);
private:
	int num;//标记现在是哪一页
	cocos2d::CCSize winsize;//屏幕的大小
	cocos2d::CCSize size;//地图的大小
	//int k ;

};
#endif