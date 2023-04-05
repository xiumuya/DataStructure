#include <stdio.h>
#include <string.h>
const int MAX=100;
char c[MAX][3];
int st=0,sp,n;			//全局变量，st记录移动的步骤，sp指向为'-'的棋子
void print()				//输出一个移动步骤
{	printf("  step%-2d:",++st);
	for (int i=1;i<=2*n+2;i++)
		printf("%s",c[i]);
	printf("\n");
}
void mvtosp(int k)		//将c[k]和c[k+1]两个棋子与'--'交换
{	for (int j=0;j<=1;j++)
	{	strcpy(c[sp+j],c[k+j]);
		strcpy(c[k+j],"―");
	}
	sp=k;			//sp指向"--"的棋子
	print();			//输出一个解
}
void mv(int n)		//求解2n个棋子移动问题
{	if (n==4)			//递归出口
	{	mvtosp(4); mvtosp(8); mvtosp(2);
		mvtosp(7); mvtosp(1);
	}
	else				//求解n>4的情况
	{	mvtosp(n);
		mvtosp(2*n-1);
		mv(n-1); 
	}
}
void init(int n)		//初始化c数组
{	int i;
	st=0;
	sp=2*n+1;			//sp指向第2n+1的棋子，即"--"
	for (i=1;i<=n;i++)
		strcpy(c[i],"○");
	for (i=n+1;i<=2*n;i++)
		strcpy(c[i],"●");
	strcpy(c[2*n+1],"―");
	strcpy(c[2*n+2],"―");
}
int main()
{	do
	{	printf("输入n值(4-20):");
		scanf("%d",&n);
	} while (n>20 || n<4);
	init(n);
	printf("移动过程如下:\n");
	mv(n);
	printf("\n");
	return 1;
}

