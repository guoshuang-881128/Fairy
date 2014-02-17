#include "Level.h"
#include "cocos2d.h"
#include "Appreciate.h"
#include "resource1.h"
#include "MainMenu.h"
#include "config.h"
#include "GameScene.h"

USING_NS_CC;
using namespace cocos2d;

Level::Level()
{
	num =1;
}

Level::~Level()
{

}


CCScene *Level::scene()
{
	CCScene *scene = NULL;
	scene = CCScene::create();
	Level *layer = (Level*)Level::create();
	scene->addChild(layer);
	return scene;
}


bool Level::init()
{
	if (!CCLayer::init())
	{
		return false;
	}
	CCSize winsize = CCDirector::sharedDirector()->getWinSize();


	//���ر߿�
	CCSprite * backgound = CCSprite::create(s_bild);
	backgound->setAnchorPoint(ccp(0,0));
	backgound->setPosition(ccp(0,0));
	this->addChild(backgound);
	
	//���ذ�ť

	CCMenuItemImage *up = CCMenuItemImage::create(s_up,s_up1,NULL,this,menu_selector(Level::Up));
	CCMenuItemImage *down = CCMenuItemImage::create(s_down,s_down1,NULL,this,menu_selector(Level::Down));
	CCMenuItemImage *back = CCMenuItemImage::create(s_backmenu1,s_backmenu2,NULL,this,menu_selector(Level::Backmenu));
	CCMenuItemImage *store1 = CCMenuItemImage::create(s_store1,s_store2,this,menu_selector(Level::Store));
	CCMenuItemImage *app = CCMenuItemImage::create(s_appreciate1,s_appreciate2,NULL,this,menu_selector(Level::Appre));
	app->setScale(0.8f);
	//back->setScale(0.9f);
	//back->setPosition(ccp(-winsize.width/1.5,0));
	//�����������������꣬������û���óɹ�������̫���
	CCMenu *menu = CCMenu::create(up,back,store1,app,down,NULL);
	menu->setAnchorPoint(ccp(0,0));
	menu->alignItemsHorizontallyWithPadding(80);
	menu->setPosition(ccp(winsize.width/2,winsize.height/19));
	this->addChild(menu);

	//��ʼ���ؿ�
	CCSprite *snow = CCSprite::create(s_baixue);
	snow->setAnchorPoint(ccp(0,0));
	snow->setPosition(ccp(0,0));
	this->addChild(snow);
	//size = snow->getContentSize();
    Picture1(3,3,this);

	int level =Config::shareConfig()->GetLevel();
	updateUI1(level);
	//��������
	this->setTouchEnabled(true);

	//�Զ�����
	//this->schedule(schedule_selector(Level::update), 0.1f);//���´���
	return true;
}

