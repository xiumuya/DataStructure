#include "graph.cpp"

int visited[MAXV];				//全局变量
void MDFS(MatGraph g,int v)
{	int w;
	printf("%d  ",v);			//访问顶点v
	visited[v]=1;				//置访问标记
	for (w=0;w<g.n;w++)			//找顶点v的所有邻接点
		if (g.edges[v][w]!=0 && g.edges[v][w]!=INF && visited[w]==0)
			MDFS(g,w);			//找顶点v的未访问过的邻接点w
}


int main()
{
	MatGraph g;
	int A[MAXV][MAXV]={{0,1,0,1,1},{1,0,1,1,0},
			{0,1,0,1,1},{1,1,1,0,1},{1,0,1,1,0}};
	int n=5, e=8;
	CreateMat(g,A,n,e);			//建立《教程》中图8.1(a)的邻接矩阵
	printf("图G的邻接矩阵:\n");
	DispMat(g);					//输出邻接矩阵g

	for (int i=0;i<g.n;i++) visited[i]=0;
	printf("DFS:"); MDFS(g,0); printf("\n");

	return 1;
}
