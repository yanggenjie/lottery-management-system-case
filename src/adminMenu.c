#include "account.h"
#include "adminMenu.h"
#include "fileIO.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// int issue;        //发行期号
// int price;        //彩票单价
// int status;       //开奖状态
// int totalSold;    //本期售出总数
// float totalPrize; //本期奖池总额

// 发行的彩票信息
TicktetLinkedList *LTHead = NULL;
TicktetLinkedList *LTCurrent = NULL;
// 彩民账号
extern LotteryAccountLinkedList *userHead;
extern LotteryAccountLinkedList *userCurrent;

// 管理员后台主菜单
void AdminMenu()
{
    while (1)
    {
        printf("\t1.发行彩票\n");
        printf("\t2.查询彩民信息\n");
        printf("\t3.排序彩民信息\n");
        printf("\t4.查看发行历史\n");
        printf("\t5.账号管理\n");
        printf("\t6.保存\n");
        printf("\t7.清空所有数据\n");
        printf("\t8.退出登录\n");
        printf("\n*******************************************\n");
        printf("请选择功能：");
        int choose = RecStringConverToInt();
        switch (choose)
        {
        case 1:
            IssueLotteryTickey();
            break;
        case 2:
            QueryLotteryInfoMenu();
            break;
        case 3:
            SortDisplayLotteryMenu();
            break;
        case 4:
            ReleaseView();
            break;
        case 5:
            AccountManager();
            break;
        case 6:
            Save();
            break;
        case 7:
            ClearAllFiledata();
            return;
        case 8:
            return;
        default:
            break;
        }
    }
}

/********************************/
/***********发行彩票功能相关********/

//发行彩票
void IssueLotteryTickey()
{
    printf("输入发行期号(期号格式如:20220901)：");
    unsigned issue = RecStringConverToInt();
    int issueUniqueness = CheckIssueNumberUniqueness(issue); //期号唯一
    int preStatus = CheckPreIssueStatus();                   //开奖状态
    //判断期号唯一性
    if (issueUniqueness)
    {
        //判断上期是否已开奖
        if (preStatus)
        {
            //发行彩票
            TicketData newInfo;
            newInfo.issue = issue; //输入期号
            newInfo.price = 2;     //默认单价
            newInfo.status = 0;    //默认未开奖
            char empty[22] = {'\0'};
            strcpy(newInfo.winResult, empty); //默认没有中奖号码
            newInfo.totalSold = 0;            //初始化售出总数
            newInfo.totalPrize = 0;           //初始化奖池总额
            //初始化中奖数量
            for (int i = 0; i < 6; i++)
            {
                newInfo.winLevelCount[i] = 0;
            }
            //添加到链表
            AddToLottertTickeyLinkedList(newInfo);
        }
        else
        {
            printf("************************\n");
            printf("上期未开奖，无法发布下一期!\n");
            printf("************************\n");
        }
    }
    else
    {
        printf("************************\n");
        printf("期号已发布，请重新检查期号！\n");
        printf("************************\n");
    }
}

//添加到彩票信息链表
void AddToLottertTickeyLinkedList(TicketData newData)
{
    //发行彩票
    TicktetLinkedList *newLT = malloc(sizeof(TicktetLinkedList));
    newLT->data = newData;
    newLT->next = NULL;
    if (LTHead == NULL)
    {
        LTHead = newLT;
        LTCurrent = newLT;
        printf("************************\n");
        printf("第%d期彩票发行成功!", LTCurrent->data.issue);
        DisplayLotteryTicketInfo(LTCurrent);
        printf("************************\n");
        return;
    }
    LTCurrent->next = newLT;
    LTCurrent = newLT;
    printf("************************\n");
    printf("第%d期彩票发行成功!\n", LTCurrent->data.issue);
    DisplayLotteryTicketInfo(LTCurrent);
    printf("************************\n");
}

//判断期号唯一性
int CheckIssueNumberUniqueness(unsigned int issue)
{
    TicktetLinkedList *temp = LTHead;
    while (temp != NULL)
    {
        if (issue == temp->data.issue)
        {
            //在历史中找到相同的期号，说明不唯一，返回0
            return 0;
        }
        temp = temp->next;
    }
    //没有找到，说明输入的期号是唯一的，可以使用
    return 1;
}

//检查上期开奖状态
int CheckPreIssueStatus()
{
    //如果没有发行过任何彩票，则直接发行新期
    if (LTHead == NULL || LTCurrent == NULL)
    {
        return 1;
    }
    else
    {
        //如果已发行过1期以上，未发行新期之前，上一期就是当前期。
        return LTCurrent->data.status;
    }
}