void Level::Up(CCObject *pSender)
{
	char *temp;
	num--;
	int level = Config::shareConfig()->GetLevel();
	if (num <= 0)
	{
		num = 5;
	}
	switch(num)
	{
	case 1:
		this->removeChildByTag(203,true);
		this->removeChildByTag(201,true);
		this->removeChildByTag(302,true);
		CCTextureCache::sharedTextureCache()->removeUnusedTextures();
		temp = (char *)s_baixue;
		changeback(temp);
		Picture1(3,3,this);
		updateUI1(level);
		break;
	case 2:
		this->removeChildByTag(204,true);
		this->removeChildByTag(201,true);
		this->removeChildByTag(303,true);
		CCTextureCache::sharedTextureCache()->removeUnusedTextures();
		temp = (char *)s_gray;
		changeback(temp);
		Picture2(3,4,this);
		updateUI2(level);
		break;
	case 3:
		this->removeChildByTag(205,true);
		this->removeChildByTag(201,true);
		this->removeChildByTag(304,true);
		CCTextureCache::sharedTextureCache()->removeUnusedTextures();
		temp = (char *)s_pinocao;
		changeback(temp);
		Picture3(4,4,this);
		updateUI3(level);
		break;
	case 4:
		this->removeChildByTag(206,true);
		this->removeChildByTag(201,true);
		this->removeChildByTag(305,true);
		CCTextureCache::sharedTextureCache()->removeUnusedTextures();
		temp = (char *)s_huochai;
		changeback(temp);
		Picture4(4,5,this);
		updateUI4(level);
		break;
	case 5:
		this->removeChildByTag(202,true);
		this->removeChildByTag(201,true);
		this->removeChildByTag(301,true);
		CCTextureCache::sharedTextureCache()->removeUnusedTextures();
		temp = (char *)s_light;
		changeback(temp);
		Picture5(5,5,this);
		updateUI5(level);
		break;	
	}	
	
}
void Level::Down(CCObject *pSender)
{
	char *temp;
	num++;
	int level =Config::shareConfig()->GetLevel();

	if (num > 5)
	{
		num = 1;
	}
	switch(num)
	{
	case 1:
		this->removeChildByTag(206,true);
		this->removeChildByTag(201,true);
		this->removeChildByTag(305,true);
		CCTextureCache::sharedTextureCache()->removeUnusedTextures();
		temp = (char *)s_baixue;
		changeback(temp);
		Picture1(3,3,this);
		updateUI1(level);
		break;
	case 2:
		this->removeChildByTag(202,true);
		this->removeChildByTag(201,true);
		this->removeChildByTag(301,true);
		CCTextureCache::sharedTextureCache()->removeUnusedTextures();
		temp = (char *)s_gray;
		changeback(temp);
		Picture2(3,4,this);
		updateUI2(level);
		break;
	case 3:
		this->removeChildByTag(203,true);
		this->removeChildByTag(201,true);
		this->removeChildByTag(302,true);
		CCTextureCache::sharedTextureCache()->removeUnusedTextures();
		temp = (char *)s_pinocao;
		changeback(temp);
		Picture3(4,4,this);
		updateUI3(level);
		break;
	case 4:
		this->removeChildByTag(204,true);
		this->removeChildByTag(201,true);
		this->removeChildByTag(303,true);
		CCTextureCache::sharedTextureCache()->removeUnusedTextures();
		temp = (char *)s_huochai;
		changeback(temp);
		Picture4(4,5,this);
		updateUI4(level);
		break;
	case 5:
		this->removeChildByTag(205,true);
		this->removeChildByTag(201,true);
		this->removeChildByTag(304,true);
		CCTextureCache::sharedTextureCache()->removeUnusedTextures();
		temp = (char *)s_light;
		changeback(temp);
		Picture5(5,5,this);
		updateUI5(level);
		break;	
	}	
}

void Level::Store(CCObject *pSender)
{
	
}

void Level::Backmenu(CCObject *pSender)
{
	CCScene *scene = CCScene::create();
	scene->addChild(MainMenu::create());
	CCDirector::sharedDirector()->replaceScene( CCTransitionPageTurn::create(0.5f,scene,false));

}

void Level::changeback(char *p)
{
	CCSprite *background = CCSprite::create(p);
	background->setAnchorPoint(ccp(0,0));
	background->setPosition(ccp(0,0));
	background->setTag(201);
	this->addChild(background);
}

void Level::Appre(CCObject *pSender)
{
	CCScene *scene = CCScene::create();
	scene->addChild(Appreciate::create());
	CCDirector::sharedDirector()->replaceScene( CCTransitionSlideInR::create(0.5f,scene));
}

void Level::registerWithTouchDispatcher()
{
	CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this,0,true);
}

bool Level::ccTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)
{
	return true;
}


void Level::ccTouchEnded(cocos2d::CCTouch *pTouch,cocos2d:: CCEvent *pEvent)
{
	CCPoint pos = pTouch->getLocationInView();
	pos = CCDirector::sharedDirector()->convertToGL(pos);
	checkRect(pos,3,3);
}

void Level::ccTouchMoved(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)
{

}

