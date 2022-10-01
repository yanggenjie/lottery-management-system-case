#include "account.h"
#include "userMenu.h"
#include "adminMenu.h"
#include "fileIO.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
// 彩民当前登录的账号
extern LotteryAccountLinkedList *lotteryCurrentLogin;
// 彩民账号
extern LotteryAccountLinkedList *userHead;
extern LotteryAccountLinkedList *userCurrent;
// 彩票发行信息
extern ReleaseDataLinkedlist *releaseDataHead;
extern ReleaseDataLinkedlist *releaseDataCurrent;

//彩民客户端主界面
void UserMenu()
{
    while (1)
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
            DisplaySingleLotteryInfo(lotteryCurrentLogin);
            break;
        case 2:
            ChangePassword();
            //保存彩民账号文件
            WriteLotteryAccountToBin();
            break;
        case 3:
            Recharge();
            //保存彩民账号文件
            WriteLotteryAccountToBin();
            break;
        case 4:
            Bet();
            //保存发行信息文件
            WriteReleaseDataToBin();
            //保存彩民账号文件
            WriteLotteryAccountToBin();
            //保存彩民购买的彩票历史
            WriteBoughtHistoryToFile();
            break;
        case 5:
            DisplayUserBoughtData(lotteryCurrentLogin);
            break;
        case 6:
            DeleteLotteryAccount();
            //更新彩民账号文件
            WriteLotteryAccountToBin();
            // 退出登录
            return;
        case 7:
            return;
        default:
            break;
        }
    }
}

//修改密码
void ChangePassword()
{
    char oldPasswd[32];
    char newPasswd1[32];
    char newPasswd2[32];
    int cnt = 0; //密码输错计数器，输错3次退出修改密码程序。
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
                printf("下次登录生效，请尽快使用新密码重新登录\n");
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
                printf("密码输入错误%d次，取消密码修改\n", cnt);
                //返回主菜单
                UserMenu();
            }
            printf("密码输入错误%d次，请重新输入\n", cnt);
        }
    } while (cnt < 3);
}
//充值
void Recharge()
{
    float rechargeNum = 0;
    printf("当前余额：%.2f\n", lotteryCurrentLogin->data.balance);
    printf("要充值的金额:");
    scanf("%f", &rechargeNum);
    lotteryCurrentLogin->data.balance += rechargeNum;
    printf("充值成功!\n");
    printf("当前余额:%.2f\n", lotteryCurrentLogin->data.balance);
}

/********************************/
/***********下注相关功能*********/
//下注
void Bet()
{
    //判断当前是否有彩票发行
    if (releaseDataHead == NULL)
    {
        printf("------------------------------------------\n");
        printf("尚未发行任何彩票，无法使用下注功能，请关注后续公告\n");
        printf("------------------------------------------\n");
        return;
    }
    //如果存在发行的彩票，显示发行信息
    printf("\n当前发行期数为%d,具体信息如下:", releaseDataCurrent->data.issue);
    DisplaySingleReleaseData(releaseDataCurrent);

    //如果当前发行已经开奖，不能下注，只能下注未开奖的
    if (releaseDataCurrent->data.status)
    {
        printf("------------------------------------------\n");
        printf("当前彩票期数已经开奖了，无法下注，请关注后续公告\n");
        printf("------------------------------------------\n");
        return;
    }

    //满足以上条件，开始下注
    printf("\t你要下几注？(输入数字即可，如下两注直接输入2)：");
    int number = RecStringConverToInt();
    if (number > 5)
    {
        printf("----------------------------\n");
        printf("注意:单张彩票最多能下5注，将为您购买多张彩票\n"); //提示单张彩票最多可下5注
        printf("----------------------------\n");
    }

    //如果余额不足，无法进行下注，先提示充值
    //当前余额 - 单价*注数 < 0,说明余额不足
    int condition1 = (lotteryCurrentLogin->data.balance - releaseDataCurrent->data.price * number) < 0;
    if (condition1)
    {
        printf("您购买%d注号码，预计%d元\n", number, releaseDataCurrent->data.price * number);
        printf("您当前余额为:%.2f，余额不足，请先进行充值。\n", lotteryCurrentLogin->data.balance);
        return;
    }

    //条件满足，可以选择下注方式
    printf("请选择投注方式：\n\n1.自选号码投注\t2.机选号码投注\t3.取消投注\n\n");
    int choose = RecStringConverToInt();
    switch (choose)
    {
    case 1:
        printf("暂不支持手动选号,待开发!\n");
        break;
    case 2:
        MachineSelection(number);
        break;
    case 3:
        return;
    default:
        break;
    }
    //选完更新余额
    lotteryCurrentLogin->data.balance -= number * releaseDataCurrent->data.price;
    //更新某个用户购买的彩票数、号码数
    UpdateUserTicketsAndNumbers(lotteryCurrentLogin);
    //更新奖池信息
    UpdatePrizePool();
}