/********************************/
/***********查询功能相关***********/
//查询彩民信息主界面
void QueryLotteryInfoMenu()
{
    while (1)
    {
        printf("\n*******************************************\n");
        printf("\t1.根据彩民账号查询\n");
        printf("\t2.根据账户余额区间查询\n");
        printf("\t3.返回上一级菜单\n");
        printf("\n*******************************************\n");
        printf("请选择功能：");
        int choose = RecStringConverToInt();
        switch (choose)
        {
        case 1:
            QueryByUserName();
            break;
        case 2:
            QueryByBalanceRange();
            break;
        case 3:
            return;
        default:
            break;
        }
    }
}

void QueryByUserName()
{
    char uname[30];
    int check = 0; //检测查询结果数
    printf("输入要查询的用户名：");
    scanf("%s", uname);
    //遍历查询User表
    LotteryAccountLinkedList *temp = userHead;
    if (temp == NULL)
    {
        printf("\n尚不存在任何用户!\n");
        return;
    }
    while (temp != NULL)
    {
        if (strcmp(uname, temp->data.account.name) == 0)
        {
            check++;
            //输出打印彩民信息
            DisplaySingleLotteryInfo(temp);
        }
        temp = temp->next;
    }
    if (check == 0)
    {
        printf("\n没有找到符合条件的用户\n");
        return;
    }
}
void QueryByBalanceRange()
{
    float min, max;
    LotteryAccountLinkedList *temp = userHead;
    int check = 0; //用于检测找到的结果数
    printf("请指定余额区间,结果包含区间边界(格式如:10-20)：");
    scanf("%f-%f", &min, &max);
    if (temp == NULL)
    {
        printf("\n尚不存在任何用户信息!\n");
        return;
    }
    //遍历查找User表
    while ((temp != NULL))
    {
        if (temp->data.balance >= min && temp->data.balance <= max)
        {
            //找到直接输出结果
            check++;
            DisplaySingleLotteryInfo(temp);
        }
        temp = temp->next;
    }
    //如果都没找到，提示结果
    if (check == 0)
    {
        printf("没有找到符合条件的结果!\n");
        return;
    }
    printf("\n总共找到%d个结果\n", check);
}

/********************************/
/***********排序功能相关***********/
//排序功能主界面
void SortDisplayLotteryMenu()
{
    while (1)
    {
        printf("\n*******************************************\n");
        printf("\t1.根据账号排序显示\n");
        printf("\t2.根据账户余额排序显示\n");
        printf("\t3.返回上一级菜单\n");
        printf("\n*******************************************\n");
        printf("请选择功能：");
        int choose = RecStringConverToInt();
        switch (choose)
        {
        case 1:
            SortDisplayLotteryByAccount();
            break;
        case 2:
            SortDisplayLotteryByBalance();
            break;
        case 3:
            return;
        default:
            break;
        }
    }
}

void SortDisplayLotteryByAccount()
{
    //没有任何用户
    if (userHead == NULL)
    {
        printf("\n尚不存在任何用户\n");
        return;
    }
    //只有一个用户，直接打印输出，无需排序
    if (userHead->next == NULL)
    {
        DisplaySingleLotteryInfo(userHead);
        return;
    }

    //有2个以上的用户，进行选择排序，升序排序
    for (LotteryAccountLinkedList *i = userHead; i != NULL; i = i->next)
    {
        //标记最小值
        LotteryAccountLinkedList *min = i;
        //扫描比较
        for (LotteryAccountLinkedList *j = i->next; j != NULL; j = j->next)
        {
            if (strcmp(min->data.account.name, j->data.account.name) > 0)
            {
                min = j;
            }
        }
        //得到更小值之后，节点交换
        //如果是头节点，要重新标记头节点，其他可直接交换
        LotteryAccountLinkedList *prev = FindPreNode(min);
        LotteryAccountLinkedList *next = min->next;
        if (prev == userHead)
        {
            userHead->next = min->next;
            min->next = userHead;
            userHead = min;
            break;
        }
        min->next = userHead->next;
        prev->next = userHead;
        userHead->next = next;
        userHead = min;
    }
    //打印输出信息
    DisplayAllLottery();
}
void SortDisplayLotteryByBalance()
{
    //没有任何用户
    if (userHead == NULL)
    {
        printf("\n尚不存在任何用户\n");
        return;
    }
    //只有一个用户，直接打印输出，无需排序
    if (userHead->next == NULL)
    {
        DisplaySingleLotteryInfo(userHead);
        return;
    }

    //有2个以上的用户，进行选择排序，升序排序
    for (LotteryAccountLinkedList *i = userHead; i != NULL; i = i->next)
    {
        //标记最小值
        LotteryAccountLinkedList *min = i;
        //扫描比较
        for (LotteryAccountLinkedList *j = i->next; j != NULL; j = j->next)
        {
            if (min->data.balance > j->data.balance)
            {
                min = j;
            }
        }
        //得到更小值之后，节点交换
        //如果是头节点，要重新标记头节点，其他可直接交换
        LotteryAccountLinkedList *prev = FindPreNode(min);
        LotteryAccountLinkedList *next = min->next;
        if (prev == userHead)
        {
            userHead->next = min->next;
            min->next = userHead;
            userHead = min;
            break;
        }
        min->next = userHead->next;
        prev->next = userHead;
        userHead->next = next;
        userHead = min;
    }
    //打印输出信息
    DisplayAllLottery();
}

