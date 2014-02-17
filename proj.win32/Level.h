//关卡选择页面

#ifndef LEVEL_H
#define LEVEL_H
#include "cocos2d.h"
#include "Appreciate.h"

class Level:public cocos2d::CCLayer
{
public:
	virtual bool init();
	cocos2d::CCScene *scene();
	Level();
	~Level();

	//触屏处理的相关
	virtual void registerWithTouchDispatcher();
	virtual bool ccTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
	virtual void ccTouchEnded(cocos2d::CCTouch *pTouch,cocos2d:: CCEvent *pEvent);
	virtual void ccTouchMoved(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
	virtual void update(float dt);

	//回调函数
	void Up(CCObject *pSender);//上一页
	void Down(CCObject *pSender);//下一页
	void Backmenu(CCObject *pSender);//返回主菜单
	void Store(CCObject *pSender);//商城
	void Appre(CCObject *pSender);//图鉴
	void changeback(char *p);

	void Picture1(int row,int line,CCNode *pra);//画拼图
	void Picture2(int row,int line,CCNode *pra);
	void Picture3(int row,int line,CCNode *pra);
	void Picture4(int row,int line,CCNode *pra);
	void Picture5(int row,int line,CCNode *pra);

	void updateUI1(int Level);
	void updateUI2(int Level);
	void updateUI3(int Level);
	void updateUI4(int Level);
	void updateUI5(int Level);

	void checkRect(cocos2d::CCPoint point,int row,int line);
	CREATE_FUNC(Level);
private:
	//Appreciate *appreciate;
	int num;//判断是第一页
	cocos2d::CCPoint pos1[31];//定义一个数组用来存放白雪公主的坐标
	
};
#endif