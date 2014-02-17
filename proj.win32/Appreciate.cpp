#include "Appreciate.h"
#include "cocos2d.h"
#include "resource1.h"
#include "MainMenu.h"
#include "Level.h"
#include "config.h"

USING_NS_CC;
using namespace cocos2d;


Appreciate::Appreciate()
{
	num = 1;
	//k =1;
}

Appreciate::~Appreciate()
{

}

CCScene* Appreciate::scene()
{
	CCScene *scene = NULL;
	scene = CCScene::create();
	Appreciate *layer = (Appreciate*)Appreciate::create();
	scene->addChild(layer);
	return scene;
}

bool Appreciate::init()
{
	if (!CCLayer::init())
	{
		return false;
	}

	 winsize = CCDirector::sharedDirector()->getWinSize();
	//加载边框
	CCSprite* backgound = CCSprite::create(s_bild);
	backgound->setAnchorPoint(ccp(0,0));
	this->addChild(backgound);

	//加载按钮

	CCMenuItemImage *up = CCMenuItemImage::create(s_up,s_up1,NULL,this,menu_selector(Appreciate::Up));
	CCMenuItemImage *down = CCMenuItemImage::create(s_down,s_down1,NULL,this,menu_selector(Appreciate::Down));
	CCMenuItemImage *back = CCMenuItemImage::create(s_back,s_back1,NULL,this,menu_selector(Appreciate::Back));
	CCMenuItemImage *store1 = CCMenuItemImage::create(s_store1,s_store2,this,menu_selector(Appreciate::Store));

	CCMenu *menu = CCMenu::create(up,back,store1,down,NULL);
	menu->setAnchorPoint(ccp(0,0));
	menu->alignItemsHorizontallyWithPadding(100);
	menu->setPosition(ccp(winsize.width/2,winsize.height/19));
	this->addChild(menu);

	//默认的拼图
	CCSprite *snow = CCSprite::create(s_baixue);
	snow->setAnchorPoint(ccp(0,0));
	snow->setPosition(ccp(0,0));
	this->addChild(snow);
	size = snow->getContentSize();
	Picture1(3,3,this);
	return true;

}

void Appreciate::Up(CCObject *pSender)
{
	char *temp;
	num--;
	if (num <= 0)
	{
		num = 5;
	}
	switch(num)
	{
	case 1:
		this->removeChildByTag(103,true);
		this->removeChildByTag(101,true);
		CCTextureCache::sharedTextureCache()->removeUnusedTextures();
		temp = (char *)s_baixue;
		Changebackg(temp);
		Picture1(3,3,this);
		break;
	case 2:
		this->removeChildByTag(104,true);
		this->removeChildByTag(101,true);
		CCTextureCache::sharedTextureCache()->removeUnusedTextures();
		temp = (char *)s_gray;
		Changebackg(temp);
		Picture2(3,4,this);
		break;
	case 3:
		this->removeChildByTag(105,true);
		this->removeChildByTag(101,true);
		CCTextureCache::sharedTextureCache()->removeUnusedTextures();
		temp = (char *)s_pinocao;
		Changebackg(temp);
		Picture3(4,4,this);
		break;
	case 4:
		this->removeChildByTag(106,true);
		this->removeChildByTag(101,true);
		CCTextureCache::sharedTextureCache()->removeUnusedTextures();
		temp = (char *)s_huochai;
		Changebackg(temp);
		Picture4(4,5,this);
		break;
	case 5:
		this->removeChildByTag(102,true);
		this->removeChildByTag(101,true);
		CCTextureCache::sharedTextureCache()->removeUnusedTextures();
		temp = (char *)s_light;
		Changebackg(temp);
		Picture5(5,5,this);
		break;	
	}	
}

void Appreciate::Down(CCObject *pSender)
{
	char *temp;
	num++;
	
	if (num > 5)
	{
		num = 1;
	}
	switch(num)
	{
	case 1:
		this->removeChildByTag(106,true);
		this->removeChildByTag(101,true);
		CCTextureCache::sharedTextureCache()->removeUnusedTextures();

		temp = (char *)s_baixue;
		Changebackg(temp);
		Picture1(3,3,this);
		//removeFromParentAndCleanup(true);
		
		break;
	case 2:
		this->removeChildByTag(102,true);
		this->removeChildByTag(101,true);
		CCTextureCache::sharedTextureCache()->removeUnusedTextures();
		temp = (char *)s_gray;
		Changebackg(temp);
		Picture2(3,4,this);
	     break;
	case 3:
		this->removeChildByTag(103,true);
		this->removeChildByTag(101,true);
		CCTextureCache::sharedTextureCache()->removeUnusedTextures();
		temp = (char *)s_pinocao;
		Changebackg(temp);
		Picture3(4,4,this);
		break;
	case 4:
		
		this->removeChildByTag(104,true);
		this->removeChildByTag(101,true);
		CCTextureCache::sharedTextureCache()->removeUnusedTextures();
		temp = (char *)s_huochai;
		Changebackg(temp);
		Picture4(4,5,this);
		
		
		break;
	case 5:
		this->removeChildByTag(105,true);
		this->removeChildByTag(101,true);
		CCTextureCache::sharedTextureCache()->removeUnusedTextures();
		temp = (char *)s_light;
		Changebackg(temp);
		Picture5(5,5,this);
		break;	
	}	
}
void Appreciate::Changebackg(char *p)
{
	CCSprite *background = CCSprite::create(p);
	background->setAnchorPoint(ccp(0,0));
	background->setPosition(ccp(0,0));
	this->addChild(background);
	background->setTag(101);
}

