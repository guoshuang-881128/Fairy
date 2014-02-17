#include "GameOver.h"
#include "resource1.h"
#include "MainMenu.h"

USING_NS_CC;
using namespace cocos2d;
GameOver::GameOver()
{

}

GameOver::~GameOver()
{

}

CCScene* GameOver::scene()
{
	CCScene *scene = CCScene::create();
	scene->addChild(GameOver::create());
	return scene;
}

bool GameOver::init()
{
	if (!CCLayer::init())
	{
		return false;
	}
	CCSize winsize = CCDirector::sharedDirector()->getWinSize();
	CCSprite *background = CCSprite::create(s_gameoverb);
	background->setAnchorPoint(ccp(0,0));
	this->addChild(background);
	background->setScale(1.5f);


	CCSprite *lost = CCSprite::create(s_lost);
	lost->setAnchorPoint(ccp(0,0));
	lost->setPosition(ccp(winsize.width/4,winsize.height/1.5));
	this->addChild(lost);
	lost->setScale(0.8f);

	CCSprite *timeup = CCSprite::create(s_timeup);
	timeup->setAnchorPoint(ccp(0,0));
	timeup->setPosition(ccp(winsize.width/4,winsize.height/3));
	this->addChild(timeup);
	timeup->setScale(0.7f);

	CCBlink *bink = CCBlink::create(1,3);
	timeup->runAction(CCRepeatForever::create(bink));

	//back
	CCLabelBMFont *font = CCLabelBMFont::create("GO BACK",s_font);
	CCMenuItemLabel *backf = CCMenuItemLabel::create(font,this,menu_selector(GameOver::backmenu));

	//backf->setScale(0.6f);
	CCActionInterval *fadeIn = CCFadeTo::create(1, 152);
	CCActionInterval *fadeOut = CCFadeTo::create(1, 255);
	CCEaseSineInOut *ease1 = CCEaseSineInOut::create(fadeIn);
	CCEaseSineInOut *ease2 = CCEaseSineInOut::create(fadeOut);
	CCFiniteTimeAction *seq = CCSequence::create(ease1, ease2, NULL);
	// 这里也是，参数必须强转，否则NDK编译不过
	backf->runAction(CCRepeatForever::create((CCActionInterval*)seq));

	CCMenu *menu = CCMenu::create(backf,NULL);
	menu->setAnchorPoint(ccp(0,0));
	this->addChild(menu);
	menu->setPosition(ccp(winsize.width/2,winsize.height/4));
	return true;
}

void GameOver::backmenu(CCObject * pSender)
{
	CCScene *scene = CCScene::create();
	scene->addChild(MainMenu::create());
	CCDirector::sharedDirector()->replaceScene(CCTransitionPageTurn::create(0.5f,scene,true));
}