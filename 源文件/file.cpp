/*�� file.cpp�ļ����������£�*/
#include <stdio.h>
#include <stdlib.h>
#include "file.h"
#include "information.h"
/*�������ܣ����ļ������ݶ�������������
�����������ṹ��ָ��
��������ֵ�����ļ��ж�����ʵ�ʼ�¼����
*/
int readFile(inf *contact)
{
	int i=0;
	FILE *fp;
	fp=fopen("D:\\contact.txt", "r");           /*�Զ���ʽ��ָ���ļ�*/
	if(fp==0)
	{
		printf("���ļ�ʧ�ܣ�\n");             /*����ʧ�������ʾ��Ϣ*/
		exit(1);
	}
    fscanf(fp,"%d%s%s%s%s%s%s",&contact[i].num,contact[i].name,contact[i].phone,contact[i].hometel,contact[i].officetel,contact[i].email,contact[i].type);        /*������һ����¼*/
   	while(!feof(fp))                            /*�ļ�δ����ʱѭ��*/
	{	
        i++;
	   	fscanf(fp,"%d%s%s%s%s%s%s",&contact[i].num,contact[i].name,contact[i].phone,contact[i].hometel,contact[i].officetel,contact[i].email,contact[i].type);          /*�ٶ�����һ����¼*/
    }
	fclose(fp);                                /*�ر��ļ�*/
	return i;                                  /*���ؼ�¼����*/
}
/*�������ܣ�������������д���ļ���
����������2���βηֱ�Ϊ�ṹ��ָ����ܼ�¼����ָ��
��������ֵ����������д���ʵ�ʼ�¼����
*/
int save(inf *contact,int *n)
{
	FILE *fp;
	fp=fopen("D:\\contact.txt", "w");        /*��д��ʽ��ָ���ļ�*/
	if(fp==0)
	{
		printf("���ļ�ʧ�ܣ�\n");           /*����ʧ�������ʾ��Ϣ*/
		exit(1);
	}
	int i;
	for(i=0;i<(*n);i++)
	{
	    fprintf(fp,"%d\t%s\t%s\t\t%s\t\t%s\t\t%s\t\t%s\n",contact[i].num,contact[i].name,contact[i].phone,contact[i].hometel,contact[i].officetel,contact[i].email,contact[i].type);            /*һ�������ļ�д��n����¼*/
	}
	fclose(fp);                               /*�ر��ļ�*/
	printf("����ɹ���\n");
	return i-1;                               /*���ؼ�¼����*/
}