/*③ information.h文件的内容如下：*/
#ifndef _INFORMATION                       /*条件编译，防止重复包含的错误*/
#define _INFORMATION
typedef struct information                 /*定义结构体数组*/
{
    int num;                               /*编号*/
	char name[20];                         /*姓名*/
    char phone[20];                        /*手机号码*/
    char hometel[20];                      /*家庭电话号码*/
    char officetel[20];                    /*办公电话*/
    char email[50];                        /*电子邮件*/
    char type[20];                         /*分组*/
}inf;
void input(inf *contact,int *n,int r);     /*输入新联系人的信息*/
void output(inf *contact,int r);           /*输出指定联系人所有的信息*/
void change(inf *contact,int r);           /*改变指定联系人的信息*/
void del(inf *contact,int *n,int r);       /*删除一条联系人信息*/
#endif