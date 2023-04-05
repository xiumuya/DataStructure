#include "graph.cpp"				//图的基本运算算法

int visited[MAXV];					//全局变量数组
void Cycle(AdjGraph *G,int u,int v,int d,bool &has)
{	//调用时has置初值false,d为-1
	ArcNode *p;	int w;
	visited[u]=1; d++;				//置已访问标记
	p=G->adjlist[u].firstarc;		//p指向顶点u的第一个邻接点
	while (p!=NULL)
	{	w=p->adjvex;
		if (visited[w]==0)			//若顶点w未访问,递归访问它
			Cycle(G,w,v,d,has);		//从顶点w出发搜索
		else if (w==v && d>1)		//u到v存在一条边且回路长度大于1
		{
			has=true;
			return;
		}
		p=p->nextarc;				//找下一个邻接点
	}
}

bool hasCycle(AdjGraph *G,int v)   //判断连通图G中是否有经过顶点v的回路
{
	bool has=false;
	Cycle(G,v,v,-1,has);			//从顶点v出发搜索	
	return has;
}

int main()
{
	AdjGraph *G;
	int A[MAXV][MAXV]={
		{0,1,1,1},
		{1,0,0,1},
		{1,0,0,0},
		{1,1,0,0}};
	int n=4, e=4;
	CreateAdj(G,A,n,e);
	printf("图G的邻接表:\n");
	DispAdj(G);					//输出邻接表
	for (int i=0;i<n;i++)
		visited[i]=0;
	if (hasCycle(G,3))
		printf("G中存在回路\n");
	else
		printf("G中没有回路\n");

	DestroyAdj(G);

	return 1;
}