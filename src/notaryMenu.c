#include "adminMenu.h"
#include "notaryMenu.h"
#include "userMenu.h"
#include "fileIO.h"
#include <stdio.h>
#include <string.h>
// 彩票发行信息
extern ReleaseDataLinkedlist *releaseDataHead;
extern ReleaseDataLinkedlist *releaseDataCurrent;

// 彩民账号
extern LotteryAccountLinkedList *lotteryAccountHead;
extern LotteryAccountLinkedList *lotteryAccountCurrent;

// 彩票信息
extern TicketDataLinkedList *ticketDataHead;
extern TicketDataLinkedList *ticketDataCurrent;

// 公证员客户端主界面
void NotaryMenu()
{
    // 统计当期的销售总额、销售量
    CountCurrentReleaseSoldData();
    for (;;)
    {
        printf("\n*******************************************\n");
        printf("\t1.开奖\n");
        printf("\t2.查看当期发行\n");
        printf("\t3.查看历史发行\n");
        printf("\t4.退出登录\n");
        printf("\n*******************************************\n");
        printf("请选择功能：");
        int choose = RecStringConverToInt();
        switch (choose)
        {
        case 1:
            ReleaseResults();
            break;
        case 2:
            // 打印当前发行信息
            ViewSingleRelease(releaseDataCurrent);
            break;
        case 3:
            ViewAllRelease();
            break;
        case 4:
            return;
        default:
            break;
        }
    }
}

// 开奖
void ReleaseResults()
{

    // 尚未发行彩票
    if (releaseDataHead == NULL)
    {
        printf("尚未发行任何彩票!\n");
        return;
    }
    if (releaseDataCurrent->data.status == 1)
    {
        printf("本期已开奖!不可重复开奖！\n");
        printf("\t本期中奖号码:%s\n", releaseDataCurrent->data.winResult);
        printf("\t本期售出总数:%d\n", releaseDataCurrent->data.totalSold);
        printf("\t本期奖池总额:%.2f\n", releaseDataCurrent->data.totalPrize);
        for (int i = 0; i < 6; i++)
        {
            if (releaseDataCurrent->data.winLevelCount[i] > 0)
            {
                printf("%d等奖用户%d个\n", i + 1, releaseDataCurrent->data.winLevelCount[i]);
            }
        }
        return;
    }
    // 生成随机号作为结果
    randomNum(releaseDataCurrent->data.winResult);
    releaseDataCurrent->data.status = 1;
    printf("开奖成功!\n");
    printf("本期中奖号码为:%s\n", releaseDataCurrent->data.winResult);
    // 更新中奖结果，然后同步数据到彩票上
    SynDataToTicket();
    // 发完所有低等奖奖金之后,用奖池剩余的奖金分发到一等奖、二等奖用户
    DistributeAdvanceBonus();
    // 打印中奖用户
    DisplayWinner();
    // 保存发行信息文件
    WriteReleaseDataToBin();
    // 保存用户信息
    WriteLotteryAccountToBin();
    // 保存彩票信息
    WriteTicketDataToFile();
}

// 中奖用户
void SynDataToTicket()
{
    // 先把中奖的号码字符串取出来,转成整型放到winResult,0-5存放红球,6放蓝球
    int winResult[7] = {0};
    char empty[22] = {'\0'};
    StrArrayToInt(releaseDataCurrent->data.winResult, winResult);
    // 检相同查彩票上的号码，看是否有和当前中奖号码
    TicketDataLinkedList *tickDataTemp = ticketDataHead;
    if (tickDataTemp == NULL)
    {
        printf("没有中奖用户\n");
        return;
    }
    // 如果有彩票数据，遍历所有彩票，把中奖结果、中奖等级、开奖状态等数据同步到该彩票信息上
    while (tickDataTemp != NULL)
    {
        // 先同步彩票中奖状态
        tickDataTemp->data.status = releaseDataCurrent->data.status;
        // 遍历本张彩票的5组号码
        for (int i = 0; strcmp(tickDataTemp->data.numStr[i], empty) != 0 && i < 5; i++)
        {
            // 取出用户第i组号码,存放到userNum中。
            int userNum[7] = {0};
            StrArrayToInt(tickDataTemp->data.numStr[i], userNum);
            // 计算中奖情况，返回中奖等级
            // CalculateWinningGrade函数一次只遍历一组号码
            // 如果存在一张彩票上有两个中奖号码，那最后一次的中奖等级会覆盖前面的结果
            // 但奖金发放是正确的，只是等级会被覆盖，只能显示一种中奖等级
            int finalLevel = CalculateWinningGrade(winResult, userNum);
            switch (finalLevel)
            {
                // 更新中奖结果数据，同步到彩票上，低等奖直接发奖金
            case 1:
                UpdateWinningResultToTicketData(tickDataTemp, finalLevel, 0); // 奖金待定
                //记录中奖数量，下同
                releaseDataCurrent->data.winLevelCount[0]++;
                break;
            case 2:
                UpdateWinningResultToTicketData(tickDataTemp, finalLevel, 0); // 奖金待定
                releaseDataCurrent->data.winLevelCount[1]++;
                break;
            case 3:
                UpdateWinningResultToTicketData(tickDataTemp, finalLevel, 3000);
                releaseDataCurrent->data.winLevelCount[2]++;
                break;
            case 4:
                UpdateWinningResultToTicketData(tickDataTemp, finalLevel, 200);
                releaseDataCurrent->data.winLevelCount[3]++;
                break;
            case 5:
                UpdateWinningResultToTicketData(tickDataTemp, finalLevel, 10);
                releaseDataCurrent->data.winLevelCount[4]++;
                break;
            case 6:
                UpdateWinningResultToTicketData(tickDataTemp, finalLevel, 5);
                releaseDataCurrent->data.winLevelCount[5]++;
                break;
            default:
                break;
            }
        }
        // 遍历下一张彩票
        tickDataTemp = tickDataTemp->next;
    }
}

