#include <stdio.h>
#define MaxSize 100
void fun1()
{	int i,n,x;
	int st[MaxSize],top=-1;			//栈和栈指针
	int qu[MaxSize],front=0,rear=0;	//队列和队指针
	printf("n:");
	scanf("%d",&n);
	for (i=0;i<n;i++)
	{	printf("第%d个车皮编号:",i+1);
		scanf("%d",&x);
		if (x%2==1)		//编号为奇数,则进队列
		{	qu[rear]=x;
			printf("  %d进队\n",x);
			rear++;
		}
		else			//编号为偶数,则进栈
		{	top++;
			st[top]=x;
			printf("  %d进栈\n",x);
		}
	}
	printf("出轨操作:\n  ");
	while (front!=rear)		//队列中所有元素出队
	{	printf("%d出队 ",qu[front]);
		front++;
	}
	while (top>=0)			//栈中所有元素出栈
	{	printf("%d出栈 ",st[top]);
		top--;
	}
	printf("\n");
}
int main()
{
	fun1();
	return 0;
}
