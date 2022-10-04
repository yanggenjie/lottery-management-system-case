#ifndef USERMENU_H
#define USERMENU_H
#include "account.h"
/********************************/
/***********彩民主界面*********/
// 彩民客户端主界面
void UserMenu();
// 显示个人信息,详见adminMenu.h,在查询彩民信息时已实现

// 修改密码
void ChangePassword();
// 充值功能
void Recharge();

/********************************/
/***********下注相关功能*********/

// 下注
void Bet();
/*
	机选号码
@param n 要购买几组号码
*/
void MachineSelection(int n);
// 清空字符数组
void EmptyNumStr();
// 添加到彩票链表
void AddToTicketDataLinkedList(TicketData newData);

/*
	生成随机数的字符串
@param nums 用于接收生成的随机字符串。结果长度22
*/
void randomNum(char *nums);

/*
	检查号码重复性
返回值：重复返回1,不重复返回0
@param nums 要检查的字符串号码
*/
int CheckBetNumberUniqueness(char nums[]);
// 彩票ID生成器
void TimePlugRandIDGenerator(char *id);

/*
id重复性检测
返回值：重复返回1，不重复返回0
*/
int CheckIDUniqueness(char *id);

// 下注成功通知
void DisplaySelectedResult();

/********************************/
/***********注销账号相关***********/
// 删除彩民账号
void DeleteLotteryAccount();
// 删除账号确认
int DeleteLotteryAccountConfirm();

/********************************/
/***********查看历史记录***********/
// 查看历史记录菜单
void ViewTicketDataHistory();
// 打印彩票数据
void DisplayTicketData(TicketDataLinkedList *ticketData);

/********************************/
/***********统计相关**************/
/*
 * 重新统计用户购买的彩票数据
 * user 要统计的用户
 */
void ReCountUserTicketData(LotteryAccountLinkedList *user);


#endif