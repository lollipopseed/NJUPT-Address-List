/*�� information.cpp�ļ����������£�*/
#include<stdio.h>
#include <string.h>
#include <time.h>
#include "information.h"
#include "menu.h"
/*�������ܣ���������ϵ�˵���Ϣ
����������3���βηֱ�Ϊ�ṹ��ָ�룬�ܼ�¼����ָ��ͱ��
��������ֵ���޷���ֵ
*/
void input(inf *contact,int *n,int r)
{
	int i;                                                                    /*�������iΪѭ������*/
	int j1,j2;                                                                /*�������j1,j2��¼�жϽ��*/
	printf("�밴����ʾ������Ϣ��������������0��\n");  
	contact[r].num=r+1;                                                       /*��űȽṹ�������±��1*/
	printf("��%d����¼\n",r+1);
    do
	{
		j1=0;
		j2=0;
		printf("������");
        scanf("%s",contact[r].name);                                          /*��������*/
		printf("�ֻ����룺");
        scanf("%s",contact[r].phone);                                         /*�����ֻ�����*/
        printf("��ͥ�绰���룺");
		scanf("%s",contact[r].hometel);                                       /*�����ͥ�绰����*/
        printf("�칫�绰��");
		scanf("%s",contact[r].officetel);                                     /*����칫�绰*/
		j1=(strcmp(contact[r].phone,"0")==0 && strcmp(contact[r].hometel,"0")==0 && strcmp(contact[r].officetel,"0")==0); 
		if(j1)                                                                /*���ֻ����룬��ͥ�绰���룬�칫�绰ͬʱΪ0������ʱ��������ʾ*/
			printf("�ֻ����롢��ͥ�绰���롢�칫�绰�����ͬʱΪ�գ�\n");
		for(i=0;i<(*n)&&!j1;i++)
		{
			j2=(strcmp(contact[r].name,contact[i].name)==0 && strcmp(contact[r].phone,contact[i].phone)==0 && strcmp(contact[r].hometel,contact[i].hometel)==0 && strcmp(contact[r].officetel,contact[i].officetel)==0);
		    if(j2)                                                           /*�������������ļ������������ظ���������ʾ*/
	        {
	            printf("�����ظ�����Ϣ�����������룡\n");
				break;
	        }
		}
	}while(j1 || j2);                                                        /*����������ͬʱΪ0���������ظ���ѭ�����ϴ���ֱ��������������*/
    printf("�����ʼ���");
    scanf("%s",contact[r].email);                                            /*�����������*/
	printf("���飨δ֪��ͬ�¡����ݡ����ѡ����ˡ�ͬѧ�ȣ���");
	scanf("%s",contact[r].type);                                             /*�������*/
	if(strcmp(contact[r].type,"0")==0)                                       /*���������Ϊ0������ʱϵͳ���Զ���������Ϊ��δ֪��*/
		strcpy(contact[r].type,"δ֪");
	printf("��ӳɹ���\n");
	(*n)++;                                                                  /*�ܼ�¼������һ*/
}
/*�������ܣ����ָ����ϵ�����е���Ϣ
����������2���βηֱ�Ϊ�ṹ��ָ��ͱ��
��������ֵ���޷���ֵ
*/
void output(inf *contact,int r)
{
	r=r-1;                                                                    /*��űȽṹ�������±��1*/
	printf("%d\t%s\t%s\t\t%s\t\t%s\t\t%s\t\t%s\n",contact[r].num,contact[r].name,contact[r].phone,contact[r].hometel,contact[r].officetel,contact[r].email,contact[r].type);
}
/*�������ܣ��ı�ָ����ϵ�˵���Ϣ
����������2���βηֱ�Ϊ�ṹ��ָ��ͱ��
��������ֵ���޷���ֵ
*/
void change(inf *contact,int r)
{
	int choice;                                                                /*�������choice��¼ѡ��*/
	choice=menuStruct();                                                       /*��ʾ�ṹ��˵�*/
	while(choice>=1 && choice<=7)                                              /*ѡ��˵��еĶ�Ӧ����*/
	{
	    switch(choice)
	    {
	    case 1:                                                                /*1. ����*/
			printf("������");
			scanf("%s",contact[r].name);                                       /*�����޸ĺ������*/
			printf("�޸ĳɹ���\n");
			choice=menuStruct();                                               /*��ʾ�ṹ��˵�*/
			continue;                                                          /*���¿�ʼ��һ��ѡ��*/
	    case 2:                                                                /*2. �ֻ�����*/
		    printf("�ֻ����룺");
            scanf("%s",contact[r].phone);                                      /*�����޸ĺ�ĵ绰����*/
			printf("�޸ĳɹ���\n"); 
			choice=menuStruct();                                               /*��ʾ�ṹ��˵�*/
			continue;                                                          /*���¿�ʼ��һ��ѡ��*/
		case 3:														           /*3.��ͥ�绰����*/
			printf("��ͥ�绰���룺");
            scanf("%s",contact[r].hometel);                                    /*�����޸ĺ�ļ�ͥ�绰����*/
			printf("�޸ĳɹ���\n");
			choice=menuStruct();                                               /*��ʾ�ṹ��˵�*/
			continue;                                                          /*���¿�ʼ��һ��ѡ��*/
		case 4:                                                                /*4. �칫�绰*/
			printf("�칫�绰��");
            scanf("%s",contact[r].officetel);                                  /*�����޸ĺ�İ칫�绰����*/
			printf("�޸ĳɹ���\n");
			choice=menuStruct();                                               /*��ʾ�ṹ��˵�*/
			continue;                                                          /*���¿�ʼ��һ��ѡ��*/
		case 5:                                                                /*5. �����ʼ�*/
			printf("�����ʼ���");
            scanf("%s",contact[r].email);                                      /*�����޸ĺ�ĵ����ʼ�*/
			printf("�޸ĳɹ���\n");
			choice=menuStruct();                                               /*��ʾ�ṹ��˵�*/
			continue;                                                          /*���¿�ʼ��һ��ѡ��*/
		case 6:                                                                /*6. ����*/
            printf("���飨δ֪��ͬ�¡����ݡ����ѡ����ˡ�ͬѧ�ȣ���");
			scanf("%s",contact[r].type);                                       /*�����޸ĺ�ļ�ͥ�绰����*/
			if(strcmp(contact[r].type,"0")==0)                                 /*���������Ϊ0������ʱϵͳ���Զ���������Ϊ��δ֪��*/
				strcpy(contact[r].type,"δ֪");
			printf("�޸ĳɹ���\n");
			choice=menuStruct();                                               /*��ʾ�ṹ��˵�*/
			continue;                                                          /*���¿�ʼ��һ��ѡ��*/
	    }
	}
}
/*�������ܣ�ɾ��һ����ϵ����Ϣ
����������3���βηֱ�Ϊ�ṹ��ָ�룬�ܼ�¼����ָ��ͱ��
��������ֵ���޷���ֵ
*/
void del(inf *contact,int *n,int r)
{
	int i;                                                                     /*�������iΪѭ������*/
	for(i=r-1;i<(*n);i++)                                                      /*����ѭ��ʹ�ý�ɾ��������ÿһ�������ǰһ��������ɶԸ����ɾ��*/
	{
	    strcpy(contact[i].name,contact[i+1].name);  
		strcpy(contact[i].phone,contact[i+1].phone);  
		strcpy(contact[i].hometel,contact[i+1].hometel);
		strcpy(contact[i].officetel,contact[i+1].officetel);
		strcpy(contact[i].email,contact[i+1].email);
		strcpy(contact[i].type,contact[i+1].type);
		printf("ɾ���ɹ���\n");
	}
	(*n)--;                                                                    /*�ܼ�¼������һ*/
}