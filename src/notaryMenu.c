#include "adminMenu.h"
#include "notaryMenu.h"
#include <stdio.h>
#include <string.h>
//彩票发行信息
extern TicktetLinkedList *LTHead;
extern TicktetLinkedList *LTCurrent;

// 彩民账号
extern LotteryAccountLinkedList *userHead;
extern LotteryAccountLinkedList *userCurrent;

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
    randomNum(LTCurrent->data.winResult);
    //打印结果
    if (LTHead == NULL)
    {
        printf("尚未发行任何彩票!\n");
        return;
    }
    if (LTCurrent->data.status)
    {
        printf("本期已开奖!\n");
        printf("本期中奖号码为:%s\n", LTCurrent->data.winResult);
        ShowWinner();
        return;
    }
    else
    {
        LTCurrent->data.status = 1;
        printf("开奖成功!\n");
        printf("本期中奖号码为:%s\n", LTCurrent->data.winResult);
        //打印中奖用户
        ShowWinner();
        return;
    }
}

//中奖用户
void ShowWinner()
{
    //遍历所有用户的购买号码看是否和当前中奖号码相同
    LotteryAccountLinkedList *user = userHead;
    LTSoldDataLinkedList *userSoldData = user->data.soldDataHead;
    //先把中奖的号码取出来放到winResult,0-5存放红球，6放蓝球
    int winResult[7] = {0};
    char empty[22] = {'\0'};
    StrArrayToInt(LTCurrent->data.winResult, winResult);
    if (userHead == NULL)
    {
        printf("没有中奖用户\n");
    }
    //遍历所有用户
    while (user != NULL)
    {
        //如果当前用户没有购买记录，直接换下一个用户
        if (userSoldData == NULL)
        {
            user = user->next;
            continue;
        }
        //如果有记录，遍历当前用户的购买的所有号码
        while (userSoldData != NULL)
        {
            //遍历第一张彩票的号码
            for (int i = 0; strcmp(userSoldData->data.numStr[i], empty) != 0; i++)
            {
                int userNum[7] = {0};
                //取出用户第i个号码，存放到userNum中。
                StrArrayToInt(userSoldData->data.numStr[i], userNum);
                //比较
                int finalResult = CompareResult(winResult, userNum);
                switch (finalResult)
                {
                case 1:
                    printf("一等奖用户:%s\n", user->data.account.name);
                    userSoldData->data.winStatus = 1;
                    user->data.winer = 1;
                    break;
                case 2:
                    printf("二等奖用户:%s\n", user->data.account.name);
                    userSoldData->data.winStatus = 2;
                    user->data.winer = 2;
                    break;
                case 3:
                    printf("三等奖用户:%s\n", user->data.account.name);
                    userSoldData->data.winStatus = 3;
                    user->data.winer = 3;
                    break;
                case 4:
                    printf("四等奖用户:%s\n", user->data.account.name);
                    userSoldData->data.winStatus = 4;
                    user->data.winer = 4;
                    break;
                case 5:
                    printf("五等奖用户:%s\n", user->data.account.name);
                    userSoldData->data.winStatus = 5;
                    user->data.winer = 5;
                    break;
                case 6:
                    printf("六等奖用户:%s\n", user->data.account.name);
                    userSoldData->data.winStatus = 6;
                    user->data.winer = 6;
                    break;
                default:
                    break;
                }
            }
            //换下一张彩票
            userSoldData = userSoldData->next;
        }

        user = user->next;
    }
}

//字符串转整形
void StrArrayToInt(char *sourceStr, int num[])
{
    //转成整形
    // char tempStr[7];
    int i = 0;
    //拆分字符保存到tempStr
    sscanf(sourceStr, "%d-%d-%d-%d-%d-%d-%d",
           &num[0], &num[1], &num[2],
           &num[3], &num[4], &num[5],
           &num[6]);
    // // tempStr转为整形,保存到num
    // for (i = 0; i < 6; i++)
    // {
    //     num[i] = atoi(tempStr[i]);
    // }
    // num[i] = atoi(tempStr[i]);
}
//中奖比较
int CompareResult(int winNum[7], int userNum[7])
{
    // result第一个位置表示有多少个相同的红球数，
    // result第二个位置表示有多少个相同的蓝球数
    //比较红球0-5是红球，6是蓝球
    int result[2];
    int i = 0, j = 0;
    //比较6个红球
    for (i = 0; i < 6; i++)
    {
        for (j = 0; j < 6; j++)
        {
            if (&winNum[i] == &userNum[j])
            {
                result[0]++;
            }
            // continue;
        }
    }
    //比较1个蓝球
    if (&winNum[6] == &userNum[6])
    {
        result[1]++;
    }
    //一等奖，6红球相同、1个蓝球相同，顺序不限，下同
    int No1 = (result[0] == 6 && result[1] == 1);
    //二等奖，6红球相同、0个蓝球相同
    int No2 = (result[0] == 6 && result[1] == 0);
    //三等奖，5红球相同、1个蓝球相同
    int No3 = (result[0] == 5 && result[1] == 0);
    //四等奖，5红球相同、0个蓝球相同或4个红球1个蓝球
    int No4 = (result[0] == 5 && result[1] == 0) || (result[0] == 4 && result[1] == 1);
    //五等奖，4红球相同、0个蓝球相同或3个红球1个蓝球
    int No5 = (result[0] == 4 && result[1] == 0) || (result[0] == 3 && result[1] == 1);
    //六等奖，1个蓝球相同
    int No6 = (result[1] == 1);
    if (No1)
    {
        // printf("一等奖\n");
        return 1;
    }
    else if (No2)
    {
        // printf("二等奖\n");
        return 2;
    }
    else if (No3)
    {
        // printf("三等奖\n");
        return 3;
    }
    else if (No4)
    {
        // printf("四等奖\n");
        return 4;
    }
    else if (No5)
    {
        // printf("五等奖\n");
        return 5;
    }
    else if (No6)
    {
        // printf("六等奖\n");
        return 6;
    }
    else
    {
        // printf("没中奖\n");
        return 0;
    }
}