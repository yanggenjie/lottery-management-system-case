#ifndef USERMENU_H
#define USERMENU_H
#include"account.h"
//彩票售出号码记录
// typedef struct
// {
// 	short int red[6];
// 	short int blue;
// }LTSoldNumber;

struct LTSoldInfo{
	char num[5][22];//单张彩票最多5组号码
	// Lottery *userFlags;
	struct LTSoldInfo *next;
};
typedef struct LTSoldInfo LTSoldInfo;

/********************************/
/***********彩民主界面*********/
//彩民客户端主界面
void UserMenu();
//显示个人信息
void ViewPersonalInfo();
//修改密码
void ChangePassword();
//充值功能
void Recharge();

/********************************/
/***********下注相关功能*********/

//下注
void Bet();

/*
    购买并记录售出号码
@param n 要购买几组号码
*/
void MachineSelection(int n);
//生成随机数的字符串
void rangeNum(char *nums);

/*
	检查号码重复性
返回值：重复返回1，不重复返回0
*/
int CheckBetNumberUniqueness(char nums[]);



//显示当前已选
void DisplayCurrentSelected();
void DisplayBoughtInfo();


#endif