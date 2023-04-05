#include <stdio.h>
#define MAXL 100

void fun(int a[],int n,int b[])
{	int i;
	for (i=0;i<n;i++)
		b[a[i]-1]=a[i];
}

void disparr(int a[],int n)	//Êä³öÊý×éa
{
	for (int i=0;i<n;i++)
		printf("%3d",a[i]);
	printf("\n");
}

int main()
{
	int a[]={2,7,10,6,1,5,9,4,3,8};
	int n=10;
	int b[MAXL];
	printf("a:"); disparr(a,n);
	fun(a,n,b);
	printf("b:"); disparr(b,n);
	return 1;
}
