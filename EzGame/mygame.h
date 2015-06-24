class Shell;
#ifndef _MYGAME_H
#define _MYGAME_H

#include<iostream>
#include<stdio.h>
#include<stdint.h>
#include "Player.h"
using namespace std;
#define MAX_PLAYER_NUM 4
//����shell,������Ϸ���˵Ļ���
class Shell{
public:
	Shell();
	~Shell();
	uint8_t gameStart();//��Ϸ��ʼ//����0������Ϸ����
private:
	uint32_t playernumber;//��Ϸ��Ҹ���
	Player* playerlist[MAX_PLAYER_NUM];//��Ϸ����б�


	uint8_t gameInit();//��Ϸ��ʼ����������ң����ѡ���ɫ//�����캯������
	uint8_t gameOver();//ɾ����Ϸ�в����ı�������ȫ����//��������������
	uint8_t ListInfo(uint32_t);
	uint8_t TakeAction(uint32_t);

	uint8_t ShowTitle();
	int32_t MenuChoose(int32_t,int32_t);

	void DispLevel(Level);
	uint8_t Action_Attack(uint32_t i);
	uint8_t Action_Buy(uint32_t i);
	uint8_t Action_UsePotion(uint32_t i);

	uint8_t BUWea(uint32_t i);
	uint8_t BUArm(uint32_t i);
};


#endif