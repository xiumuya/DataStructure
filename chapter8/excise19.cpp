#include "graph.cpp"
typedef struct
{	int v;									//������
	int level;								//����Ĳ��
} QType;									//���ζ���Ԫ������
int visited[MAXV];
void ShortPath(AdjGraph *G,int i)
{	QType qu[MAXV];							//���廷�ζ���qu 
	int front=0,rear=0,u,w,lev;				//lev�����i�����ʶ���Ĳ���
	ArcNode *p;
	visited[i]=1;
	rear++;qu[rear].v=i;qu[rear].level=0;	//����i�ѷ���,�������
	while (front!=rear)						//�ӷǿ���ִ��
	{	front=(front+1)% MAXV;				//����
		u=qu[front].v;
		lev=qu[front].level;
		if (u!=i) 
			printf("  ����%d������%d����̾�����:%d\n",i,u,lev);
		p=G->adjlist[u].firstarc;			//ȡk�ı߱�ͷָ��
		while (p!=NULL)						//���������ڽӵ�
		{	w=p->adjvex;					//�ҵ�����u���ڽӵ�w 
			if (visited[w]==0)				//������wδ���ʹ�
			{	visited[w]=1;				//���ʶ���w 
				rear=(rear+1)% MAXV;
				qu[rear].v=w;				//���ʹ����ڽӵ����
				qu[rear].level=lev+1;
			}
			p=p->nextarc;					//�Ҷ���u����һ���ڽӵ�
		}
	}
}

int main()
{	AdjGraph *G;
	int n=5,e=8;
	int A[MAXV][MAXV]={{0,1,0,1,1},{1,0,1,1,0},
		{0,1,0,1,1},{1,1,1,0,1},{1,0,1,1,0}};
	CreateAdj(G,A,n,e);
	printf("ͼG���ڽӱ�:\n");DispAdj(G);	//����ڽӱ�
	for (int i=0;i<n;i++)
		visited[i]=0;
	printf("����1���������������̾�������:\n");
	ShortPath(G,1);
	return 1;
}
