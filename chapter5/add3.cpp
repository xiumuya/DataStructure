#include <stdio.h>
int fun(int i)
{	if (i==7)
		return 2;
	else
		return 2*fun(i+1)+1;
}
int main()
{
	printf("½á¹û:%d\n",fun(0));
	return 1;
}
	