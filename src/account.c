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

//注册功能主界面
void SignUpMenu()
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
            //记录到文件
            WriteLotteryAccountToBin();
            break;
        case 2:
            return;
        default:
            break;
        }
    }
}

//彩民注册
void SignUpUser()
{

    //检测账号密码合规性
    AccountComm *temp = malloc(sizeof(AccountComm));
    temp = CheckAccountSpecification(temp);
    //如果用户名密码不合规，销毁空间，结束函数
    if (temp == NULL)
    {
        free(temp);
        return;
    }
    //合规，初始化基本信息，传值添加到链表
    LotteryData newAccount;
    newAccount.account = *temp;
    newAccount.balance = 0;
    newAccount.tickets = 0;
    newAccount.ticketNums = 0;
    newAccount.AdvanceAward = 0;
    newAccount.ticketDataHead = NULL;
    newAccount.ticketDataCurrent = NULL;
    AddToLotteryAccountLinkedList(newAccount);
    //销毁临时空间
    free(temp);
    printf("\n************注册成功!************\n");
    return;
}

/********************************/
/*********账号管理功能相关**********/

//账号管理菜单
void AccountManagerMenu()
{
    while (1)
    {
        printf("\n*******************************************\n");
        printf("\t1.添加管理员账号\n");
        printf("\t2.添加公证员账号\n");
        printf("\t3.删除管理员账号\n");
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
            AddNotaryAccount();
            break;
        case 3:
            DeleteAdminAccount();
            break;
        case 4:
            DeleteNotaryAccount();
            break;
        case 5:
            return;
        default:
            break;
        }
    }
}

//管理员账号初始化
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
//公证员账号初始化
void InitNotaryAccount()
{
    NotaryAccountLinkedlist *initAccount = malloc(sizeof(NotaryAccountLinkedlist));
    strcpy(initAccount->data.name, "notary");
    strcpy(initAccount->data.pwd, "123");
    initAccount->next = NULL;
    notaryHead = initAccount;
    notaryCurrent = initAccount;
    return;
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
    AddToAdminAccountLinkedList(*temp);
    //销毁临时空间
    free(temp);
    printf("\n************注册成功!************\n");
    return;
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
    AddToNotaryAccountLinkedList(*temp);
    //销毁临时空间
    free(temp);
    printf("\n************注册成功!************\n");
    return;
}

//删除管理员账号(仅管理员可用)
void DeleteAdminAccount()
{
    //输入要删除的用户名
    char name[100] = {'\0'};
    printf("输入要删除的用户名:");
    scanf("%s", name);
    //不能删除默认账号
    if (strcmp(name, "admin") == 0)
    {
        printf("无法删除默认账号\n");
        return;
    }
    //根据用户名查找账号所在的节点
    AdminAccountLinkedList *del = FindAdminAccountNodeByUserName(name);
    // 没有找到用户
    if (del == NULL)
    {
        printf("不存在该账户\n");
        return;
    }
    //找到前一节点
    AdminAccountLinkedList *prev = FindAdminAccountPreNode(del);
    //要删除的节点处于末尾
    if (del->next == NULL)
    {
        prev->next = NULL;
        return;
    }
    //要删除的节点在中间
    prev->next = del->next;
    return;
}

//删除公证员账户(仅管理员可用)
void DeleteNotaryAccount()
{
    //输入要删除的用户名
    char name[100] = {'\0'};
    printf("输入要删除的用户名:");
    scanf("%s", name);
    //不能删除默认账号
    if (strcmp(name, "notary") == 0)
    {
        printf("无法删除默认账号\n");
        return;
    }
    //根据用户名查找账号所在的节点
    NotaryAccountLinkedlist *del = FindNotaryAccountNodeByUserName(name);
    // 没有找到用户
    if (del == NULL)
    {
        printf("不存在该账户\n");
        return;
    }
    //找到前一节点
    NotaryAccountLinkedlist *prev = FindNotaryAccountPreNode(del);
    //要删除的节点处于末尾
    if (del->next == NULL)
    {
        prev->next = NULL;
        return;
    }
    //要删除的节点在中间
    prev->next = del->next;
    return;
}
//删除彩民账号
void DeleteLotteryAccount()
{
    int confirm = DeleteLotteryAccountConfirm();
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
            LotteryAccountLinkedList *prev = FindLotteryAccountPreNode(lotteryCurrentLogin);
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

//删除彩民账号操作确认
int DeleteLotteryAccountConfirm()
{
    char uname[30];
    printf("×××××××××××××××××××××××××××××\n");
    printf("此操作属于风险极高，请谨慎操作!\n");
    printf("×××××××××××××××××××××××××××××\n");
    printf("---------------------------\n");
    printf("您当前账户：\n");
    DisplaySingleLotteryInfo(lotteryCurrentLogin); //显示账户信息
    printf("---------------------------\n");
    printf("注销账户之后，您的账户金额将被清空，且不可恢复！\n");
    printf("您购买彩票的历史订单将被移除，且不可恢复！\n");
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
            printf("没有选择正确的选项，取消操作!\n");
            return 0;
        }
    }
    printf("用户名不匹配，取消操作!\n");
    return 0;
}

