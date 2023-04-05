#include "graph.cpp"

void DFSTrav(MatGraph g,int parent,int child,int &len)
{	int clen,v=0,maxlen;
	clen=len;
	maxlen=len;
	while (v<g.n && g.edges[child][v]==0)	//找child的第一个邻接点v
		v++;
	while (v<g.n)							//存在邻接点时循环
	{	if (v!=parent)
		{	len=len+g.edges[child][v];
			DFSTrav(g,child,v,len);
			if (len>maxlen)					//比较找最大值
				maxlen=len;
		}
		v++;
		while (v<g.n && g.edges[child][v]==0)//找child的下一个邻接点
			v++;
		len=clen;
	}
	len=maxlen;
}
int Diameter(MatGraph g,int v)
{	int maxlen1=0;		//存放到目前找到根v到叶节点的最大值
	int maxlen2=0;		//存放到目前找到根v到叶节点的次大值
	int len=0;			//记录深度优先遍历中到某个叶节点的距离
	int w=0;			//存放v的邻接顶点
	while (w<g.n && g.edges[v][w]==0)	//找与v相邻的第一个顶点w
		w++;
	while (w<g.n)						//存在邻接点时循环
	{	len=g.edges[v][w];
		DFSTrav(g,v,w,len);
		if (len>maxlen1)
		{	maxlen2=maxlen1;
			maxlen1=len;
		}
		else if (len>maxlen2)
			maxlen2=len;
		w++;
		while (w<g.n && g.edges[v][w]==0)	//找v的下一个邻接点w
			w++;
	}
	return maxlen1+maxlen2;
}
int MaxDiameter(MatGraph g)		//求g的直径
{
	int i,diam,d;
	diam=Diameter(g,0);
	for (i=1;i<g.n;i++)			//找出从所有顶点出发直径的最大值
	{	d=Diameter(g,i);
		if (diam<d) diam=d;
	}
	return diam;
}

int main()
{
	MatGraph g;
	int A[MAXV][MAXV]={{0,2,0,0,0,0},{2,0,4,0,12,5},{0,4,0,2,0,0},
		{0,0,2,0,0,0},{0,12,0,0,0,0},{0,5,0,0,0,0}};
	int n=6,e=5;
	CreateMat(g,A,n,e);
	printf("图G的邻接矩阵:\n");DispMat(g);

	printf("T的直径=%d\n",MaxDiameter(g));

	return 1;
}
