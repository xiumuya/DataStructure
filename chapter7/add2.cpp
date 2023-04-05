#include <stdio.h>
#define MaxSize 30
typedef char ElemType;
typedef ElemType SqBinTree[MaxSize];

void PreOrder1(SqBinTree a,int i)
//a����洢����������СΪMaxSize��,i��ֵΪ1
{
	if (i<MaxSize)
	{
		if (a[i]!='#')
		{	printf("%c ",a[i]);		//���ʸ��ڵ�
			PreOrder1(a,2*i);		//����������
			PreOrder1(a,2*i+1);		//����������
		}
	}
}

void PreOrder2(SqBinTree a) //a����洢����������СΪMaxSize��
{	int St[MaxSize],top=-1,i=1;
	top++;						//���ڵ�1��ջ
	St[top]=i;
	while (top>-1)
	{
		i=St[top];top--;		//��ջ�ڵ�i
		printf("%c ",a[i]);
		if (2*i+1<MaxSize && a[2*i+1]!='#')	//�Һ��ӽ�ջ
		{	top++;
			St[top]=2*i+1;
		}
		if (2*i<MaxSize && a[2*i]!='#')		//���ӽ�ջ
		{	top++;
			St[top]=2*i;
		}
	}
}

int main()
{	
	SqBinTree bt="#ABCDE#F##GH##I##";
	printf("  ��������ĵݹ��㷨:"); PreOrder1(bt,1);printf("\n");
	printf("��������ķǵݹ��㷨:"); PreOrder2(bt);printf("\n");
	return 1;
}
