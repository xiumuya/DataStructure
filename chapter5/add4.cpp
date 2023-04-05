#include <stdio.h>

bool isn(int x,int y)	//x整除y时返回true
{
	if (x % y==0)
		return true;
	else
		return false;
}
int fun(int n,int m) 
{
	if (n==6)
		return m; 
	else
	{
		if (isn(5*fun(n+1,m),4))
			return (5*fun(n+1,m)/4+1);
		else		//当m不合适时返回-1
			return -1;
	}
}
int pnumber()
{
	int k;
	int m=0;
	while(true) 
	{
		k=fun(1,m);
		if (k!=-1)
			break;
		m++;
	}
	return k;
}
int main()
{
	printf("结果:%d\n",pnumber());
	return 1;
}
	