// 计算中奖等级
int CalculateWinningGrade(int *winNum, int *userNum)
{
    // cnt[0] 记录红球区，相同的数字有几对
    // cnt[1] 记录蓝球区，同的数字有几对
    int cnt[2] = {0, 0};
    int result[6] = {0};
    int i = 0, j = 0;
    // 比较6个红球中，有几个数字相同，顺序不限，故两层循环
    for (i = 0; i < 6; i++) // 遍历开奖号
    {
        for (j = 0; j < 6; j++) // 遍历用户购买的号
        {
            if (winNum[i] == userNum[j])
            {
                cnt[0]++;
                i++; // 不重复比较，如果有相同，就直接比较第二个
            }
        }
    }
    // 比较1个蓝球
    if (winNum[i] == userNum[j])
    {
        cnt[1]++;
    }
    // 一等奖,6红球相同、1个蓝球相同,(顺序不限,下同)
    result[0] = (cnt[0] == 6 && cnt[1] == 1);
    // 二等奖,6红球相同、0个蓝球相同
    result[1] = (cnt[0] == 6 && cnt[1] == 0);
    // 三等奖,5红球相同、1个蓝球相同
    result[2] = (cnt[0] == 5 && cnt[1] == 0);
    // 四等奖,5红球相同、0个蓝球相同或4个红球1个蓝球
    result[3] = (cnt[0] == 5 && cnt[1] == 0) || (cnt[0] == 4 && cnt[1] == 1);
    // 五等奖,4红球相同、0个蓝球相同或3个红球1个蓝球
    result[4] = (cnt[0] == 4 && cnt[1] == 0) || (cnt[0] == 3 && cnt[1] == 1);
    // 六等奖,1个蓝球相同
    result[5] = (cnt[1] == 1);
    // 结果数组result中的元素值不是0就是1,数组下标0-5分别代表一等奖到6等奖的中奖情况
    for (int i = 0; i < 6; i++)
    {
        // 如果对应位置的值为1，返回i+1代表中奖等级，
        // result[0]=1，返回0+1，代表一等奖
        if (result[i])
        {
            return (i + 1);
        }
    }
    return 0;
}

// 更新中奖结果
void UpdateWinningResultToTicketData(TicketDataLinkedList *ticket, short level, float bonus)
{
    ticket->data.winLevel = level; // 标记中奖等级到彩票上
    ticket->data.bonus = bonus;    // 标记中奖金额到彩票上
    LotteryAccountLinkedList *findUser = NULL;
    // 通过彩票上的购买者信息，找到用户，发放奖金
    findUser = FindLotteryAccountNodeByUserName(ticket->data.purchaser);
    if (findUser != NULL)
    {
        // 低等奖用户发放奖金
        findUser->data.balance += ticket->data.bonus; // 更新用户余额
        // 一等奖用户，额外进行标记，后面发放奖金
        if (level == 1)
        {
            findUser->data.AdvanceAward = 1;
        }
        // 二等奖用户，额外进行标记，后面发放奖金
        if (level == 2)
        {
            findUser->data.AdvanceAward = 2;
        }
    }
}

// 字符串转整型
void StrArrayToInt(char *sourceStr, int num[])
{
    // 拆分字符保存到tempStr
    sscanf(sourceStr, "%d-%d-%d-%d-%d-%d-%d",
           &num[0], &num[1], &num[2],
           &num[3], &num[4], &num[5],
           &num[6]);
}

