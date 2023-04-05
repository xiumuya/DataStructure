#include <stdio.h>

void disparr(int a[],int n)	//Êä³öÊı×éa
{
	for (int i=0;i<n;i++)
		printf("%3d",a[i]);
	printf("\n");
}

void fun(int a[],int n)
{	int i,j,d,tmp;
	d=n/3;
	while (true)
	{	for (i=d;i<n;i++)
		{	tmp=a[i];
			j=i-d;
			while (j>=0 && tmp<a[j])
			{	a[j+d]=a[j];
				j=j-d;
			}
			a[j+d]=tmp;
		}
		printf("d=%d:",d); disparr(a,n);
		if (d==1) break;
		else if (d<3) d=1;
		else d=d/3;
	}
}

int main()
{
	int a[]={5,1,3,6,2,7,4,8};
	int n=8;
	printf("a:"); disparr(a,n);
	fun(a,n);
	printf("a:"); disparr(a,n);

	return 1;
}
