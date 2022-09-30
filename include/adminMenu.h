#ifndef ADMINMENU_H
#define ADMINMENU_H
#include "account.h"
#include <stdlib.h>
//彩票基础信息
typedef struct
{
	unsigned issue;		   //发行期号
	int price;			   //彩票单价
	unsigned short status; //开奖状态,0未开奖，1已开奖
	char winResult[22];	   //本期中奖号码
	unsigned totalSold;	   //本期售出总数
	float totalPrize;	   //本期奖池总额
} TicketData;

//彩票发行信息链表
struct ticketLinkedlist
{
	TicketData data;
	struct ticketLinkedlist *next;
};
typedef struct ticketLinkedlist TicktetLinkedList;


// 管理员后台主菜单
void AdminMenu();

/********************************/
/***********发行彩票功能相关********/

// 发行彩票
void IssueLotteryTickey();
void AddToLottertTickeyLinkedList(TicketData newData);
/*
 *   检查期号唯一性
 * @param issue 期号
 * 返回值：期号唯一，返回1，不唯一返回0
 */
int CheckIssueNumberUniqueness(unsigned int issue);

/*
 *   检查上期开奖状态
 * @param issue 期号
 * 返回值：没有发行过任何期数时或上期已开奖，返回1，未开奖返回
 */
int CheckPreIssueStatus();

/********************************/
/***********查询功能相关***********/
//查询彩民信息主界面
void QueryLotteryInfoMenu();

void QueryByUserName();
void QueryByBalanceRange();

//输出打印彩民信息
void DisplayLotteryInfo();

/********************************/
/***********排序功能相关***********/
//排序功能主界面
void SortDisplayLotteryMenu();
void SortDisplayLotteryByAccount();
void SortDisplayLotteryByBalance();

//显示所有彩民信息
void DisplayAllLottery();
//显示单个彩民信息
void DisplaySingleLotteryInfo(LotteryAccountLinkedList *userNode);

//查找当前节点的上一节点
LotteryAccountLinkedList *FindPreNode(LotteryAccountLinkedList *currentNode);

/********************************/
/*********账号管理功能相关**********/
//账号管理
void AccountManager();

//查看发行历史
void ReleaseView();

//打印某期彩票信息
void DisplayLotteryTicketInfo(TicktetLinkedList *LT);

/********************************/
/*********保存功能相关**********/
void Save();

// 接收字符串,转为整型
int RecStringConverToInt();
//清空数据
void ClearAllFiledata();
#endif
