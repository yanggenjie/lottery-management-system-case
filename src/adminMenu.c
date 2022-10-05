#include "account.h"
#include "adminMenu.h"
#include "notaryMenu.h"
#include "userMenu.h"
#include "fileIO.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 发行的彩票信息
ReleaseDataLinkedlist *releaseDataHead = NULL;
ReleaseDataLinkedlist *releaseDataCurrent = NULL;
// 彩民账号
extern LotteryAccountLinkedList *lotteryAccountHead;
extern LotteryAccountLinkedList *lotteryAccountCurrent;

// 管理员后台主菜单
void AdminMenu()
{
    for (;;)
    {
        printf("\t1.发行彩票\n");
        printf("\t2.查询彩民信息\n");
        printf("\t3.排序彩民信息\n");
        printf("\t4.查看发行历史\n");
        printf("\t5.账号管理\n");
        printf("\t6.保存\n");
        printf("\t7.退出登录\n");
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
            ViewAllRelease();
            break;
        case 5:
            AccountManagerMenu();
            break;
        case 6:
            SaveMenu();
            break;
        case 7:
            return;
        default:
            break;
        }
    }
}

/********************************/
/***********发行彩票功能相关********/

// 发行彩票
void IssueLotteryTickey()
{
    int preStatus = CheckPreIssueStatus(); // 开奖状态判断码
    if (preStatus)                         // 判断上期是否已开奖
    {
        if (releaseDataHead == NULL)
        {
            printf("输入发行期号(当前未发行过任何彩票):");
        }
        else
        {
            printf("输入发行期号(当前发行号%d):", releaseDataCurrent->data.issue);
        }
        int issue = RecStringConverToInt();                      // 期号输入
        int issueUniqueness = CheckIssueNumberUniqueness(issue); // 期号唯一判断码
        // 判断期号唯一性
        if (issueUniqueness)
        {
            // 发行彩票
            ReleaseData newInfo;
            newInfo.issue = issue; // 输入期号
            newInfo.price = 2;     // 默认单价
            newInfo.status = 0;    // 默认未开奖
            char empty[22] = {'\0'};
            strcpy(newInfo.winResult, empty); // 初始化中奖号码为空
            newInfo.totalSold = 0;            // 初始化售出总数
            newInfo.totalPrize = 0;           // 初始化奖池总额
            // 初始化中奖数量
            for (int i = 0; i < 6; i++)
            {
                newInfo.winLevelCount[i] = 0;
            }
            // 添加到链表
            AddToReleaseDataLinkedList(newInfo);
            printf("************************\n");
            printf("第%d期彩票发行成功!", releaseDataCurrent->data.issue);
            ViewSingleRelease(releaseDataCurrent);
            printf("************************\n");
        }
        else
        {
            printf("************************\n");
            printf("期号已发布,请重新检查期号！\n");
            printf("************************\n");
        }
    }
    else
    {

        printf("************************\n");
        printf("上期未开奖,无法发布下一期!\n");
        printf("************************\n");
    }
}

// 添加到彩票信息链表
void AddToReleaseDataLinkedList(ReleaseData newData)
{
    ReleaseDataLinkedlist *newNode = malloc(sizeof(ReleaseDataLinkedlist));
    newNode->data = newData;
    newNode->next = NULL;
    if (releaseDataHead == NULL)
    {
        releaseDataHead = newNode;
        releaseDataCurrent = newNode;
        return;
    }
    releaseDataCurrent->next = newNode;
    releaseDataCurrent = newNode;
}

// 判断期号唯一性
int CheckIssueNumberUniqueness(unsigned int issue)
{
    ReleaseDataLinkedlist *temp = releaseDataHead;
    while (temp != NULL)
    {
        if (issue == temp->data.issue)
        {
            // 在历史中找到相同的期号,说明不唯一,返回0
            return 0;
        }
        temp = temp->next;
    }
    // 没有找到,说明输入的期号是唯一的,可以使用
    return 1;
}

// 检查上期开奖状态
int CheckPreIssueStatus()
{
    // 如果没有发行过任何彩票,则直接发行新期
    if (releaseDataHead == NULL || releaseDataCurrent == NULL)
    {
        return 1;
    }
    else
    {
        // 如果已发行过1期以上,未发行新期之前,上一期就是当前期。
        return releaseDataCurrent->data.status;
    }
}

