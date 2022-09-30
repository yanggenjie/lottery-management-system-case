#include "account.h"
#include "adminMenu.h"
#include "userMenu.h"
#include "notaryMenu.h"
#include "fileIO.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//管理员链表头
AdminAccountLinkedList *adminHead = NULL;
AdminAccountLinkedList *adminCurrent = NULL;
//彩民链表头
LotteryAccountLinkedList *userHead = NULL;
LotteryAccountLinkedList *userCurrent = NULL;
//公证员链表头
NotaryAccountLinkedlist *notaryHead = NULL;
NotaryAccountLinkedlist *notaryCurrent = NULL;

//当前登录的账号标记
AdminAccountLinkedList *adminCurrentLogin = NULL;
LotteryAccountLinkedList *lotteryCurrentLogin = NULL;
NotaryAccountLinkedlist *notaryCurrentLogin = NULL;

/********************************/
/***********注册功能实现***********/

void SignUp()
{
    //选择要注册的类型
    while (1)
    {
        printf("\n*******************************************\n");
        printf("\n\t1.彩民注册\n");
        printf("\t2.返回主菜单\n\n");
        printf("\n*******************************************\n");
        printf("请选择要注册的类型:");
        int choose = RecStringConverToInt();
        switch (choose)
        {
        case 1:
            SignUpUser();
            break;
        case 2:
            return;
        default:
            break;
        }
    }
}

//新增管理员账号(仅管理员可用)
void AddAdminAccount()
{
    AccountComm *temp = malloc(sizeof(AccountComm));
    //接收符合规范的用户名和密码
    temp = CheckAccountSpecification(temp);
    //如果用户名密码不合规，销毁空间，结束函数
    if (temp == NULL)
    {
        free(temp);
        return;
    }
    //合规，则传值，添加到管理员链表
    AddToAdminAccount(*temp);
    //销毁临时空间
    free(temp);
    printf("\n************注册成功!************\n");
    return;
}

//删除管理员账号(仅管理员可用)
void DeleteAdminAccount()
{
}

//新增公证员账号(仅管理员可用)
void AddNotaryAccount()
{
    AccountComm *temp = malloc(sizeof(AccountComm));
    temp = CheckAccountSpecification(temp);
    //如果用户名密码不合规，销毁空间，结束函数
    if (temp == NULL)
    {
        free(temp);
        return;
    }
    //合规，则传值，添加到管理员链表
    AddToNotaryAccount(*temp);
    //销毁临时空间
    free(temp);
    printf("\n************注册成功!************\n");
    return;
}
//彩民注册
void SignUpUser()
{
    LotteryData tempLTAccount;
    //检测账号密码合规性
    AccountComm *temp = malloc(sizeof(AccountComm));
    temp = CheckAccountSpecification(temp);
    //如果用户名密码不合规，销毁空间，结束函数
    if (temp == NULL)
    {
        free(temp);
        return;
    }
    //合规，初始化余额，传值添加到链表
    tempLTAccount.account = *temp;
    tempLTAccount.balance = 0;
    tempLTAccount.soldDataHead = NULL;
    tempLTAccount.soldDataCurrent = NULL;
    tempLTAccount.tickets=0;
    tempLTAccount.ticketNums=0;
    AddToLotteryAccount(tempLTAccount);
    //记录到文件
    // WriteLotteryAccountToBin();
    //销毁临时空间
    free(temp);
    printf("\n************注册成功!************\n");
    return;
}
//检查用户名，密码是否合规
AccountComm *CheckAccountSpecification(AccountComm *account)
{
    char pwd1[32];
    printf("输入用户名(最长30个字符)：");
    scanf("%s", account->name);
    printf("输入密码(最长32个字符)：");
    scanf("%s", account->pwd);
    printf("再次确认密码(最长32个字符)：");
    scanf("%s", pwd1);
    //检查用户名及密码的长度是否满足要求
    int condition1 = strlen(account->name) > 0 && strlen(account->name) < 30;
    int condition2 = strlen(account->pwd) > 0 && strlen(account->pwd) < 32;
    int condition3 = strlen(pwd1) > 0 && strlen(pwd1) < 32;
    if (condition1 && condition2 && condition3)
    {
        //检查两次密码是否相同
        if (strcmp(account->pwd, pwd1) == 0)
        {
            //检查是否已经存在该账户
            int existed = CheckALLUserName(account->name);
            if (!existed)
            {
                //都满足，保留空间，返回用户名密码
                return account;
            }
            else
            {
                printf("\n用户名重复，请输入其它用户名!\n");
            }
        }
        else
        {
            printf("\n两次输入的密码不一致，请重新输入\n");
        }
    }
    else
    {
        printf("\n长度超出最大限制，重新输入\n");
    }
    return NULL;
}

