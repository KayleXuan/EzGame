#ifndef ITEM_H
#define ITEM_H
//////////////////////////////////////////////////////////////
class Item;
enum Level{bronze, silver, gold, diamond };
class Weapon;
class Armour;
class Potion;



#include <string>
#include "Role.h"


using namespace std;
//////////////////////////////////////////////////////////////

//������Ʒ��Ļ���
class Item{
protected:
	//��Ʒ����
	string itemname;
	//���ý�ɫ//Ϊ���ַ���ʱ�������κν�ɫ
	string role2use;
	//�ȼ�
	Level level;
	//�����Ǯ
	RoleAttributeType Cost;
	//������ļӳ�
	RoleAttributeType addHP;//����ֵ
	RoleAttributeType addATK;//������
	RoleAttributeType addDEF;//������
	uint8_t Level2Int(Level le);
public:
	string getitemname();
	Level getlevel();
	RoleAttributeType getCost();
	RoleAttributeType getaddHP();//����ֵ
	RoleAttributeType getaddATK();//������
	RoleAttributeType getaddDEF();//������
	string getRole2ues(void);

	//���캯��
	Item();
};

class Weapon:public Item{//����
public:Weapon(Role*,Level);
};

class Armour:public Item{//װ��
public:Armour(Role*, Level);
};

class Potion :public Item{//��ҩ
public:Potion(Role*, Level);
};
#endif


