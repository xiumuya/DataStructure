#include <stdio.h>
#define MaxSize 100
typedef char ElemType;
typedef struct 
{	ElemType S[MaxSize];		//��Ź���ջ�е�Ԫ��
	int top1,top2;				//����ջ��ָ��
} StackType;					//��������ջ����
//-----ջ��ʼ���㷨------
void InitStack1(StackType &st)
{	st.top1=-1;
	st.top2=MaxSize;
}
//-----��ջ���㷨------
bool StackEmpty1(StackType st,int i)	//i=1:ջ1��i=2:ջ2
{	if (i==1)
		return(st.top1==-1);
	else 	//i=2
		return(st.top2==MaxSize);
}
//-----��ջ�㷨------
bool Push1(StackType &st,int i,ElemType x)	//i=1:ջ1��i=2:ջ2
{	if (st.top1==st.top2-1)			//ջ��
		return false;
	if (i==1)						//x��ջS1
	{	st.top1++;
		st.S[st.top1]=x;
	}
	else if (i==2)					//x��ջS2
	{	st.top2--;
		st.S[st.top2]=x;
	}
	else							//����i���󷵻�false
		return false;
	return true;					//�����ɹ�����true
}
//-----��ջ�㷨------
bool Pop1(StackType &st,int i,ElemType &x) //i=1:ջ1��i=2:ջ2
{	if (i==1)						//S1��ջ
	{	if (st.top1==-1)			//S1ջ��
			return false;
		else						//��ջS1��Ԫ��
		{	x=st.S[st.top1];
			st.top1--;
		}
	}
	else if (i==2)					//S2��ջ
	{	if (st.top2==MaxSize)		//S2ջ��
			return false;
		else						//��ջS2��Ԫ��
		{	x=st.S[st.top2];
			st.top2++;
		}
	}
	else							//����i���󷵻�false
		return false;
	return true;					//�����ɹ�����true
}