//添加到管理员链表
void AddToAdminAccountLinkedList(AccountComm newData)
{
    AdminAccountLinkedList *newNode = malloc(sizeof(AdminAccountLinkedList));
    newNode->data = newData;
    newNode->next = NULL;
    //如果头节点为空，标记新节点为头节点
    if (adminHead == NULL)
    {
        adminHead = newNode;
        adminCurrent = newNode;
        return;
    }
    adminCurrent->next = newNode;
    adminCurrent = newNode;
}
//添加到公证员链表
void AddToNotaryAccountLinkedList(AccountComm newData)
{

    NotaryAccountLinkedlist *newNode = malloc(sizeof(NotaryAccountLinkedlist));
    newNode->data = newData;
    newNode->next = NULL;
    //如果头节点为空，标记新节点为头节点
    if (notaryHead == NULL)
    {
        notaryHead = newNode;
        notaryCurrent = newNode;
    }
    notaryCurrent->next = newNode;
    notaryCurrent = newNode;
}
//添加到彩民账号链表
void AddToLotteryAccountLinkedList(LotteryData newData)
{
    LotteryAccountLinkedList *newNode = malloc(sizeof(LotteryAccountLinkedList));
    newNode->data = newData;
    newNode->next = NULL;
    //如果头节点为空，标记新节点为头节点
    if (userHead == NULL)
    {
        userHead = newNode;
        userCurrent = newNode;
        return;
    }
    userCurrent->next = newNode;
    userCurrent = newNode;
}

//查找当前节点的上一节点
LotteryAccountLinkedList *FindLotteryAccountPreNode(LotteryAccountLinkedList *findNode)
{
    LotteryAccountLinkedList *temp = userHead;
    if (findNode == userHead)
    {
        return NULL;
    }
    while (temp != NULL)
    {
        if (temp->next == findNode)
        {
            return temp;
        }
        temp = temp->next;
    }
}

AdminAccountLinkedList *FindAdminAccountPreNode(AdminAccountLinkedList *findNode)
{
    AdminAccountLinkedList *temp = adminHead;
    while (temp != NULL)
    {
        if (temp->next == findNode)
        {
            return temp;
        }
        temp = temp->next;
    }
}
AdminAccountLinkedList *FindAdminAccountNodeByUserName(char name[])
{
    AdminAccountLinkedList *user = adminHead;
    while (user != NULL)
    {
        if (strcmp(name, user->data.name) == 0)
        {
            return user;
        }
        user = user->next;
    }
    return NULL;
}

NotaryAccountLinkedlist *FindNotaryAccountPreNode(NotaryAccountLinkedlist *findNode)
{
    NotaryAccountLinkedlist *temp = notaryHead;
    while (temp != NULL)
    {
        if (temp->next == findNode)
        {
            return temp;
        }
        temp = temp->next;
    }
}
NotaryAccountLinkedlist *FindNotaryAccountNodeByUserName(char name[])
{
    NotaryAccountLinkedlist *user = notaryHead;
    while (user != NULL)
    {
        if (strcmp(name, user->data.name) == 0)
        {
            return user;
        }
        user = user->next;
    }
    return NULL;
}

//检查用户名及密码规范性
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

/********************************/
/***********登录功能实现***********/

/*
    登录功能
自动判断管理员、公证员、彩民
*/
void SignInMenu()
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
    LotteryAccountLinkedList *user = userHead;
    if (user == NULL)
    {
        return 0;
    }
    while (user != NULL)
    {
        int condition1 = (strcmp(name, user->data.account.name) == 0);
        int condition2 = (strcmp(pwd, user->data.account.pwd) == 0);
        if (condition1 && condition2)
        {
            //标记当前登录账号
            lotteryCurrentLogin = user;
            //读取当前账号彩票购买历史
            ReadBoughtHistoryFromFile();
            return 1;
        }
        user = user->next;
    }
    return 0;
}

/********************************/
/***********注销功能相关***********/
