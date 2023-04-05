#include <stdio.h>
#define M 3			//行数常量
#define N 4			//列数常量
void Find(int B[M][N],int x,int &i,int &j)
{	i=0;j=N-1;
	while (B[i][j]!=x)
	{	if(B[i][j]<x) i++;
		else j--;
	}
}
int main()
{	int i,j,x=11;
	int B[M][N]={{1,2,3,4},{5,6,7,8},{9,10,11,12}};
	Find(B,x,i,j);
	printf("B[%d][%d]=%d\n",i,j,x);
	return 1;
}

