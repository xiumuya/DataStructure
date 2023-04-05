#include "graph.cpp"		//图的基本运算算法

void AddEdge(AdjGraph *&G,int i,int j,int w)
{
	ArcNode *p;
	p=(ArcNode *)malloc(sizeof(ArcNode));
	p->adjvex=j;
	p->weight=w;
	p->nextarc=G->adjlist[i].firstarc;
	G->adjlist[i].firstarc=p;
	G->e++;
}

int main()
{ 
	int n=5, e=7;
	int A[MAXV][MAXV]={
		{0,1,1,0,0},{0,0,1,0,0},{0,0,0,1,1},
		{0,0,0,0,1},{1,0,0,0,0}};	

	AdjGraph *G;
	CreateAdj(G,A,n,e);			////建立图8.19的邻接表
	printf("图G:\n");DispAdj(G);//输出邻接表

	int i=1,j=4,w=1;
	printf("增加边<%d,%d>:%d\n",i,j,w);
	AddEdge(G,i,j,w);
	printf("图G:\n");DispAdj(G);//输出邻接表

	DestroyAdj(G);				//销毁邻接表
	return 1;
}