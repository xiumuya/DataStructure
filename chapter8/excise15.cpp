#include "graph.cpp"		//图的基本运算算法

void InDs2(AdjGraph *G)				//求出图G中每个顶点的入度
{	ArcNode *p;
	int A[MAXV],i;					//A存放各顶点的入度
	for (i=0;i<G->n;i++)			//A中元素置初值0
		A[i]=0;
	for (i=0;i<G->n;i++)			//扫描所有头节点
	{	p=G->adjlist[i].firstarc;
		while (p!=NULL)				//扫描边节点
		{	A[p->adjvex]++;			//表示i到p->adjvex顶点有一条边
			p=p->nextarc;
		}
	}
	printf("各顶点入度:\n");		//输出各顶点的入度
	for (i=0;i<G->n;i++)
		printf("  顶点%d:%d\n",i,A[i]);
}

void OutDs2(AdjGraph *G)		//求出图G中每个顶点的出度
{	int i,n;
	ArcNode *p;
	printf("各顶点出度:\n");
	for (i=0;i<G->n;i++)			//扫描所有头节点
	{	n=0;
		p=G->adjlist[i].firstarc;
		while (p!=NULL)				//扫描边节点
		{	n++;					//累计出边的数
			p=p->nextarc;
		}
		printf("  顶点%d:%d\n",i,n);
	}
}


void ZeroOutDs2(AdjGraph *G)		//求出图G中出度为0的顶点数
{	int i,n;
	ArcNode *p;
	printf("出度为0的顶点:");
	for (i=0;i<G->n;i++)			//扫描所有头节点
	{	p=G->adjlist[i].firstarc;
		n=0;
		while (p!=NULL)				//扫描边节点
		{	n++;					//累计出边的数
			p=p->nextarc;
		}
		if (n==0)					//输出出边数为0的顶点编号
			printf("%2d",i);
	}
	printf("\n");
}


int main()
{
	AdjGraph *G;
	int A[MAXV][MAXV]={
		{0,1,0,1,0},
		{0,0,1,1,0},
		{0,0,0,1,1},
		{0,0,0,0,0},
		{1,0,0,1,0}};
	int n=5, e=8;
	CreateAdj(G,A,n,e);			//建立《教程》中图8.1(b)的邻接表
	printf("图G的邻接表:\n");
	DispAdj(G);					//输出邻接表

	InDs2(G);
	OutDs2(G);
	ZeroOutDs2(G);

	DestroyAdj(G);

	return 1;
}