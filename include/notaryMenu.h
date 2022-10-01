#ifndef NOTARYMENU_H
#define NOTARYMENU_H
#include "userMenu.h"
//公证员客户端主界面
void NotaryMenu();

//开奖
void ReleaseResults();

//显示中奖用户
void ShowWinner();
//双色球字符串转整型
void StrArrayToInt(char *str, int num[]);
//单个用户彩票检测
void TicketDataCheck(LotteryAccountLinkedList *user);
//中奖比较
int CompareResult(int *winNum, int *userNum);

//分发高等奖奖金
void DistributeAdvanceBonus();

#endif