// 分发高等奖奖金
void DistributeAdvanceBonus()
{

    // 把统计结果复制出来,简化标识符长度
    int result[6];
    for (int i = 0; i < 6; i++)
    {
        result[i] = releaseDataCurrent->data.winLevelCount[i];
    }

    // 先看统计结果有没有中高等奖的,没有就不用发奖金
    if (result[0] == 0 && result == 0)
    {
        return;
    }
    // 如果有,那就先计算奖金,待用
    // 低等奖总奖金 = 三等奖数量*3000 + 四等奖数量*200 + 五等奖数量*10 + 六等奖数量*5
    // 高等奖总奖金 = 奖池总额*0.49 - 低等奖总奖金
    // 一等奖奖金 = 高等奖总奖金*0.75; 二等奖奖金 = 高等奖总奖金*0.25
    float lowTotalPrize = result[2] * 3000.0 + result[3] * 200.0 + result[4] * 10.0 + result[5] * 5.0;
    float advancePrizeBinus = releaseDataCurrent->data.totalPrize * 0.49 - lowTotalPrize;
    float firstPrizeBonus = advancePrizeBinus * 0.75;
    float secondPrizeBonus = advancePrizeBinus * 0.25;
    // 找出中一等奖的用户
    LotteryAccountLinkedList *user = lotteryAccountHead;
    while (user != NULL)
    {
        // 当前用户中一等奖,分发奖金
        if (user->data.AdvanceAward == 1)
        {
            user->data.balance += firstPrizeBonus;
        }
        // 当前用户中二等奖,分发奖金
        if (user->data.AdvanceAward == 2)
        {
            user->data.balance += secondPrizeBonus;
        }
        // 当前用户没有中奖,换下一个用户
        user = user->next;
    }
}

// 打印中奖用户的信息
void DisplayWinner()
{
    // 遍历所有彩票，找到中奖的彩票，打印彩票上的购买者
    TicketDataLinkedList *ticketTemp = ticketDataHead;
    if (ticketTemp == NULL)
    {
        printf("没有用户购买彩票\n");
        return;
    }
    // 打印中奖总数量
    for (int i = 0; i < 6; i++)
    {
        printf("%d等奖用户数量%d\n", i + 1, releaseDataCurrent->data.winLevelCount[i]);
    }
    while (ticketTemp != NULL)
    {
        // winLevel数据，0表示没中奖，1-6表示1到6等奖
        if (ticketTemp->data.winLevel > 0)
        {
            printf("恭喜%s用户中了%d等奖\n", ticketTemp->data.purchaser, ticketTemp->data.winLevel);
            printf("中奖金额%.2f\n", ticketTemp->data.bonus);
        }
        ticketTemp = ticketTemp->next;
    }
}

// 打印某期彩票信息
void ViewSingleRelease(ReleaseDataLinkedlist *release)
{

    if (release == NULL)
    {
        printf("没有找到相关的发布信息\n");
        return;
    }
    printf("\n----------------------------\n");
    printf("\t第%d期\n", release->data.issue);
    printf("\t单价:%d元\n", release->data.price);
    printf("\t开奖状态：");
    release->data.status ? printf("已开奖\n") : printf("未开奖\n");
    printf("\t本期中奖号码:%s\n", release->data.winResult);
    printf("\t本期售出总数:%d\n", release->data.totalSold);
    printf("\t本期奖池总额:%.2f\n", release->data.totalPrize);
    for (int i = 0; i < 6; i++)
    {
        if (release->data.winLevelCount[i] > 0)
        {
            printf("%d等级用户%d个", i + 1, release->data.winLevelCount[i]);
        }
    }
    printf("----------------------------\n");
}

// 统计当前发行期的销售总额、销售量
void CountCurrentReleaseSoldData()
{
    // 如果当前未发行彩票，取消统计
    if (releaseDataCurrent == NULL)
    {
        return;
    }
    int cntNum = 0;
    char empty[22] = {'\0'};
    TicketDataLinkedList *ticketTemp = ticketDataHead;
    while (ticketTemp != NULL)
    {
        // 找到当前期数的彩票
        if (releaseDataCurrent->data.issue == ticketTemp->data.issueNum)
        {
            // 遍历号码
            for (int i = 0; strcmp(ticketTemp->data.numStr[i], empty) != 0 && i < 5; i++)
            {
                cntNum++;
            }
        }
        ticketTemp = ticketTemp->next;
    }
    releaseDataCurrent->data.totalSold = cntNum;
    releaseDataCurrent->data.totalPrize = cntNum * releaseDataCurrent->data.price;
}