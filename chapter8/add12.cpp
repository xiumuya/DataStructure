#include "graph.cpp"

void Dispath(AdjGraph *G,int dist[],int path[],int S[],int v)
//����Ӷ���v�������������·��
{	int i,j,k;
	int apath[MAXV],d;					//���һ�����·��(����)���䶥�����
	for (i=0;i<G->n;i++)				//ѭ������Ӷ���v��i��·��
		if (S[i]==1 && i!=v)
		{	printf("  �Ӷ���%d������%d��·������Ϊ:%d\t·��Ϊ:",v,i,dist[i]);
			d=0; apath[d]=i;			//���·���ϵ��յ�
			k=path[i];
			if (k==-1)					//û��·�������
				printf("��·��\n");
			else						//����·��ʱ�����·��
			{	while (k!=v)
				{	d++; apath[d]=k;
					k=path[k];
				}
				d++; apath[d]=v;		//���·���ϵ����
				printf("%d",apath[d]);	//��������
				for (j=d-1;j>=0;j--)	//�������������
					printf(",%d",apath[j]);
				printf("\n");
			}
		}
}
void MDijkstra(AdjGraph *G,int v)
{
	ArcNode *p;
	int dist[MAXV],path[MAXV];
	int S[MAXV];				//S[i]=1��ʾ����i��S��, S[i]=0��ʾ����i��U��
	int Mindis,i,j,u;
	for (i=0;i<G->n;i++)		//�����ʼ��Ϊ�ޣ�S��Ϊ��		
	{
		dist[i]=INF;
		S[i]=0;
		path[i]=-1;
	}
	S[v]=1;						//��Դ��v����S
	p=G->adjlist[v].firstarc;
	while (p!=NULL)				//����dist[p->adjvex]Ϊ<v,p->adjvex>��Ȩֵ
	{
		dist[p->adjvex]=p->weight;
		path[p->adjvex]=v;
		p=p->nextarc;
	}
	for (i=0;i<G->n-1;i++)		//ѭ��ֱ�����ж�������·�������
	{
		Mindis=INF;				//Mindis����󳤶ȳ�ֵ
		for (j=0;j<G->n;j++)	//ѡȡ����S�У���U�У��Ҿ�����С���·�����ȵĶ���u
			if (S[j]==0 && dist[j]<Mindis) 
			{	u=j;
				Mindis=dist[j];
			}
		S[u]=1;					//����u����S��
		p=G->adjlist[u].firstarc;
		while (p!=NULL)
		{
			j=p->adjvex;		//����u�ĳ����ڽӵ�Ϊj
			if (S[j]==0 && dist[u]+p->weight<dist[j]) //�޸Ĳ���S�еĶ�������·��
			{
				dist[j]=dist[u]+p->weight;
				path[j]=u;
			}
			p=p->nextarc;
		}
	}
	Dispath(G,dist,path,S,v);	//������·��
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

	int v=0;
	printf("��%d������������·������:\n",v);
	MDijkstra(G,v);

	DestroyAdj(G);
	return 1;
}