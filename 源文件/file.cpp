/*① file.cpp文件的内容如下：*/
#include <stdio.h>
#include <stdlib.h>
#include "file.h"
#include "information.h"
/*函数功能：将文件中内容读出置于数组中
函数参数：结构体指针
函数返回值：从文件中读出的实际记录条数
*/
int readFile(inf *contact)
{
	int i=0;
	FILE *fp;
	fp=fopen("D:\\contact.txt", "r");           /*以读方式打开指定文件*/
	if(fp==0)
	{
		printf("打开文件失败！\n");             /*若打开失败输出提示信息*/
		exit(1);
	}
    fscanf(fp,"%d%s%s%s%s%s%s",&contact[i].num,contact[i].name,contact[i].phone,contact[i].hometel,contact[i].officetel,contact[i].email,contact[i].type);        /*读出第一条记录*/
   	while(!feof(fp))                            /*文件未结束时循环*/
	{	
        i++;
	   	fscanf(fp,"%d%s%s%s%s%s%s",&contact[i].num,contact[i].name,contact[i].phone,contact[i].hometel,contact[i].officetel,contact[i].email,contact[i].type);          /*再读出下一条记录*/
    }
	fclose(fp);                                /*关闭文件*/
	return i;                                  /*返回记录条数*/
}
/*函数功能：将数组中内容写入文件中
函数参数：2个形参分别为结构体指针和总记录条数指针
函数返回值：从数组中写入的实际记录条数
*/
int save(inf *contact,int *n)
{
	FILE *fp;
	fp=fopen("D:\\contact.txt", "w");        /*以写方式打开指定文件*/
	if(fp==0)
	{
		printf("打开文件失败！\n");           /*若打开失败输出提示信息*/
		exit(1);
	}
	int i;
	for(i=0;i<(*n);i++)
	{
	    fprintf(fp,"%d\t%s\t%s\t\t%s\t\t%s\t\t%s\t\t%s\n",contact[i].num,contact[i].name,contact[i].phone,contact[i].hometel,contact[i].officetel,contact[i].email,contact[i].type);            /*一次性向文件写入n条记录*/
	}
	fclose(fp);                               /*关闭文件*/
	printf("保存成功！\n");
	return i-1;                               /*返回记录条数*/
}