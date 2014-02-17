#include "GameScene.h"
#include "SimpleAudioEngine.h"
#include "cocos2d.h"
#include "resource1.h"
#include "config.h"
#include "MainMenu.h"
#include "GameOver.h"
#include "Blick.h"
#include "GameWin.h"

USING_NS_CC;
using namespace cocos2d;
using namespace CocosDenshion;

GameScene::GameScene()
{

}

GameScene::~GameScene()
{
	
}

CCScene* GameScene::scene()
{
	CCScene *scene = CCScene::create();
	scene->addChild(GameScene::create());
	return scene;
}

bool GameScene::init()
{
	if (!CCLayer::init())
	{
		return false;
	}

	winsize = CCDirector::sharedDirector()->getWinSize();
	//加载背景图
	CCSprite *backg = CCSprite::create(s_gameback);
	backg->setAnchorPoint(ccp(0,0));
	backg->setPosition(ccp(0,0));
	this->addChild(backg);

	//预加载水晶
	AncationJing();
	//加载水晶
	CCSprite *jing = CCSprite::create(s_jing1,CCRectMake(0,0,116,94));
	jing->setAnchorPoint(ccp(0,0));
	jing->setPosition(ccp(winsize.width/10,winsize.height/1.2));
	CCAnimation *antion1 = CCAnimationCache::sharedAnimationCache()->animationByName("shuijing");
	jing->runAction(CCRepeatForever::create(CCAnimate::create(antion1)));
	this->addChild(jing);


	//加载边框
	CCSprite *backk = CCSprite::create(s_biankuang);
	backk->setAnchorPoint(ccp(0,0));
	backk->setPosition(ccp(0,0));
	this->addChild(backk);

	
	//加载叶子

	CCSprite *leaf = CCSprite::create(s_leaf);
	leaf->setAnchorPoint(ccp(0,0));
	leaf->setPosition(ccp(winsize.width/10,winsize.height));
	this->addChild(leaf);

	//预加载精灵
	AncationSprite();
	

	CCSprite *sprite = CCSprite::create(s_sprite3,CCRectMake(0,0,150,140));
	sprite->setAnchorPoint(ccp(0,0));
	sprite->setPosition(ccp(winsize.width/9,winsize.height/1.5));
	this->addChild(sprite);
	CCAnimation *anction = CCAnimationCache::sharedAnimationCache()->animationByName("sprite");
	sprite->runAction(CCRepeatForever::create(CCAnimate::create(anction)));
	sprite->setScale(0.8f);

	//预加载南瓜
	AncationNan();
	CCSprite *sprite3 = CCSprite::create(s_nangua,CCRectMake(0,0,150,140));
	sprite3->setAnchorPoint(ccp(0,0));
	sprite3->setPosition(ccp(winsize.width/8.5,winsize.height/2.5));
	this->addChild(sprite3);
	CCAnimation *anction4 = CCAnimationCache::sharedAnimationCache()->animationByName("nangua");
	sprite3->runAction(CCRepeatForever::create(CCAnimate::create(anction4)));
	sprite3->setScale(0.7f);
	//预加载爆炸
	AncationBoo();
	
	//加载返回
	CCMenuItemImage *buttonb = CCMenuItemImage::create(s_back,s_back1,NULL,this,menu_selector(GameScene::back));
	CCMenuItemImage *buttons = CCMenuItemImage::create(s_restart,s_restart1,NULL,this,menu_selector(GameScene::restart));
	
	CCMenu *menu = CCMenu::create(buttonb,buttons,NULL);
	menu->setAnchorPoint(ccp(0,0));
	menu->setPosition(ccp(winsize.width/8,winsize.height/3.5));
	menu->alignItemsVerticallyWithPadding(10);
	menu->setScale(0.9f);
	this->addChild(menu);

	//

	CCMenuItemImage *shop = CCMenuItemImage::create(s_store1,s_store2,NULL,this,menu_selector(GameScene::Store));
	shop->setTag(15);
	CCMenuItemImage *set = CCMenuItemImage::create(s_seting1,s_seting2,NULL,this,menu_selector(GameScene::Seting));
	set->setTag(16);

	CCMenu *setmenu = CCMenu::create(shop,set,NULL);
	setmenu->alignItemsHorizontallyWithPadding(10);
	setmenu->setAnchorPoint(ccp(0,0));
	setmenu->setPosition(ccp(winsize.width/8,winsize.height/7.5));
	this->addChild(setmenu);

	//加载设置菜单的隐藏菜单
	CCMenuItemImage *musicon = CCMenuItemImage::create(s_musicon,s_musicon);
	CCMenuItemImage *musicoff = CCMenuItemImage::create(s_musicoff,s_musicoff);
	CCMenuItemToggle *music = CCMenuItemToggle::createWithTarget(this,menu_selector(GameScene::Music),musicon,musicoff,NULL);
	CCMenuItemToggle *sound = CCMenuItemToggle::createWithTarget(this,menu_selector(GameScene::Sound),CCMenuItemImage::create(s_soundon,s_soundon),CCMenuItemImage::create(s_soundoff,s_soundoff),NULL);
	CCMenuItemImage *seting1 = CCMenuItemImage::create(s_set1,NULL);
	size = musicon->getContentSize();
	menuhide= CCMenu::create(music,sound,seting1,NULL);
	menuhide->setAnchorPoint(ccp(0,0));
	menuhide->setPosition(ccp(winsize.width/4.5+size.width,winsize.height/7.5));
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

	//加载时间条
	CCSprite *time1 = CCSprite::create(s_time1);
	time1->setAnchorPoint(ccp(0,0));
	time1->setPosition(ccp(winsize.width/4.5,16));
	time1->setScaleX(0.5f);
	this->addChild(time1);
	CCSprite *time2 = CCSprite::create(s_time2);
	time2->setAnchorPoint(ccp(0,0));
	time2->setPosition(ccp(winsize.width/4.5,16));
	time2->setScaleX(0.5f);
	this->addChild(time2);
	time3 = CCSprite::create(s_time3);
	
	
	
	
	this->scheduleUpdate();
	this->setTouchEnabled(true);

	//加载宝石
	blick = Blick::create();
	this->addChild(blick);
	//blick->setScale(0.5f);
	Newlevel();
	schedule(schedule_selector(GameScene::Check),0.01f);
	schedule(schedule_selector(GameScene::Checksucess),0.05f);
	return true;
}

