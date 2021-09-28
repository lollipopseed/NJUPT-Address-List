/*⑤ menu.h文件的内容如下：*/
#ifndef _MENU         /*条件编译，防止重复包含的错误*/
#define _MENU
void menu();          /*欢迎界面*/
int menuBase();       /*顶层菜单函数*/
int menuStruct();     /*结构体菜单函数*/
void menuout();       /*辅助输出函数显示信息*/
#endif