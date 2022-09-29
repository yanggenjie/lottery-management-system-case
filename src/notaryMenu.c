#include "adminMenu.h"
#include "notaryMenu.h"
#include <stdio.h>
extern LotteryTicket *LTHead;
extern LotteryTicket *LTCurrent;

//公证员客户端主界面
void NotaryMenu()
{
    while (1)
    {
        printf("\n*******************************************\n");
        printf("\t1.开奖\n");
        printf("\t2.查看彩票发行历史\n");
        printf("\t3.退出登录\n");
        printf("\n*******************************************\n");
        printf("请选择功能：");
        int choose = RecStringConverToInt();
        switch (choose)
        {
        case 1:
            ReleaseResults();
            break;
        case 2:
            ReleaseView();
            break;
        case 3:
            return;
        default:
            break;
        }
    }
}

//开奖
void ReleaseResults()
{
    //生成随机号作为结果
    randomNum(LTCurrent->Info.winResult);
    //打印结果
    if (LTHead == NULL)
    {
        printf("尚未发行任何彩票!\n");
        return;
    }
    if (LTCurrent->Info.status)
    {
        printf("本期已开奖!\n");
        printf("本期中奖号码为:%s\n", LTCurrent->Info.winResult);
        return;
    }
    else
    {
        LTCurrent->Info.status = 1;
        printf("开奖成功!\n");
        printf("本期中奖号码为:%s\n", LTCurrent->Info.winResult);
        return;
    }
}