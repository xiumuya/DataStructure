#include "graph.cpp"  //ͼ�Ļ��������㷨

int visited[MAXV];
void findpath(AdjGraph *G,int u,int v,int path[],int d,int length)
{	//d��ʾpath�ж����������ʼΪ0��length��ʾ·�����ȣ���ʼΪ0
	int w,i;
	ArcNode *p;
	path[d]=u; d++; 				//����u���뵽·���У�d��1
	visited[u]=1;					//���ѷ��ʱ��
	if (u==v && d>0)				//�ҵ�һ��·�������
	{
		printf("  ·������:%d, ·��:",length);
		for (i=0;i<d;i++)
			printf("%2d",path[i]);
		printf("\n");
	}
	p=G->adjlist[u].firstarc;		//pָ�򶥵�u�ĵ�һ���ڽӵ�
	while (p!=NULL)
	{
		w=p->adjvex;				//wΪ����u���ڽӵ�
		if (visited[w]==0)			//��w����δ����,�ݹ������
			findpath(G,w,v,path,d,p->weight+length);
		p=p->nextarc;				//pָ�򶥵�u����һ���ڽӵ�
	}
	visited[u]=0;					//�ָ�����,ʹ�ö��������ʹ��
}

int main()
{
	AdjGraph *G;
	int A[MAXV][MAXV]={
		{0,4,6,6,INF,INF,INF},
		{INF,0,1,INF,7,INF,INF},
		{INF,INF,0,INF,6,4,INF},
		{INF,INF,2,0,INF,5,INF},
		{INF,INF,INF,INF,0,INF,6},
		{INF,INF,INF,INF,1,0,8},
		{INF,INF,INF,INF,INF,INF,0}};
	int n=7, e=12;
	CreateAdj(G,A,n,e);			//�������̡̳���ͼ8.35���ڽӱ�
	printf("ͼG���ڽӱ�:\n");
	DispAdj(G);					//����ڽӱ�
	int u=0,v=5;
	int path[MAXV];
	printf("��%d->%d������·��:\n",u,v);
	findpath(G,u,v,path,0,0);

	DestroyAdj(G);

	return 1;
}