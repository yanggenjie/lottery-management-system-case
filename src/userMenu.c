/*
 * 当前文件：userMenu
 * 文件描述：实现彩民界面相关功能
 */
#include "account.h"
#include "userMenu.h"
#include "adminMenu.h"
#include "notaryMenu.h"
#include "fileIO.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

// 单张彩票信息
TicketDataLinkedList *ticketDataHead = NULL;
TicketDataLinkedList *ticketDataCurrent = NULL;

// 彩民当前登录的账号
extern LotteryAccountLinkedList *lotteryCurrentLogin;
// 彩民账号
extern LotteryAccountLinkedList *lotteryAccountHead;
extern LotteryAccountLinkedList *lotteryAccountCurrent;
// 彩票发行信息
extern ReleaseDataLinkedlist *releaseDataHead;
extern ReleaseDataLinkedlist *releaseDataCurrent;

// 彩民客户端主界面
void UserMenu()
{
    for (;;)
    {
        printf("\t1.查看个人信息\n");
        printf("\t2.修改密码\n");
        printf("\t3.账户充值\n");
        printf("\t4.下注\n");
        printf("\t5.查看购买记录\n");
        printf("\t6.注销账号\n");
        printf("\t7.退出登录\n");
        printf("\n*******************************************\n");
        printf("请选择功能：");
        int choose = RecStringConverToInt();
        switch (choose)
        {
        case 1:
            ViewPersonalInfo(lotteryCurrentLogin);
            break;
        case 2:
            ChangePassword();
            break;
        case 3:
            Recharge();
            break;
        case 4:
            Bet();
            break;
        case 5:
            ViewTicketDataHistory();
            break;
        case 6:
            DeleteLotteryAccount();
            // 保存账号文件
            WriteLotteryAccountToBin();
            // 退出登录
            break;
        case 7:
            return;
        default:
            break;
        }
    }
}

// 查看彩民信息
void ViewPersonalInfo(LotteryAccountLinkedList *userNode)
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

// 修改密码
void ChangePassword()
{
    char oldPasswd[32];
    char newPasswd1[32];
    char newPasswd2[32];
    int cnt = 0; // 密码输错计数器,输错3次退出修改密码程序。
    do
    {
        if (lotteryCurrentLogin == NULL)
        {
            printf("未检测到当前用户信息\n");
            return;
        }
        printf("请输入原密码:");
        scanf("%s", oldPasswd);
        if (strcmp(oldPasswd, lotteryCurrentLogin->data.account.pwd) == 0)
        {
            printf("请输入新密码:");
            scanf("%s", newPasswd1);
            printf("再次确认新密码:");
            scanf("%s", newPasswd2);
            if (strcmp(newPasswd1, newPasswd2) == 0)
            {
                strcpy(lotteryCurrentLogin->data.account.pwd, newPasswd1);
                printf("密码修改成功,新密码为：%s\n", lotteryCurrentLogin->data.account.pwd);
                printf("下次登录生效,请尽快使用新密码重新登录\n");
                // 保存彩民账号文件
                WriteLotteryAccountToBin();
                return;
            }
            else
            {
                printf("两次密码不一致,请重新输入\n");
            }
        }
        else
        {
            cnt++;
            if (cnt == 3)
            {
                printf("密码输入错误%d次,取消密码修改\n", cnt);
                // 返回主菜单
                return;
            }
            printf("密码输入错误%d次,请重新输入\n", cnt);
        }
    } while (cnt < 3);
}
// 充值
void Recharge()
{
    float rechargeNum = 0;
    printf("当前余额：%.2f\n", lotteryCurrentLogin->data.balance);
    printf("要充值的金额:");
    scanf("%f", &rechargeNum);
    while (getchar() != 10)
    {
    };
    lotteryCurrentLogin->data.balance += rechargeNum;
    printf("充值成功!\n");
    printf("当前余额:%.2f\n", lotteryCurrentLogin->data.balance);
    // 保存彩民账号文件
    WriteLotteryAccountToBin();
}