//检查用户名唯一性
int CheckALLUserName(char name[])
{
    //遍历查找Admin表、Notary表、User表,若已存在返回1
    int existedAdLinkList = CheckAdminAccount(name);
    int existedNTLinkList = CheckNotaryAccount(name);
    int existedUserLinkList = CheckLotteryAccount(name);
    return (existedAdLinkList || existedNTLinkList || existedUserLinkList);
}
//遍历检查admin表
int CheckAdminAccount(char name[])
{
    AdminAccountLinkedList *temp = adminHead;
    while (temp != NULL)
    {
        if (strcmp(name, temp->data.name) == 0)
        {
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}
//遍历检查Notary表
int CheckNotaryAccount(char name[])
{
    NotaryAccountLinkedlist *temp = notaryHead;
    while (temp != NULL)
    {
        if (strcmp(name, temp->data.name) == 0)
        {
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}
//遍历检查User表
int CheckLotteryAccount(char name[])
{
    LotteryAccountLinkedList *temp = userHead;
    while (temp != NULL)
    {
        if (strcmp(name, temp->data.account.name) == 0)
        {
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

//添加到管理员链表
void AddToAdminAccount(AccountComm newAccount)
{
    AdminAccountLinkedList *newAdmin = malloc(sizeof(AdminAccountLinkedList));
    newAdmin->data = newAccount;
    newAdmin->next = NULL;
    //如果头节点为空，标记新节点为头节点
    if (adminHead == NULL)
    {
        adminHead = newAdmin;
        adminCurrent = newAdmin;
        return;
    }
    else
    {
        adminCurrent->next = newAdmin;
        adminCurrent = newAdmin;
    }
}
//添加到公证员链表
void AddToNotaryAccount(AccountComm ntAccount)
{

    NotaryAccountLinkedlist *newNotary = malloc(sizeof(NotaryAccountLinkedlist));
    newNotary->data = ntAccount;
    newNotary->next = NULL;
    //如果头节点为空，标记新节点为头节点
    if (notaryHead == NULL)
    {
        notaryHead = newNotary;
        notaryCurrent = newNotary;
    }
    else
    {
        notaryCurrent->next = newNotary;
        notaryCurrent = newNotary;
    }
}
//添加到彩民链表
void AddToLotteryAccount(LotteryData lotteryAccount)
{
    LotteryAccountLinkedList *newUser = malloc(sizeof(LotteryAccountLinkedList));
    newUser->data = lotteryAccount;
    newUser->next = NULL;
    //如果头节点为空，标记新节点为头节点
    if (userHead == NULL)
    {
        userHead = newUser;
        userCurrent = newUser;
        return;
    }
    else
    {
        userCurrent->next = newUser;
        userCurrent = newUser;
    }
}

/********************************/
/***********登录功能实现***********/

/*
    登录功能
自动判断管理员、公证员、彩民
*/
void SignIn()
{
    int cnt = 0;
    do
    {
        char name[30];
        char passwd[32];
        //输入账号、密码
        printf("账号:");
        scanf("%s", name);
        printf("密码:");
        scanf("%s", passwd);
        //管理员登录
        if (IsAdminLogin(name, passwd))
        {
            printf("\n*******************************************\n");
            printf("\t欢迎登入管理员后台\n");
            printf("*******************************************\n");
            AdminMenu();
            return;
        }
        else if (IsNotaryLogin(name, passwd))
        {
            printf("\n*******************************************\n");
            printf("\t欢迎登入公证员客户端\n");
            printf("*******************************************\n");
            NotaryMenu();
            return;
        }
        else if (IsUserLogin(name, passwd))
        {
            printf("\n*******************************************\n");
            printf("\t欢迎登入彩民客户端\n");
            printf("*******************************************\n");
            UserMenu();
            return;
        }
        else
        {
            cnt++;
            if (cnt == 3)
            {
                printf("用户名、密码输错3次，系统退出\n");
                exit(0);
            }
            printf("用户名与密码不正确，请重新输入!\n");
        }
    } while (cnt < 3);
}
//管理员初始化
void InitAdminAccount()
{
    AdminAccountLinkedList *initAccount = malloc(sizeof(AdminAccountLinkedList));
    strcpy(initAccount->data.name, "admin");
    strcpy(initAccount->data.pwd, "123");
    initAccount->next = NULL;
    adminHead = initAccount;
    adminCurrent = initAccount;
    return;
}
//判断是否是管理员登录
int IsAdminLogin(char name[], char pwd[])
{
    //从Admin表头开始扫描
    AdminAccountLinkedList *temp = adminHead;
    if (temp == NULL)
    {
        return 0;
    }
    while (temp != NULL)
    {
        int condition1 = (strcmp(name, temp->data.name) == 0);
        int condition2 = (strcmp(pwd, temp->data.pwd) == 0);
        if (condition1 && condition2)
        {
            //标记当前登录账号
            adminCurrentLogin = temp;
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

//判断是否是公证员登录
int IsNotaryLogin(char name[], char pwd[])
{
    //从Notary表头开始扫描
    NotaryAccountLinkedlist *temp = notaryHead;
    if (temp == NULL)
    {
        return 0;
    }
    while (temp != NULL)
    {
        int condition1 = (strcmp(name, temp->data.name) == 0);
        int condition2 = (strcmp(pwd, temp->data.pwd) == 0);
        if (condition1 && condition2)
        {
            //标记当前账号
            notaryCurrentLogin = temp;
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}
//判断是否是彩民登录
int IsUserLogin(char name[], char pwd[])
{
    //从User表头开始扫描
    LotteryAccountLinkedList *temp = userHead;
    if (temp == NULL)
    {
        return 0;
    }
    while (temp != NULL)
    {
        int condition1 = (strcmp(name, temp->data.account.name) == 0);
        int condition2 = (strcmp(pwd, temp->data.account.pwd) == 0);
        if (condition1 && condition2)
        {
            //标记当前登录账号
            lotteryCurrentLogin = temp;
            //读取当前账号彩票购买历史
            ReadBoughtHistoryFromFile();
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

/********************************/
/***********注销功能相关***********/
//注销账户
void DeleteAccount()
{
    int confirm = DeleteAccountOprationConfirm();
    if (confirm)
    {
        //仅有当前一个账号
        if (lotteryCurrentLogin == userHead && userHead->next == NULL)
        {
            //头节点指向空
            userHead = NULL;
            userCurrent = NULL;
            //退出登录
            return;
        }
        //有多个账号，当前账号处于第一个节点
        if (userHead->next != NULL && lotteryCurrentLogin == userHead)
        {
            //头节点往后移动
            userHead = lotteryCurrentLogin->next;
            //退出登录
            return;
        }
        //有多个账号，当前账号不在头节点
        if (userHead->next != NULL && lotteryCurrentLogin != userCurrent)
        {
            //找到当前节点的前一节点
            LotteryAccountLinkedList *prev = FindPreNode(lotteryCurrentLogin);
            //前一节点指向下一节点
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

//删除操作确认
int DeleteAccountOprationConfirm()
{
    char uname[30];
    printf("此操作属于风险极高，请谨慎操作!\n");
    printf("您当前账户：\n");
    ViewPersonalInfo();
    printf("注销账户之后，您的账户金额将被清空，且不可恢复！\n");
    printf("您购买彩票的历史订单将被移除，且不可恢复！\n");
    printf("请输入当前账户名 %s 确认删除", lotteryCurrentLogin->data.account.name);
    scanf("%s", uname);
    if (strcmp(uname, lotteryCurrentLogin->data.account.name) == 0)
    {
        int choose;
        printf("确认删除?\n1.确认\t2.取消");
        scanf("%d", &choose);
        switch (choose)
        {
        case 1:
            return 1;
        case 2:
            return 0;
        default:
            printf("没有选择正确的选项，取消操作!\n");
            return 0;
        }
    }
    printf("用户名不匹配，取消操作!\n");
    return 0;
}