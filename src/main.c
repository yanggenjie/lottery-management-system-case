#include "account.h"
#include "adminMenu.h"
#include "fileIO.h"
#include <stdio.h>
#include <stdlib.h>
int main()
{
    //初始化配置文件
    initConfig();
    //主菜单
    while (1)
    {
        int choose;
        printf("\n\n*******************************************\n");
        printf("\n\t欢迎使用彩票管理系统\n\n");
        printf("\t1.登录\n");
        printf("\t2.新用户注册\n");
        printf("\t3.退出程序\n");
        printf("\n*******************************************\n");
        printf("请选择功能：");
        scanf("%d", &choose);
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
            exit(0);
        }
    }
    return 0;
}