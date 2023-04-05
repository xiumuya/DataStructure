#include "graph.cpp"		//图的基本运算算法

void DelEdge(AdjGraph *&G,int i,int j)
{	ArcNode *pre,*p;
	pre=G->adjlist[i].firstarc;
	if (pre==NULL) return;
	if (pre->adjvex==j)
	{	G->adjlist[i].firstarc=pre->nextarc;
		free(pre);
		G->e--;
	}
	else
	{	p=pre->nextarc;
		while (p!=NULL && p->adjvex!=j)
		{	pre=p;
			p=p->nextarc;
		}
		pre->nextarc=p->nextarc;
		free(p);
		G->e--;
	}
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

	int i=0,j=2;
	printf("删除边<%d,%d>\n",i,j);
	DelEdge(G,i,j);
	printf("图G:\n");DispAdj(G);//输出邻接表

	DestroyAdj(G);				//销毁邻接表
	return 1;
}