/********************************/
/***********查询功能相关***********/
// 查询彩民信息主界面
void QueryLotteryInfoMenu()
{
    for (;;)
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
// 根据彩民账号(用户名)查询
void QueryByUserName()
{
    char uname[30];
    int check = 0; // 检测查询结果数
    printf("输入要查询的用户名：");
    scanf("%s", uname);
    // 遍历查询User表
    LotteryAccountLinkedList *temp = lotteryAccountHead;
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
            // 输出打印彩民信息
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
// 根据账户余额查询
void QueryByBalanceRange()
{
    float min, max;
    LotteryAccountLinkedList *temp = lotteryAccountHead;
    int check = 0; // 用于检测找到的结果数
    printf("请指定余额区间,结果包含区间边界(格式如:10-20)：");
    scanf("%f-%f", &min, &max);
    if (temp == NULL)
    {
        printf("\n尚不存在任何用户信息!\n");
        return;
    }
    // 遍历查找User表
    while ((temp != NULL))
    {
        if (temp->data.balance >= min && temp->data.balance <= max)
        {
            // 找到直接输出结果
            check++;
            DisplaySingleLotteryInfo(temp);
        }
        temp = temp->next;
    }
    // 如果都没找到,提示结果
    if (check == 0)
    {
        printf("没有找到符合条件的结果!\n");
        return;
    }
    printf("\n总共找到%d个结果\n", check);
}

/********************************/
/***********排序功能相关***********/
// 排序功能主界面
void SortDisplayLotteryMenu()
{
    for (;;)
    {
        printf("\n*******************************************\n");

        printf("\t1.显示所有彩民信息\n");
        printf("\t1.根据账号排序显示\n");
        printf("\t3.根据账户余额排序显示\n");
        printf("\t4.返回上一级菜单\n");
        printf("\n*******************************************\n");
        printf("请选择功能：");
        int choose = RecStringConverToInt();
        switch (choose)
        {
        case 1:
            DisplayAllLottery();
            break;
        case 2:
            SortDisplayLotteryByAccount();
            break;
        case 3:
            SortDisplayLotteryByBalance();
            break;
        case 4:
            return;
        default:
            break;
        }
    }
}
// 根据账号排序显示

void SortDisplayLotteryByAccount()
{
    // 没有任何用户
    if (lotteryAccountHead == NULL)
    {
        printf("\n尚不存在任何用户\n");
        return;
    }
    // 只有一个用户,直接打印输出,无需排序
    if (lotteryAccountHead->next == NULL)
    {
        DisplaySingleLotteryInfo(lotteryAccountHead);
        return;
    }

    // 有2个以上的用户,进行选择排序,升序排序
    for (LotteryAccountLinkedList *i = lotteryAccountHead; i != NULL; i = i->next)
    {
        // 标记最小值
        LotteryAccountLinkedList *min = i;
        // 扫描比较
        for (LotteryAccountLinkedList *j = i->next; j != NULL; j = j->next)
        {
            if (strcmp(min->data.account.name, j->data.account.name) > 0)
            {
                min = j;
            }
        }
        // 得到更小值之后,节点交换
        // 如果是头节点,要重新标记头节点,其他可直接交换
        LotteryAccountLinkedList *prev = FindLotteryAccountPreNode(min);
        LotteryAccountLinkedList *next = min->next;
        if (prev == lotteryAccountHead)
        {
            lotteryAccountHead->next = min->next;
            min->next = lotteryAccountHead;
            lotteryAccountHead = min;
            break;
        }
        min->next = lotteryAccountHead->next;
        prev->next = lotteryAccountHead;
        lotteryAccountHead->next = next;
        lotteryAccountHead = min;
    }
    // 打印输出信息
    DisplayAllLottery();
}
// 根据余额排序显示
void SortDisplayLotteryByBalance()
{
    // 没有任何用户
    if (lotteryAccountHead == NULL)
    {
        printf("\n尚不存在任何用户\n");
        return;
    }
    // 只有一个用户,直接打印输出,无需排序
    if (lotteryAccountHead->next == NULL)
    {
        DisplaySingleLotteryInfo(lotteryAccountHead);
        return;
    }

    // 有2个以上的用户,进行选择排序,升序排序
    for (LotteryAccountLinkedList *i = lotteryAccountHead; i != NULL; i = i->next)
    {
        // 标记最小值
        LotteryAccountLinkedList *min = i;
        // 扫描比较
        for (LotteryAccountLinkedList *j = i->next; j != NULL; j = j->next)
        {
            if (min->data.balance > j->data.balance)
            {
                min = j;
            }
        }
        // 得到更小值之后,节点交换
        // 如果是头节点,要重新标记头节点,其他可直接交换
        LotteryAccountLinkedList *prev = FindLotteryAccountPreNode(min);
        LotteryAccountLinkedList *next = min->next;
        if (prev == lotteryAccountHead)
        {
            lotteryAccountHead->next = min->next;
            min->next = lotteryAccountHead;
            lotteryAccountHead = min;
            break;
        }
        min->next = lotteryAccountHead->next;
        prev->next = lotteryAccountHead;
        lotteryAccountHead->next = next;
        lotteryAccountHead = min;
    }
    // 打印输出信息
    DisplayAllLottery();
}

// 显示所有彩民信息
void DisplayAllLottery()
{
    LotteryAccountLinkedList *temp = lotteryAccountHead;
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
// 输出单个彩民信息
void DisplaySingleLotteryInfo(LotteryAccountLinkedList *userNode)
{
    if (userNode == NULL)
    {
        printf("用户信息不存在,\n");
        return;
    }
    ReCountUserTicketData(userNode);
    printf("------------------------------------------\n");
    printf("用户名：%s\n", userNode->data.account.name);
    printf("账户余额：%.2f 元\n", userNode->data.balance);
    // printf("当期已购：%d张彩票\n", userNode->data.tickets);
    printf("当期购买：%d张彩票\n", userNode->data.currentReleaseTickets);
    printf("当期下注：%d个号码\n", userNode->data.currentReleaseTicketNums);
    printf("历史购买：%d张彩票\n", userNode->data.allReleaseTickets);
    printf("历史下注：%d个号码\n", userNode->data.allReleaseTicketNums);
    printf("------------------------------------------\n");
}

// 查看发行历史
void ViewAllRelease()
{
    ReleaseDataLinkedlist *releaseData = releaseDataHead;
    if (releaseData == NULL)
    {
        printf("\n*********尚未发行过彩票**********\n");
        return;
    }
    while (releaseData != NULL)
    {
        // 打印彩票信息
        ViewSingleRelease(releaseData);
        releaseData = releaseData->next;
    }
}

/********************************/
/*********保存功能相关**********/
void SaveMenu()
{
    for (;;)
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
            WriteReleaseDataToBin();
            printf("\n------------------------------\n");
            printf("发行信息保存成功,感谢使用彩票管理系统\n");
            printf("\n------------------------------\n");
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
    // 接受完毕,清空缓存流,防止用户误输入的数据对下一次输入的影响
    while (getchar() != 10)
    {
    };
    return atoi(str1);
}
