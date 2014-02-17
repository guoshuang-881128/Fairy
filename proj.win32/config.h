#ifndef CONFIG_H
#define CONFIG_H

class Config
{
public:
	Config();
	~Config();
	bool GetSetState();
	static Config* shareConfig();
	void updateset(bool isset);
	bool GetMusic();
	void updateMusic(bool ismusic);
	bool GetSound();
	void updateSound(bool issound);
	int GetLevel();//得到当前关卡
	void updateLevel();//更新当前到达的关卡
	void updateChose(int l);
	int getlevel2();
	bool GetSuccess();//判断当前关卡是否成功
	void updateSuccess(bool success);//玩完当前关卡就更新当前关卡的状态
private:
	bool setstate;//设置按钮的状态
	bool music;//音乐状态
	bool sound;//音效状态
	//bool ismenu;//判断是否返回主菜单
	int level;//当前关卡
	bool isSuccess;//判断当前关卡是否成功，ture成功，false失败
	bool success[31];//存放都那一关完成，true为完成，false未完成
	int level2;//判断当前要选择的那个关卡,已完成功
};
#endif