/********************************/
/***********下注相关功能*********/
// 下注
void Bet()
{

    // 判断当前是否有彩票发行
    if (releaseDataHead == NULL)
    {
        printf("------------------------------------------\n");
        printf("尚未发行任何彩票,无法使用下注功能,请关注后续公告\n");
        printf("------------------------------------------\n");
        return;
    }
    // 如果存在发行的彩票,更新发行信息，并显示发行信息
    printf("\n当前发行期数为%d,具体信息如下:", releaseDataCurrent->data.issue);
    ViewSingleRelease(releaseDataCurrent);

    // 如果当前发行已经开奖,不能下注,只能下注未开奖的
    if (releaseDataCurrent->data.status)
    {
        printf("------------------------------------------\n");
        printf("当前彩票期数已经开奖了,无法下注,请关注后续公告\n");
        printf("------------------------------------------\n");
        return;
    }

    // 满足以上条件,开始下注
    printf("\t你要下几注?():");
    int number = RecStringConverToInt();
    if (number > 5)
    {
        printf("----------------------------\n");
        printf("注意:单张彩票最多能下5注,将为您购买多张彩票\n"); // 提示单张彩票最多可下5注
        printf("----------------------------\n");
    }

    // 如果余额不足,无法进行下注,先提示充值
    // 当前余额 - 单价*注数 < 0,说明余额不足
    int condition1 = (lotteryCurrentLogin->data.balance - releaseDataCurrent->data.price * number) < 0;
    if (condition1)
    {
        printf("您购买%d注号码,预计%d元\n", number, releaseDataCurrent->data.price * number);
        printf("您当前余额为:%.2f,余额不足,请先进行充值。\n", lotteryCurrentLogin->data.balance);
        return;
    }

    // 条件满足,可以选择下注方式
    printf("请选择投注方式：\n\n1.自选号码投注\t2.机选号码投注\n\n");
    int choose = RecStringConverToInt();
    switch (choose)
    {
    case 1:
        printf("暂不支持手动选号,待开发!\n");
        break;
    case 2:
        MachineSelection(number);
        break;
    default:
        break;
    }
}

// 机选号码
void MachineSelection(int n)
{
    TicketData newSoldData;
    // 生成唯一id序列
    IDGeneratorWithTimeAndRandNum(newSoldData.id);
    // 初始化彩票发行号
    newSoldData.issueNum = releaseDataCurrent->data.issue;
    // 初始化本期开奖状态
    newSoldData.status = releaseDataCurrent->data.status;
    // 标记购买者账号
    strcpy(newSoldData.purchaser, lotteryCurrentLogin->data.account.name);
    // 初始化中奖等级
    newSoldData.winLevel = 0;
    // 初始化中奖金额
    newSoldData.bonus = 0;
    // 清空字符数组，为避免垃圾数据对新数据的影响，在初始化前后清空其中的垃圾数据
    EmptyNumStr(&newSoldData);

    // 本张彩票选中的号码数据
    // 下注5个号码以内(包含5)
    if (n <= 5)
    {
        // 机选号码生成
        for (int i = 0; i < n; i++)
        {
            // 生成随机字符串
            char nums[22] = {'\0'};
            randomNum(nums);
            // 机选号码赋值
            strcpy(newSoldData.numStr[i], nums);
        }
        // 添加到链表之前检查id是否重复
        if (CheckIDUniqueness(newSoldData.id))
        {
            IDGeneratorWithTimeAndRandNum(newSoldData.id);
        }
        // 添加数据到链表
        AddToTicketDataLinkedList(newSoldData);
        // 清空字符数组
        EmptyNumStr(&newSoldData);
    }
    // 下注超过5个号,拆分多张彩票

    if (n > 5)
    {
        // 被5整除的部分，填满n/5张彩票。
        // 如n = 11，应该用三彩票存放
        // 前面2张彩票都有5个号码，循环n/5次，每次填充5个号码
        for (int i = 0; i < (n / 5); i++)
        {
            for (int j = 0; j < 5; j++)
            {
                char nums[30] = {'\0'};
                // 生成随机字符串
                randomNum(nums);
                // 赋值
                strcpy(newSoldData.numStr[j], nums);
            }
            // 添加到链表之前检查id是否重复
            if (CheckIDUniqueness(newSoldData.id))
            {
                IDGeneratorWithTimeAndRandNum(newSoldData.id);
            }
            // 添加数据到链表
            AddToTicketDataLinkedList(newSoldData);
            // 清空字符数组
            EmptyNumStr(&newSoldData);
        }
        // 11%5=1，最后一张彩票只添加1张彩票，只执行1次，且只添加n%5个号码,n%5==0，不执行添加链表操作
        if (n % 5)
        {
            for (int j = 0; j < n % 5; j++)
            {
                char nums[30] = {'\0'};
                // 生成随机字符串
                randomNum(nums);
                strcpy(newSoldData.numStr[j], nums);
            }
            // 添加到链表之前检查id是否重复
            if (CheckIDUniqueness(newSoldData.id))
            {
                IDGeneratorWithTimeAndRandNum(newSoldData.id);
            }
            // 添加数据到链表
            AddToTicketDataLinkedList(newSoldData);
        }
        // 清空字符数组
        EmptyNumStr(&newSoldData);
    }
    // 显示下注结果
    DisplaySelectedResult();
    // 选完更新余额
    lotteryCurrentLogin->data.balance -= n * releaseDataCurrent->data.price;
    // 更新用户购买的彩票数、号码数
    ReCountUserTicketData(lotteryCurrentLogin);
    // 统计当期的销售总额、销售量
    CountCurrentReleaseSoldData();
    // 保存发行信息文件
    WriteReleaseDataToBin();
    // 保存彩民账号文件
    WriteLotteryAccountToBin();
    // 保存彩民购买的彩票历史
    WriteTicketDataToFile();
}

