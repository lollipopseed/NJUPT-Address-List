/*② function.cpp文件的内容如下：*/
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "information.h"
#include "menu.h"
/*函数功能：按照人名查找编号
函数参数：2个形参分别为结构体指针和总记录条数指针
函数返回值：查找结果所对应的编号，如果未查找到则返回0
*/
int searchperson(inf *contact,int *n)
{
	int i;                                                /*定义i为循环变量*/
	char names[20];                                       /*定义姓名输入数组*/
	printf("请输入要查询的人名：");
    scanf("%s",names);                                    /*输入需要查询的人名*/
	for(i=0;i<(*n);i++)                                   /*循环遍历所有人名*/
    {
        if(strcmp(names,contact[i].name)==0)              /*比较查询人名与文件里人名的异同*/
        {
             return i+1;                                  /*如果相同则返回该联系人编号*/
             break;                                       /*退出循环*/
        }
    }
	if(i==(*n))                                           /*如果没有查询到结果*/
	    printf("没有此记录！");
    return 0;                                             /*返回0*/
}
/*函数功能：按照号码查找编号
函数参数：2个形参分别为结构体指针和总记录条数指针
函数返回值：查找结果所对应的编号，如果未查找到则返回0
*/
int searchphone(inf *contact,int *n)
{
	int i;                                                /*定义i为循环变量*/
	char phones[20];                                      /*定义号码输入数组*/
	printf("请输入要查询的电话号码：");
    scanf("%s",phones);                                   /*输入号码*/
	for(i=0;i<(*n);i++)                                   /*循环遍历所有编号*/
    {
        if(strcmp(phones,contact[i].phone)==0 || strcmp(phones,contact[i].hometel)==0 || strcmp(phones,contact[i].officetel)==0)
        {
             return i+1;                                  /*比较该号码与通讯录内的手机号码、家庭电话号码、办公电话异同，如果相同则返回编号*/
             break;                                       /*退出循环*/
        }
    }
	if(i==(*n))                                           /*如果没有查询到结果*/
	    printf("没有此记录！");
	return 0;                                             /*返回0*/
}
/*函数功能：按分类寻找所有符合联系人的姓名和电话并输出
函数参数：2个形参分别为结构体指针和总记录条数指针
函数返回值：无返回值
*/
void searchtype(inf *contact,int *n)
{
	int i;                                                /*定义i为循环变量*/
	char compare[20];                                     /*定义比较预留数组*/
	printf("请输入您需要查找的分组：");
	scanf("%s",compare);                                  /*输入分组名称*/
	printf("姓名\t手机号码\t家庭电话号码\t办公电话\n");
	for(i=0;i<(*n);i++)                                   /*循环遍历所有编号*/
	{
	    if(strcmp(contact[i].type,compare)==0)            /*比较该分组名称与通讯录内每个人分组名称的异同，如果相同则输出*/
		{
			printf("%s\t%s\t%s\t%s\n",contact[i].name,contact[i].phone,contact[i].hometel,contact[i].officetel);
		}
	}
	printf("查询完毕！\n");
}
/*函数功能：延迟所需的时间
函数参数：形参为需要延迟的时间
函数返回值：无返回值
*/
void delayms(clock_t delay)
{
    clock_t start=clock();                                  /*开始计时*/
    clock_t end;                                            /*记录结束时间*/
    do
	{
        end=clock();                                        /*直至结束时间达到达到所需延迟时间才能退出循环*/
    }while(end-start<delay);
}
/*函数功能：模拟拨号，屏幕上模拟打字机的效果依次显示出此人的电话号码中的各个数字
函数参数：2个形参分别为结构体指针和总记录条数指针
函数返回值：无返回值
*/
void call(inf *contact,int *n)
{
	int i;                                                  /*定义i为编号循环变量*/
    int j;                                                  /*定义j为延时循环变量*/
	int choice=0;                                           /*定义choice记录选项，并初始化为0*/
	char names[20];                                         /*定义姓名输入数组*/
	for(i=0;i<(*n);i++)                                     /*循环遍历所有编号*/
	{
	    printf("%s\n",contact[i].name);                     /*输出所有的联系人名*/
	}
	printf("请输入要拨打的人名：");
    scanf("%s",names);                                      /*输入需要拨打的人名*/
	for(i=0;i<(*n);i++)                                     /*循环遍历所有编号*/
    {
        if(strcmp(names,contact[i].name)==0)                /*比较查询通信录中是否保存该联系人信息*/
        {
			 char compare[20];                              /*定义比较预留数组*/
			 do
			 {
				 printf("请输入您需要拨打的电话类型 1.手机号码\t2.家庭电话\t3.办公电话 ：");
			     scanf("%d",&choice);                       /*输入拨打电话类型选项*/
			 }while(choice!=1 && choice!=2 && choice!=3);
			 if(choice==1)
			     strcpy(compare,contact[i].phone);          /*选择拨打联系人的手机号码*/  
			 else if(choice==2)
				 strcpy(compare,contact[i].hometel);        /*选择拨打联系人的家庭电话*/
			 else if(choice==3)
				 strcpy(compare,contact[i].officetel);      /*选择拨打联系人的办公电话*/
			 for(j=0;j<strlen(compare);j++)
			 {
			     delayms(1000);                             /*选择模拟打印延迟时长*/
				 putchar(compare[j]);                       /*依次输出字符*/
			 }
			 printf("\n");
             break;                                         /*退出循环*/
        }
    }
	if(i==(*n))                                             /*如果没有查询到结果*/
	{
	    printf("没有此记录！");                             /*返回0*/
	}
}
/*函数功能：中文模糊查找，如输入一个“李”，则列出所有姓李的信息
函数参数：2个形参分别为结构体指针和总记录条数指针
函数返回值：查询到结果的条数
*/
int fuzzy(inf *contact,int *n)
{
	int i;                                                  /*定义i为外层循环变量*/
	int j;                                                  /*定义j为内层循环变量*/
	int count=0;                                            /*定义count为计数变量，并初始化为0*/
	char word[10];                                          /*定义数组，存储要查询的关键字*/
	char compare[20];                                       /*定义比较数组，存储姓名*/
	printf("请输入要搜索的关键字：");
    scanf("%s",word);                                       /*输入要查询的关键字*/
	menuout();                                              /*辅助输出函数显示信息*/
	for(i=0;i<(*n);i++)                                     /*循环遍历所有编号*/
	{
		for(j=0;j<strlen(contact[i].name);j+=2)             /*从姓名字符串中分离出单个中文字符*/
		{
			compare[0]=contact[i].name[j];
			compare[1]=contact[i].name[j+1];
			compare[2]='\0';
			if(strcmp(word,compare)==0)                     /*如果遇到相同字符*/
			{
				output(contact,i+1);                        /*输出此联系人的所有信息*/
				count++;                                    /*计数变量加一*/
			}
			continue;                                       /*结束内循环*/
		}
	}
    printf("查询结束,共查询到%d条结果\n",count);
	return count;                                           /*返回查询到结果的条数*/
}