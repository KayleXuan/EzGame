#ifndef ROLE_H
#define ROLE_H
////////////////////////////////////////////////////////////////////////////
class Role;

class Warrior;//սʿ
class Wizard;//��ʦ
class Goblin;//����
#define RoleAttributeType int32_t
#define MAX_POTIONmun 8//��ɫ��Я�������ҩ����

/////////////////////////////////////////////////////////////////////////////////


#include <stdint.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdexcept>
#include <stdexcpt.h>
#include <stdio.h>
#include <string>

#include "Player.h"
#include "Item.h"



using namespace std;


class Role{

public:
	//��ɫ��//һ��roleֻ�ܱ�һ��player��
	uint8_t bindPlayer(Player*);//�󶨽�ɫ��������ң��Ѿ�����ʱ���޷��������󶨣�
//	uint8_t unbindPlayer(void);//���
	const Player* getBoundPlayer(void);//�鿴��ɫ���󶨵���ң�û�б����Ƿ��ؿգ�//��ֹ�ôӽ�ɫ���õ���ָ���޸�ӵ���ţ�����const

	//��ɫ�Ƿ�����
	bool ifDead() const;
	//��ѯ����
	string getRolename(void);
	//�鿴��������//���Կ��Ƿ�װ��һ���µ�class//�������...��ֵ��...
	RoleAttributeType getHP(void);//����ֵ
	RoleAttributeType getATK(void);//������������������������
	RoleAttributeType getDEF(void);//�����������������׾�����
	RoleAttributeType getWealth(void);// ��Ǯ�����������������������ף�

	//�ı�������ԣ��������Ϊ�仯��,��СΪ0
	RoleAttributeType addHP(RoleAttributeType);//����ֵ
	RoleAttributeType addATK(RoleAttributeType);//������������������������
	RoleAttributeType addDEF(RoleAttributeType);//�����������������׾�����
	RoleAttributeType addWealth(RoleAttributeType);// ��Ǯ�����������������������ף�



	uint8_t EquipWeapon(Weapon*);
	uint8_t EquipArmour(Armour*);
	uint8_t RemoveWeapon();
	uint8_t RemoveArmour();
	uint8_t addPotion(Potion*);
	uint8_t UsePotion(uint8_t);//ָ��ʹ���ĸ�ҩ��

	Weapon* getweapon();
	Armour* getarmour();
	Potion** getpotion();
	//���캯��
	Role();
	//��������
	~Role();

protected:
	//��ɫ����
	string Rolename;

	
private:
	bool ifdead;//��ɫ�Ƿ�����
	//��ɫ��������ң������ڽ����κβ���ǰ�󶨣�
	Player * player;
	//����
#define MAX_HP 1000
#define MAX_ATK 100
#define MAX_DEF 100
	RoleAttributeType HP;//����ֵ
	RoleAttributeType ATK;//������������������������
	RoleAttributeType DEF;//�����������������׾�����
	RoleAttributeType Wealth;// ��Ǯ�����������������������ף�

	Weapon* weapon;
	Armour* armour;
	Potion* potion[MAX_POTIONmun];
	
};

class Warrior :public Role{//սʿ
public:
	Warrior();
};
class Wizard :public Role{//��ʦ
public:
	Wizard();
};
class Goblin :public Role{//����
public:
	Goblin();
};

#endif
