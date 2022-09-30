#ifndef NOTARYMENU_H
#define NOTARYMENU_H
//公证员客户端主界面
void NotaryMenu();

//开奖
void ReleaseResults();

//中奖
void ShowWinner();
//字符串转双色球
void StrArrayToInt(char *str, int num[]);
//彩票号码拆分
void LotteryNumberSplitting(char *sourceStr, char *targetStr[7]);

//中奖比较
int CompareResult(int winNum[7], int userNum[7]);

#endif