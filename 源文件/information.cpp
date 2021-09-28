/*③ information.cpp文件的内容如下：*/
#include<stdio.h>
#include <string.h>
#include <time.h>
#include "information.h"
#include "menu.h"
/*函数功能：输入新联系人的信息
函数参数：3个形参分别为结构体指针，总记录条数指针和编号
函数返回值：无返回值
*/
void input(inf *contact,int *n,int r)
{
	int i;                                                                    /*定义变量i为循环变量*/
	int j1,j2;                                                                /*定义变量j1,j2记录判断结果*/
	printf("请按照提示输入信息（如留空请输入0）\n");  
	contact[r].num=r+1;                                                       /*编号比结构体数组下标多1*/
	printf("第%d条记录\n",r+1);
    do
	{
		j1=0;
		j2=0;
		printf("姓名：");
        scanf("%s",contact[r].name);                                          /*输入姓名*/
		printf("手机号码：");
        scanf("%s",contact[r].phone);                                         /*输入手机号码*/
        printf("家庭电话号码：");
		scanf("%s",contact[r].hometel);                                       /*输入家庭电话号码*/
        printf("办公电话：");
		scanf("%s",contact[r].officetel);                                     /*输入办公电话*/
		j1=(strcmp(contact[r].phone,"0")==0 && strcmp(contact[r].hometel,"0")==0 && strcmp(contact[r].officetel,"0")==0); 
		if(j1)                                                                /*当手机号码，家庭电话号码，办公电话同时为0即留空时，给出提示*/
			printf("手机号码、家庭电话号码、办公电话三项不能同时为空！\n");
		for(i=0;i<(*n)&&!j1;i++)
		{
			j2=(strcmp(contact[r].name,contact[i].name)==0 && strcmp(contact[r].phone,contact[i].phone)==0 && strcmp(contact[r].hometel,contact[i].hometel)==0 && strcmp(contact[r].officetel,contact[i].officetel)==0);
		    if(j2)                                                           /*当输入数据与文件中已有数据重复，给出提示*/
	        {
	            printf("输入重复的信息，请重新输入！\n");
				break;
	        }
		}
	}while(j1 || j2);                                                        /*若三个号码同时为0或者数据重复则循环以上代码直至满足输入条件*/
    printf("电子邮件：");
    scanf("%s",contact[r].email);                                            /*输入电子邮箱*/
	printf("分组（未知、同事、亲戚、朋友、家人、同学等）：");
	scanf("%s",contact[r].type);                                             /*输入分组*/
	if(strcmp(contact[r].type,"0")==0)                                       /*若输入分组为0即留空时系统将自动将其分组改为“未知”*/
		strcpy(contact[r].type,"未知");
	printf("添加成功！\n");
	(*n)++;                                                                  /*总记录条数加一*/
}
/*函数功能：输出指定联系人所有的信息
函数参数：2个形参分别为结构体指针和编号
函数返回值：无返回值
*/
void output(inf *contact,int r)
{
	r=r-1;                                                                    /*编号比结构体数组下标多1*/
	printf("%d\t%s\t%s\t\t%s\t\t%s\t\t%s\t\t%s\n",contact[r].num,contact[r].name,contact[r].phone,contact[r].hometel,contact[r].officetel,contact[r].email,contact[r].type);
}
/*函数功能：改变指定联系人的信息
函数参数：2个形参分别为结构体指针和编号
函数返回值：无返回值
*/
void change(inf *contact,int r)
{
	int choice;                                                                /*定义变量choice记录选项*/
	choice=menuStruct();                                                       /*显示结构体菜单*/
	while(choice>=1 && choice<=7)                                              /*选择菜单中的对应功能*/
	{
	    switch(choice)
	    {
	    case 1:                                                                /*1. 姓名*/
			printf("姓名：");
			scanf("%s",contact[r].name);                                       /*输入修改后的姓名*/
			printf("修改成功！\n");
			choice=menuStruct();                                               /*显示结构体菜单*/
			continue;                                                          /*重新开始下一轮选择*/
	    case 2:                                                                /*2. 手机号码*/
		    printf("手机号码：");
            scanf("%s",contact[r].phone);                                      /*输入修改后的电话号码*/
			printf("修改成功！\n"); 
			choice=menuStruct();                                               /*显示结构体菜单*/
			continue;                                                          /*重新开始下一轮选择*/
		case 3:														           /*3.家庭电话号码*/
			printf("家庭电话号码：");
            scanf("%s",contact[r].hometel);                                    /*输入修改后的家庭电话号码*/
			printf("修改成功！\n");
			choice=menuStruct();                                               /*显示结构体菜单*/
			continue;                                                          /*重新开始下一轮选择*/
		case 4:                                                                /*4. 办公电话*/
			printf("办公电话：");
            scanf("%s",contact[r].officetel);                                  /*输入修改后的办公电话号码*/
			printf("修改成功！\n");
			choice=menuStruct();                                               /*显示结构体菜单*/
			continue;                                                          /*重新开始下一轮选择*/
		case 5:                                                                /*5. 电子邮件*/
			printf("电子邮件：");
            scanf("%s",contact[r].email);                                      /*输入修改后的电子邮件*/
			printf("修改成功！\n");
			choice=menuStruct();                                               /*显示结构体菜单*/
			continue;                                                          /*重新开始下一轮选择*/
		case 6:                                                                /*6. 分组*/
            printf("分组（未知、同事、亲戚、朋友、家人、同学等）：");
			scanf("%s",contact[r].type);                                       /*输入修改后的家庭电话号码*/
			if(strcmp(contact[r].type,"0")==0)                                 /*若输入分组为0即留空时系统将自动将其分组改为“未知”*/
				strcpy(contact[r].type,"未知");
			printf("修改成功！\n");
			choice=menuStruct();                                               /*显示结构体菜单*/
			continue;                                                          /*重新开始下一轮选择*/
	    }
	}
}
/*函数功能：删除一条联系人信息
函数参数：3个形参分别为结构体指针，总记录条数指针和编号
函数返回值：无返回值
*/
void del(inf *contact,int *n,int r)
{
	int i;                                                                     /*定义变量i为循环变量*/
	for(i=r-1;i<(*n);i++)                                                      /*利用循环使得将删除项后面的每一项都覆盖在前一项上以完成对该项的删除*/
	{
	    strcpy(contact[i].name,contact[i+1].name);  
		strcpy(contact[i].phone,contact[i+1].phone);  
		strcpy(contact[i].hometel,contact[i+1].hometel);
		strcpy(contact[i].officetel,contact[i+1].officetel);
		strcpy(contact[i].email,contact[i+1].email);
		strcpy(contact[i].type,contact[i+1].type);
		printf("删除成功！\n");
	}
	(*n)--;                                                                    /*总记录条数减一*/
}