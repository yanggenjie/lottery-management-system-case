#ifndef USER_H
#define USER_H
#include "userMenu.h"
/********************************/
/*******账号结构体数据***********/
//账号通用信息
struct accountComm
{
    char name[30];
    char pwd[32];
};
typedef struct accountComm AccountComm;

//管理员账号
struct admin
{
    AccountComm data;
    struct admin *next;
};
typedef struct admin AdminAccountLinkedList;

//公证员账号
struct notary
{
    AccountComm data;
    struct notary *next;
};
typedef struct notary NotaryAccountLinkedlist;

//彩民账号信息
typedef struct
{
    AccountComm account;                     //用户名和密码
    float balance;                           //余额
    unsigned tickets;                        //购买的彩票张数
    unsigned ticketNums;                     //购买的彩票号码数
    unsigned short AdvanceAward;             //仅用于标记一等奖、二等奖,1为1等奖，2为2等奖
    TicketDataLinkedList *ticketDataHead;    //彩票号码头节点关联账户
    TicketDataLinkedList *ticketDataCurrent; //彩票号码当前节点关联账户
} LotteryData;

struct lotteryAccount
{
    LotteryData data;
    struct lotteryAccount *next;
};
typedef struct lotteryAccount LotteryAccountLinkedList;

/********************************/
/***********注册功能相关***********/
//注册功能主界面
void SignUpMenu();
//彩民注册
void SignUpUser();

/********************************/
/*********账号管理相关**********/
//账号管理菜单
void AccountManagerMenu();

/*
 * 管理员账号初始化
 * 默认账号：admin，密码123
 */
void InitAdminAccount();
void InitNotaryAccount();

//添加管理员账号(仅管理员可用)
void AddAdminAccount();
//添加公证员账号(仅管理员可用)
void AddNotaryAccount();

//删除管理员账号(仅管理员可用),不能删除默认账号
void DeleteAdminAccount();
//删除公证员账号(仅管理员可用)，不能删除默认账号
void DeleteNotaryAccount();

//删除彩民账户
void DeleteLotteryAccount();
//删除操作确认
int DeleteLotteryAccountConfirm();

//添加到对应账户链表
void AddToAdminAccountLinkedList(AccountComm newData);
void AddToNotaryAccountLinkedList(AccountComm newData);
void AddToLotteryAccountLinkedList(LotteryData newData);

//查找当前节点的上一节点
LotteryAccountLinkedList *FindLotteryAccountPreNode(LotteryAccountLinkedList *findNode);
AdminAccountLinkedList *FindAdminAccountPreNode(AdminAccountLinkedList *findNode);
AdminAccountLinkedList *FindAdminAccountNodeByUserName(char name[]);
//公证员节点查找
NotaryAccountLinkedlist *FindNotaryAccountPreNode(NotaryAccountLinkedlist *findNode);
NotaryAccountLinkedlist *FindNotaryAccountNodeByUserName(char name[]);

/*
 *    检查用户名及密码规范性
 * 返回值：返回符合规范的账号、密码
 */
AccountComm *CheckAccountSpecification(AccountComm *account);

/*
 *  检查用户名唯一性
 * @param name 要检查的用户名
 * 返回值：若数据库中已存在，返回1，不存在返回0
 */
int CheckALLUserName(char name[]);

/*
 *    遍历检查admin表
 *返回值：在admin表中已存在，返回1；不存在返回0；
 */
int CheckAdminAccount(char name[]);

/*
 *     遍历检查Notary表
 * 返回值：在Notary表中已存在，返回1；不存在返回0；
 */
int CheckNotaryAccount(char name[]);

/*
 *     遍历检查Lottery表
 * 返回值：在Lottery表中已存在，返回1；不存在返回0；
 */
int CheckLotteryAccount(char name[]);

/********************************/
/***********登录功能相关***********/

//登录功能主界面
void SignInMenu();

/*
 *     判断是否是管理员登录
 * @param name 用户输入的账号
 * @param pwd 用户输入的密码
 * 返回值：是返回1，不是返回0；
 */
int IsAdminLogin(char name[], char pwd[]);

/*
 *     判断是否是公证员登录
 * @param name 用户输入的账号
 * @param pwd 用户输入的密码
 * 返回值：是返回1，不是返回0；
 */
int IsNotaryLogin(char name[], char pwd[]);

/*
 *     判断是否是彩民登录
 * @param name 用户输入的账号
 * @param pwd 用户输入的密码
 * 返回值：是返回1，不是返回0；
 */
int IsUserLogin(char name[], char pwd[]);

/********************************/
/***********查看历史记录***********/
//显示某个用户的购买记录
void DisplayUserBoughtData(LotteryAccountLinkedList *user);

/********************************/
/***********其它***********/
/*
 * 统计更新某个用户购买的彩票数、号码数
 * user 要统计的用户
 */
void UpdateUserTicketsAndNumbers(LotteryAccountLinkedList *user);

/*
 * 	更新奖池
 * 更新奖池，应该统计所有用户的购买数据
 * 奖池售出量 = 所有用户购买的号码数
 * 奖池奖金 = 所有用户购买的号码数 * 单价
 */
void UpdatePrizePool();

#endif