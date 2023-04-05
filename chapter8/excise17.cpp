#include "graph.cpp"

int visited[MAXV];					//全局数组
void DFS2(AdjGraph *G,int v,int &vn,int &en)
{	//深度优先遍历图G,并求出遍历过的顶点数vn和边数en
	ArcNode *p;
	visited[v]=1;vn++;			//遍历过的顶点数增1
	p=G->adjlist[v].firstarc;
	while (p!=NULL) 
	{	en++;					//遍历过的边数增1
		if (visited[p->adjvex]==0)
			DFS2(G,p->adjvex,vn,en);
		p=p->nextarc;
	}
}
int IsTree(AdjGraph *G)			//判断无向图G是否是一棵树
{	int vn=0,en=0,i;
	for (i=0;i<G->n;i++)
		visited[i]=0;
	DFS2(G,1,vn,en);
	if (vn==G->n && en==2*(G->n-1))
		return 1;				//遍历顶点为G->n个,遍历边数为2(G->n-1),则为树
	else
		return 0;
}


int main()
{
	AdjGraph *G;
	int A[MAXV][MAXV]={{0,1,0,1,1},{1,0,1,1,0},
			{0,1,0,1,1},{1,1,1,0,1},{1,0,1,1,0}};
	int n=5, e=8;
	CreateAdj(G,A,n,e);			//建立《教程》中图8.1(a)的邻接表
	printf("图G的邻接表:\n");
	DispAdj(G);					//输出邻接表G

	printf("结果:%d\n",IsTree(G));
	
	DestroyAdj(G);				//销毁邻接表
	return 1;
}
