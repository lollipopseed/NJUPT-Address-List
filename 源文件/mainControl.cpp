/*④ mainConttrol.cpp文件的内容如下：*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string>
#include "file.h"
#include "function.h"
#include "information.h"
#include "mainControl.h"
#include "menu.h"
inf contact[100];                                        /*定义结构体数组存储联系人信息*/
int main( )                                              /*主函数，读取文件*/
{
	int n;                                               /*定义变量n为总记录条数*/
	int r;                                               /*定义变量r为当前操作的联系人编号*/
    int choice;                                          /*定义变量choice为主程序中选项*/
	int k=0;                                             /*定义变量k记录case6中选择按何种方法查询*/
	n=readFile(contact);                                 /*首先读取文件，记录条数返回赋值给总记录条数n*/
	if (!n)                                              /*如果原来的文件为空*/
		input(contact,&n,0);                             /*写入新的数据*/
	menu();                                              /*显示欢迎菜单*/
	choice=menuBase();                                   /*显示顶层菜单*/
	while(choice>=1 && choice<=8)                        /*选择菜单中的对应功能*/
	{
	    switch(choice)
	    {
	    case 1:                                          /*1. 增加新联系人*/
			r=n;                                         /*记录新加联系人的编号*/
		    input(contact,&n,r);                         /*输入新联系人的信息*/
		    choice=menuBase();                           /*显示顶层菜单*/
		    continue;                                    /*重新开始下一轮选择*/
	    case 2:                                          /*2. 修改联系人信息*/
	    	if(r=searchperson(contact,&n));              /*如果可以查询到该联系人*/
	    	else                                         /*如果不能查询到该联系人*/
			{
				choice=menuBase();                       /*显示顶层菜单*/
		        continue;                                /*重新开始下一轮选择*/
			}
			change(contact,r-1);                         /*修改该联系人的信息*/
			choice=menuBase();                           /*显示顶层菜单*/
		    continue;                                    /*重新开始下一轮选择*/
		case 3:                                          /*3. 删除联系人*/
			if(r=searchperson(contact,&n));              /*如果可以查询到该联系人*/
	    	else                                         /*如果不能查询到该联系人*/
			{
				choice=menuBase();                       /*显示顶层菜单*/
		        continue;                                /*重新开始下一轮选择*/
			}
			del(contact,&n,r);                           /*删除该联系人的信息*/
			choice=menuBase();                           /*显示顶层菜单*/
		    continue;                                    /*重新开始下一轮选择*/
		case 4:                                          /*4. 拨号*/
			call(contact,&n);                            /*调用拨号功能函数*/
			choice=menuBase();                           /*显示顶层菜单*/
		    continue;                                    /*重新开始下一轮选择*/
		case 5:                                          /*5. 查看联系人信息*/
			searchtype(contact,&n);                      /*调用查看分组函数*/
			choice=menuBase();                           /*显示顶层菜单*/
			continue;                                    /*重新开始下一轮选择*/
		case 6:                                          /*6. 查找联系人信息*/
			while(k!=1 && k!=2)
			{
				printf("1.按人名查找\t2.按号码查询\n请输入您的选择：");
			    scanf("%d",&k);                          /*输入查询方法选项*/
			}
			if(k==1)
			{
			    if(r=searchperson(contact,&n))           /*如果可以按人名查询到该联系人*/
				{
					menuout();                           /*辅助输出函数显示信息*/
			        output(contact,r);                   /*输出指定联系人所有的信息*/
				    k=0;                                 /*重置查询变量*/
				}
	    	    else                                     /*如果不能按人名查询到该联系人*/
			    {
					k=0;                                 /*重置查询变量*/
				    choice=menuBase();                   /*显示顶层菜单*/
		            continue;                            /*重新开始下一轮选择*/
			    }
			}
			else if(k==2)
			{
			    if(r=searchphone(contact,&n))            /*如果可以按号码查询到该联系人*/
				{
					menuout();                           /*辅助输出函数显示信息*/
			        output(contact,r);                   /*输出指定联系人所有的信息*/
				    k=0;                                 /*重置查询变量*/
				}
	    	    else                                     /*如果不能按号码查询到该联系人*/
			    {
					k=0;                                 /*重置查询变量*/
				    choice=menuBase();                   /*显示顶层菜单*/
		            continue;                            /*重新开始下一轮选择*/
			    }
			}
			choice=menuBase();                           /*显示顶层菜单*/
			continue;                                    /*重新开始下一轮选择*/
		case 7:                                          /*7. 保存联系人信息*/
			save(contact,&n);                            /*调用保存函数将数组中内容写入文件中*/
			choice=menuBase();                           /*显示顶层菜单*/
			continue;                                    /*重新开始下一轮选择*/
		case 8:                                          /*8. 中文模糊查找*/
			fuzzy(contact,&n);                           /*调用模糊查找函数*/
			choice=menuBase();                           /*显示顶层菜单*/
			continue;                                    /*重新开始下一轮选择*/
	    }
	}
	if(!choice)                                          /*如果选择0退出*/
	{
		save(contact,&n);                                /*退出时自动保存，将数组中内容写入文件中*/
		printf("感谢您的使用！");
	}
    return 0;
}