//机选号码
void MachineSelection(int n)
{
    TicketData newSoldData;
    //初始化彩票发行号
    newSoldData.issueNum = releaseDataCurrent->data.issue;
    //初始化彩票开奖状态
    newSoldData.status = releaseDataCurrent->data.status;
    //初始化中奖等级
    newSoldData.winLevel = 0;
    //生成彩票及号码数据
    //下注5个号码以内(包含5)
    if (n <= 5)
    {
        for (int i = 0; i < n; i++)
        {
            char nums[25] = {'\0'};
            //生成随机字符串并检查重复性
            do
            {
                randomNum(nums);
            } while (CheckBetNumberUniqueness(nums));
            strcpy(newSoldData.numStr[i], nums);
        }
        //添加数据到链表
        AddToTicketDataLinkedList(newSoldData);
    }
    //下注超过5个号,拆分多张彩票
    if (n > 5)
    {
        for (int i = 0; i < (n / 5 + n % 5); i++)
        {
            for (int j = 0; j < 5; j++)
            {
                char nums[25] = {'\0'};
                //生成随机字符串并检查重复性
                do
                {
                    randomNum(nums);
                } while (CheckBetNumberUniqueness(nums));
                strcpy(newSoldData.numStr[j], nums);
            }
            //添加数据到链表
            AddToTicketDataLinkedList(newSoldData);
        }
    }
    //显示下注结果
    DisplaySelectedResult();
}

//添加到彩票数据链表
void AddToTicketDataLinkedList(TicketData newData)
{
    //申请新节点
    TicketDataLinkedList *newNode = malloc(sizeof(TicketDataLinkedList));
    //初始化
    newNode->data = newData;
    newNode->next = NULL;
    //将新节点连接到链表中，关联到当前登录用户
    if (lotteryCurrentLogin->data.ticketDataHead == NULL)
    {
        //没有头节点,标记为头节点
        lotteryCurrentLogin->data.ticketDataHead = newNode;
        lotteryCurrentLogin->data.ticketDataCurrent = newNode;
        return;
    }
    //已存在头节点,连接到节点尾部
    lotteryCurrentLogin->data.ticketDataCurrent->next = newNode;
    lotteryCurrentLogin->data.ticketDataCurrent = newNode;
}

//生成随机数
void randomNum(char *nums)
{
    int red[6], blue;
    char empty[25] = {'\0'};
    //先清空用于接受随机字符串的字符数组
    strcpy(nums, empty);
    // 6红色球号码从1—33中选择；1蓝色球号码从1—16中选择。
    for (int i = 0; i < 6; i++)
    {
        char temp[5] = {'\0'};
        red[i] = rand() % 33 + 1;
        // 1-9在前面加0组成双位数
        if (red[i] >= 1 && red[i] <= 9)
        {
            sprintf(temp, "0%d-", red[i]);
            strcat(nums, temp);
            continue;
        }
        sprintf(temp, "%d-", red[i]);
        strcat(nums, temp);
    }
    blue = rand() % 16 + 1;
    char blues[5] = {'\0'};
    // 1-9在前面加0组成双位数
    if (blue >= 1 && blue <= 9)
    {
        sprintf(blues, "0%d", blue);
    }
    else
    {
        sprintf(blues, "%d", blue);
    }
    //得到随机数
    strcat(nums, blues);
}

