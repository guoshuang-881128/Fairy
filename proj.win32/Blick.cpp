#include "Blick.h"
#include "cocos2d.h"
#include "resource1.h"
#include "config.h"

using namespace cocos2d;
USING_NS_CC;

Blick::Blick()
{

}

Blick::~Blick()
{

}

bool Blick::init()
{
	if (!CCSprite::init())
	{
		return false;
	}
	winsize = CCDirector::sharedDirector()->getWinSize();
	return true;
}
//生成宝石的数组
//把数组后半部分复制给前半部分
void Blick::CreateBlick(int row1,int line1,int type)
{
	row = row1;
	line = line1;
	int m =0,n =0;
	for (int i = 0; i < row ;i++)
	{
		n = line-1;
		for (int j = 0; j < line;j++)
		{
			if (i >= row/2)
			{
				arry_blick[row1-1][j] =arry_blick[m][n];	
				n--;
				//line1--;
			}
			else
			{
				int num = CCRANDOM_0_1()*type;
				arry_blick[i][j] = num;
			}	
		}
		if (i >= row/2)
		{
			m++;
			row1--;
		}
		
	}
	ChangeBlick();

}

void Blick::ChangeBlick()
{
	//这里随机出来四个数分别代表行列的值，来随机交换数组里面的值
	int rowrand1,linerand1,rowrand2,linerand2;
	int temp;
	for (int i = 0;i < 40;i++)
	{
        rowrand1 = CCRANDOM_0_1()*(row-1);
		linerand1 =CCRANDOM_0_1()*(line-1);
		rowrand2 = CCRANDOM_0_1()*(row-1);
		linerand2 = CCRANDOM_0_1()*(line-1);
		temp = arry_blick[rowrand1][linerand1];
		arry_blick[rowrand1][linerand1] = arry_blick[rowrand2][linerand2];
		arry_blick[rowrand2][linerand2] = temp;	
	}
}
bool Blick::CheckBlick()
{
	//检测每个宝石的上下左右是否有相同的宝石，如果有就消除，没有就不做处理
	for (int i = 0;i < row;i++)
	{
		for (int j = 0;j < line;j++)
		{
			//判断上一个
			if ((arry_blick[i][j] == arry_blick[i-1][j])&&(i != 0))
			{
				arry_blick[i][j]=-1;
				arry_blick[i-1][j] =-1;
				//Boo(i,j);
				
			}
			//判断下一个
			if ((arry_blick[i-1][j] == arry_blick[i][j]) && (i != row-1))
			{
				arry_blick[i][j] = -1;
				arry_blick[i-1][j] = -1;
				//Boo(i,j);
				
			}

			//判断左面
			if ((arry_blick[i][j-1] == arry_blick[i][j]) && (j != 0) )
			{
				arry_blick[i][j] = -1;
				arry_blick[i][j-1] =-1;
				//Boo(i,j);
			
			}

			//判断右面
			if (arry_blick[i][j] == arry_blick[i][j+1] && (j != line-1))
			{
				arry_blick[i][j] = -1;
				arry_blick[i][j+1] = -1;
				//Boo(i,j);
				
			}
		}
	}
	return true;
}
void Blick::Boo(int posx,int posy)
{
	CCSprite *sprite3 = CCSprite::create(s_boo1,CCRectMake(0,0,190,190));
	sprite3->setAnchorPoint(ccp(0,0));
	sprite3->setPosition(pos2[posx][posy]);
	this->addChild(sprite3);
	CCAnimation *anction4 = CCAnimationCache::sharedAnimationCache()->animationByName("BOO");
	//sprite3->runAction(CCRepeatForever::create(CCAnimate::create(anction4)));
	sprite3->setScale(0.7f);
}

