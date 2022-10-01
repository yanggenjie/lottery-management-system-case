#include "adminMenu.h"
#include "notaryMenu.h"
#include "fileIO.h"
#include <stdio.h>
#include <string.h>
//彩票发行信息
extern ReleaseDataLinkedlist *releaseDataHead;
extern ReleaseDataLinkedlist *releaseDataCurrent;

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
        printf("\t2.查看当期信息\n");
        printf("\t3.查看发行历史\n");
        printf("\t4.退出登录\n");
        printf("\n*******************************************\n");
        printf("请选择功能：");
        int choose = RecStringConverToInt();
        switch (choose)
        {
        case 1:
            ReleaseResults();
            //同步用户彩票的开奖信息
            //保存发行信息文件
            WriteReleaseDataToBin();
            break;
        case 2:
            DisplaySingleReleaseData(releaseDataCurrent);
            break;
        case 3:
            ReleaseView();
            //更新文件信息
            //更新奖池，即发行信息文件
            WriteReleaseDataToBin();
            //更新彩民账号信息
            WriteLotteryAccountToBin();
            //更新购买彩票上的信息
            WriteBoughtHistoryToFile();
            break;
        case 4:
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
    randomNum(releaseDataCurrent->data.winResult);
    //打印结果
    if (releaseDataHead == NULL)
    {
        printf("尚未发行任何彩票!\n");
        return;
    }
    if (releaseDataCurrent->data.status == 1)
    {
        printf("本期已开奖!\n");
        printf("本期中奖号码为:%s\n", releaseDataCurrent->data.winResult);
        // ShowWinner();
        return;
    }
    releaseDataCurrent->data.status = 1;
    printf("开奖成功!\n");
    printf("本期中奖号码为:%s\n", releaseDataCurrent->data.winResult);
    //打印中奖用户，并直接发放三等奖到六等奖的奖金
    ShowWinner();
    //发完所有低等奖奖金之后，用奖池剩余的奖金分发到一等奖、二等奖用户
    DistributeAdvanceBonus();
}

//中奖用户
void ShowWinner()
{
    //遍历所有用户的购买号码看是否和当前中奖号码相同
    LotteryAccountLinkedList *user = userHead;
    if (userHead == NULL)
    {
        printf("没有中奖用户\n");
    }
    //遍历所有用户
    while (user != NULL)
    {
        //遍历单个用户的数据
        TicketDataCheck(user);
        //换下一个用户的
        user = user->next;
    }
}

//字符串转整型
void StrArrayToInt(char *sourceStr, int num[])
{
    //拆分字符保存到tempStr
    sscanf(sourceStr, "%d-%d-%d-%d-%d-%d-%d",
           &num[0], &num[1], &num[2],
           &num[3], &num[4], &num[5],
           &num[6]);
}

//遍历单个用户的彩票数据

