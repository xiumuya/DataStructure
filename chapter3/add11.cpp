#include <stdio.h>
#define MaxSize 100
void fun1()
{	int i,n,x;
	int st[MaxSize],top=-1;			//ջ��ջָ��
	int qu[MaxSize],front=0,rear=0;	//���кͶ�ָ��
	printf("n:");
	scanf("%d",&n);
	for (i=0;i<n;i++)
	{	printf("��%d����Ƥ���:",i+1);
		scanf("%d",&x);
		if (x%2==1)		//���Ϊ����,�������
		{	qu[rear]=x;
			printf("  %d����\n",x);
			rear++;
		}
		else			//���Ϊż��,���ջ
		{	top++;
			st[top]=x;
			printf("  %d��ջ\n",x);
		}
	}
	printf("�������:\n  ");
	while (front!=rear)		//����������Ԫ�س���
	{	printf("%d���� ",qu[front]);
		front++;
	}
	while (top>=0)			//ջ������Ԫ�س�ջ
	{	printf("%d��ջ ",st[top]);
		top--;
	}
	printf("\n");
}
int main()
{
	fun1();
	return 0;
}
