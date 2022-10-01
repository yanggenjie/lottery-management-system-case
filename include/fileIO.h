#ifndef FILEIO_H
#define FILEIO_H
//初始化配置
void InitConfig();

//保存彩民账号
void WriteLotteryAccountToBin();
//读取彩民账号
void ReadLotteryAccountFromBin();

//保存管理员账号
//读取管理员账号

//保存公证员账号
//读取公证员账号

//保存发行信息
void WriteReleaseDataToBin();
//读取发行信息
void ReadReleaseDataFromBin();


//保存用户购买历史
void WriteBoughtHistoryToFile();
//读取用户购买历史
void ReadBoughtHistoryFromFile();

#endif