//��ѩ����
void Level::Picture1(int row,int line,CCNode *pra)
{
	int k = 1;
	char strname[64] = {0};
	//�ٶ��ǵ�ͼ�����飬һ��һ������ͼ
	CCNode *father = CCNode::create();
	for (int i = row-1;i>=0;i--)
	{
		for (int j = 0;j<line;j++)
		{
			sprintf(strname,"�ؿ�ѡ�����/ѩ�ڰ�/%d.png",k);
			
			CCSprite *tempSprite = CCSprite::create(strname);
			tempSprite->setAnchorPoint(ccp(0,0));
			tempSprite->setPosition(ccp(915/line * j+20,555/row *i-10));
			//pra->addChild(tempSprite);
			father->addChild(tempSprite);
			pos1[k-1] = tempSprite->getPosition();
			//pos1[k-1] = ccp(915/line * j+20,555/row *i-10);
			k++;
		}
	}
	father->setTag(202);
	pra->addChild(father);
}
//�ҹ���
void Level::Picture2(int row,int line,CCNode *pra)
{
	int k = 1;
	char strname[64] = {0};
	CCNode *father = CCNode::create();
	for (int i = row-1;i>=0;i--)
	{
		for (int j = 0;j<line;j++)
		{
			sprintf(strname,"�ؿ�ѡ�����/�ҹ��� �ڰ�/%d.png",k);
			
			CCSprite *tempSprite = CCSprite::create(strname);
			tempSprite->setAnchorPoint(ccp(0,0));
			tempSprite->setPosition(ccp(915/line * j+20,555/row *i-10));
			//pra->addChild(tempSprite);
			father->addChild(tempSprite);
			pos1[k-1] = tempSprite->getPosition();
				k++;
		}
	}
	father->setTag(203);
	pra->addChild(father);
}
//ƥŵ��
void Level::Picture3(int row,int line,CCNode *pra)
{
	int k = 1;
	char strname[64] = {0};
	CCNode *father = CCNode::create();
	for (int i = row-1;i>=0;i--)
	{
		for (int j = 0;j<line;j++)
		{
			sprintf(strname,"�ؿ�ѡ�����/ƥŵ�ܺڰ�/%d.png",k);
			
			CCSprite *tempSprite = CCSprite::create(strname);
			tempSprite->setAnchorPoint(ccp(0,0));
			tempSprite->setPosition(ccp(915/line * j+18,555/row *i+10));
			father->addChild(tempSprite);
			//pra->addChild(tempSprite);
			pos1[k-1] = tempSprite->getPosition();
			k++;
		}
	}
	father->setTag(204);
	pra->addChild(father);
}
//������СŮ��
void Level::Picture4(int row,int line,CCNode *pra)
{
	int k = 1;
	char strname[64] = {0};
	CCNode *app = CCNode::create();
	for (int i = row-1;i>=0;i--)
	{
		for (int j = 0;j<line;j++)
		{
			sprintf(strname,"�ؿ�ѡ�����/���ڰ�/%d.png",k);
			
			CCSprite *tempSprite = CCSprite::create(strname);
			tempSprite->setAnchorPoint(ccp(0,0));
			tempSprite->setPosition(ccp(915/line * j+25,555/row *i+23));
			//pra->addChild(tempSprite);
			app->addChild(tempSprite);
			pos1[k-1] = tempSprite->getPosition();
			k++;
		}
	}
	app->setTag(205);
	pra->addChild(app);
}

//���
void Level::Picture5(int row,int line,CCNode *pra)
{
	int k = 1;
	char strname[64] = {0};
	CCNode* father = CCNode::create();
	for (int i = row-1;i>=0;i--)
	{
		for (int j = 0;j<line;j++)
		{
			sprintf(strname,"�ؿ�ѡ�����/��������ƺڰ�/%d.png",k);
			//k++;
			CCSprite *tempSprite = CCSprite::create(strname);
			tempSprite->setAnchorPoint(ccp(0,0));
			tempSprite->setPosition(ccp(915/line * j+25,555/row *i+23));
			//pra->addChild(tempSprite);
			father->addChild(tempSprite);
			pos1[k-1] = tempSprite->getPosition();
			k++;
		}
	}
	father->setTag(206);
	pra->addChild(father);
}
//���°�ѩ����
void Level::updateUI1(int level)
{
	char strname[64] = {0};
	//int level1 = level;
	CCNode *father = CCNode::create();
	for (int i =0;i<level;i++)
	{
		////�����ǰ�ؿ�����
		//if (i == level1 )
		{
			sprintf(strname,"�ؿ�ѡ�����/ѩ/%d.png",i+1);
			CCSprite *temp = CCSprite::create(strname);
			temp->setAnchorPoint(ccp(0,0));
			temp->setPosition(pos1[i]);
			father->addChild(temp);
			//this->addChild(temp);
		}
		
	}
	father->setTag(301);
	this->addChild(father);
}

