#ifndef MAINMENU_H
#define MAINMENU_H
#include "cocos2d.h"
//���˵���
class MainMenu:public cocos2d::CCLayer
{
public:
	MainMenu();
	~MainMenu();
	virtual bool init();
	static cocos2d::CCScene * scene();
	void StarGame(cocos2d::CCObject* pSender);//��ʼ��Ϸ
	void ContinueGame(cocos2d::CCObject *pSender);//������Ϸ
	void Appreciate1(cocos2d::CCObject *pSender);//ͼ������
	void Store(cocos2d::CCObject *pSender);//�̳�
	void Seting(cocos2d::CCObject *pSender);//����
	void Music(cocos2d::CCObject *pSender);//����
	void Sound(cocos2d::CCObject *pSender);//��Ч
	CREATE_FUNC(MainMenu);
private:
	cocos2d::CCSize winsize;
	//CCMenu Setmenu;
	cocos2d::CCMenu *menuhide;
};
#endif