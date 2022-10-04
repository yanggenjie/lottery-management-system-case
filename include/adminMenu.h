#ifndef ADMINMENU_H
#define ADMINMENU_H
#include "account.h"

/********************************/
/***********管理员菜单相关功能***********/
// 管理员后台主菜单
void AdminMenu();

/********************************/
/***********发行彩票功能相关********/

// 发行彩票
void IssueLotteryTickey();
/*
 * 添加到发行信息链表
 * @param newData 发行信息
 */
void AddToReleaseDataLinkedList(ReleaseData newData);

/*
 *   检查期号唯一性
 * @param issue 期号
 * 返回值：期号唯一,返回1,不唯一返回0
 */
int CheckIssueNumberUniqueness(unsigned int issue);

/*
 *   检查上期开奖状态
 * @param issue 期号
 * 返回值：没有发行过任何期数时或上期已开奖,返回1,未开奖返回
 */
int CheckPreIssueStatus();

/********************************/
/***********查询功能相关***********/
// 查询彩民信息主界面
void QueryLotteryInfoMenu();

// 根据彩民账号(用户名)查询
void QueryByUserName();

// 根据账户余额查询
void QueryByBalanceRange();

// 输出打印彩民信息
void DisplayLotteryInfo();

/********************************/
/***********排序功能相关***********/
// 排序功能主界面
void SortDisplayLotteryMenu();
// 根据账号排序显示
void SortDisplayLotteryByAccount();
// 根据余额排序显示
void SortDisplayLotteryByBalance();

// 显示所有彩民信息
void DisplayAllLottery();
// 显示单个彩民信息
void DisplaySingleLotteryInfo(LotteryAccountLinkedList *userNode);

// 查看发行历史
void ViewAllRelease();

/********************************/
/*********账号管理相关**********/
// 详见	account.h


/********************************/
/*********保存功能相关**********/
void SaveMenu();
// 其余详见	fileIO.h

/********************************/
/*********其它**********/
// 接收字符串,转为整型
int RecStringConverToInt();

#endif
