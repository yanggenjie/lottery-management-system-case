#ifndef USERMENU_H
#define USERMENU_H
//彩票售出号码记录
typedef struct
{
	unsigned short count;//购买的号码数量
	char numStr[5][22]; //单张彩票最多5组号码
} SoldCommData;

struct LTSoldData
{
	SoldCommData data;
	struct LTSoldData *next;
};
typedef struct LTSoldData LTSoldDataLinkedList;

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
	机选号码
@param n 要购买几组号码
*/
void MachineSelection(int n);

//添加到售出数据到链表
void AddSoldDataToLinkedlist(SoldCommData newData);

/*
	生成随机数的字符串
@param nums 用于接收生成的随机字符串。结果长度22
*/
void randomNum(char *nums);

/*
	检查号码重复性
返回值：重复返回1，不重复返回0
@param nums 要检查的字符串号码
*/
int CheckBetNumberUniqueness(char nums[]);

/********************************/
/***********注销账号相关***********/
//注销账户
void DeleteAccount();
//删除操作确认
int DeleteAccountOprationConfirm();

/********************************/
/***********查看历史记录***********/

//显示当前购买的号码
void DisplayCurrentSelected();

//显示所有购买记录
void DisplayBoughtHistory();

#endif