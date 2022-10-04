#include "account.h"
#include "adminMenu.h"
#include "fileIO.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    srand((unsigned)time(NULL)); // 随机数生成
    // 初始化配置文件
    InitConfig();
    // 主菜单
    for (;;)
    {
        printf("\n\n*******************************************\n");
        printf("\n\t欢迎使用彩票管理系统\n");
        printf("*******************************************\n");
        printf("\t1.登录\n");
        printf("\t2.新用户注册\n");
        printf("\t3.退出程序\n");
        printf("\n*******************************************\n");
        printf("请选择功能：");
        int choose = RecStringConverToInt();
        switch (choose)
        {
        case 1:
            SignInMenu();
            break;
        case 2:
            SignUpMenu();
            break;
        case 3:
            exit(0);
        default:
            break;
        }
    }
    return 0;
}