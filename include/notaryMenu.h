#ifndef NOTARYMENU_H
#define NOTARYMENU_H
#include "account.h"
//公证员客户端主界面
void NotaryMenu();

//开奖
void ReleaseResults();

//显示中奖用户
void ShowWinner();

//计算中奖等级
int CalculateWinningGrade(int *winNum, int *userNum);

//更新中奖结果
void UpdateWinningResult(TicketDataLinkedList *ticket,short level,float bonus);

//分发高等奖奖金
void DistributeAdvanceBonus();

//字符串转整型
void StrArrayToInt(char *str, int num[]);
#endif