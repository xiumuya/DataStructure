#include "graph.cpp"		//图的基本运算算法

int visited[MAXV];			//全局变量数组
void DFS(AdjGraph *G,int v)  
{
	ArcNode *p;
	visited[v]=1;                   //置已访问标记
	printf("%d  ",v); 				//输出被访问顶点的编号
	p=G->adjlist[v].firstarc;      	//p指向顶点v的第一条弧的弧头结点
	while (p!=NULL) 
	{
		if (visited[p->adjvex]==0)	//若p->adjvex顶点未访问,递归访问它
			DFS(G,p->adjvex);    
		p=p->nextarc;              	//p指向顶点v的下一条弧的弧头结点
	}
}
int DFSTrave(AdjGraph *G)
{
	int k,num=0;			//num记录连通分量的个数
	for (k=0;k<G->n;k++)
		visited[k]=0;
	for (k=0;k<G->n;k++)
		if (visited[k]==0)
		{	num++;
			printf("第%d个连通分量顶点集:",num);
			DFS(G,k);		//DFS是《教程》中深度优先遍历算法
			printf("\n");
		}
	return num;
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

	printf("连通分量个数:%d\n",DFSTrave(G));

	DestroyAdj(G);				//销毁邻接表
	return 1;
}