#ifndef FILEIO_H
#define FILEIO_H
//初始化配置
void initConfig();
//保存彩民账号
void WriteLotteryAccountToBin();
//读取彩民账号
void ReadLotteryAccountFromBin();

void WriteLotteryTicketInfoToBin();
//读取
void ReadLotteryTicketInfoFromBin();
#endif