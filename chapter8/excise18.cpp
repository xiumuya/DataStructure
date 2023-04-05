#include "graph.cpp"

int vedge[MAXV][MAXV];		//边访问数组,vedge[i][j]表示(i,j)边是否访问过
void Traversal(AdjGraph *G,int u,int v,int k,int path[],int d)
//d是到当前为止已走过的路径长度，调用时初值为-1
{	int w,i;
	ArcNode *p;
	d++; path[d]=v;					//(u,v)加入到path中
	
	vedge[u][v]=vedge[v][u]=1;		//(u,v)边已访问
	p=G->adjlist[v].firstarc;		//p指向顶点v的第一条边
	while (p!=NULL)
	{	w=p->adjvex;				//(v,w)有一条边
		if (w==k && d==G->e-1)		//找到一个回路，输出之
		{	printf("  %d->",k);
			for (i=0;i<=d;i++)
				printf("%d->",path[i]);
			printf("%d\n",w);
		}
		if (vedge[v][w]==0)			//(v,w)未访问过,则递归访问之
			Traversal(G,v,w,k,path,d);
		p=p->nextarc;				//找v的下一条边
	}
	vedge[u][v]=vedge[v][u]=0;		//恢复环境：使该边点可重新使用
}
void FindCPath(AdjGraph *G,int k)	//输出经过顶点k和所有边的全部回路
{	int path[MAXV];
	int i,j,v;
	ArcNode *p;
	for (i=0;i<G->n;i++)			//vedge数组置初值
		for (j=0;j<G->n;j++)
			if (i==j) vedge[i][j]=1;
			else vedge[i][j]=0;
	printf("经过顶点%d的走过所有边的回路:\n",k);
	p=G->adjlist[k].firstarc; 
	while (p!=NULL)
	{	v=p->adjvex;
		Traversal(G,k,v,k,path,-1);
		p=p->nextarc;
	}
}
int main()
{	int i,j,v=4;
	AdjGraph *G;
	int n=5,e=6;
	int A[MAXV][MAXV]={{0,1,0,0,1},	{1,0,0,0,1},
						{0,0,0,1,1},{0,0,1,0,1},{1,1,1,1,0}};
	CreateAdj(G,A,n,e);
	printf("图G的邻接表:\n");DispAdj(G);	//输出邻接表
	FindCPath(G,v);
	printf("\n");
	DestroyAdj(G);
	return 1;
}
