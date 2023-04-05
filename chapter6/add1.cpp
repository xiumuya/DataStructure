#include <stdio.h>
int FindMin(int a[],int n)
{	int i,mini=0;
	for (i=1;i<n;i++)
		if (a[i]<=a[mini])
			mini=i;
	return mini;
}


int main()
{
	int a[]={1,2,3,1};
	int n=sizeof(a)/sizeof(a[0]);
	printf("½á¹û:%d\n",FindMin(a,n));
	return 1;
}
	
