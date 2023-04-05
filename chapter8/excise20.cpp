#include "graph.cpp"  //图的基本运算算法

int visited[MAXV];
void findpath(AdjGraph *G,int u,int v,int path[],int d,int length)
{	//d表示path中顶点个数，初始为0；length表示路径长度，初始为0
	int w,i;
	ArcNode *p;
	path[d]=u; d++; 				//顶点u加入到路径中，d增1
	visited[u]=1;					//置已访问标记
	if (u==v && d>0)				//找到一条路径则输出
	{
		printf("  路径长度:%d, 路径:",length);
		for (i=0;i<d;i++)
			printf("%2d",path[i]);
		printf("\n");
	}
	p=G->adjlist[u].firstarc;		//p指向顶点u的第一个邻接点
	while (p!=NULL)
	{
		w=p->adjvex;				//w为顶点u的邻接点
		if (visited[w]==0)			//若w顶点未访问,递归访问它
			findpath(G,w,v,path,d,p->weight+length);
		p=p->nextarc;				//p指向顶点u的下一个邻接点
	}
	visited[u]=0;					//恢复环境,使该顶点可重新使用
}

int main()
{
	AdjGraph *G;
	int A[MAXV][MAXV]={
		{0,4,6,6,INF,INF,INF},
		{INF,0,1,INF,7,INF,INF},
		{INF,INF,0,INF,6,4,INF},
		{INF,INF,2,0,INF,5,INF},
		{INF,INF,INF,INF,0,INF,6},
		{INF,INF,INF,INF,1,0,8},
		{INF,INF,INF,INF,INF,INF,0}};
	int n=7, e=12;
	CreateAdj(G,A,n,e);			//建立《教程》中图8.35的邻接表
	printf("图G的邻接表:\n");
	DispAdj(G);					//输出邻接表
	int u=0,v=5;
	int path[MAXV];
	printf("从%d->%d的所有路径:\n",u,v);
	findpath(G,u,v,path,0,0);

	DestroyAdj(G);

	return 1;
}