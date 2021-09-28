/*① file.h文件的内容如下：*/
#ifndef _FILE                         /*条件编译，防止重复包含的错误*/
#define _FILE
#include "information.h"
int readFile(inf *contact);           /*将文件中内容读出置于数组中*/
int save(inf *contact,int *n);        /*将数组中内容写入文件中*/
#endif