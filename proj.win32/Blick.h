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
	void CreateBlick(int row,int line,int type);//创建宝石
	bool CheckBlick();//检测宝石
	bool MoveBlick(cocos2d::CCPoint pos,int dir);//移动宝石
	void DrawBlick(CCNode* parent);//绘制宝石
	void ChangeBlick();//打乱宝石的顺序
    bool SearchUP();//向上搜索
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
	cocos2d::CCRect posr[MaxR][MaxL];//存放每个宝石的区域
	int Rtab;//这里用来标记选中的是哪个
	int Ltab;
	cocos2d::CCPoint pos2[MaxR][MaxL];
};
#endif