//检查号码重复性，所有账号的
int CheckBetNumberUniqueness(char nums[])
{
    //从第一个账号开始遍历
    LotteryAccountLinkedList *user = userHead;
    if (user == NULL)
    {
        return 0;
    }
    while (user != NULL)
    {
        //判断当前用户购买的彩票信息是否存在
        if (user->data.ticketDataHead == NULL)
        {
            //不存在结束当前循环，遍历下一个账号
            user = user->next;
            break;
        }
        //如果存在，则遍历当前账号在本期购买的号码
        for (int i = 0; i < 5; i++)
        {
            if (strcmp(nums, user->data.ticketDataCurrent->data.numStr[i]) == 0)
            {
                return 1;
            }
        }
        //继续遍历下一个账号
        user = user->next;
    }
    return 0;
}

//下注成功通知
void DisplaySelectedResult()
{
    printf("----------------------------\n");
    printf("下注成功，请到==购买记录==查看详情。\n\n");
    printf("感谢使用彩票管理系统，敬请期待开奖结果!\n");
    printf("----------------------------\n");
}

//显示某个用户的购买记录
void DisplayUserBoughtData(LotteryAccountLinkedList *user)
{
    TicketDataLinkedList *userSoldData = user->data.ticketDataHead;
    if (userSoldData == NULL)
    {
        printf("没有购买过任何彩票\n");
        return;
    }
    int cnt = 1;
    printf("您购买的彩票信息如下:\n");
    while (userSoldData != NULL)
    {
        char empty[22] = {'\0'};
        printf("---------------------------\n");
        printf("第%d张彩票:\n", cnt++);
        printf("发行期数:%d\n", userSoldData->data.issueNum);
        if (userSoldData->data.status)
        {
            printf("开奖状态：已开奖\n");
        }
        else
        {
            printf("开奖状态：未开奖\n");
        }

        if (userSoldData->data.winLevel)
        {
            printf("中奖状态：%d等奖\n", userSoldData->data.winLevel);
        }
        else
        {
            printf("中奖状态：未中奖\n");
        }
        printf("已购号码:\n");
        for (int i = 0; strcmp(userSoldData->data.numStr[i], empty) != 0; i++)
        {
            printf("%c  %s\n", 'A' + i, userSoldData->data.numStr[i]);
        }
        printf("---------------------------\n");
        userSoldData = userSoldData->next;
    }
    printf("您一共购买了%d张彩票,", user->data.tickets);
    printf("共有%d个号码\n", user->data.ticketNums);
}

//更新某个用户购买的彩票数、号码数
void UpdateUserTicketsAndNumbers(LotteryAccountLinkedList *user)
{
    TicketDataLinkedList *userSoldData = user->data.ticketDataHead;
    //统计之前，重置数据
    lotteryCurrentLogin->data.tickets = 0;
    lotteryCurrentLogin->data.ticketNums = 0;
    //彩民购买了彩票，统计彩票及号码
    //开始统计当前用户的所有SoldData。
    while (userSoldData != NULL)
    {
        char empty[22] = {'\0'};
        lotteryCurrentLogin->data.tickets++;
        for (int i = 0; strcmp(userSoldData->data.numStr[i], empty) != 0; i++)
        {
            lotteryCurrentLogin->data.ticketNums++;
        }
        userSoldData = userSoldData->next;
    }
}

// 更新奖池信息
void UpdatePrizePool()
{
    LotteryAccountLinkedList *user = userHead;
    //先确保有奖池存在
    if (releaseDataCurrent == NULL)
    {
        printf("当前没有发行彩票");
        return;
    }
    //重置奖池数据
    releaseDataCurrent->data.totalSold = 0;
    releaseDataCurrent->data.totalPrize = 0;
    //遍历用户购买数据
    while (user != NULL)
    {
        //先更新用户购买的数量
        UpdateUserTicketsAndNumbers(user);
        //更新到奖池
        releaseDataCurrent->data.totalSold += user->data.ticketNums;
        releaseDataCurrent->data.totalPrize += user->data.ticketNums * releaseDataCurrent->data.price;
        //继续遍历下一个用户
        user = user->next;
    }
}