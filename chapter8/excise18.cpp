#include "graph.cpp"

int vedge[MAXV][MAXV];		//�߷�������,vedge[i][j]��ʾ(i,j)���Ƿ���ʹ�
void Traversal(AdjGraph *G,int u,int v,int k,int path[],int d)
//d�ǵ���ǰΪֹ���߹���·�����ȣ�����ʱ��ֵΪ-1
{	int w,i;
	ArcNode *p;
	d++; path[d]=v;					//(u,v)���뵽path��
	
	vedge[u][v]=vedge[v][u]=1;		//(u,v)���ѷ���
	p=G->adjlist[v].firstarc;		//pָ�򶥵�v�ĵ�һ����
	while (p!=NULL)
	{	w=p->adjvex;				//(v,w)��һ����
		if (w==k && d==G->e-1)		//�ҵ�һ����·�����֮
		{	printf("  %d->",k);
			for (i=0;i<=d;i++)
				printf("%d->",path[i]);
			printf("%d\n",w);
		}
		if (vedge[v][w]==0)			//(v,w)δ���ʹ�,��ݹ����֮
			Traversal(G,v,w,k,path,d);
		p=p->nextarc;				//��v����һ����
	}
	vedge[u][v]=vedge[v][u]=0;		//�ָ�������ʹ�ñߵ������ʹ��
}
void FindCPath(AdjGraph *G,int k)	//�����������k�����бߵ�ȫ����·
{	int path[MAXV];
	int i,j,v;
	ArcNode *p;
	for (i=0;i<G->n;i++)			//vedge�����ó�ֵ
		for (j=0;j<G->n;j++)
			if (i==j) vedge[i][j]=1;
			else vedge[i][j]=0;
	printf("��������%d���߹����бߵĻ�·:\n",k);
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
	printf("ͼG���ڽӱ�:\n");DispAdj(G);	//����ڽӱ�
	FindCPath(G,v);
	printf("\n");
	DestroyAdj(G);
	return 1;
}
