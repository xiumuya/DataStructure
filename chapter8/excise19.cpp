#include "graph.cpp"
typedef struct
{	int v;									//顶点编号
	int level;								//顶点的层次
} QType;									//环形队列元素类型
int visited[MAXV];
void ShortPath(AdjGraph *G,int i)
{	QType qu[MAXV];							//定义环形队列qu 
	int front=0,rear=0,u,w,lev;				//lev保存从i到访问顶点的层数
	ArcNode *p;
	visited[i]=1;
	rear++;qu[rear].v=i;qu[rear].level=0;	//顶点i已访问,将其进队
	while (front!=rear)						//队非空则执行
	{	front=(front+1)% MAXV;				//出队
		u=qu[front].v;
		lev=qu[front].level;
		if (u!=i) 
			printf("  顶点%d到顶点%d的最短距离是:%d\n",i,u,lev);
		p=G->adjlist[u].firstarc;			//取k的边表头指针
		while (p!=NULL)						//依次搜索邻接点
		{	w=p->adjvex;					//找到顶点u的邻接点w 
			if (visited[w]==0)				//若顶点w未访问过
			{	visited[w]=1;				//访问顶点w 
				rear=(rear+1)% MAXV;
				qu[rear].v=w;				//访问过的邻接点进队
				qu[rear].level=lev+1;
			}
			p=p->nextarc;					//找顶点u的下一个邻接点
		}
	}
}

int main()
{	AdjGraph *G;
	int n=5,e=8;
	int A[MAXV][MAXV]={{0,1,0,1,1},{1,0,1,1,0},
		{0,1,0,1,1},{1,1,1,0,1},{1,0,1,1,0}};
	CreateAdj(G,A,n,e);
	printf("图G的邻接表:\n");DispAdj(G);	//输出邻接表
	for (int i=0;i<n;i++)
		visited[i]=0;
	printf("顶点1到其他各顶点的最短距离如下:\n");
	ShortPath(G,1);
	return 1;
}