LotteryAccountLinkedList *FindPreNode(LotteryAccountLinkedList *currentNode)
{
    LotteryAccountLinkedList *temp = userHead;
    if (currentNode == userHead)
    {
        return NULL;
    }
    while (temp != NULL)
    {
        if (temp->next == currentNode)
        {
            return temp;
        }
        temp = temp->next;
    }
}

//显示所有彩民信息
void DisplayAllLottery()
{
    LotteryAccountLinkedList *temp = userHead;
    if (temp == NULL)
    {
        printf("尚不存在任何用户\n");
    }
    while (temp != NULL)
    {
        DisplaySingleLotteryInfo(temp);
        temp = temp->next;
    }
}
//输出单个彩民信息
void DisplaySingleLotteryInfo(LotteryAccountLinkedList *userNode)
{
    if (userNode == NULL)
    {
        printf("要显示的用户不存在，\n");
        return;
    }
    printf("账号：%s\t", userNode->data.account.name);
    // printf("密码：%s\t", userNode->account.pwd);
    printf("余额：%.2f\n", userNode->data.balance);
}

/********************************/
/*********账号管理功能相关**********/
//账号管理
void AccountManager()
{
    while (1)
    {
        printf("\n*******************************************\n");
        printf("\t1.添加管理员账号\n");
        printf("\t2.删除管理员账号\n");
        printf("\t3.添加公证员账号\n");
        printf("\t4.删除公证员账号\n");
        printf("\t5.返回上一级菜单\n");
        printf("\n*******************************************\n");
        printf("请选择功能：");
        int choose = RecStringConverToInt();
        switch (choose)
        {
        case 1:
            AddAdminAccount();
            break;
        case 2:
            break;
        case 3:
            AddNotaryAccount();
            break;
        case 4:
            break;
        case 5:
            return;
        default:
            break;
        }
    }
}
//查看发行历史
void ReleaseView()
{
    TicktetLinkedList *temp = LTHead;
    if (temp == NULL)
    {
        printf("\n*********尚未发行过彩票**********\n");
        return;
    }
    while (temp != NULL)
    {
        //打印彩票信息
        DisplayLotteryTicketInfo(temp);
        temp = temp->next;
    }
}
//打印某期彩票信息
void DisplayLotteryTicketInfo(TicktetLinkedList *LT)
{
    if (LT == NULL)
    {
        printf("没有找到相关的发布信息\n");
        return;
    }
    printf("\n----------------------------\n");
    printf("\t第%d期\n", LT->data.issue);
    printf("\t单价:%d元\n", LT->data.price);
    if (LT->data.status)
    {
        printf("\t开奖状态：已开奖\n");
    }
    else
    {
        printf("\t开奖状态：未开奖\n");
    }
    printf("\t本期中奖号码:%s\n", LT->data.winResult);
    printf("\t本期售出总数:%d\n", LT->data.totalSold);
    printf("\t本期奖池总额:%.2f\n", LT->data.totalPrize);
    printf("----------------------------\n");
}

/********************************/
/*********保存功能相关**********/
void Save()
{
    while (1)
    {
        printf("\n*******************************************\n");
        printf("\t1.保存彩票发行信息\n");
        printf("\t2.保存公证员账号\n");
        printf("\t3.保存管理员账号\n");
        printf("\t4.返回上一级菜单\n");
        printf("\n*******************************************\n");
        printf("请选择功能：");
        int choose = RecStringConverToInt();
        switch (choose)
        {
        case 1:
            WriteLotteryTicketInfoToBin();
            break;
        case 2:
            printf("尚未开通\n");
            break;
        case 3:
            printf("尚未开通\n");
            break;
        case 4:
            return;
        default:
            break;
        }
    }
}

// 接收字符串,转为整型
int RecStringConverToInt()
{
    char str1[100];
    int choose;
    scanf("%s", str1);
    //接受完毕，清空缓存流，防止用户误输入的数据对下一次输入的影响
    while (getchar() != 10)
    {
    };
    return atoi(str1);
}

//清空数据
void ClearAllFiledata()
{
    //清空彩票信息
    FILE *LTFile = fopen("data/LotteryTicket.dat", "wb");
    if (LTFile == NULL)
    {
        perror("data/Lottery.dat");
        exit(EXIT_FAILURE);
    }
    TicketData empty;
    fwrite(&empty, sizeof(TicktetLinkedList), 0, LTFile);
    fclose(LTFile);
    //清空彩民账号

    //
}