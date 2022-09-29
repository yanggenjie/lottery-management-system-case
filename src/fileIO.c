#include "account.h"
#include "adminMenu.h"
#include "fileIO.h"
#include <stdio.h>
#include <stdlib.h>
extern Lottery *userHead;
extern Lottery *userCurrent;
extern LotteryTicket *LTHead;
extern LotteryTicket *LTCurrent;
//初始化配置
void initConfig(){
    //初始化管理员账号
    InitAdminAccount();
    //读取彩民账号
    ReadLotteryAccountFromBin();
}

//保存彩民账号
void WriteLotteryAccountToBin()
{
    FILE *userData = fopen("data/account/Lottery.dat", "wb+");
    if (userData == NULL)
    {
        perror("data/account/Lottery.dat");
        exit(EXIT_FAILURE);
    }
    Lottery *temp = userHead;
    if (temp == NULL)
    {
        printf("没有任何彩民信息，保存失败");
        return;
    }
    while (temp != NULL)
    {
        fwrite(&temp->account, sizeof(LotteryAccount), 1, userData);
        temp = temp->next;
    }
    fclose(userData);
}

//读取彩民账号
void ReadLotteryAccountFromBin()
{
    FILE *LTAccountFile = fopen("data/account/Lottery.dat", "r");
    if (LTAccountFile == NULL)
    {
        perror("data/account/Lottery.dat");
        exit(EXIT_FAILURE);
    }
    LotteryAccount LTaccountFromFile;
    while (fread(&LTaccountFromFile, sizeof(LotteryAccount), 1, LTAccountFile))
    {
        AddToLotteryLinkedList(LTaccountFromFile);
    }
}

//保存彩票发行信息表
void WriteLotteryTicketInfoToBin()
{
    FILE *userData = fopen("data/LotteryTicket.dat", "wb+");
    if (userData == NULL)
    {
        perror("data/LotteryTicket.dat");
        exit(EXIT_FAILURE);
    }
    LotteryTicket *temp = LTHead;
    if (temp == NULL)
    {
        printf("没有任何彩民信息，保存失败");
        return;
    }
    while (temp != NULL)
    {
        fwrite(temp, sizeof(temp), 1, userData);
    }
    fclose(userData);
}
//读取
void ReadLotteryInfoFromBin()
{
    FILE *userData = fopen("data/Lottery.dat", "rb");
    if (userData == NULL)
    {
        perror("data/Lottery.dat");
        exit(EXIT_FAILURE);
    }
    LotteryAccount *temp;
    while (fread(temp, sizeof(temp), 1, userData) > 0)
    {
        //增加到彩民链表
    }
}
void ReadLotteryTicketInfoFromBin();