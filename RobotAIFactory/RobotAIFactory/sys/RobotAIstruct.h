//--------------------------------------
//������Ĵ��뿴�����У����Ҷ���~~~
//--------------------------------------


#pragma once

#define Info_MaxArsenals 2
#define Info_MaxObstacles 5
#define Info_MaxRobots 2
#define Info_MaxBullets 200

#include "struct.h"


enum weapontypename
{
	WT_Cannon
	,WT_Shotgun
	,WT_RPG
	,WT_Machinegun
	,WT_Prism
	,WT_Tesla
	,WT_PlasmaTorch
	,WT_MissileLauncher
	,WT_ElectricSaw

	//����
	,WT_GrenadeThrower
	,WT_MineLayer

	,WT_Apollo
};

enum enginetypename
{
	ET_Spider
	,ET_Robotman
	,ET_AFV
	,ET_UFO

	//����
	,ET_Quad
	,ET_GhostTank
	,ET_XCraft
	,ET_Shuttle
};

enum bullettypename
{
	BT_Cannonball
	,BT_ShotgunBall
	,BT_RPGBall
	,BT_MachinegunBall
	,BT_Prism_Laser
	,BT_Tesla_Lightning
	,BT_PlasmaBall
	,BT_TrackingMissile
	,BT_ElectricSaw
	
	//����
	,BT_Grenade
	,BT_Mine

	,BT_ApolloBall


	,BT_TinyBall		//�������ĸ����ӵ�
	


	//�����ǹ����Ե�����
	
	,BT_NULL
};



struct RobotAI_Order
{
	int fire;	//����Fire(int mnplt)�Ĳ�����
	int wturn;	//����Turn(int mnplt)�Ĳ�����
	int run;	//����Run(int mnplt)�Ĳ�����
	int eturn;	//����Turn(int mnplt)�Ĳ�����

	RobotAI_Order(){fire=0;wturn=0;run=0;eturn=0;}
};


struct RobotAI_RobotInformation
{
	//�����Ա��������Ҫ��ע
	int entityID;

	int id;		//RobotAI_BattlefieldInformation��Robot���±�

	weapontypename weaponTypeName;	//��������
	enginetypename engineTypeName;	//��������
	

	//��ǰ����
	Circle circle;		//engine��Բ(x,y,radium)
	double engineRotation;	//����Ƕ�
	double weaponRotation;	//�����Ƕ�
	double vx,vy,vr;		//x���ٶȣ�y���ٶȣ���ת�ٶ�
	
	int hp;					//����

	
	int remainingAmmo;		//ʣ�൯ҩ
	int cooling;			//ʣ����ȴֵ

	
};

struct RobotAI_BulletInformation
{
	//�����Ա��������Ҫ��ע
	int entityID;

	//�����ߵ��±�
	int launcherID;
	

	//temp
	bullettypename type;		//�ӵ�����,�������ݲ����

	Circle circle;		//bullet��Բ(x,y,radium)
	double rotation;	//����Ƕ�
	double vx,vy,vr;
};


struct RobotAI_ArsenalInformation
{
	Circle circle;
	int respawning_time;
};

//ÿ֡��ս����Ϣ
struct RobotAI_BattlefieldInformation
{
	//ʹ�������������洢

	//Robot
	int num_robot;	//����������������Ϊ2��

	RobotAI_RobotInformation robotInformation[Info_MaxRobots];

	//Bullet
	int num_bullet;	//��ǰս�����ӵ�����������ѭ��������ֹ��

	RobotAI_BulletInformation bulletInformation[Info_MaxBullets];

	//Obstacle Info
	int num_obstacle;	//��ǰս�����ϰ�������������ѭ��������ֹ��

	Circle obstacle[Info_MaxObstacles];		

	//Arsenal Info
	int num_arsenal;	//��ǰս���Ͼ��������������ѭ��������ֹ��

	RobotAI_ArsenalInformation arsenal[Info_MaxArsenals];


	//boundary���߽�
	Box boundary;
};