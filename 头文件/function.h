/*�� function.h�ļ����������£�*/
#ifndef _FUNCTION                                 /*�������룬��ֹ�ظ������Ĵ���*/
#define _FUNCTION
int searchperson(inf *contact,int *n);            /*�����������ұ��*/
int searchphone(inf *contact,int *n);             /*���պ�����ұ��*/
void searchtype(inf *contact,int *n);             /*������Ѱ�����з�����ϵ�˵������͵绰�����*/
void delayms(clock_t delay);                      /*�ӳ������ʱ��*/
void call(inf *contact,int *n);                   /*ģ�Ⲧ�ţ���Ļ��ģ����ֻ���Ч��������ʾ�����˵ĵ绰�����еĸ�������*/
int fuzzy(inf *contact,int *n);                   /*����ģ�����ң�������һ����������г������������Ϣ*/
#endif