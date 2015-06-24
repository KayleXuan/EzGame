#ifndef PLAYER_H
#define PLAYER_H
/////////////////////////////////////////////////////////////////////
class Player;








////////////////////////////////////////////////////////////////////






#include <string>

#include "Role.h"
#include "Item.h"

using namespace std;

class Player{
	friend class Role;
	friend class Repertory;

private:
	string playername;

	//һ�������ӵ�е�ѡ��
	//һ��ѡ��ֻ�ܱ�һ����Ұ�
	Role* role;//����//���ǵ���ҵ�������������ȵȣ�����ʹ��ָ������
//	Repertory repertory;//�����ӵ�е���Ʒ�����Ը������䱸
public:
	//�õ���Щֵ
	Role* getRole(void);
//	const Repertory* getRepertory(void);

	//���Ҫ��ӵ�ѡ�����Ѿ������ڱ����һ���δ���󶨣����޷������
	uint8_t addRole(Role*);//�ɹ�����0

	//��ͼɾ��δ����ӵ�ѡ��ʱ�᷵�ش���
	uint8_t deleteRole(void);//�ɹ�����0

	//����name
	string getPlayername(void);



	//���캯��
	Player(string name);
	Player(void);
	//��������
	~Player(void);
};




#endif