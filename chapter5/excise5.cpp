#include<stdio.h>

int fun(int n)
{	if (n==1 || n==2)
		return n;
	else
		return fun(n-1)+fun(n-2);
}

int main()
{
	int n=5;
	printf("n=%d的不同走法数=%d\n",n,fun(n));
	return 1;
}
	
