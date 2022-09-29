#include "account.h"
#include "userMenu.h"
#include "adminMenu.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
//当前登录账号
extern Lottery *lotteryCurrentLogin;
//彩民链表头
extern Lottery *userHead;
extern Lottery *userCurrent;
//彩票号码记录
LTSoldInfo *LTSoldInfoHead = NULL;
LTSoldInfo *LTSoldInfoCurrent = NULL;

// 发行彩票链表
extern LotteryTicket *LTHead;
extern LotteryTicket *LTCurrent;

//彩民客户端主界面
void UserMenu()
{
    int choose;
    while (1)
    {
        printf("\t1.查看个人信息\n");
        printf("\t2.修改密码\n");
        printf("\t3.账户充值\n");
        printf("\t4.下注\n");
        printf("\t5.查看历史记录\n");
        printf("\t6.注销账号\n");
        printf("\t7.退出登录\n");
        printf("\n*******************************************\n");
        printf("请选择功能：");
        scanf("%d", &choose);
        switch (choose)
        {
        case 1:
            ViewPersonalInfo();
            break;
        case 2:
            ChangePassword();
            return;
        case 3:
            Recharge();
            break;
        case 4:
            Bet();
            break;
        case 5:
            break;
        case 6:
            DeleteAccount();
            return;
        case 7:
            return;
        default:
            break;
        }
    }
}

void ViewPersonalInfo()
{
    printf("当前账号：%s\t", lotteryCurrentLogin->account.account.name);
    printf("余额：%.2f\n", lotteryCurrentLogin->account.balance);
}

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
        if (strcmp(oldPasswd, lotteryCurrentLogin->account.account.pwd) == 0)
        {
            printf("请输入新密码:");
            scanf("%s", newPasswd1);
            printf("再次确认新密码:");
            scanf("%s", newPasswd2);
            if (strcmp(newPasswd1, newPasswd2) == 0)
            {
                strcpy(lotteryCurrentLogin->account.account.pwd, newPasswd1);
                printf("密码修改成功,请重新登录\n");
                //连续退出到登录界面
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

    printf("当前余额：%.2f\n", lotteryCurrentLogin->account.balance);
    printf("要充值的金额:");
    scanf("%f", &lotteryCurrentLogin->account.balance);
    printf("充值成功!\n");
    printf("当前余额:%.2f\n", lotteryCurrentLogin->account.balance);
}

/********************************/
/***********下注相关功能*********/
//下注
void Bet()
{
    int number;
    int method;
    if (LTHead == NULL)
    {
        printf("------------------------------------------\n");
        printf("尚未发行任何彩票，无法使用下注功能，请关注后续公告\n");
        printf("------------------------------------------\n");
        return;
    }
    printf("\n当前发行期数为%d,具体信息如下:", LTCurrent->issue);
    DisplayLotteryTicketInfo(LTCurrent);
    printf("\t你要下几注？(输入数字即可，如下两注直接输入2)：");
    scanf("%d", &number);
    if (number > 5)
    {
        printf("----------------------------\n");
        printf("单张彩票最多能下5注，请重新下注\n");
        printf("----------------------------\n");
        return;
    }
    if (lotteryCurrentLogin->account.balance < (LTCurrent->price * number))
    {
        printf("您购买%d注号码，预计%d元\n", number, LTCurrent->price * number);
        printf("您当前余额为:%.2f，余额不足，请先进行充值。\n", lotteryCurrentLogin->account.balance);
        return;
    }
    printf("请选择投注方式：\n\n1.自选号码投注\t2.机选号码投注\n\n");
    scanf("%d", &method);
    switch (method)
    {
    case 1:
        break;
    case 2:
        MachineSelection(number);
        break;
    default:
        break;
    }
    //开始投注
    //机选
    // DisplayCurrentSelected();
}

// void MachineSelection(int num)
// {
//     srand(time(NULL));
//     for (int i = 0; i < num; i++)
//     {
//         LTSoldNumber *newNum = malloc(sizeof(LTSoldNumber));
//         // 6红色球号码从1—33中选择；1蓝色球号码从1—16中选择。
//         for (int j = 0; j < 6; j++)
//         {
//             newNum->red[j] = rand() % 33 + 1;
//         }
//         newNum->blue = rand() % 16 + 1;
//         //保存号码信息
//         int duplicated = CheckBetNumberUniqueness(*newNum);
//         if (!duplicated)
//         {
//             AddToSoldInfo(*newNum);
//         }
//         free(newNum);
//     }
// }

//记录售出的号码
void MachineSelection(int n)
{
    srand((unsigned)time(NULL));
    LTSoldInfo *newInfo = malloc(sizeof(LTSoldInfo));
    for (int i = 0; i < n; i++)
    {
        char nums[25] = {'\0'};
        char empty = {'\0'};
        rangeNum(nums);
        strcpy(newInfo->num[i], nums);
    }
    // newInfo->userFlags = lotteryCurrentLogin;
    newInfo->next = NULL;
    if (LTSoldInfoHead == NULL)
    {
        LTSoldInfoHead = newInfo;
        LTSoldInfoCurrent = newInfo;
        //余额变动
        lotteryCurrentLogin->account.balance -= LTCurrent->price * n;
        //奖池变动
        LTCurrent->totalSold += n;
        LTCurrent->totalPrize += LTCurrent->price * n;
        //提示机选成功
        DisplayCurrentSelected();
        return;
    }
    LTSoldInfoCurrent->next = newInfo;
    LTSoldInfoCurrent = newInfo;
    //余额变动
    lotteryCurrentLogin->account.balance -= LTCurrent->price * n;
    //奖池变动
    LTCurrent->totalSold += n;
    LTCurrent->totalPrize += LTCurrent->price * n;
    //提示机选成功
    DisplayCurrentSelected();
}

void rangeNum(char *nums)
{
    int red[6], blue;
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
        //检查重复性，如果有重复，清空empty
    } while (CheckBetNumberUniqueness(nums));
}

//检查号码重复性
int CheckBetNumberUniqueness(char nums[])
{
    LTSoldInfo *temp = LTSoldInfoHead;
    if (temp == NULL)
    {
        return 0;
    }
    while (temp != NULL)
    {
        for (int i = 0; i < 5; i++)
        {
            if (strcmp(nums, temp->num[i]) == 0)
            {
                return 1;
            }
        }
        temp = temp->next;
    }
    return 0;
}

//显示已选
void DisplayCurrentSelected()
{
    printf("----------------------------\n");
    printf("机选成功，您当前选到的号码如下：\n");
    printf("----------------------------\n");
    for (int i = 0; *LTSoldInfoCurrent->num[i] != '\0'; i++)
    {
        printf("%c  %s\n", 'A' + i, LTSoldInfoCurrent->num[i]);
    }
    printf("感谢使用彩票管理系统，敬请期待开奖结果!\n");
    printf("----------------------------\n");
}

void DisplayBoughtInfo()
{
    LTSoldInfo *temp = LTSoldInfoHead;
    if (temp == NULL)
    {
        printf("没有购买过任何彩票\n");
        return;
    }
    while (temp != NULL)
    {
        for (int i = 0; *temp->num[i] != '\0'; i++)
        {
            printf("%s\n", temp->num[i]);
        }
        temp = temp->next;
    }
}