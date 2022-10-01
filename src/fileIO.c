#include "account.h"
#include "adminMenu.h"
#include "fileIO.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//彩民账号
extern LotteryAccountLinkedList *userHead;
extern LotteryAccountLinkedList *userCurrent;
//当前登录的彩民
extern LotteryAccountLinkedList *lotteryCurrentLogin;

//发行的彩票
extern ReleaseDataLinkedlist *releaseDataHead;
extern ReleaseDataLinkedlist *releaseDataCurrent;

//初始化配置
void InitConfig()
{
    //初始化管理员账号
    InitAdminAccount();
    //初始化彩民账号
    InitNotaryAccount();
    //读取彩民账号
    ReadLotteryAccountFromBin();
    // 读取彩票发行信息
    ReadReleaseDataFromBin();
}

/********************************/
/***********彩民账号保存功能********/
//保存彩民账号
void WriteLotteryAccountToBin()
{
    char filePath[100] = "data/LotteryAccount";
    //打开文件
    FILE *writeFile = fopen(filePath, "wb");
    if (writeFile == NULL)
    {
        perror(filePath);
        exit(EXIT_FAILURE);
    }
    //保存账号数据
    LotteryAccountLinkedList *user = userHead;
    while (user != NULL)
    {
        fwrite(&user->data, sizeof(LotteryData), 1, writeFile);
        user = user->next;
    }
    //关闭文件
    fclose(writeFile);
}

//读取彩民账号
void ReadLotteryAccountFromBin()
{
    char filePath[100] = "data/LotteryAccount";
    //打开文件
    FILE *readFile = fopen(filePath, "rb");
    if (readFile == NULL)
    {
        perror(filePath);
        // exit(EXIT_FAILURE);
        return;
    }
    //读取数据、创建链表
    LotteryData dataFromFile;
    while (fread(&dataFromFile, sizeof(LotteryData), 1, readFile) > 0)
    {
        // //初始化用户的彩票购买历史的头指针,
        // //之后，在登录成功时，读取历史记录文件，再重新关联历史记录
        // dataFromFile.ticketDataHead = NULL;
        // dataFromFile.ticketDataCurrent == NULL;
        //添加数据到链表
        AddToLotteryAccountLinkedList(dataFromFile);
    }
    //关闭文件
    fclose(readFile);
}

/********************************/
/***********彩票信息保存功能********/
//保存发行信息表
void WriteReleaseDataToBin()
{
    char filePath[100] = "data/LotteryTicket";
    //打开文件
    FILE *writeFile = fopen(filePath, "wb");
    if (writeFile == NULL)
    {
        perror(filePath);
        exit(EXIT_FAILURE);
    }
    //保存发行数据
    ReleaseDataLinkedlist *releaseData = releaseDataHead;
    while (releaseData != NULL)
    {
        fwrite(&releaseData->data, sizeof(ReleaseData), 1, writeFile);
        releaseData = releaseData->next;
    }
    //关闭文件
    fclose(writeFile);
}

//读取彩票发行信息
void ReadReleaseDataFromBin()
{
    char filePath[100] = "data/LotteryTicket";
    //打开文件
    FILE *readFile = fopen(filePath, "rb");
    if (readFile == NULL)
    {
        perror(filePath);
        // exit(EXIT_FAILURE);
        return;
    }

    //读取数据、创建链表
    ReleaseData dataFromFile;
    while (fread(&dataFromFile, sizeof(ReleaseData), 1, readFile) > 0)
    {
        //增加到彩票链表
        AddToReleaseDataLinkedList(dataFromFile);
    }

    //关闭文件
    fclose(readFile);
}

//保存用户购买历史
void WriteBoughtHistoryToFile()
{
    //自定义用户特有的文件名
    char filePath[100] = "data/boughtHistory_";
    strcat(filePath, lotteryCurrentLogin->data.account.name);

    //打开文件
    FILE *writeFile = fopen(filePath, "wb");
    if (writeFile == NULL)
    {
        perror(filePath);
        exit(EXIT_FAILURE);
    }

    //保存购买历史数据
    TicketDataLinkedList *ticketData = lotteryCurrentLogin->data.ticketDataHead;
    while (ticketData != NULL)
    {
        fwrite(&ticketData->data, sizeof(TicketData), 1, writeFile);
        ticketData = ticketData->next;
    }

    //关闭文件
    fclose(writeFile);
}

//读取用户购买历史
void ReadBoughtHistoryFromFile()
{
    //自定义用户特有的文件名
    char filePath[100] = "data/boughtHistory_";
    strcat(filePath, lotteryCurrentLogin->data.account.name);
    //打开文件
    FILE *readFile = fopen(filePath, "rb");
    if (readFile == NULL)
    {
        perror(filePath);
        // exit(EXIT_FAILURE);
        return;
    }
    //读取数据、创建链表
    TicketData ticketDataFromFile;

    //初始化当前用户的彩票信息头指针，
    //这样下面在执行的时候才会把读取的第一个数据关联到当前登录用户
    lotteryCurrentLogin->data.ticketDataHead = NULL;
    lotteryCurrentLogin->data.ticketDataCurrent = NULL;
    while (fread(&ticketDataFromFile, sizeof(TicketData), 1, readFile))
    {
        //添加到当前用户的历史链表
        AddToTicketDataLinkedList(ticketDataFromFile);
    }

    //关闭文件
    fclose(readFile);
}