#include "sqstack.cpp"

void fun(ElemType a[],int n)
{
	int i;
	ElemType e;
	SqStack *st1,*st2;
	InitStack(st1);
	InitStack(st2);
	for (i=0;i<n;i++)
		if (a[i]%2==1)
			Push(st1,a[i]);
		else
			Push(st2,a[i]);
	i=0;
	while (!StackEmpty(st1))
	{	Pop(st1,e);
		a[i++]=e;
	}
	while (!StackEmpty(st2))
	{	Pop(st2,e);
		a[i++]=e;
	}
	DestroyStack(st1);
	DestroyStack(st2);
}

int main()
{
	ElemType a[]={1,2,3,4,5,6};
	int n=6,i;
	for (i=0;i<n;i++)
		printf("%d ",a[i]);
	printf("\n");
	fun(a,n);
	for (i=0;i<n;i++)
		printf("%d ",a[i]);
	printf("\n");
	return 1;
}