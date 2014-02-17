#include "config.h"
#include "cocos2d.h"

USING_NS_CC;
using namespace cocos2d;

Config *config = NULL;
Config::Config()
{
	setstate = false;
	music = true;
	sound = true;
	//ismenu = false;
	level = 1;
	level2 = 1;
	isSuccess = false;
}

Config::~Config()
{
	delete config;
	config = NULL;
}

Config* Config::shareConfig()
{
	if (!config)
	{
		config = new Config();	
	}
	return config;
	
}
bool Config::GetSetState()
{
	return setstate;
}

void Config::updateset(bool isset)
{
	setstate = isset;
}

bool Config::GetMusic()
{
	return music;
}

void Config::updateMusic(bool ismusic)
{
	music = ismusic;
}

bool Config::GetSound()
{
	return sound;
}

void Config::updateSound(bool issound)
{
	sound = issound;
}

int Config::GetLevel()
{
	return level;
}

void Config::updateLevel()
{
	level++;
}

void Config::updateChose(int l)
{
	level2 = l;
}

int Config::getlevel2()
{
	return level2;
}
bool Config::GetSuccess()
{
	return isSuccess;
}

void Config::updateSuccess(bool success)
{
	isSuccess = success;
}