#include<stdio.h>

int fun(int n)
{	if (n<10)
		return 1;
	else
		return fun(n/10)+1;
}

int main()
{
	int n=100;
	printf("%d��λ��=%d\n",n,fun(n));
	return 1;
}
	
