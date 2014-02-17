#include "GameWin.h"
#include "cocos2d.h"
#include "resource1.h"
#include "config.h"
#include "GameScene.h"

using namespace cocos2d;

CCScene* GameWin::scene()
{
	CCScene *scene = NULL;
	scene->addChild(GameWin::create());
	return scene;
}

bool GameWin::init()
{
	if (!CCLayer::init())
	{
		return false;
	}

	CCSize winsize = CCDirector::sharedDirector()->getWinSize();

	CCSprite *background = CCSprite::create(s_winb);
	background->setAnchorPoint(ccp(0,0));
	background->setScale(1.5f);
	this->addChild(background);

	CCSprite *biankuang = CCSprite::create(s_login);
	biankuang->setAnchorPoint(ccp(0,0));
	biankuang->setPosition(ccp(0,0));
	//biankuang->setScale(1.2f);
	this->addChild(biankuang);

	CCSprite *win = CCSprite::create(s_win);
	win->setAnchorPoint(ccp(0,0));
	win->setPosition(ccp(winsize.width/3,winsize.height/2));
	win->setScale(0.6f);
	this->addChild(win);
	CCBlink *blink = CCBlink::create(1,3);
	win->runAction(CCRepeatForever::create(blink));

	CCMenuItemImage *Item = CCMenuItemImage::create(s_winbutton,s_winbutton1,NULL,this,menu_selector(GameWin::callback));

	CCMenu *menu = CCMenu::create(Item,NULL);
	menu->setAnchorPoint(ccp(0,0));
	menu->setPosition(ccp(winsize.width/2.5,winsize.height/3));
	this->addChild(menu);
	return true;
}
void GameWin::callback(CCObject *pseder)
{
	Config::shareConfig()->updateLevel();
	int level = Config::shareConfig()->getlevel2();
	++level;
	Config::shareConfig()->updateChose(level);

	CCScene *scene = CCScene::create();
	scene->addChild(GameScene::create());
	CCDirector::sharedDirector()->replaceScene(CCTransitionCrossFade::create(0.05f,scene));

}