//���»ҹ���

void Level::updateUI2(int level)
{
	char strname[64] = {0};
	//int level1 = level-1;
	CCNode *father = CCNode::create();
	for (int i =0;i<level;i++)
	{
		//�����ǰ�ؿ�����
		//if (i == level1 )
		{
			sprintf(strname,"�ؿ�ѡ�����/�ҹ���/%d.png",i+1);
			CCSprite *temp = CCSprite::create(strname);
			temp->setAnchorPoint(ccp(0,0));
			temp->setPosition(pos1[i]);
			//this->addChild(temp);
			father->addChild(temp);
		}
	}
	father->setTag(302);
	this->addChild(father);
}
//���°������
void Level::updateUI5(int level)
{
	char strname[64] = {0};
	//int level1 = level-1;
	CCNode *father = CCNode::create();
	for (int i =0;i<level;i++)
	{
		//�����ǰ�ؿ�����
		//if (i == level1 )
		{
			sprintf(strname,"�ؿ�ѡ�����/���������/%d.png",i+1);
			CCSprite *temp = CCSprite::create(strname);
			temp->setAnchorPoint(ccp(0,0));
			temp->setPosition(pos1[i]);
			//this->addChild(temp);
			father->addChild(temp);
		}
	}
	this->addChild(father);
	father->setTag(303);
}
//���»��
void Level::updateUI4(int level)
{
	char strname[64] = {0};
	//int level1 = level-1;
	CCNode *father = CCNode::create();
	for (int i =0;i<level;i++)
	{
		//�����ǰ�ؿ�����
		//if (i == level1 )
		{
			sprintf(strname,"�ؿ�ѡ�����/���/%d.png",i+1);
			CCSprite *temp = CCSprite::create(strname);
			temp->setAnchorPoint(ccp(0,0));
			temp->setPosition(pos1[i]);
			//this->addChild(temp);
			father->addChild(temp);
		}
	}
	father->setTag(304);
	this->addChild(father);
}
//����ƥŵ��
void Level::updateUI3(int level)
{
	char strname[64] = {0};
	//int level1 = level-1;
	CCNode *father = CCNode::create();
	for (int i =0;i<level;i++)
	{
		//�����ǰ�ؿ�����
		//if (i == level1 )
		{
			sprintf(strname,"�ؿ�ѡ�����/ƥŵ��/%d.png",i+1);
			CCSprite *temp = CCSprite::create(strname);
			temp->setAnchorPoint(ccp(0,0));
			temp->setPosition(pos1[i]);
			//this->addChild(temp);
			father->addChild(temp);
		}
	}
	father->setTag(305);
	this->addChild(father);
}

void Level::update(float dt)
{
	int level = Config::shareConfig()->GetLevel();
	//updateUI1(level);
	/*updateUI2(level);
	updateUI3(level);
	updateUI4(level);
	updateUI5(level);*/
}
//����ֻдһ���ؿ���
void Level::checkRect(CCPoint point,int row,int line)
{
	CCPoint pos = point;
	CCRect rect;

	//������ѭ������ʽ�ж��Ƿ�������������棬������ΪͼƬ�ĳ��������⣬����ֻ��дֱ������
	int level = Config::shareConfig()->GetLevel();

	for (int i = 0;i < row * line;i++)
	{
		//�������������ж�������
		rect = CCRectMake(pos1[i].x,pos1[i].y,915/line,549/row);
		if (rect.containsPoint(pos)&& i <= level)
		{
			level = i +1;
			Config::shareConfig()->updateChose(level);
			CCScene * scene = CCScene::create();
			scene->addChild(GameScene::create());
			CCDirector::sharedDirector()->replaceScene(CCTransitionCrossFade::create(0.5f,scene));
			
		}
	}
}