void Appreciate::Back(CCObject *pSender)
{
		CCScene *scene = CCScene::create();
		scene->addChild(MainMenu::create());
		CCDirector::sharedDirector()->replaceScene(CCTransitionShrinkGrow::create(0.5f,scene));	
}
void Appreciate::Store(CCObject *pSender)
{

}
//这里因图片大小有问题，所以导致了重新写,其实完全可以写成一个的，这里暂时先不考虑
//雪这个界面还是有问题
void Appreciate::Picture1(int row,int line,CCNode *pra)
{
	
	int k=1;
	char strname[64] = {0};

	CCNode *father = CCNode::create();
	//假定是地图是数组，一个一个的贴图
	for (int i = row-1;i>=0;i--)
	{
		for (int j = 0;j<line;j++)
		{
			sprintf(strname,"关卡选择界面/雪/%d.png",k);
			k++;
			CCSprite *tempSprite = CCSprite::create(strname);
			tempSprite->setAnchorPoint(ccp(0,0));
			tempSprite->setPosition(ccp(915/line * j+20,555/row *i-10));
			father->addChild(tempSprite);
			
		}
	}
	pra->addChild(father);
	father->setTag(102);
}
//灰姑娘
void Appreciate::Picture2(int row,int line,CCNode *pra)
{
	int k = 1;
	char strname[64] = {0};
	
	CCNode *father = CCNode::create();
	for (int i = row-1;i>=0;i--)
	{
		for (int j = 0;j<line;j++)
		{
			sprintf(strname,"关卡选择界面/灰姑娘/%d.png",k);
			k++;
			CCSprite *tempSprite= CCSprite::create(strname);
			tempSprite->setAnchorPoint(ccp(0,0));
			tempSprite->setPosition(ccp(915/line * j+20,555/row *i-10));
			//tempSprite->setTag(202+k);
			//pra->addChild(tempSprite);
			father->addChild(tempSprite);
		}
	}
	father->setTag(103);
	pra->addChild(father);

}
//匹诺曹
void Appreciate::Picture3(int row,int line,CCNode *pra)
{
	int k = 1;
	char strname[64] = {0};
	
	CCNode *father = CCNode::create();
	for (int i = row-1;i>=0;i--)
	{
		for (int j = 0;j<line;j++)
		{
			sprintf(strname,"关卡选择界面/匹诺曹/%d.png",k);
			k++;
			CCSprite *tempSprite= CCSprite::create(strname);
			tempSprite->setAnchorPoint(ccp(0,0));
			tempSprite->setPosition(ccp(915/line * j+18,555/row *i+10));
			//tempSprite->setTag(302+k);
			//pra->addChild(tempSprite);
			father->addChild(tempSprite);
		}
	}
	father->setTag(104);
	pra->addChild(father);
	
}
//卖火柴的小女孩
void Appreciate::Picture4(int row,int line,CCNode *pra)
{
	int k = 1;
	char strname[64] = {0};
	
	CCNode *father = CCNode::create();
	for (int i = row-1;i>=0;i--)
	{
		for (int j = 0;j<line;j++)
		{
			sprintf(strname,"关卡选择界面/火柴/%d.png",k);
			k++;
			CCSprite *tempSprite= CCSprite::create(strname);
			tempSprite->setAnchorPoint(ccp(0,0));
			tempSprite->setPosition(ccp(915/line * j+25,555/row *i+23));
			//tempSprite->setTag(402+k);
			//pra->addChild(tempSprite);
			father->addChild(tempSprite);

		}
	}
	pra->addChild(father);
	father->setTag(105);
}

//神灯
void Appreciate::Picture5(int row,int line,CCNode *pra)
{
	int k = 1;
	char strname[64] = {0};
	CCNode *father = CCNode::create();
	for (int i = row-1;i>=0;i--)
	{
		for (int j = 0;j<line;j++)
		{
			sprintf(strname,"关卡选择界面/阿拉丁神灯/%d.png",k);
			k++;
			CCSprite *tempSprite= CCSprite::create(strname);
			tempSprite->setAnchorPoint(ccp(0,0));
			tempSprite->setPosition(ccp(915/line * j+25,555/row *i+23));
			father->addChild(tempSprite);
		}
	}
	father->setTag(106);
	pra->addChild(father);
}