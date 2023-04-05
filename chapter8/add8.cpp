#include "graph.cpp"

void MBFS(MatGraph g,int v)
{
	int Qu[MAXV],front=0,rear=0;			//定义循环队列并初始化
	int visited[MAXV];						//定义存放节点的访问标志的数组
	int w,i;
	for (i=0;i<g.n;i++) visited[i]=0;		//访问标志数组初始化
	printf("%3d",v);						//输出被访问顶点的编号
	visited[v]=1;							//置已访问标记
	rear=(rear+1)%MAXV;
	Qu[rear]=v;								//v进队
	while (front!=rear)						//若队列不空时循环
	{	front=(front+1)%MAXV;
		w=Qu[front];						//出队并赋给w
		for (i=0;i<g.n;i++)					//找与顶点w相邻的顶点
			if (g.edges[w][i]!=0 && g.edges[w][i]!=INF && visited[i]==0)
			{	//若当前邻接顶点i未被访问
				printf("%3d",i);			//访问相邻顶点i
				visited[i]=1;				//置该顶点已被访问的标志
				rear=(rear+1)%MAXV;			//该顶点进队
				Qu[rear]=i;
			}
	}
	printf("\n");
}


int main()
{
	MatGraph g;
	int A[MAXV][MAXV]={{0,1,0,1,1},{1,0,1,1,0},
			{0,1,0,1,1},{1,1,1,0,1},{1,0,1,1,0}};
	int n=5, e=8;
	CreateMat(g,A,n,e);			//建立《教程》中图8.1(a)的邻接矩阵
	printf("图G的邻接矩阵:\n");
	DispMat(g);					//输出邻接矩阵g

	printf("BFS:"); MBFS(g,0); printf("\n");

	return 1;
}