void GameScene::update(float dt)
{
	int a = proesstimer->getPercentage();
	if (a == 100)
	{
		CCScene *scene = CCScene::create();
		scene->addChild(GameOver::create());
		CCDirector::sharedDirector()->replaceScene(CCTransitionPageTurn::create(0.5f,scene,true));
	}
	
}

void GameScene::Check(float dt)
{
	blick->CheckBlick();
	this->removeChildByTag(199,true);
	CCTextureCache::sharedTextureCache()->removeUnusedTextures();
	blick->DrawBlick(this);
}

void GameScene::Checksucess(float dt)
{
	if (blick->CheckSucess())
	{
		CCScene *scene = CCScene::create();
		scene->addChild(GameWin::create());
		CCDirector::sharedDirector()->replaceScene(CCTransitionProgressVertical::create(0.1f,scene));
	}
}
//每关进行的时间不同，所以时间条的速度也不同
void GameScene::SetProessTimer(int time)
{
	//time3->setVisible(true);
	
	proesstimer = CCProgressTimer::create(time3);
	proesstimer->setType(kCCProgressTimerTypeBar);
	proesstimer->setMidpoint(ccp(0.5,0));
	proesstimer->setBarChangeRate(ccp(0,1));
	proesstimer->setPosition(ccp(winsize.width/4.2-2,340));
	proesstimer->setPercentage(0);
	//proesstimer->runAction(CCRepeatForever::create(p));
	CCProgressTo *p =CCProgressTo::actionWithDuration(time,100);
	proesstimer->setScaleX(0.4f);
	proesstimer->runAction(p);
	this->addChild(proesstimer);

}

void GameScene::Newlevel()
{
	int l = Config::shareConfig()->getlevel2();
	switch(l)
	{
	case 1:
		blick->CreateBlick(4,4,8);
		blick->DrawBlick(this);
		SetProessTimer(2022);
		break;
	case 2:
		blick->CreateBlick(4,5,8);
		blick->DrawBlick(this);
		SetProessTimer(30);
		break;
	case 3:
		blick->CreateBlick(4,6,8);
		blick->DrawBlick(this);
		SetProessTimer(35);
		break;
	case 4:
		blick->CreateBlick(4,7,9);
		blick->DrawBlick(this);
		SetProessTimer(45);
		break;
	case 5:
		blick->CreateBlick(6,7,9);
		blick->DrawBlick(this);
		SetProessTimer(55);
		break;
	case 6:
		blick->CreateBlick(6,8,10);
		blick->DrawBlick(this);
		SetProessTimer(65);
		break;
	case 7:
		blick->CreateBlick(8,7,10);
		blick->DrawBlick(this);
		SetProessTimer(75);
		break;
	case 8:
		blick->CreateBlick(8,9,10);
		blick->DrawBlick(this);
		SetProessTimer(85);
		break;
	case 9:
		blick->CreateBlick(8,10,10);
		blick->DrawBlick(this);
		SetProessTimer(90);
		break;
		
	}
}


