//ͼ�����ͽ���


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

	void Up(CCObject *pSender);//��һҳ
	void Down(CCObject *pSender);//��һҳ
	void Back(CCObject *pSender);//����
	void Store(CCObject *pSender);//�̳�
	void Picture1(int row,int line,CCNode *pra);//��ƴͼ
	void Picture2(int row,int line,CCNode *pra);
    void Picture3(int row,int line,CCNode *pra);
	void Picture4(int row,int line,CCNode *pra);
	void Picture5(int row,int line,CCNode *pra);
	void Changebackg(char *p);
	CREATE_FUNC(Appreciate);
private:
	int num;//�����������һҳ
	cocos2d::CCSize winsize;//��Ļ�Ĵ�С
	cocos2d::CCSize size;//��ͼ�Ĵ�С
	//int k ;

};
#endif