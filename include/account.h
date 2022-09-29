#ifndef USER_H
#define USER_H
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
    AccountComm account;
    struct admin *next;
};
typedef struct admin Admin;

//公证员账号
struct notary
{
    AccountComm account;
    struct notary *next;
};
typedef struct notary Notary;

//彩民账号
typedef struct
{
    AccountComm account;
    float balance; //余额
} LotteryAccount;

struct lottery
{
    LotteryAccount account;
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
//添加账户到Admin链表
void AddToAdminLinkedList(AccountComm newAccount);
//添加账户到Notary链表
void AddToNotaryLinkedList(AccountComm ntAccount);
//添加账户到User链表
void AddToLotteryLinkedList(LotteryAccount userAccount);

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
int CheckAdminLinkedList(char name[]);

/*
 *     遍历检查Notary表
 * 返回值：在Notary表中已存在，返回1；不存在返回0；
 */
int CheckNotaryLinkedList(char name[]);

/*
 *     遍历检查User表
 * 返回值：在User表中已存在，返回1；不存在返回0；
 */
int CheckUserLinkedList(char name[]);

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


/********************************/
/***********注销功能相关***********/
//注销账户
void DeleteAccount();
//删除操作确认
int DeleteAccountOprationConfirm();

#endif