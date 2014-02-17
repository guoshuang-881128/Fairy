#include "MainMenu.h"
#include "cocos2d.h"
#include "SimpleAudioEngine.h"
#include "resource1.h"
#include "config.h"
#include "Appreciate.h"
#include "Level.h"
//#include "GameWin.h"
#include "GameScene.h"


USING_NS_CC;
using namespace cocos2d;
using namespace CocosDenshion;


MainMenu::MainMenu()
{

}

MainMenu::~MainMenu()
{

}


CCScene* MainMenu::scene()
{
	CCScene * scene = NULL;
	scene = CCScene::create();
	MainMenu *layer = (MainMenu*)MainMenu::create();
	scene->addChild(layer);
	return scene;
}

bool MainMenu::init()
{
	if (!CCLayer::init())
	{
		return false;
	}
	winsize = CCDirector::sharedDirector()->getWinSize();
	//加载背景
	CCSprite *background = CCSprite::create(s_background);
	background->setAnchorPoint(ccp(0,0));
	this->addChild(background);
	//加载界面框
	CCSprite *login = CCSprite::create(s_login);
	login->setAnchorPoint(ccp(0,0));
	login->setPosition(ccp(0,0));
	this->addChild(login);

	//加载logo
	CCSprite *logo = CCSprite::create(s_logo);
	logo->setAnchorPoint(ccp(0,0));
	logo->setPosition(ccp(winsize.width/9,winsize.height/2));
	this->addChild(logo);

	
	CCMoveTo *moveleft = CCMoveTo::create(2,ccp(winsize.width/9-5,winsize.height/2));
	CCMoveTo *moveright = CCMoveTo::create(2,ccp(winsize.width/9+5,winsize.height/2));
	
	CCSequence *sequce =(CCSequence*) CCSequence::create(moveleft,moveright,NULL);
	CCRepeatForever *anction = CCRepeatForever::create(sequce);
	logo->runAction(anction);

	//创建菜单
	CCSprite *normalnewgame = CCSprite::create(s_startGame);
	CCSprite *selectednewgame = CCSprite::create(s_startgame);
	CCSprite *normalcontinuegame = CCSprite::create(s_containgame);
	CCSprite *selectedcontinuegame = CCSprite::create(s_containgame1);
	CCSprite *norappreciate = CCSprite::create(s_appreciate1);
	CCSprite *selappreciate = CCSprite::create(s_appreciate2);

	CCMenuItemSprite * menunewgame = CCMenuItemSprite::create(normalnewgame,selectednewgame,NULL,this,menu_selector(MainMenu::StarGame));
	CCMenuItemSprite *continuegame = CCMenuItemSprite::create(normalcontinuegame,selectedcontinuegame,NULL,this,menu_selector(MainMenu::ContinueGame));
	continuegame->setTag(12);
	CCMenuItemSprite *appreciate = CCMenuItemSprite::create(norappreciate,selappreciate,NULL,this,menu_selector(MainMenu::Appreciate1));
	appreciate->setTag(13);

	CCMenu *menu = CCMenu::create(menunewgame,continuegame,appreciate,NULL);
	menu->alignItemsVerticallyWithPadding(10);
	this->addChild(menu);
	menu->setAnchorPoint(ccp(0,0));
	CCSize size = normalnewgame->getContentSize();
	menu->setPosition(ccp(winsize.width/2+1.5*size.width,winsize.height/2-size.height/2));


	CCMenuItemImage *shop = CCMenuItemImage::create(s_store1,s_store2,NULL,this,menu_selector(MainMenu::Store));
	shop->setTag(15);
	CCMenuItemImage *set = CCMenuItemImage::create(s_seting1,s_seting2,NULL,this,menu_selector(MainMenu::Seting));
	set->setTag(16);

	CCMenu *setmenu = CCMenu::create(shop,set,NULL);
	setmenu->alignItemsHorizontallyWithPadding(10);
	setmenu->setAnchorPoint(ccp(0,0));
	setmenu->setPosition(ccp(winsize.width/2+1.5*size.width,winsize.height/5-size.height/5));
	this->addChild(setmenu);

	//加载设置菜单的隐藏菜单
	CCMenuItemImage *musicon = CCMenuItemImage::create(s_musicon,s_musicon);
	CCMenuItemImage *musicoff = CCMenuItemImage::create(s_musicoff,s_musicoff);
	CCMenuItemToggle *music = CCMenuItemToggle::createWithTarget(this,menu_selector(MainMenu::Music),musicon,musicoff,NULL);
	CCMenuItemToggle *sound = CCMenuItemToggle::createWithTarget(this,menu_selector(MainMenu::Sound),CCMenuItemImage::create(s_soundon,s_soundon),CCMenuItemImage::create(s_soundoff,s_soundoff),NULL);
	CCMenuItemImage *seting1 = CCMenuItemImage::create(s_set1,NULL);

	menuhide= CCMenu::create(music,sound,seting1,NULL);
	menuhide->setAnchorPoint(ccp(0,0));
	menuhide->setPosition(ccp(winsize.width/2+2.4*size.width,winsize.height/5-size.height/5));
	menuhide->alignItemsHorizontallyWithPadding(0);
//
	menuhide->setVisible(false);
	Config::shareConfig()->updateset(false);
	this->addChild(menuhide);

	if (Config::shareConfig()->GetMusic())
	{
		SimpleAudioEngine::sharedEngine()->playBackgroundMusic(s_music,true);
		
	}
	if (Config::shareConfig()->GetSound())
	{
		SimpleAudioEngine::sharedEngine()->playEffect(s_sound,true);
	}
	Config::shareConfig()->updateMusic(false);
	Config::shareConfig()->updateSound(false);
	return true;
}

