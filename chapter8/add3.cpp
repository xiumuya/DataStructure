#include "graph.cpp"		//图的基本运算算法

void AllInNeig(AdjGraph *G,int i)
{	int j;
	ArcNode *p;
	if (i<0 || i>G->n)
		return;
	for (j=0;j<G->n;j++)
	{	p=G->adjlist[j].firstarc;
		while (p!=NULL)
		{	if (p->adjvex==i)
			{	printf("%d ",j);
				break;
			}
			p=p->nextarc;
		}
	}
	printf("\n");
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

	int i=2;
	printf("顶点%d的入边邻接点:",i); AllInNeig(G,i);	

	DestroyAdj(G);				//销毁邻接表
	return 1;
}