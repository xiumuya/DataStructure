#include "graph.cpp"

void Dispath(AdjGraph *G,int dist[],int path[],int S[],int v)
//输出从顶点v出发的所有最短路径
{	int i,j,k;
	int apath[MAXV],d;					//存放一条最短路径(逆向)及其顶点个数
	for (i=0;i<G->n;i++)				//循环输出从顶点v到i的路径
		if (S[i]==1 && i!=v)
		{	printf("  从顶点%d到顶点%d的路径长度为:%d\t路径为:",v,i,dist[i]);
			d=0; apath[d]=i;			//添加路径上的终点
			k=path[i];
			if (k==-1)					//没有路径的情况
				printf("无路径\n");
			else						//存在路径时输出该路径
			{	while (k!=v)
				{	d++; apath[d]=k;
					k=path[k];
				}
				d++; apath[d]=v;		//添加路径上的起点
				printf("%d",apath[d]);	//先输出起点
				for (j=d-1;j>=0;j--)	//再输出其他顶点
					printf(",%d",apath[j]);
				printf("\n");
			}
		}
}
void MDijkstra(AdjGraph *G,int v)
{
	ArcNode *p;
	int dist[MAXV],path[MAXV];
	int S[MAXV];				//S[i]=1表示顶点i在S中, S[i]=0表示顶点i在U中
	int Mindis,i,j,u;
	for (i=0;i<G->n;i++)		//距离初始化为∞，S置为空		
	{
		dist[i]=INF;
		S[i]=0;
		path[i]=-1;
	}
	S[v]=1;						//将源点v放入S
	p=G->adjlist[v].firstarc;
	while (p!=NULL)				//设置dist[p->adjvex]为<v,p->adjvex>的权值
	{
		dist[p->adjvex]=p->weight;
		path[p->adjvex]=v;
		p=p->nextarc;
	}
	for (i=0;i<G->n-1;i++)		//循环直到所有顶点的最短路径都求出
	{
		Mindis=INF;				//Mindis置最大长度初值
		for (j=0;j<G->n;j++)	//选取不在S中（即U中）且具有最小最短路径长度的顶点u
			if (S[j]==0 && dist[j]<Mindis) 
			{	u=j;
				Mindis=dist[j];
			}
		S[u]=1;					//顶点u加入S中
		p=G->adjlist[u].firstarc;
		while (p!=NULL)
		{
			j=p->adjvex;		//顶点u的出边邻接点为j
			if (S[j]==0 && dist[u]+p->weight<dist[j]) //修改不在S中的顶点的最短路径
			{
				dist[j]=dist[u]+p->weight;
				path[j]=u;
			}
			p=p->nextarc;
		}
	}
	Dispath(G,dist,path,S,v);	//输出最短路径
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

	int v=0;
	printf("从%d顶点出发的最短路径如下:\n",v);
	MDijkstra(G,v);

	DestroyAdj(G);
	return 1;
}