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
extern TicktetLinkedList *LTHead;
extern TicktetLinkedList *LTCurrent;

//初始化配置
void InitConfig()
{
    //初始化管理员账号
    InitAdminAccount();
    // //读取彩民账号
    // ReadLotteryAccountFromBin();
    // //读取彩票发行信息
    // ReadLotteryTicketInfoFromBin();
}

/********************************/
/***********彩民账号保存功能********/
//保存彩民账号
void WriteLotteryAccountToBin()
{
    FILE *userData = fopen("data/LotteryAccount.dat", "wb");
    if (userData == NULL)
    {
        perror("data/LotteryAccount.dat");
        exit(EXIT_FAILURE);
    }
    LotteryAccountLinkedList *temp = userHead;
    if (temp == NULL)
    {
        printf("没有任何彩民信息，保存失败");
        return;
    }
    while (temp != NULL)
    {
        fwrite(&temp->data, sizeof(LotteryData), 1, userData);
        temp = temp->next;
    }
    fclose(userData);
}

//读取彩民账号
void ReadLotteryAccountFromBin()
{
    FILE *LTAccountFile = fopen("data/LotteryAccount.dat", "r");
    if (LTAccountFile == NULL)
    {
        perror("data/LotteryAccount.dat");
        exit(EXIT_FAILURE);
    }
    LotteryData LTaccountFromFile;
    while (fread(&LTaccountFromFile, sizeof(LotteryData), 1, LTAccountFile))
    {
        AddToLotteryAccount(LTaccountFromFile);
    }
}

/********************************/
/***********彩票信息保存功能********/
//保存彩票发行信息表
void WriteLotteryTicketInfoToBin()
{
    FILE *lotteryTicketFile = fopen("data/LotteryTicket.dat", "wb");
    if (lotteryTicketFile == NULL)
    {
        perror("data/LotteryTicket.dat");
        exit(EXIT_FAILURE);
    }
    TicktetLinkedList *LTInfo = LTHead;
    if (LTHead == NULL)
    {
        printf("没有任何发行信息\n");
        fwrite(&LTInfo->data, sizeof(TicketData), 0, lotteryTicketFile);
        return;
    }
    while (LTInfo != NULL)
    {
        fwrite(&LTInfo->data, sizeof(TicketData), 1, lotteryTicketFile);
        LTInfo = LTInfo->next;
    }
    fclose(lotteryTicketFile);
    printf("保存发行信息成功!\n");
    return;
}

//读取彩票发行信息
void ReadLotteryTicketInfoFromBin()
{
    FILE *lotteryTicketFile = fopen("data/LotteryTicket.dat", "rb");
    if (lotteryTicketFile == NULL)
    {
        perror("data/Lottery.dat");
        exit(EXIT_FAILURE);
    }

    TicketData readLTInfoFromFile;
    while (fread(&readLTInfoFromFile, sizeof(TicketData), 1, lotteryTicketFile) > 0)
    {
        //增加到彩票链表
        AddToLottertTickeyLinkedList(readLTInfoFromFile);
    }
}

//保存购买历史
void WriteBoughtHistoryToFile()
{
    char fileName[100] = "data/boughtHistory";
    strcat(fileName, lotteryCurrentLogin->data.account.name);
    //打开和关闭文件的假动作,如果一开始没有配置,会自动生成空配置
    FILE *t=fopen(fileName,"ab");
    fclose(t);
    FILE *outputData = fopen(fileName, "wb");
    if (outputData == NULL)
    {
        perror(fileName);
        exit(EXIT_FAILURE);
    }
    LTSoldDataLinkedList *temp = lotteryCurrentLogin->data.soldDataHead;
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
    SoldCommData newData;
    while (fread(&newData, sizeof(newData), 1, inputData) > 0)
    {
        //添加到当前用户的历史链表
        AddSoldDataToLinkedlist(newData);
    }
}