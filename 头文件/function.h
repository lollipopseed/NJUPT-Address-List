/*② function.h文件的内容如下：*/
#ifndef _FUNCTION                                 /*条件编译，防止重复包含的错误*/
#define _FUNCTION
int searchperson(inf *contact,int *n);            /*按照人名查找编号*/
int searchphone(inf *contact,int *n);             /*按照号码查找编号*/
void searchtype(inf *contact,int *n);             /*按分类寻找所有符合联系人的姓名和电话并输出*/
void delayms(clock_t delay);                      /*延迟所需的时间*/
void call(inf *contact,int *n);                   /*模拟拨号，屏幕上模拟打字机的效果依次显示出此人的电话号码中的各个数字*/
int fuzzy(inf *contact,int *n);                   /*中文模糊查找，如输入一个“李”，则列出所有姓李的信息*/
#endif