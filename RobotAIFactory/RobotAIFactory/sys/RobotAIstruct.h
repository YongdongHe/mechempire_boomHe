//--------------------------------------
//这里面的代码看看就行，别乱动啊~~~
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

	//二期
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

	//二期
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
	
	//二期
	,BT_Grenade
	,BT_Mine

	,BT_ApolloBall


	,BT_TinyBall		//布雷器的辅助子弹
	


	//以下是功能性的类型
	
	,BT_NULL
};



struct RobotAI_Order
{
	int fire;	//武器Fire(int mnplt)的操作码
	int wturn;	//武器Turn(int mnplt)的操作码
	int run;	//引擎Run(int mnplt)的操作码
	int eturn;	//引擎Turn(int mnplt)的操作码

	RobotAI_Order(){fire=0;wturn=0;run=0;eturn=0;}
};


struct RobotAI_RobotInformation
{
	//这个成员变量不需要关注
	int entityID;

	int id;		//RobotAI_BattlefieldInformation中Robot的下标

	weapontypename weaponTypeName;	//武器名字
	enginetypename engineTypeName;	//引擎名字
	

	//当前属性
	Circle circle;		//engine的圆(x,y,radium)
	double engineRotation;	//引擎角度
	double weaponRotation;	//武器角度
	double vx,vy,vr;		//x轴速度，y轴速度，旋转速度
	
	int hp;					//生命

	
	int remainingAmmo;		//剩余弹药
	int cooling;			//剩余冷却值

	
};

struct RobotAI_BulletInformation
{
	//这个成员变量不需要关注
	int entityID;

	//发射者的下标
	int launcherID;
	

	//temp
	bullettypename type;		//子弹类型,属性数据查表获得

	Circle circle;		//bullet的圆(x,y,radium)
	double rotation;	//引擎角度
	double vx,vy,vr;
};


struct RobotAI_ArsenalInformation
{
	Circle circle;
	int respawning_time;
};

//每帧的战场信息
struct RobotAI_BattlefieldInformation
{
	//使用最基本的数组存储

	//Robot
	int num_robot;	//机甲数量（本季恒为2）

	RobotAI_RobotInformation robotInformation[Info_MaxRobots];

	//Bullet
	int num_bullet;	//当前战场上子弹数量（便于循环访问终止）

	RobotAI_BulletInformation bulletInformation[Info_MaxBullets];

	//Obstacle Info
	int num_obstacle;	//当前战场上障碍物数量（便于循环访问终止）

	Circle obstacle[Info_MaxObstacles];		

	//Arsenal Info
	int num_arsenal;	//当前战场上军火库数量（便于循环访问终止）

	RobotAI_ArsenalInformation arsenal[Info_MaxArsenals];


	//boundary，边界
	Box boundary;
};