void GameScene::registerWithTouchDispatcher()
{
	CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this,-9999,false);
}

bool GameScene::ccTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)
{
	posFirst = pTouch->getLocationInView();
	posFirst = CCDirector::sharedDirector()->convertToGL(posFirst);
	blick->Move(posFirst);
	return true;
}

void GameScene::ccTouchEnded(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)
{
	CCPoint p = pTouch->getLocationInView();
	p = CCDirector::sharedDirector()->convertToGL(p);
	//向上移动
	 
	if (p.y - posFirst.y > 56/2)
	{
		Moveblick(p,1);
	}
	if (p.y - posFirst.y <-56/2)
	{
		Moveblick(p,2);
	}

	if (p.x - posFirst.x < -56/2)
	{
		Moveblick(p,3);
	}
	if (p.x - posFirst.x > 56/2)
	{
		Moveblick(p,4);
	}

}

void GameScene::ccTouchMoved(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)
{
	//CCPoint p = pTouch->getLocationInView();
	//p = CCDirector::sharedDirector()->convertToGL(p);
	////向上移动
	//if (p.y - posFirst.y >=56/2)
	//{
	//	Moveblick(p,1);
	//}
	//if (posFirst.y - p.y >= 56/2)
	//{
	//	Moveblick(p,2);
	//}

	//if (p.x -  posFirst.x <=-56/2)
	//{
	//	Moveblick(p,3);
	//}
	//if (p.x - posFirst.x >= 56/2)
	//{
	//	Moveblick(p,4);
	//}
	
}

void GameScene::Moveblick(CCPoint p,int dir)
{
	if (blick->MoveBlick(p,dir))
	{
		this->removeChildByTag(1789,true);
		this->removeChildByTag(199,true);
		CCTextureCache::sharedTextureCache()->removeUnusedTextures();
		blick->DrawBlick(this);
	}
	
	
}

void GameScene::AncationSprite()
{
	CCRect rect = CCRectMake(0,0,150,140);
	CCTextureCache *cache = CCTextureCache::sharedTextureCache();
	CCTexture2D *text1 = cache->addImage(s_sprite1);
	CCTexture2D *text2 = cache->addImage(s_sprite2);
	CCTexture2D *text3 = cache->addImage(s_sprite3);

	CCSpriteFrame *sprite1 = CCSpriteFrame::createWithTexture(text1,rect);
	CCSpriteFrame *sprite2 = CCSpriteFrame::createWithTexture(text2,rect);
	CCSpriteFrame *sprite3 = CCSpriteFrame::createWithTexture(text3,rect);

	CCArray * ani_arry = CCArray::create();
	ani_arry->addObject(sprite3);
	ani_arry->addObject(sprite2);
	ani_arry->addObject(sprite1);

	CCAnimation *aniction = CCAnimation::createWithSpriteFrames(ani_arry,0.5f);
	CCAnimationCache::sharedAnimationCache()->addAnimation(aniction,"sprite");
}

void GameScene::AncationJing()
{
	CCRect rect = CCRectMake(0,0,116,94);
	CCTextureCache *cache = CCTextureCache::sharedTextureCache();
	CCTexture2D *text1 = cache->addImage(s_jing1);
	CCTexture2D *text2 = cache->addImage(s_jing2);
	CCTexture2D *text3 = cache->addImage(s_jing3);
	CCTexture2D *text4 = cache->addImage(s_jing4);
	CCTexture2D *text5 = cache->addImage(s_jing5);
	CCTexture2D *text6 = cache->addImage(s_jing6);
	CCTexture2D *text7 = cache->addImage(s_jing7);

	CCSpriteFrame *frame1 = CCSpriteFrame::createWithTexture(text1,rect);
	CCSpriteFrame *frame2 = CCSpriteFrame::createWithTexture(text2,rect);
	CCSpriteFrame *frame3 = CCSpriteFrame::createWithTexture(text3,rect);
	CCSpriteFrame *frame4 = CCSpriteFrame::createWithTexture(text4,rect);
    CCSpriteFrame *frame5 = CCSpriteFrame::createWithTexture(text5,rect);
	CCSpriteFrame *frame6 = CCSpriteFrame::createWithTexture(text6,rect);
	CCSpriteFrame *frame7 = CCSpriteFrame::createWithTexture(text7,rect);

	CCArray *ani_arry = CCArray::create();
	ani_arry->addObject(frame1);
	ani_arry->addObject(frame2);
	ani_arry->addObject(frame3);
	ani_arry->addObject(frame4);
	ani_arry->addObject(frame5);
	ani_arry->addObject(frame6);
	ani_arry->addObject(frame7);

	CCAnimation *anction3 = CCAnimation::createWithSpriteFrames(ani_arry,0.5f);
	CCAnimationCache::sharedAnimationCache()->addAnimation(anction3,"shuijing");
}

