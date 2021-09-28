/*�� mainConttrol.cpp�ļ����������£�*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string>
#include "file.h"
#include "function.h"
#include "information.h"
#include "mainControl.h"
#include "menu.h"
inf contact[100];                                        /*����ṹ������洢��ϵ����Ϣ*/
int main( )                                              /*����������ȡ�ļ�*/
{
	int n;                                               /*�������nΪ�ܼ�¼����*/
	int r;                                               /*�������rΪ��ǰ��������ϵ�˱��*/
    int choice;                                          /*�������choiceΪ��������ѡ��*/
	int k=0;                                             /*�������k��¼case6��ѡ�񰴺��ַ�����ѯ*/
	n=readFile(contact);                                 /*���ȶ�ȡ�ļ�����¼�������ظ�ֵ���ܼ�¼����n*/
	if (!n)                                              /*���ԭ�����ļ�Ϊ��*/
		input(contact,&n,0);                             /*д���µ�����*/
	menu();                                              /*��ʾ��ӭ�˵�*/
	choice=menuBase();                                   /*��ʾ����˵�*/
	while(choice>=1 && choice<=8)                        /*ѡ��˵��еĶ�Ӧ����*/
	{
	    switch(choice)
	    {
	    case 1:                                          /*1. ��������ϵ��*/
			r=n;                                         /*��¼�¼���ϵ�˵ı��*/
		    input(contact,&n,r);                         /*��������ϵ�˵���Ϣ*/
		    choice=menuBase();                           /*��ʾ����˵�*/
		    continue;                                    /*���¿�ʼ��һ��ѡ��*/
	    case 2:                                          /*2. �޸���ϵ����Ϣ*/
	    	if(r=searchperson(contact,&n));              /*������Բ�ѯ������ϵ��*/
	    	else                                         /*������ܲ�ѯ������ϵ��*/
			{
				choice=menuBase();                       /*��ʾ����˵�*/
		        continue;                                /*���¿�ʼ��һ��ѡ��*/
			}
			change(contact,r-1);                         /*�޸ĸ���ϵ�˵���Ϣ*/
			choice=menuBase();                           /*��ʾ����˵�*/
		    continue;                                    /*���¿�ʼ��һ��ѡ��*/
		case 3:                                          /*3. ɾ����ϵ��*/
			if(r=searchperson(contact,&n));              /*������Բ�ѯ������ϵ��*/
	    	else                                         /*������ܲ�ѯ������ϵ��*/
			{
				choice=menuBase();                       /*��ʾ����˵�*/
		        continue;                                /*���¿�ʼ��һ��ѡ��*/
			}
			del(contact,&n,r);                           /*ɾ������ϵ�˵���Ϣ*/
			choice=menuBase();                           /*��ʾ����˵�*/
		    continue;                                    /*���¿�ʼ��һ��ѡ��*/
		case 4:                                          /*4. ����*/
			call(contact,&n);                            /*���ò��Ź��ܺ���*/
			choice=menuBase();                           /*��ʾ����˵�*/
		    continue;                                    /*���¿�ʼ��һ��ѡ��*/
		case 5:                                          /*5. �鿴��ϵ����Ϣ*/
			searchtype(contact,&n);                      /*���ò鿴���麯��*/
			choice=menuBase();                           /*��ʾ����˵�*/
			continue;                                    /*���¿�ʼ��һ��ѡ��*/
		case 6:                                          /*6. ������ϵ����Ϣ*/
			while(k!=1 && k!=2)
			{
				printf("1.����������\t2.�������ѯ\n����������ѡ��");
			    scanf("%d",&k);                          /*�����ѯ����ѡ��*/
			}
			if(k==1)
			{
			    if(r=searchperson(contact,&n))           /*������԰�������ѯ������ϵ��*/
				{
					menuout();                           /*�������������ʾ��Ϣ*/
			        output(contact,r);                   /*���ָ����ϵ�����е���Ϣ*/
				    k=0;                                 /*���ò�ѯ����*/
				}
	    	    else                                     /*������ܰ�������ѯ������ϵ��*/
			    {
					k=0;                                 /*���ò�ѯ����*/
				    choice=menuBase();                   /*��ʾ����˵�*/
		            continue;                            /*���¿�ʼ��һ��ѡ��*/
			    }
			}
			else if(k==2)
			{
			    if(r=searchphone(contact,&n))            /*������԰������ѯ������ϵ��*/
				{
					menuout();                           /*�������������ʾ��Ϣ*/
			        output(contact,r);                   /*���ָ����ϵ�����е���Ϣ*/
				    k=0;                                 /*���ò�ѯ����*/
				}
	    	    else                                     /*������ܰ������ѯ������ϵ��*/
			    {
					k=0;                                 /*���ò�ѯ����*/
				    choice=menuBase();                   /*��ʾ����˵�*/
		            continue;                            /*���¿�ʼ��һ��ѡ��*/
			    }
			}
			choice=menuBase();                           /*��ʾ����˵�*/
			continue;                                    /*���¿�ʼ��һ��ѡ��*/
		case 7:                                          /*7. ������ϵ����Ϣ*/
			save(contact,&n);                            /*���ñ��溯��������������д���ļ���*/
			choice=menuBase();                           /*��ʾ����˵�*/
			continue;                                    /*���¿�ʼ��һ��ѡ��*/
		case 8:                                          /*8. ����ģ������*/
			fuzzy(contact,&n);                           /*����ģ�����Һ���*/
			choice=menuBase();                           /*��ʾ����˵�*/
			continue;                                    /*���¿�ʼ��һ��ѡ��*/
	    }
	}
	if(!choice)                                          /*���ѡ��0�˳�*/
	{
		save(contact,&n);                                /*�˳�ʱ�Զ����棬������������д���ļ���*/
		printf("��л����ʹ�ã�");
	}
    return 0;
}