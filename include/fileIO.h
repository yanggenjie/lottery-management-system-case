#ifndef FILEIO_H
#define FILEIO_H
// 初始化配置
void InitConfig();

// 保存彩民账号
void WriteLotteryAccountToBin();
// 读取彩民账号
void ReadLotteryAccountFromBin();

// 保存管理员账号
// 读取管理员账号

// 保存公证员账号
// 读取公证员账号

// 保存发行信息
void WriteReleaseDataToBin();
// 读取发行信息
void ReadReleaseDataFromBin();


// 保存彩票信息
void WriteTicketDataToFile();
// 读取彩票信息
void ReadTicketDataToFile();

#endif