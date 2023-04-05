#include "graph.cpp"		//图的基本运算算法

void InDs1(MatGraph g)		//求出图G中每个顶点的入度
{	int i,j,n;
	printf("各顶点入度:\n");
	for (j=0;j<g.n;j++)
	{	n=0;
		for (i=0;i<g.n;i++)
			if (g.edges[i][j]!=0)
				n++;		//n累计入度数
		printf("  顶点%d:%d\n",j,n);
	}
}
void OutDs1(MatGraph g)		//求出图G中每个顶点的出度
{	int i,j,n;
	printf("各顶点出度:\n");
	for (i=0;i<g.n;i++)
	{	n=0;
		for (j=0;j<g.n;j++)
			if (g.edges[i][j]!=0)
				n++;			//n累计出度数
		printf("  顶点%d:%d\n",i,n);
	}
}

void ZeroOutDs1(MatGraph g)		//求出图G中出度为0的顶点个数
{	int i,j,n;
	printf("出度为0的顶点:");
	for (i=0;i<g.n;i++)
	{	n=0;
		for (j=0;j<g.n;j++)
			if (g.edges[i][j]!=0)	//存在一条边
				n++;
		if (n==0)
			printf("%2d\n",i);
	}
	printf("\n");
}


int main()
{
	MatGraph g;
	int A[MAXV][MAXV]={
		{0,1,0,1,0},
		{0,0,1,1,0},
		{0,0,0,1,1},
		{0,0,0,0,0},
		{1,0,0,1,0}};
	int n=5, e=8;
	CreateMat(g,A,n,e);			//建立《教程》中图8.1(b)的邻接矩阵
	printf("图G的邻接矩阵:\n");
	DispMat(g);					//输出邻接矩阵

	InDs1(g);
	OutDs1(g);
	ZeroOutDs1(g);

	return 1;
}