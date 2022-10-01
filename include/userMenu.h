#ifndef USERMENU_H
#define USERMENU_H
#include"account.h"
//用户购买的彩票信息
typedef struct
{
	unsigned issueNum;	   //记录发行期号
	unsigned short status; //记录本期开奖状态
	short winLevel;		   //记录本张彩票中奖等级
	char numStr[5][22];	   //记录本张彩票最多5组号码
} TicketData;

//用户购买的彩票链表
struct ticketDataLinkedList
{
	TicketData data;
	struct ticketDataLinkedList *next;
};
typedef struct ticketDataLinkedList TicketDataLinkedList;

/********************************/
/***********彩民主界面*********/
//彩民客户端主界面
void UserMenu();
//显示个人信息，详见adminMenu.h，在查询彩民信息时已实现

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

//添加到彩票链表
void AddToTicketDataLinkedList(TicketData newData);

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

//下注成功通知
void DisplaySelectedResult();

/********************************/
/***********注销账号相关***********/
//详见account.h

/********************************/
/***********查看历史记录***********/
//显示某个用户的购买记录,需要传入账户的指针
//防止头文件互相引用，将函数声明在account.h，
// void DisplayUserBoughtData(LotteryAccountLinkedList *user);

/*
 * 	更新奖池
 * 更新奖池，应该统计所有用户的购买数据
 * 奖池售出量 = 所有用户购买的号码数
 * 奖池奖金 = 所有用户购买的号码数 * 单价
 */
void UpdatePrizePool();


#endif