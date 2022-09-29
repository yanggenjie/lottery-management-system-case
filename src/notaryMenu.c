#include "adminMenu.h"
#include "notaryMenu.h"
#include <stdio.h>
extern LotteryTicket *LTHead;
extern LotteryTicket *LTCurrent;
//公证员客户端主界面
void NotaryMenu()
{
    int choose;
    while (1)
    {
        printf("\n*******************************************\n");
        printf("\t1.开奖\n");
        printf("\t2.查看彩票发行历史\n");
        printf("\t3.退出登录\n");
        printf("\n*******************************************\n");
        printf("请选择功能：");
        scanf("%d", &choose);
        switch (choose)
        {
        case 1:
            lottery();
            break;
        case 2:
            ViewRelease();
            break;
        case 3:
            return;
        default:
            break;
        }
    }
}

//开奖
void lottery()
{
    if (LTHead == NULL)
    {
        printf("尚未发行任何彩票!\n");
        return;
    }
    if (LTCurrent->status)
    {
        printf("本期已开奖!\n");
        return;

    }
    else
    {
        LTCurrent->status = 1;
        printf("开奖成功!\n");
        return;
    }
}