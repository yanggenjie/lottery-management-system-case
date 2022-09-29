#include "account.h"
#include "adminMenu.h"
#include "fileIO.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    //初始化配置文件
    InitConfig();
    srand((unsigned)time(NULL)); //随机数生成
    //主菜单
    while (1)
    {
        printf("\n\n*******************************************\n");
        printf("\n\t欢迎使用彩票管理系统\n\n");
        printf("\t1.登录\n");
        printf("\t2.新用户注册\n");
        printf("\t3.退出程序\n");
        printf("\n*******************************************\n");
        printf("请选择功能：");
        int choose = RecStringConverToInt();
        switch (choose)
        {
        case 1:
            SignIn();
            break;
        case 2:
            SignUp();
            break;
        case 3:
            exit(0);
        default:
            break;
        }
    }
    return 0;
}