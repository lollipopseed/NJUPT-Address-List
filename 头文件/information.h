/*�� information.h�ļ����������£�*/
#ifndef _INFORMATION                       /*�������룬��ֹ�ظ������Ĵ���*/
#define _INFORMATION
typedef struct information                 /*����ṹ������*/
{
    int num;                               /*���*/
	char name[20];                         /*����*/
    char phone[20];                        /*�ֻ�����*/
    char hometel[20];                      /*��ͥ�绰����*/
    char officetel[20];                    /*�칫�绰*/
    char email[50];                        /*�����ʼ�*/
    char type[20];                         /*����*/
}inf;
void input(inf *contact,int *n,int r);     /*��������ϵ�˵���Ϣ*/
void output(inf *contact,int r);           /*���ָ����ϵ�����е���Ϣ*/
void change(inf *contact,int r);           /*�ı�ָ����ϵ�˵���Ϣ*/
void del(inf *contact,int *n,int r);       /*ɾ��һ����ϵ����Ϣ*/
#endif