// 清空字符数组
void EmptyNumStr(TicketDataLinkedList *newData)
{
    char empty[30] = {'\0'};
    for (int i = 0; i < 5; i++)
    {
        strcpy(newData->data.numStr[i], empty);
    }
}

// 添加到彩票数据链表
void AddToTicketDataLinkedList(TicketData newData)
{
    // 申请新节点
    TicketDataLinkedList *newNode = malloc(sizeof(TicketDataLinkedList));
    // 初始化
    newNode->data = newData;
    newNode->next = NULL;
    if (ticketDataHead == NULL)
    {
        // 没有头节点,标记为头节点
        ticketDataHead = newNode;
        ticketDataCurrent = newNode;
        return;
    }
    // 已存在头节点,连接到节点尾部
    ticketDataCurrent->next = newNode;
    ticketDataCurrent = newNode;
}

// 生成随机数
void randomNum(char *nums)
{
    char emptyContainer[30] = {'\0'};
    int red[6] = {0}, blue = 0;
    do
    {
        // 6红色球号码从1—33中选择；1蓝色球号码从1—16中选择。
        for (int i = 0; i < 6; i++)
        {
            char temp[5] = {'\0'};
            red[i] = rand() % 33 + 1;
            // 1-9在前面加0组成双位数
            if (red[i] >= 1 && red[i] <= 9)
            {
                sprintf(temp, "0%d-", red[i]);
                strcat(emptyContainer, temp);
                continue;
            }
            sprintf(temp, "%d-", red[i]);
            strcat(emptyContainer, temp);
        }
        blue = rand() % 16 + 1;
        char blues[10] = {'\0'};
        // 1-9在前面加0组成双位数
        if (blue >= 1 && blue <= 9)
        {
            sprintf(blues, "0%d", blue);
        }
        else
        {
            sprintf(blues, "%d", blue);
        }
        // 得到随机数
        strcat(emptyContainer, blues);
    } while (CheckBetNumberUniqueness(emptyContainer));
    strcpy(nums, emptyContainer);
}

