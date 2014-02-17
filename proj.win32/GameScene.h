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
	void AncationSprite();//��Ӿ��鶯��
	void AncationJing();//ˮ������
	void AncationNan();//�Ϲ϶���
	void AncationBoo();//��ը����

	virtual void registerWithTouchDispatcher();
	virtual bool ccTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
	virtual void ccTouchEnded(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
	virtual void ccTouchMoved(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);

	void back(CCObject *pSender);
	void restart(CCObject *pSender);

	void Store(cocos2d::CCObject *pSender);//�̳�
	void Seting(cocos2d::CCObject *pSender);//����
	void Music(cocos2d::CCObject *pSender);//����
	void Sound(cocos2d::CCObject *pSender);//��Ч
	virtual void update(float dt);
	void SetProessTimer(int time);//����������
	void Newlevel();//�µĵȼ�
	void Check(float dt);//��ⱦʯ
	void Moveblick(cocos2d::CCPoint p,int dir);//�ƶ���ʯ
	void Checksucess(float dt);//����Ƿ�ʤ��
	CREATE_FUNC(GameScene);
private:
	cocos2d::CCSize winsize;
	cocos2d::CCMenu *menuhide;//���ز˵�
	cocos2d::CCSize size;
	cocos2d::CCProgressTimer *proesstimer;//ʱ����
	cocos2d::CCSprite *time3;//ʱ��������
	Blick *blick;
	cocos2d::CCPoint posFirst;//��ʼ������
};
#endif