void GameScene::AncationBoo()
{
	CCRect rect = CCRectMake(0,0,190,190);
	CCTextureCache *cache = CCTextureCache::sharedTextureCache();
	CCTexture2D *text1 = cache->addImage(s_boo1);
	CCTexture2D *text2 = cache->addImage(s_boo2);
	CCTexture2D *text3 = cache->addImage(s_boo3);
	CCTexture2D *text4 = cache->addImage(s_boo4);
	CCTexture2D *text5 = cache->addImage(s_boo5);
	CCTexture2D *text6 = cache->addImage(s_boo6);
	CCTexture2D *text7 = cache->addImage(s_boo7);
	CCTexture2D *text8 = cache->addImage(s_boo8);
	CCTexture2D *text9 = cache->addImage(s_boo9);
	CCTexture2D *text10 = cache->addImage(s_boo10);

	CCSpriteFrame *frame1 = CCSpriteFrame::createWithTexture(text1,rect);
	CCSpriteFrame *frame2 = CCSpriteFrame::createWithTexture(text2,rect);
	CCSpriteFrame *frame3 = CCSpriteFrame::createWithTexture(text3,rect);
	CCSpriteFrame *frame4 = CCSpriteFrame::createWithTexture(text4,rect);
	CCSpriteFrame *frame5 = CCSpriteFrame::createWithTexture(text5,rect);
	CCSpriteFrame *frame6 = CCSpriteFrame::createWithTexture(text6,rect);
	CCSpriteFrame *frame7 = CCSpriteFrame::createWithTexture(text7,rect);
	CCSpriteFrame *frame8 = CCSpriteFrame::createWithTexture(text8,rect);
	CCSpriteFrame *frame9 = CCSpriteFrame::createWithTexture(text9,rect);
	CCSpriteFrame *frame10 = CCSpriteFrame::createWithTexture(text10,rect);

	CCArray *ani_arry = CCArray::create();
	ani_arry->addObject(frame1);
	ani_arry->addObject(frame2);
	ani_arry->addObject(frame3);
	ani_arry->addObject(frame4);
	ani_arry->addObject(frame5);
	ani_arry->addObject(frame6);
	ani_arry->addObject(frame7);
	ani_arry->addObject(frame8);
	ani_arry->addObject(frame9);
	ani_arry->addObject(frame10);

	CCAnimation *anction3 = CCAnimation::createWithSpriteFrames(ani_arry,0.5f);
	CCAnimationCache::sharedAnimationCache()->addAnimation(anction3,"BOO");
}
void GameScene::AncationNan()
{
	CCRect rect = CCRectMake(0,0,150,140);
	CCTextureCache *cache = CCTextureCache::sharedTextureCache();
	CCTexture2D *text1 = cache->addImage(s_nangua);
	CCTexture2D *text2 = cache->addImage(s_nangua1);
	

	CCSpriteFrame *sprite1 = CCSpriteFrame::createWithTexture(text1,rect);
	CCSpriteFrame *sprite2 = CCSpriteFrame::createWithTexture(text2,rect);
	

	CCArray * ani_arry = CCArray::create();
	
	ani_arry->addObject(sprite2);
	ani_arry->addObject(sprite1);

	CCAnimation *aniction = CCAnimation::createWithSpriteFrames(ani_arry,0.5f);
	CCAnimationCache::sharedAnimationCache()->addAnimation(aniction,"nangua");
}

void GameScene::back(CCObject *pSender)
{
	CCScene *scene = CCScene::create();
	scene->addChild(MainMenu::create());
	CCDirector::sharedDirector()->replaceScene(CCTransitionPageTurn::create(0.5f,scene,false));
}

void GameScene::restart(CCObject *pSender)
{
	this->removeChildByTag(1789,true);
	this->removeChildByTag(199,true);
	CCTextureCache::sharedTextureCache()->removeUnusedTextures();
	Newlevel();

}

void GameScene::Seting(cocos2d::CCObject *pSender)
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

void GameScene::Store(cocos2d::CCObject *pSender)
{

}
void GameScene::Music(cocos2d::CCObject *pSender)
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

void GameScene::Sound(cocos2d::CCObject *pSender)
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