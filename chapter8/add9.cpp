#include "graph.cpp"

int visited[MAXV];				//全局变量
void MDFS(MatGraph g,int v)		//基于邻接矩阵的深度优先遍历算法
{	int w;
	visited[v]=1;				//置访问标记
	for (w=0;w<g.n;w++)			//找顶点v的所有邻接点
		if (g.edges[v][w]!=0 && g.edges[v][w]!=INF && visited[w]==0)
			MDFS(g,w);			//找顶点v的未访问过的邻接点w
}
int DGRoot(MatGraph g)			//基于深度优先遍历求图的根
{
	int i,j,k,n;
	for (i=0;i<g.n;i++)
	{	for (j=0;j<g.n;j++)
			visited[j]=0;
		MDFS(g,i);
		n=0;					//累计从顶点i出发访问到的顶点个数
		for (k=0;k<g.n;k++)
			if (visited[k]==1) n++;
		if (n==g.n) return(i);	//若访问所有顶点,则顶点i为根
	}
	return(-1);					//图没有根
}

int main()
{
	MatGraph g;
	int A[MAXV][MAXV]={{0,INF,1,INF,INF},{INF,0,INF,1,INF},
			{INF,INF,0,INF,INF},{INF,INF,INF,0,INF},{1,1,1,1,0}};
	int n=5, e=6;
	CreateMat(g,A,n,e);			//建立《教程》中图8.1(a)的邻接矩阵
	printf("图G的邻接矩阵:\n");
	DispMat(g);					//输出邻接矩阵g

	printf("根:%d\n",DGRoot(g));

	return 1;
}
