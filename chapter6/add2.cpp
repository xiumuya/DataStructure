#include <stdio.h>
#define M 10
#define N 10
bool LowDiag(int a[M][N],int m,int n,int &s)
{	int i,j;
	if (m!=n)
		return false;
	s=0;
	for (i=1;i<m;i++)
		for (j=0;j<i;j++)
			s+=a[i][j];
	return true;
}
int main()
{
	int m=4,n=4;
	int a[M][N]={
		{1,1,1,1},
		{1,1,1,1},
		{1,1,1,1},
		{1,1,1,1}};
	int s=0;
	if(LowDiag(a,m,n,s))
		printf("½á¹û:%d\n",s);
	else
		printf("m!=n\n");

	return 1;
}
	
