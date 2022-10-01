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
    //读取彩民账号
    ReadLotteryAccountFromBin();
    //读取彩票发行信息
    ReadReleaseDataFromBin();
}

/********************************/
/***********彩民账号保存功能********/
//保存彩民账号
void WriteLotteryAccountToBin()
{
    //打开文件
    FILE *writeFile = fopen("data/LotteryAccount.dat", "wb");
    if (writeFile == NULL)
    {
        perror("data/LotteryAccount.dat");
        exit(EXIT_FAILURE);
    }
    LotteryAccountLinkedList *user = userHead;
    //写入账号数据
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
    //追加打开文件，关闭，防止一开始数据不存在的时候，可以自动创建空文件
    FILE *temp = fopen("data/LotteryAccount.dat", "a+");
    fclose(temp);
    //打开文件
    FILE *readFile = fopen("data/LotteryAccount.dat", "r");
    if (readFile == NULL)
    {
        perror("data/LotteryAccount.dat");
        exit(EXIT_FAILURE);
    }
    //读取数据、创建链表
    LotteryData dataFromFile;
    while (fread(&dataFromFile, sizeof(LotteryData), 1, readFile) > 0)
    {
        AddToLotteryAccount(dataFromFile);
    }
}

/********************************/
/***********彩票信息保存功能********/
//保存发行信息表
void WriteReleaseDataToBin()
{
    //打开文件
    FILE *writeFile = fopen("data/LotteryTicket.dat", "wb");
    if (writeFile == NULL)
    {
        perror("data/LotteryTicket.dat");
        exit(EXIT_FAILURE);
    }
    //写入发行信息
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
    //追加打开文件，关闭，防止一开始数据不存在的时候，可以自动创建空文件
    FILE *temp = fopen("data/LotteryTicket.dat", "a+");
    fclose(temp);
    //打开文件
    FILE *readFile = fopen("data/LotteryTicket.dat", "rb");
    if (readFile == NULL)
    {
        perror("data/Lottery.dat");
        exit(EXIT_FAILURE);
    }
    //读取数据、创建链表
    ReleaseData dataFromFile;
    while (fread(&dataFromFile, sizeof(ReleaseData), 1, readFile) > 0)
    {
        //增加到彩票链表
        AddToLottertTickeyLinkedList(dataFromFile);
    }
}

//保存购买历史
void WriteBoughtHistoryToFile()
{
    char fileName[100] = "data/boughtHistory";
    strcat(fileName, lotteryCurrentLogin->data.account.name);
    //打开和关闭文件的假动作,如果一开始没有配置,会自动生成空配置
    FILE *t = fopen(fileName, "ab");
    fclose(t);
    FILE *outputData = fopen(fileName, "wb");
    if (outputData == NULL)
    {
        perror(fileName);
        exit(EXIT_FAILURE);
    }
    TicketDataLinkedList *temp = lotteryCurrentLogin->data.soldDataHead;
    if (temp == NULL)
    {
        fwrite(&temp->data, sizeof(temp->data), 0, outputData);
        printf("没有数据被写入\n");
    }
    while (temp != NULL)
    {
        fwrite(&temp->data, sizeof(temp->data), 0, outputData);
        temp = temp->next;
    }
}

//读取购买历史
void ReadBoughtHistoryFromFile()
{
    char fileName[100] = "data/boughtHistory";
    strcat(fileName, lotteryCurrentLogin->data.account.name);
    FILE *inputData = fopen(fileName, "rb");
    if (inputData == NULL)
    {
        perror(fileName);
        // exit(EXIT_FAILURE);
        return;
    }
    TicketData newData;
    while (fread(&newData, sizeof(newData), 1, inputData) > 0)
    {
        //添加到当前用户的历史链表
        AddSoldDataToLinkedlist(newData);
    }
}