void Blick::Move(cocos2d::CCPoint p)
{
	//判断点在那个里面，取得这个行列的值
	for (int i = 0;i < row;i++)
	{
		for (int j =0;j <line;j++)
		{
			if (posr[i][j].containsPoint(p))
			{
				Rtab = i;
				Ltab = j;
			}
		}
	}
}
bool Blick::MoveBlick(CCPoint pos,int dir)
{
	
	

	switch(dir)
	{
	case 1:
		if (SearchUP())
		{
			return true;
		}
		else
		{
			return false;
		}
		
		break;
	case 2:
		if (SearchDown())
		{
			return true;
		}
		return false;
		
		break;
	case 3:
		if (SearchLeft())
		{
			return true;
		}
		return false;
		break;
	case 4:
		if (SearchRight())
		{
			return true;
		}
		break;
		return false;
	}
return false;

}

bool Blick::SearchUP()
{
	//根据已知的行列判断能不能移动

	if (arry_blick[Rtab+1][Ltab] != -1 || Rtab == row-1)
	{
		return false;
	}
	arry_blick[Rtab+1][Ltab]=arry_blick[Rtab][Ltab];
	arry_blick[Rtab][Ltab]=-1;
	//for (int i = Rtab;i >=0;i--)
	//{
	//	if (arry_blick[i][Ltab] == -1 && i<0)
	//	{
	//		break;
	//	}
	//	arry_blick[i+1][Ltab] = arry_blick[i][Ltab];
	//	//arry_blick[i][Ltab] = arry_blick[i-1][Ltab];
	//	
	//}
	return true;
}

bool Blick::SearchDown()
{
	if (arry_blick[Rtab-1][Ltab] != -1 || Rtab == 0)
	{
		return false;
	}
	arry_blick[Rtab-1][Ltab] = arry_blick[Rtab][Ltab];
	arry_blick[Rtab][Ltab] = -1;
	return true;
}


bool Blick::SearchLeft()
{
	if (arry_blick[Rtab][Ltab-1] != -1 || Ltab == 0)
	{
		return false;
	}
	arry_blick[Rtab][Ltab -1] = arry_blick[Rtab][Ltab];
	arry_blick[Rtab][Ltab] = -1;
	return true;
}

bool Blick::SearchRight()
{
	if (arry_blick[Rtab][Ltab+1] != -1 || Ltab == line-1)
	{
		return false;
	}
	arry_blick[Rtab][Ltab+1] = arry_blick[Rtab][Ltab];
	arry_blick[Rtab][Ltab] = -1;
	return true;
}

bool Blick::CheckSucess()
{
	for (int i = 0; i < row; i++)
	{
		for (int j =0;j < line;j++)
		{
			if (arry_blick[i][j] != -1)
			{
				Config::shareConfig()->updateSuccess(false);
				return false;
			}
		}
	}
	Config::shareConfig()->updateSuccess(true);
	return true;
}

