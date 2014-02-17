#ifndef GAMESCENE_H
#define GAMESCENE_H
#include "cocos2d.h"
#include "Blick.h"

enum Dir
{
	UP=1,
	DOWN,
	LEFT,
	RIGHT
};
class GameScene:public cocos2d::CCLayer
{
public:
	GameScene();
	~GameScene();
	virtual bool init();
	static cocos2d::CCScene *scene();
	void AncationSprite();//添加精灵动画
	void AncationJing();//水晶动画
	void AncationNan();//南瓜动画
	void AncationBoo();//爆炸动画

	virtual void registerWithTouchDispatcher();
	virtual bool ccTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
	virtual void ccTouchEnded(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
	virtual void ccTouchMoved(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);

	void back(CCObject *pSender);
	void restart(CCObject *pSender);

	void Store(cocos2d::CCObject *pSender);//商城
	void Seting(cocos2d::CCObject *pSender);//设置
	void Music(cocos2d::CCObject *pSender);//音乐
	void Sound(cocos2d::CCObject *pSender);//音效
	virtual void update(float dt);
	void SetProessTimer(int time);//进度条设置
	void Newlevel();//新的等级
	void Check(float dt);//检测宝石
	void Moveblick(cocos2d::CCPoint p,int dir);//移动宝石
	void Checksucess(float dt);//检测是否胜利
	CREATE_FUNC(GameScene);
private:
	cocos2d::CCSize winsize;
	cocos2d::CCMenu *menuhide;//隐藏菜单
	cocos2d::CCSize size;
	cocos2d::CCProgressTimer *proesstimer;//时间条
	cocos2d::CCSprite *time3;//时间条精灵
	Blick *blick;
	cocos2d::CCPoint posFirst;//初始点坐标
};
#endif