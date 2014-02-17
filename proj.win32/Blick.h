#ifndef BLICK_H
#define BLICK_H
#include "cocos2d.h"
#define MaxR 9
#define MaxL  10
enum blick
{
	Green =0,
	Pink,
    Red,
	LightBule,
	Yellow,
	HearyYellow,
	Blue,
	HearyGreen,
	Purple,
	PurpleRed,
	White
};
class Blick:public cocos2d::CCSprite
{
public:
	Blick();
	~Blick();
	virtual bool init();
	void CreateBlick(int row,int line,int type);//������ʯ
	bool CheckBlick();//��ⱦʯ
	bool MoveBlick(cocos2d::CCPoint pos,int dir);//�ƶ���ʯ
	void DrawBlick(CCNode* parent);//���Ʊ�ʯ
	void ChangeBlick();//���ұ�ʯ��˳��
    bool SearchUP();//��������
	bool SearchDown();
	bool SearchLeft();
	bool SearchRight();
	void Boo(int posx,int posy);
	bool CheckSucess();
	void Move(cocos2d::CCPoint p);
	CREATE_FUNC(Blick);
private:
	int row;
	int line;
	int arry_blick[MaxR][MaxL];
	cocos2d::CCSize winsize;
	cocos2d::CCSize size;
	cocos2d::CCRect posr[MaxR][MaxL];//���ÿ����ʯ������
	int Rtab;//�����������ѡ�е����ĸ�
	int Ltab;
	cocos2d::CCPoint pos2[MaxR][MaxL];
};
#endif