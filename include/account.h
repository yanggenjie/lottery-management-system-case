#ifndef USER_H
#define USER_H
/********************************/
/*******结构体数据****************/
// 账号通用信息

struct AccountComm
{
	char name[30];
	char pwd[32];
};
typedef struct AccountComm AccountComm;

// 管理员账号
struct AdminAccountLinkedList
{
	AccountComm data;
	struct AdminAccountLinkedList *next;
};
typedef struct AdminAccountLinkedList AdminAccountLinkedList;

// 公证员账号
struct NotaryAccountLinkedlist
{
	AccountComm data;
	struct NotaryAccountLinkedlist *next;
};
typedef struct NotaryAccountLinkedlist NotaryAccountLinkedlist;

// 用户购买的彩票信息
typedef struct
{
	char id[30];		   // 单张彩票唯一标识id,
	unsigned issueNum;	   // 所属发行期号
	unsigned short status; // 本期开奖状态
	char purchaser[30];	   // 购买者账号
	short winLevel;		   // 中奖等级,0表示不中奖，1-6表示中奖等级
	float bonus;		   // 中奖金额
	char numStr[5][22];	   // 记录本张彩票的号码,最多5组号码
} TicketData;

// 用户购买的彩票链表
struct TicketDataLinkedList
{
	TicketData data;
	struct TicketDataLinkedList *next;
};
typedef struct TicketDataLinkedList TicketDataLinkedList;

// 彩民账号信息
typedef struct
{
	AccountComm account;			   // 用户名和密码
	float balance;					   // 余额
	unsigned currentReleaseTickets;	   // 当期购买的所有彩票张数
	unsigned currentReleaseTicketNums; // 当期购买的所有号码数
	unsigned allReleaseTickets;		   // 历史购买的所有彩票张数
	unsigned allReleaseTicketNums;	   // 历史购买的所有号码数
	short AdvanceAward;				   // 用于标记一等奖、二等奖,1为1等奖,2为2等奖，方便发奖金
} LotteryData;

struct LotteryAccountLinkedList
{
	LotteryData data;
	struct LotteryAccountLinkedList *next;
};
typedef struct LotteryAccountLinkedList LotteryAccountLinkedList;

// 发行信息
typedef struct
{
	unsigned issue;			   // 发行期号
	unsigned short price;	   // 彩票单价
	unsigned short status;	   // 开奖状态,0未开奖,1已开奖
	char winResult[22];		   // 本期中奖号码,开奖时随机生成
	unsigned totalSold;		   // 本期售出总数
	float totalPrize;		   // 本期奖池总额
	unsigned winLevelCount[6]; // 中奖数量统计,数组第0个位置代表一等奖,第1个位置代表二等奖，以此类推
} ReleaseData;

// 发行信息链表
struct ReleaseDataLinkedlist
{
	ReleaseData data;
	struct ReleaseDataLinkedlist *next;
};
typedef struct ReleaseDataLinkedlist ReleaseDataLinkedlist;

/********************************/
/***********注册功能相关***********/
// 注册功能主界面
void SignUpMenu();
// 彩民注册
void SignUpUser();

/********************************/
/*********账号管理相关**********/
// 账号管理菜单
void AccountManagerMenu();

/*
 * 管理员账号初始化
 * 默认账号：admin,密码123
 */
void InitAdminAccount();
void InitNotaryAccount();

// 添加管理员账号(仅管理员可用)
void AddAdminAccount();
// 添加公证员账号(仅管理员可用)
void AddNotaryAccount();

// 删除管理员账号(仅管理员可用),不能删除默认账号
void DeleteAdminAccount();
// 删除公证员账号(仅管理员可用),不能删除默认账号
void DeleteNotaryAccount();

// 删除彩民账户
void DeleteLotteryAccount();
// 删除操作确认
int DeleteLotteryAccountConfirm();

// 添加到对应账户链表
void AddToAdminAccountLinkedList(AccountComm newData);
void AddToNotaryAccountLinkedList(AccountComm newData);
void AddToLotteryAccountLinkedList(LotteryData newData);

// 查找当前节点的上一节点
LotteryAccountLinkedList *FindLotteryAccountPreNode(LotteryAccountLinkedList *findNode);
AdminAccountLinkedList *FindAdminAccountPreNode(AdminAccountLinkedList *findNode);
NotaryAccountLinkedlist *FindNotaryAccountPreNode(NotaryAccountLinkedlist *findNode);

// 通过用户名查找节点
LotteryAccountLinkedList *FindLotteryAccountNodeByUserName(char name[]);
AdminAccountLinkedList *FindAdminAccountNodeByUserName(char name[]);
NotaryAccountLinkedlist *FindNotaryAccountNodeByUserName(char name[]);

/*
 *    检查用户名及密码规范性
 * 返回值：返回符合规范的账号、密码
 */
AccountComm *CheckAccountSpecification(AccountComm *account);

/*
 *  检查用户名唯一性
 * @param name 要检查的用户名
 * 返回值：若数据库中已存在,返回1,不存在返回0
 */
int CheckALLUserName(char name[]);

/*
 *    遍历检查admin表
 *返回值：在admin表中已存在,返回1；不存在返回0；
 */
int CheckAdminAccount(char name[]);

/*
 *     遍历检查Notary表
 * 返回值：在Notary表中已存在,返回1；不存在返回0；
 */
int CheckNotaryAccount(char name[]);

/*
 *     遍历检查Lottery表
 * 返回值：在Lottery表中已存在,返回1；不存在返回0；
 */
int CheckLotteryAccount(char name[]);

/********************************/
/***********登录功能相关***********/

// 登录功能主界面
void SignInMenu();

/*
 *     判断是否是管理员登录
 * @param name 用户输入的账号
 * @param pwd 用户输入的密码
 * 返回值：是返回1,不是返回0；
 */
int IsAdminLogin(char name[], char pwd[]);

/*
 *     判断是否是公证员登录
 * @param name 用户输入的账号
 * @param pwd 用户输入的密码
 * 返回值：是返回1,不是返回0；
 */
int IsNotaryLogin(char name[], char pwd[]);

/*
 *     判断是否是彩民登录
 * @param name 用户输入的账号
 * @param pwd 用户输入的密码
 * 返回值：是返回1,不是返回0；
 */
int IsUserLogin(char name[], char pwd[]);

#endif