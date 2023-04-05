#include<stdio.h>

double avg(double A[],int i)
{	if (i==0)
		return(A[0]);
	else
		return((avg(A,i-1)*i+A[i])/(i+1));
}

int main()
{
	double a[]={1,2,3,4};
	int n=sizeof(a)/sizeof(a[0]);
	printf("Æ½¾ùÖµ=%g\n",avg(a,n-1));
	return 1;
}
	
