#include "account.h"
#include "adminMenu.h"
#include "userMenu.h"
#include "fileIO.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// 彩民账号
extern LotteryAccountLinkedList *lotteryAccountHead;
extern LotteryAccountLinkedList *lotteryAccountCurrent;
// 发行信息
extern ReleaseDataLinkedlist *releaseDataHead;
extern ReleaseDataLinkedlist *releaseDataCurrent;

// 彩票信息
extern TicketDataLinkedList *ticketDataHead;
extern TicketDataLinkedList *ticketDataCurrent;

// 初始化配置
void InitConfig()
{
    // 初始化管理员账号
    InitAdminAccount();
    // 初始化公证员账号
    InitNotaryAccount();
    // 读取彩民账号
    ReadLotteryAccountFromBin();
    // 读取彩票发行信息
    ReadReleaseDataFromBin();
    // 读取彩票数据
    ReadTicketDataToFile();
}

/********************************/
/***********彩民账号保存功能********/
// 保存彩民账号
void WriteLotteryAccountToBin()
{
    // 打开文件
    char fileName[] = "data_LotteryAccount";
    FILE *writeFile = fopen(fileName, "wb");
    // 保存账号数据
    LotteryAccountLinkedList *user = lotteryAccountHead;
    while (user != NULL)
    {
        fwrite(&user->data, sizeof(LotteryData), 1, writeFile);
        user = user->next;
    }
    // 关闭文件
    fclose(writeFile);
}

// 读取彩民账号
void ReadLotteryAccountFromBin()
{
    char fileName[] = "data_LotteryAccount";
    // 打开文件
    FILE *readFile = fopen(fileName, "rb");
    if (readFile == NULL)
    {
        perror(fileName);
        // exit(EXIT_FAILURE);
        return;
    }
    // 读取数据、创建链表
    LotteryData dataFromFile;
    while (fread(&dataFromFile, sizeof(LotteryData), 1, readFile))
    {
        // 添加数据到链表
        AddToLotteryAccountLinkedList(dataFromFile);
    }
    // 关闭文件
    fclose(readFile);
}

/********************************/
/***********彩票信息保存功能********/
// 保存发行信息
void WriteReleaseDataToBin()
{
    char fileName[] = "data_release";
    // 打开文件
    FILE *writeFile = fopen(fileName, "wb");
    if (writeFile == NULL)
    {
        perror(fileName);
        exit(EXIT_FAILURE);
    }
    // 保存发行数据
    ReleaseDataLinkedlist *releaseData = releaseDataHead;
    while (releaseData != NULL)
    {
        fwrite(&releaseData->data, sizeof(ReleaseData), 1, writeFile);
        releaseData = releaseData->next;
    }
    // 关闭文件
    fclose(writeFile);
}

// 读取发行信息
void ReadReleaseDataFromBin()
{
    char fileName[] = "data_release";
    // 打开文件
    FILE *readFile = fopen(fileName, "rb");
    if (readFile == NULL)
    {
        perror(fileName);
        // exit(EXIT_FAILURE);
        return; // 考虑到第一次启动程序的时候，是没有任何文件的，所以就只是取消读写，而不是退出程序
    }

    // 读取数据、创建链表
    ReleaseData dataFromFile;
    while (fread(&dataFromFile, sizeof(ReleaseData), 1, readFile))
    {
        // 增加到彩票链表
        AddToReleaseDataLinkedList(dataFromFile);
    }

    // 关闭文件
    fclose(readFile);
}

// 保存彩票信息
void WriteTicketDataToFile()
{
    char fileName[] = "data_ticket";
    // 打开文件
    FILE *writeFile = fopen(fileName, "wb");
    if (writeFile == NULL)
    {
        perror(fileName);
        exit(EXIT_FAILURE);
    }

    // 保存数据
    TicketDataLinkedList *ticketData = ticketDataHead;
    while (ticketData != NULL)
    {
        fwrite(&ticketData->data, sizeof(TicketData), 1, writeFile);
        ticketData = ticketData->next;
    }
    // 关闭文件
    fclose(writeFile);
}

// 读取彩票信息
void ReadTicketDataToFile()
{
    char fileName[] = "data_ticket";
    // 打开文件
    FILE *readFile = fopen(fileName, "rb");
    if (readFile == NULL)
    {
        perror(fileName);
        // exit(EXIT_FAILURE);
        return;
    }
    // 读取数据、创建链表
    TicketData ticketDataFromFile;
    while (fread(&ticketDataFromFile, sizeof(TicketData), 1, readFile))
    {
        // 添加到当前用户的历史链表
        AddToTicketDataLinkedList(ticketDataFromFile);
    }
    // 关闭文件
    fclose(readFile);
}