//绘制宝石
void Blick::DrawBlick(CCNode* parent)
{
	CCSprite * temp;
	CCNode *father = CCNode::create();
	
	int m;
	if (Config::shareConfig()->getlevel2()<= 5)
	{
		 m = 3;	

	}
	else if (5<Config::shareConfig()->getlevel2() && Config::shareConfig()->getlevel2()<=7 )
	{
		m = 2;	
	}
	else 
	{
		m = 0;
	}

	for (int i = 0;i < row; i++)
	{
		for(int j = 0;j < line;j++)
		{
	
			if (arry_blick[i][j] == 0)
			{
				temp = CCSprite::create(s_blick0);
				size = temp->getContentSize();
				temp->setAnchorPoint(ccp(0,0));
				temp->setPosition(ccp(winsize.width/4+size.width*(j+m),size.height*(i+m)));
				father->addChild(temp);
				posr[i][j] =CCRectMake(temp->getPosition().x,temp->getPosition().y,size.width,size.height);
				pos2[i][j] = temp->getPosition();
			}

			if (arry_blick[i][j] == 1)
			{
				temp = CCSprite::create(s_blick1);
				size = temp->getContentSize();
				temp->setAnchorPoint(ccp(0,0));
				temp->setPosition(ccp(winsize.width/4+size.width*(j+m),size.height*(i+m)));
				father->addChild(temp);
				posr[i][j] =CCRectMake(temp->getPosition().x,temp->getPosition().y,size.width,size.height);
				pos2[i][j] = temp->getPosition();
				
			}

			if (arry_blick[i][j] == 2)
			{
				temp = CCSprite::create(s_blick2);
				size = temp->getContentSize();
				temp->setAnchorPoint(ccp(0,0));
				temp->setPosition(ccp(winsize.width/4+size.width*(j+m),size.height*(i+m)));
				father->addChild(temp);
				posr[i][j] =CCRectMake(temp->getPosition().x,temp->getPosition().y,size.width,size.height);
				pos2[i][j] = temp->getPosition();
				
			}
			if (arry_blick[i][j] == 3)
			{
				temp = CCSprite::create(s_blick3);
				size = temp->getContentSize();
				temp->setAnchorPoint(ccp(0,0));
				temp->setPosition(ccp(winsize.width/4+size.width*(j+m),size.height*(i+m)));
				father->addChild(temp);
				posr[i][j] =CCRectMake(temp->getPosition().x,temp->getPosition().y,size.width,size.height);
				pos2[i][j] = temp->getPosition();
			}
			if (arry_blick[i][j] == 4)
			{
				temp = CCSprite::create(s_blick4);
				size = temp->getContentSize();
				temp->setAnchorPoint(ccp(0,0));
				temp->setPosition(ccp(winsize.width/4+size.width*(j+m),size.height*(i+m)));
				father->addChild(temp);
				posr[i][j] =CCRectMake(temp->getPosition().x,temp->getPosition().y,size.width,size.height);
				pos2[i][j] = temp->getPosition();
			}
			if (arry_blick[i][j] == 5)
			{
				temp = CCSprite::create(s_blick5);
				size = temp->getContentSize();
				temp->setAnchorPoint(ccp(0,0));
				temp->setPosition(ccp(winsize.width/4+size.width*(j+m),size.height*(i+m)));
				father->addChild(temp);
				posr[i][j] =CCRectMake(temp->getPosition().x,temp->getPosition().y,size.width,size.height);
				pos2[i][j] = temp->getPosition();
			}

			if (arry_blick[i][j] == 6)
			{
				temp = CCSprite::create(s_blick6);
				size = temp->getContentSize();
				temp->setAnchorPoint(ccp(0,0));
				temp->setPosition(ccp(winsize.width/4+size.width*(j+m),size.height*(i+m)));
				father->addChild(temp);
				posr[i][j] =CCRectMake(temp->getPosition().x,temp->getPosition().y,size.width,size.height);
				pos2[i][j] = temp->getPosition();
			}
			if (arry_blick[i][j] == 7)
			{
				temp = CCSprite::create(s_blick7);
				size = temp->getContentSize();
				temp->setAnchorPoint(ccp(0,0));
				temp->setPosition(ccp(winsize.width/4+size.width*(j+m),size.height*(i+m)));
				father->addChild(temp);
				posr[i][j] =CCRectMake(temp->getPosition().x,temp->getPosition().y,size.width,size.height);
				pos2[i][j] = temp->getPosition();
			}
			if (arry_blick[i][j] == 8)
			{
				temp = CCSprite::create(s_blick8);
				size = temp->getContentSize();
				temp->setAnchorPoint(ccp(0,0));
				temp->setPosition(ccp(winsize.width/4+size.width*(j+m),size.height*(i+m)));
				father->addChild(temp);
				posr[i][j] =CCRectMake(temp->getPosition().x,temp->getPosition().y,size.width,size.height);
				pos2[i][j] = temp->getPosition();
			}
			if (arry_blick[i][j] == 9)
			{
				temp = CCSprite::create(s_blick9);
				size = temp->getContentSize();
				temp->setAnchorPoint(ccp(0,0));
				temp->setPosition(ccp(winsize.width/4+size.width*(j+m),size.height*(i+m)));
				father->addChild(temp);
				posr[i][j] =CCRectMake(temp->getPosition().x,temp->getPosition().y,size.width,size.height);
				pos2[i][j] = temp->getPosition();
			}
		}
	}
	father->setTag(199);
	parent->addChild(father);
}