/*�� function.cpp�ļ����������£�*/
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "information.h"
#include "menu.h"
/*�������ܣ������������ұ��
����������2���βηֱ�Ϊ�ṹ��ָ����ܼ�¼����ָ��
��������ֵ�����ҽ������Ӧ�ı�ţ����δ���ҵ��򷵻�0
*/
int searchperson(inf *contact,int *n)
{
	int i;                                                /*����iΪѭ������*/
	char names[20];                                       /*����������������*/
	printf("������Ҫ��ѯ��������");
    scanf("%s",names);                                    /*������Ҫ��ѯ������*/
	for(i=0;i<(*n);i++)                                   /*ѭ��������������*/
    {
        if(strcmp(names,contact[i].name)==0)              /*�Ƚϲ�ѯ�������ļ�����������ͬ*/
        {
             return i+1;                                  /*�����ͬ�򷵻ظ���ϵ�˱��*/
             break;                                       /*�˳�ѭ��*/
        }
    }
	if(i==(*n))                                           /*���û�в�ѯ�����*/
	    printf("û�д˼�¼��");
    return 0;                                             /*����0*/
}
/*�������ܣ����պ�����ұ��
����������2���βηֱ�Ϊ�ṹ��ָ����ܼ�¼����ָ��
��������ֵ�����ҽ������Ӧ�ı�ţ����δ���ҵ��򷵻�0
*/
int searchphone(inf *contact,int *n)
{
	int i;                                                /*����iΪѭ������*/
	char phones[20];                                      /*���������������*/
	printf("������Ҫ��ѯ�ĵ绰���룺");
    scanf("%s",phones);                                   /*�������*/
	for(i=0;i<(*n);i++)                                   /*ѭ���������б��*/
    {
        if(strcmp(phones,contact[i].phone)==0 || strcmp(phones,contact[i].hometel)==0 || strcmp(phones,contact[i].officetel)==0)
        {
             return i+1;                                  /*�Ƚϸú�����ͨѶ¼�ڵ��ֻ����롢��ͥ�绰���롢�칫�绰��ͬ�������ͬ�򷵻ر��*/
             break;                                       /*�˳�ѭ��*/
        }
    }
	if(i==(*n))                                           /*���û�в�ѯ�����*/
	    printf("û�д˼�¼��");
	return 0;                                             /*����0*/
}
/*�������ܣ�������Ѱ�����з�����ϵ�˵������͵绰�����
����������2���βηֱ�Ϊ�ṹ��ָ����ܼ�¼����ָ��
��������ֵ���޷���ֵ
*/
void searchtype(inf *contact,int *n)
{
	int i;                                                /*����iΪѭ������*/
	char compare[20];                                     /*����Ƚ�Ԥ������*/
	printf("����������Ҫ���ҵķ��飺");
	scanf("%s",compare);                                  /*�����������*/
	printf("����\t�ֻ�����\t��ͥ�绰����\t�칫�绰\n");
	for(i=0;i<(*n);i++)                                   /*ѭ���������б��*/
	{
	    if(strcmp(contact[i].type,compare)==0)            /*�Ƚϸ÷���������ͨѶ¼��ÿ���˷������Ƶ���ͬ�������ͬ�����*/
		{
			printf("%s\t%s\t%s\t%s\n",contact[i].name,contact[i].phone,contact[i].hometel,contact[i].officetel);
		}
	}
	printf("��ѯ��ϣ�\n");
}
/*�������ܣ��ӳ������ʱ��
�����������β�Ϊ��Ҫ�ӳٵ�ʱ��
��������ֵ���޷���ֵ
*/
void delayms(clock_t delay)
{
    clock_t start=clock();                                  /*��ʼ��ʱ*/
    clock_t end;                                            /*��¼����ʱ��*/
    do
	{
        end=clock();                                        /*ֱ������ʱ��ﵽ�ﵽ�����ӳ�ʱ������˳�ѭ��*/
    }while(end-start<delay);
}
/*�������ܣ�ģ�Ⲧ�ţ���Ļ��ģ����ֻ���Ч��������ʾ�����˵ĵ绰�����еĸ�������
����������2���βηֱ�Ϊ�ṹ��ָ����ܼ�¼����ָ��
��������ֵ���޷���ֵ
*/
void call(inf *contact,int *n)
{
	int i;                                                  /*����iΪ���ѭ������*/
    int j;                                                  /*����jΪ��ʱѭ������*/
	int choice=0;                                           /*����choice��¼ѡ�����ʼ��Ϊ0*/
	char names[20];                                         /*����������������*/
	for(i=0;i<(*n);i++)                                     /*ѭ���������б��*/
	{
	    printf("%s\n",contact[i].name);                     /*������е���ϵ����*/
	}
	printf("������Ҫ�����������");
    scanf("%s",names);                                      /*������Ҫ���������*/
	for(i=0;i<(*n);i++)                                     /*ѭ���������б��*/
    {
        if(strcmp(names,contact[i].name)==0)                /*�Ƚϲ�ѯͨ��¼���Ƿ񱣴����ϵ����Ϣ*/
        {
			 char compare[20];                              /*����Ƚ�Ԥ������*/
			 do
			 {
				 printf("����������Ҫ����ĵ绰���� 1.�ֻ�����\t2.��ͥ�绰\t3.�칫�绰 ��");
			     scanf("%d",&choice);                       /*���벦��绰����ѡ��*/
			 }while(choice!=1 && choice!=2 && choice!=3);
			 if(choice==1)
			     strcpy(compare,contact[i].phone);          /*ѡ�񲦴���ϵ�˵��ֻ�����*/  
			 else if(choice==2)
				 strcpy(compare,contact[i].hometel);        /*ѡ�񲦴���ϵ�˵ļ�ͥ�绰*/
			 else if(choice==3)
				 strcpy(compare,contact[i].officetel);      /*ѡ�񲦴���ϵ�˵İ칫�绰*/
			 for(j=0;j<strlen(compare);j++)
			 {
			     delayms(1000);                             /*ѡ��ģ���ӡ�ӳ�ʱ��*/
				 putchar(compare[j]);                       /*��������ַ�*/
			 }
			 printf("\n");
             break;                                         /*�˳�ѭ��*/
        }
    }
	if(i==(*n))                                             /*���û�в�ѯ�����*/
	{
	    printf("û�д˼�¼��");                             /*����0*/
	}
}
/*�������ܣ�����ģ�����ң�������һ����������г������������Ϣ
����������2���βηֱ�Ϊ�ṹ��ָ����ܼ�¼����ָ��
��������ֵ����ѯ�����������
*/
int fuzzy(inf *contact,int *n)
{
	int i;                                                  /*����iΪ���ѭ������*/
	int j;                                                  /*����jΪ�ڲ�ѭ������*/
	int count=0;                                            /*����countΪ��������������ʼ��Ϊ0*/
	char word[10];                                          /*�������飬�洢Ҫ��ѯ�Ĺؼ���*/
	char compare[20];                                       /*����Ƚ����飬�洢����*/
	printf("������Ҫ�����Ĺؼ��֣�");
    scanf("%s",word);                                       /*����Ҫ��ѯ�Ĺؼ���*/
	menuout();                                              /*�������������ʾ��Ϣ*/
	for(i=0;i<(*n);i++)                                     /*ѭ���������б��*/
	{
		for(j=0;j<strlen(contact[i].name);j+=2)             /*�������ַ����з�������������ַ�*/
		{
			compare[0]=contact[i].name[j];
			compare[1]=contact[i].name[j+1];
			compare[2]='\0';
			if(strcmp(word,compare)==0)                     /*���������ͬ�ַ�*/
			{
				output(contact,i+1);                        /*�������ϵ�˵�������Ϣ*/
				count++;                                    /*����������һ*/
			}
			continue;                                       /*������ѭ��*/
		}
	}
    printf("��ѯ����,����ѯ��%d�����\n",count);
	return count;                                           /*���ز�ѯ�����������*/
}