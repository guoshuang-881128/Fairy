//�ؿ�ѡ��ҳ��

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

	//������������
	virtual void registerWithTouchDispatcher();
	virtual bool ccTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
	virtual void ccTouchEnded(cocos2d::CCTouch *pTouch,cocos2d:: CCEvent *pEvent);
	virtual void ccTouchMoved(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
	virtual void update(float dt);

	//�ص�����
	void Up(CCObject *pSender);//��һҳ
	void Down(CCObject *pSender);//��һҳ
	void Backmenu(CCObject *pSender);//�������˵�
	void Store(CCObject *pSender);//�̳�
	void Appre(CCObject *pSender);//ͼ��
	void changeback(char *p);

	void Picture1(int row,int line,CCNode *pra);//��ƴͼ
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
	int num;//�ж��ǵ�һҳ
	cocos2d::CCPoint pos1[31];//����һ������������Ű�ѩ����������
	
};
#endif