#include "Role.h"


Weapon* Role::getweapon()
{
	return weapon;
}

Armour* Role::getarmour()
{
	return armour;
}


Potion** Role::getpotion()
{
	return potion;
}


bool Role::ifDead(void) const
{
	return ifdead;
}

const Player* Role::getBoundPlayer(void)
{
	return player;
}

uint8_t Role::bindPlayer(Player* player2bind)
{
	if (player != NULL)
		return 1;	//��ɫ�Ѿ�����

	if (player2bind->role != this)
		return 1;	//����Ѿ�����

	player = player2bind;
//	player2bind->role = this;
	return 0;
	//������а󶨽�ɫ
}

//uint8_t Role::unbindPlayer(void)
//{
//	if (player == NULL)
//		return 1;	//��ɫ��δ����
//
//	if (player->role != this)
//		return 1;	//���δ������ȷ��
//
//	player->role = NULL;
//	player = NULL;
//	return 0;
//	//������а󶨽�ɫ
//}


Role::Role() :Rolename("default role"), player(NULL), HP(MAX_HP), ATK(0), DEF(0), Wealth(1000), weapon(NULL), armour(NULL), ifdead(false)
{
	for (uint8_t i = 0; i < MAX_POTIONmun; i++)
		potion[i] = NULL;
}



Role::~Role()
{
//	unbindPlayer();//delete class֮ǰ���Ƚ��
//	delete player;
	if (weapon != NULL)
		delete weapon;
	if (armour != NULL)
		delete armour;
	for (uint8_t i = 0; i < MAX_POTIONmun; i++)
		delete potion[i];
}




//��ѯ����
string Role::getRolename(void)
{
	return Rolename;
}
//�鿴��������
RoleAttributeType Role::getHP(void)//����ֵ
{
	return (HP >= 0) ? HP : 0;
}
RoleAttributeType Role::getATK(void)//������������������������
{
	return (ATK >= 0) ? ATK : 0;
}
RoleAttributeType Role::getDEF(void)//�����������������׾�����
{
	return (DEF >= 0) ? DEF : 0;
}
RoleAttributeType Role::getWealth(void)// ��Ǯ�����������������������ף�
{
	return (Wealth >= 0) ? Wealth  : 0;
}

//�ı�������ԣ��������Ϊ�仯��
RoleAttributeType Role::addHP(RoleAttributeType change)//����ֵ
{
	HP += change;
	if (HP <= 0)
		ifdead = true;
	return getHP();
}
RoleAttributeType Role::addATK(RoleAttributeType change)//������������������������
{
	ATK += change;
	return getATK();
}
RoleAttributeType Role::addDEF(RoleAttributeType change)//�����������������׾�����
{
	DEF += change;
	return getDEF();
}
RoleAttributeType Role::addWealth(RoleAttributeType change)// ��Ǯ�����������������������ף�
{
	Wealth += change;
	return getHP();
}




uint8_t Role::EquipWeapon(Weapon* eq)
{
	RemoveWeapon();
	this->addATK(eq->getaddATK());
	this->addDEF(eq->getaddDEF());
	this->addHP(eq->getaddHP());
	weapon = eq;
	return 0;
}
uint8_t Role::EquipArmour(Armour* eq)
{
	RemoveArmour();
	this->addATK(eq->getaddATK());
	this->addDEF(eq->getaddDEF());
	this->addHP(eq->getaddHP());
	armour = eq;
	return 0;
}

uint8_t Role::RemoveWeapon()
{
	if (weapon != NULL)
	{
		this->addATK(-(weapon->getaddATK()));
		this->addDEF(-(weapon->getaddDEF()));
		this->addHP(-(weapon->getaddHP()));
		delete weapon;
	}
	weapon = NULL;
	return 0;
}
uint8_t Role::RemoveArmour()
{
	if (armour != NULL)
	{
		this->addATK(-(armour->getaddATK()));
		this->addDEF(-(armour->getaddDEF()));
		this->addHP(-(armour->getaddHP()));
		delete armour;
	}
	armour = NULL;
	return 0;
}
uint8_t Role::addPotion(Potion* po)
{
	uint32_t cnt;
	for (cnt = 0; cnt < MAX_POTIONmun; cnt++)
		if ((this->getpotion())[cnt] == NULL)
			break;
	if (cnt >= MAX_POTIONmun)
		return 1;//û�ط�����
	else
	{
		(this->getpotion())[cnt] = po;
		return 0;
	}

}
uint8_t Role::UsePotion(uint8_t num)//ָ��ʹ���ĸ�ҩ��
{
	if (num >= MAX_POTIONmun)
		return 1;
	if (potion[num] == NULL)
		return 1;
	//�޸�����
	this->addHP(potion[num]->getaddHP());
	delete potion[num];
	potion[num] = NULL;
	return 0;
}


Warrior::Warrior(void)
{
	Rolename = "Warrior";
}

Wizard::Wizard(void)
{
	Rolename = "Wizard";
}
Goblin::Goblin(void)
{
	Rolename = "Goblin";
}
