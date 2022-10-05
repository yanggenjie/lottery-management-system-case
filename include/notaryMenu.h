#ifndef NOTARYMENU_H
#define NOTARYMENU_H
#include "account.h"
// 公证员客户端主界面
void NotaryMenu();

// 开奖
void ReleaseResults();

// 计算中奖结果，同步数据到彩票上
void SynDataToTicket();

/*
 * 计算中奖等级
 * 返回值：返回中奖等级，1为一等奖，2为二等奖，以此类推
 * @param winNum 开奖号
 * @param userNum 用户购买的号
 */
int CalculateWinningGrade(int *winNum, int *userNum);

/*
 * 更新中奖结果
 * 功能：在彩票上标记中奖等级、中奖金额
 * @param ticket 某张彩票
 * @param level 中奖等级
 * @bonus 奖金
 */
void UpdateWinningResultToTicketData(TicketDataLinkedList *ticket, short level, float bonus);

/*
 * 字符串转整型
 * 功能：将str转为整型，保存到num中。
 * @param str 源字符串
 * @num 存放转换后的整形数组
 */
void StrArrayToInt(char *str, int num[]);

// //分发低等奖奖金
// void DistributeLowerBonus();
// 分发高等奖奖金
void DistributeAdvanceBonus();


// 打印中奖用户的信息
void DisplayWinner();

/*
 * 打印某期发行信息
 * @param LT 发行信息的某一节点
 */
void ViewSingleRelease(ReleaseDataLinkedlist *LT);

// 统计当前发行期的销售总额、销售量
void CountCurrentReleaseSoldData();

#endif