void TicketDataCheck(LotteryAccountLinkedList *user)
{
    TicketDataLinkedList *useTicketData = user->data.ticketDataHead;
    //先把中奖的号码取出来放到winResult,0-5存放红球，6放蓝球
    int winResult[7] = {0};
    char empty[22] = {'\0'};
    StrArrayToInt(releaseDataCurrent->data.winResult, winResult);
    //遍历当前用户的购买的所有号码
    while (useTicketData != NULL)
    {
        //同步彩票开奖状态
        useTicketData->data.status = releaseDataCurrent->data.status;
        //遍历第一张彩票的所有号码
        for (int i = 0; strcmp(useTicketData->data.numStr[i], empty) != 0; i++)
        {
            int userNum[7] = {0};
            //取出用户第i组号码，存放到userNum中。
            StrArrayToInt(useTicketData->data.numStr[i], userNum);
            //比较
            int finalResult = CompareResult(winResult, userNum);
            switch (finalResult)
            { //一等奖二等奖需要等所有低等奖的奖金发放完之后，再计算
            case 1:
                printf("一等奖用户:%s\n", user->data.account.name);
                releaseDataCurrent->data.winLevelCount[0]++; //统计一等奖数量，下同
                useTicketData->data.winLevel = 1;            //标记彩票中奖等级
                user->data.AdvanceAward = 1;                 //标记用户中奖等级
                break;
            case 2:
                printf("二等奖用户:%s\n", user->data.account.name);
                releaseDataCurrent->data.winLevelCount[1]++;
                useTicketData->data.winLevel = 2; //标记彩票中奖等级
                user->data.AdvanceAward = 2;      //标记用户中奖等级
                break;
            case 3:
                printf("三等奖用户:%s\n", user->data.account.name);
                releaseDataCurrent->data.winLevelCount[2]++;
                user->data.balance += 3000;       //打钱
                useTicketData->data.winLevel = 3; //标记彩票中奖等级
                break;
            case 4:
                printf("四等奖用户:%s\n", user->data.account.name);
                releaseDataCurrent->data.winLevelCount[3]++;
                user->data.balance += 200;        //打钱
                useTicketData->data.winLevel = 4; //标记彩票中奖等级
                break;
            case 5:
                printf("五等奖用户:%s\n", user->data.account.name);
                releaseDataCurrent->data.winLevelCount[4]++;
                user->data.balance += 10;         //打钱
                useTicketData->data.winLevel = 5; //标记彩票中奖等级
                break;
            case 6:
                printf("六等奖用户:%s\n", user->data.account.name);
                releaseDataCurrent->data.winLevelCount[5]++;
                user->data.balance += 5;          //打钱
                useTicketData->data.winLevel = 6; //标记彩票中奖等级
                break;
            default:
                break;
            }
        }
        //换下一张彩票
        useTicketData = useTicketData->next;
    }
}
//中奖比较
int CompareResult(int *winNum, int *userNum)
{
    // result第一个位置表示有多少个相同的红球数，
    // result第二个位置表示有多少个相同的蓝球数
    //比较红球0-5是红球，6是蓝球
    int result[2] = {0, 0};
    int i = 0, j = 0;
    //比较6个红球
    for (i = 0; i < 6; i++)
    {
        for (j = 0; j < 6; j++)
        {
            if (winNum[i] == userNum[j])
            {
                result[0]++;
            }
        }
    }
    //比较1个蓝球
    if (winNum[i] == userNum[j])
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

//分发高等奖奖金
void DistributeAdvanceBonus()
{
    //输出所有中奖的数量
    for (int i = 0; i < 6; i++)
    {
        printf("%d等奖用户数量%d\n", i + 1, releaseDataCurrent->data.winLevelCount[i]);
    }
    // 把统计结果复制出来，简化标识符长度
    int result[6];
    for (int i = 0; i < 6; i++)
    {
        result[i] = releaseDataCurrent->data.winLevelCount[i];
    }

    //先看统计结果有没有中高等奖的，没有就不用发奖金
    if (result[0] == 0 && result == 0)
    {
        return;
    }
    //如果有，那就先计算奖金，待用
    // 低等奖总奖金 = 三等奖数量*3000 + 四等奖数量*200 + 五等奖数量*10 + 六等奖数量*5
    // 高等奖总奖金 = 奖池总额*0.49 - 低等奖总奖金
    // 一等奖奖金 = 高等奖总奖金*0.75; 二等奖奖金 = 高等奖总奖金*0.25
    int lowTotalPrize = result[2] * 3000 + result[3] * 200 + result[4] * 10 + result[5] * 5;
    int advancePrizeBinus = releaseDataCurrent->data.totalPrize * 0.49 - lowTotalPrize;
    int firstPrizeBonus = advancePrizeBinus * 0.75;
    int secondPrizeBonus = advancePrizeBinus * 0.25;

    // 找出中一等奖的用户
    LotteryAccountLinkedList *user = userHead;
    while (user != NULL)
    {
        // 当前用户中一等奖，分发奖金
        if (user->data.AdvanceAward == 1)
        {
            user->data.balance += firstPrizeBonus;
        }
        // 当前用户中二等奖，分发奖金
        if (user->data.AdvanceAward == 2)
        {
            user->data.balance += secondPrizeBonus;
        }
        //当前用户没有中奖，换下一个用户
        user = user->next;
    }
}