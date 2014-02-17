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
	int GetLevel();//�õ���ǰ�ؿ�
	void updateLevel();//���µ�ǰ����Ĺؿ�
	void updateChose(int l);
	int getlevel2();
	bool GetSuccess();//�жϵ�ǰ�ؿ��Ƿ�ɹ�
	void updateSuccess(bool success);//���굱ǰ�ؿ��͸��µ�ǰ�ؿ���״̬
private:
	bool setstate;//���ð�ť��״̬
	bool music;//����״̬
	bool sound;//��Ч״̬
	//bool ismenu;//�ж��Ƿ񷵻����˵�
	int level;//��ǰ�ؿ�
	bool isSuccess;//�жϵ�ǰ�ؿ��Ƿ�ɹ���ture�ɹ���falseʧ��
	bool success[31];//��Ŷ���һ����ɣ�trueΪ��ɣ�falseδ���
	int level2;//�жϵ�ǰҪѡ����Ǹ��ؿ�,����ɹ�
};
#endif