void MainMenu::Appreciate1(cocos2d::CCObject *pSender)
{
	CCScene *scene = CCScene::create();
	Appreciate *layer = Appreciate::create();
	scene->addChild(layer);
	CCDirector::sharedDirector()->replaceScene(CCTransitionTurnOffTiles::create(0.5f,scene));
}

void MainMenu::StarGame(cocos2d::CCObject* pSender)
{
	CCScene *scene = CCScene::create();
	scene->addChild(Level::create());
	CCDirector::sharedDirector()->replaceScene(CCTransitionCrossFade::create(0.5f,scene));
}

void MainMenu::ContinueGame(cocos2d::CCObject *pSender)
{
	int le = Config::shareConfig()->GetLevel();
	Config::shareConfig()->updateChose(le);

	CCScene *scene = CCScene::create();
	scene->addChild(GameScene::create());
	CCDirector::sharedDirector()->replaceScene(CCTransitionCrossFade::create(0.05f,scene));
}

void MainMenu::Seting(cocos2d::CCObject *pSender)
{
	if (! Config::shareConfig()->GetSetState())
	{
		menuhide->setVisible(true);
		Config::shareConfig()->updateset(true);
	}
	else
	{
	 menuhide->setVisible(false);
	Config::shareConfig()->updateset(false);
	}
	
}                                                                                                                                                                                                                                                                                                                                                                                              

void MainMenu::Store(cocos2d::CCObject *pSender)
{

}
void MainMenu::Music(cocos2d::CCObject *pSender)
{
	if (Config::shareConfig()->GetMusic())
	{
		SimpleAudioEngine::sharedEngine()->resumeBackgroundMusic();
		Config::shareConfig()->updateMusic(false);
	}
	else
	{
		SimpleAudioEngine::sharedEngine()->pauseBackgroundMusic();
		Config::shareConfig()->updateMusic(true);
	}

	
	
}

void MainMenu::Sound(cocos2d::CCObject *pSender)
{
	if (Config::shareConfig()->GetSound())
	{
		SimpleAudioEngine::sharedEngine()->resumeAllEffects();
		Config::shareConfig()->updateSound(false);
	}
	else
	{
		SimpleAudioEngine::sharedEngine()->pauseAllEffects();
		Config::shareConfig()->updateSound(true);
	}
}