// 检查号码重复性,所有账号的
int CheckBetNumberUniqueness(char nums[])
{
    // 从第一个账号开始遍历
    TicketDataLinkedList *ticketTemp = ticketDataHead;
    if (ticketTemp == NULL)
    {
        return 0;
    }
    char empty[22] = {'\0'};
    while (ticketTemp != NULL)
    {
        for (int i = 0; strcmp(ticketTemp->data.numStr[i], empty) != 0 && i < 5; i++)
        {
            if (strcmp(nums, ticketTemp->data.numStr[i]) == 0)
            {
                return 1;
            }
        }
        ticketTemp = ticketTemp->next;
    }
    return 0;
}
// 彩票ID生成器
void IDGeneratorWithTimeAndRandNum(char *id)
{
    // 用时间戳+3位数的随机字符指定id，最大限度降低id重复率，目前生成字符串的长度为28
    char emptyContainer[30] = {'\0'};
    char randStr[10] = {'\0'};
    time_t now = time(NULL);
    // int randNum = rand() % 999 + 100;
    // 生成时间序列
    // strftime：将struct tm转为指定格式的字符串，并复制到指定地址
    strftime(emptyContainer, sizeof(emptyContainer), "%F %T%z ", localtime(&now));
    // 生成三位数的随机数,保存到randStr
    sprintf(randStr, "%d", (rand() % 898 + 101));
    strcat(emptyContainer, randStr);
    strcpy(id, emptyContainer);
}

// id重复性检测
int CheckIDUniqueness(char *id)
{
    TicketDataLinkedList *ticketTemp = ticketDataHead;
    while (ticketTemp != NULL)
    {
        if (strcmp(id, ticketTemp->data.id) == 0)
        {
            return 1;
        }
        ticketTemp = ticketTemp->next;
    }
    return 0;
}

// 下注成功通知
void DisplaySelectedResult()
{
    printf("----------------------------\n");
    printf("下注成功,请到【购买记录】查看详情。\n\n");
    printf("感谢使用彩票管理系统,敬请期待开奖结果!\n");
    printf("----------------------------\n");
}

/********************************/
/***********注销账号相关***********/

// 删除彩民账号
void DeleteLotteryAccount()
{
    int confirm = DeleteLotteryAccountConfirm();
    if (confirm)
    {
        // 仅有当前一个账号
        if (lotteryCurrentLogin == lotteryAccountHead && lotteryAccountHead->next == NULL)
        {
            // 头节点指向空
            lotteryAccountHead = NULL;
            lotteryAccountCurrent = NULL;
            // 退出登录
            return;
        }
        // 有多个账号,当前账号处于第一个节点
        if (lotteryAccountHead->next != NULL && lotteryCurrentLogin == lotteryAccountHead)
        {
            // 头节点往后移动
            lotteryAccountHead = lotteryCurrentLogin->next;
            // 退出登录
            return;
        }
        // 有多个账号,当前账号不在头节点
        if (lotteryAccountHead->next != NULL && lotteryCurrentLogin != lotteryAccountCurrent)
        {
            // 找到当前节点的前一节点
            LotteryAccountLinkedList *prev = FindLotteryAccountPreNode(lotteryCurrentLogin);
            // 前一节点指向下一节点
            if (lotteryCurrentLogin->next == NULL)
            {
                prev->next = NULL;
                return;
            }
            prev->next = lotteryCurrentLogin->next;
            return;
        }
    }
}

