#ifndef FILEIO_H
#define FILEIO_H
//初始化配置
void InitConfig();
//保存彩民账号
void WriteLotteryAccountToBin();
//读取彩民账号
void ReadLotteryAccountFromBin();

//保存彩票信息
void WriteLotteryTicketInfoToBin();
//读取彩票信息
void ReadLotteryTicketInfoFromBin();


//保存购买历史
void WriteBoughtHistoryToFile();
//读取购买历史
void ReadBoughtHistoryFromFile();

#endif