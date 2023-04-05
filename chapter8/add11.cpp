#include "graph.cpp"

int MinPath(MatGraph g)
{
	int i,j,k;
	int A[MAXV][MAXV];
	int min=32767,B[MAXV];
	for (i=0;i<g.n;i++)
		for (j=0;j<g.n;j++)
			A[i][j]=g.edges[i][j];
	for (k=0;k<g.n;k++)		//应用Floyd算法计算每对村庄之间的最短路径长度
		for (i=0;i<g.n;i++)
			for (j=0;j<g.n;j++)
				if (A[i][k]+A[k][j]<A[i][j])
					A[i][j]=A[i][k]+A[k][j];
	for (i=0;i<g.n;i++)		//求每个村庄到村庄i的往返路径长度
	{
		B[i]=0;
		for (j=0;j<g.n;j++)
			B[i]+=A[i][j]+A[j][i];
	}
	for (i=0;i<g.n;i++)		//求最短往返路径长度的顶点k
		if (B[i]<min)
		{	k=i;
			min=B[i];
		}
	return k;
}

int MaxMinPath(MatGraph g)
{
	int i,j,k;
	int A[MAXV][MAXV];
	int s,min=32767;
	for (i=0;i<g.n;i++)
		for (j=0;j<g.n;j++)
			A[i][j]=g.edges[i][j];

	for (k=0;k<g.n;k++)		//应用Floyd算法计算每对村庄之间的最短路径长度
		for (i=0;i<g.n;i++)
			for (j=0;j<g.n;j++)
				if (A[i][k]+A[k][j]<A[i][j])
					A[i][j]=A[i][k]+A[k][j];
	k=-1;
	for (i=0;i<g.n;i++)		//对每个村庄循环一次
	{	s=0;
		for (j=0;j<g.n;j++)	//求到达村庄i的一条最长路径长度
			if (A[j][i]>s)
				s=A[j][i];
		if (s<min)			//在各最长路径中选最短的一条,将该村庄放在k中
		{	k=i;
			min=s;
		}
	}
	return k;
}

int main()
{
	MatGraph g;
	int A[MAXV][MAXV]={{0,13,INF,4,INF},{13,0,15,INF,5},{INF,INF,0,12,INF},
		{4,INF,12,0,INF},{INF,INF,6,3,0}};
	int n=5,e=10;
	CreateMat(g,A,n,e);
	printf("图G的邻接矩阵:\n");DispMat(g);

	printf("结果1:%d\n",MaxMinPath(g));
	printf("结果2:%d\n",MinPath(g));
	
	return 1;
}