// 删除彩民账号操作确认
int DeleteLotteryAccountConfirm()
{
    char uname[30];
    printf("×××××××××××××××××××××××××××××\n");
    printf("此操作属于风险极高,请谨慎操作!\n");
    printf("×××××××××××××××××××××××××××××\n");
    printf("---------------------------\n");
    printf("您当前账户：\n");
    printf("用户名\t账户余额(元)\t当期购买(彩票/张)\t当期下注(号码/个)\t历史购买(彩票/张)\t历史下注(号码/个)\n");
    DisplaySingleLotteryInfo(lotteryCurrentLogin); // 显示账户信息
    printf("---------------------------\n");
    printf("注销账户之后,您的账户金额将被清空,且不可恢复！\n");
    printf("您购买彩票的历史订单将被移除,且不可恢复！\n");
    printf("---------------------------\n");
    printf("请输入当前账户名 %s 确认删除", lotteryCurrentLogin->data.account.name);
    printf("---------------------------\n");
    scanf("%s", uname);
    if (strcmp(uname, lotteryCurrentLogin->data.account.name) == 0)
    {
        printf("确认删除?\n1.确认\t2.取消");
        int choose = RecStringConverToInt();
        switch (choose)
        {
        case 1:
            return 1;
        case 2:
            return 0;
        default:
            printf("没有选择正确的选项,取消操作!\n");
            return 0;
        }
    }
    printf("用户名不匹配,取消操作!\n");
    return 0;
}
/********************************/
/***********查看历史记录***********/
// 查看历史记录
void ViewTicketDataHistory()
{
    TicketDataLinkedList *ticketDataTemp = ticketDataHead;
    if (ticketDataTemp == NULL)
    {
        printf("没有找到相关数据\n");
        return;
    }
    while (ticketDataTemp != NULL)
    {
        if (strcmp(lotteryCurrentLogin->data.account.name, ticketDataTemp->data.purchaser) == 0)
        {
            // 打印
            DisplayTicketData(ticketDataTemp);
        }
        ticketDataTemp = ticketDataTemp->next;
    }
}

void DisplayTicketData(TicketDataLinkedList *ticketData)
{
    char empty[22] = {'\0'};
    printf("您购买的彩票信息如下:\n");
    printf("---------------------------\n");
    printf("ID:%s\n", ticketData->data.id);
    printf("发行号:%d\n", ticketData->data.issueNum);
    printf("开奖状态:");
    ticketData->data.status ? printf("已开奖\n") : printf("未开奖\n");
    printf("购买者:%s\n", ticketData->data.purchaser);
    printf("中奖等级:");
    ticketData->data.winLevel ? printf("%d等奖\n", ticketData->data.winLevel) : printf("未中奖\n");
    printf("中奖金额:%.2f\n", ticketData->data.bonus);
    for (int i = 0; strcmp(ticketData->data.numStr[i], empty) != 0 && i < 5; i++)
    {
        printf("%c   %s\n", 'A' + i, ticketData->data.numStr[i]);
    }
    printf("---------------------------\n");
}

// 统计用户购买的彩票数据
void ReCountUserTicketData(LotteryAccountLinkedList *user)
{
    if (user == NULL)
    {
        return;
    }
    TicketDataLinkedList *ticketDataTemp = ticketDataHead;

    unsigned cntCurrentTicket = 0;
    unsigned cntCurrentNums = 0;
    unsigned cntAllTicket = 0;
    unsigned cntAllNums = 0;
    char empty[22] = {'\0'};
    if (ticketDataTemp == NULL)
    {
        return;
    }
    while (ticketDataTemp != NULL)
    {
        // 通过用户名查找到彩票数据
        if (strcmp(ticketDataTemp->data.purchaser, user->data.account.name) == 0)
        {
            // 统计当前用户所有期的彩票
            cntAllTicket++;
            for (int i = 0; strcmp(ticketDataTemp->data.numStr[i], empty) != 0 && i < 5; i++)
            {
                // 统计当前用户所有发行期的号码数
                cntAllNums++;
            }
            if (ticketDataTemp->data.issueNum == releaseDataCurrent->data.issue)
            {
                // 统计当前用户当前彩票数据中，期数与当前发行期数相同的彩票
                cntCurrentTicket++;
                for (int i = 0; strcmp(ticketDataTemp->data.numStr[i], empty) != 0 && i < 5; i++)
                {
                    // 统计当前用户当前彩票数据中，期数与当前发行期数相同的号码数
                    cntCurrentNums++;
                }
            }
        }
        ticketDataTemp = ticketDataTemp->next;
    }
    user->data.currentReleaseTickets = cntCurrentTicket;
    user->data.currentReleaseTicketNums = cntCurrentNums;
    user->data.allReleaseTickets = cntAllTicket;
    user->data.allReleaseTicketNums = cntAllNums;
}
