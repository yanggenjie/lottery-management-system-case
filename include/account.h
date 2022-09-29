#ifndef USER_H
#define USER_H
#include"userMenu.h"
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
typedef struct notary Notary;

//彩民账号
typedef struct
{
    AccountComm account;//用户名和密码
    float balance; //余额
    LTSoldDataLinkedList *soldDataHead;//彩票号码头节点关联账户
    LTSoldDataLinkedList *soldDataCurrent;//彩票号码当前节点关联账户
} LotteryData;

struct lottery
{
    LotteryData data;
    struct lottery *next;
};
typedef struct lottery Lottery;

/********************************/
/***********注册功能相关***********/
//注册功能主界面
void SignUp();
/*
 * 管理员账号初始化
 * 默认账号：admin，密码123
 */
void InitAdminAccount();

//添加管理员账号(仅管理员可用)
void AddAdminAccount();
//删除管理员账号(仅管理员可用)
void DeleteAdminAccount();
//添加公证员账号(仅管理员可用)
void AddNotaryAccount();
//删除公证员账号(仅管理员可用)
void DeleteNotaryAccount();

//彩民注册
void SignUpUser();
//添加到对应账户链表
void AddToAdminAccount(AccountComm newAccount);
void AddToNotaryAccount(AccountComm ntAccount);
void AddToLotteryAccount(LotteryData userAccount);

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
void SignIn();

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




#endif