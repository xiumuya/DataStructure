#include "graph.cpp"		//ͼ�Ļ��������㷨

void InDs2(AdjGraph *G)				//���ͼG��ÿ����������
{	ArcNode *p;
	int A[MAXV],i;					//A��Ÿ���������
	for (i=0;i<G->n;i++)			//A��Ԫ���ó�ֵ0
		A[i]=0;
	for (i=0;i<G->n;i++)			//ɨ������ͷ�ڵ�
	{	p=G->adjlist[i].firstarc;
		while (p!=NULL)				//ɨ��߽ڵ�
		{	A[p->adjvex]++;			//��ʾi��p->adjvex������һ����
			p=p->nextarc;
		}
	}
	printf("���������:\n");		//�������������
	for (i=0;i<G->n;i++)
		printf("  ����%d:%d\n",i,A[i]);
}

void OutDs2(AdjGraph *G)		//���ͼG��ÿ������ĳ���
{	int i,n;
	ArcNode *p;
	printf("���������:\n");
	for (i=0;i<G->n;i++)			//ɨ������ͷ�ڵ�
	{	n=0;
		p=G->adjlist[i].firstarc;
		while (p!=NULL)				//ɨ��߽ڵ�
		{	n++;					//�ۼƳ��ߵ���
			p=p->nextarc;
		}
		printf("  ����%d:%d\n",i,n);
	}
}


void ZeroOutDs2(AdjGraph *G)		//���ͼG�г���Ϊ0�Ķ�����
{	int i,n;
	ArcNode *p;
	printf("����Ϊ0�Ķ���:");
	for (i=0;i<G->n;i++)			//ɨ������ͷ�ڵ�
	{	p=G->adjlist[i].firstarc;
		n=0;
		while (p!=NULL)				//ɨ��߽ڵ�
		{	n++;					//�ۼƳ��ߵ���
			p=p->nextarc;
		}
		if (n==0)					//���������Ϊ0�Ķ�����
			printf("%2d",i);
	}
	printf("\n");
}


int main()
{
	AdjGraph *G;
	int A[MAXV][MAXV]={
		{0,1,0,1,0},
		{0,0,1,1,0},
		{0,0,0,1,1},
		{0,0,0,0,0},
		{1,0,0,1,0}};
	int n=5, e=8;
	CreateAdj(G,A,n,e);			//�������̡̳���ͼ8.1(b)���ڽӱ�
	printf("ͼG���ڽӱ�:\n");
	DispAdj(G);					//����ڽӱ�

	InDs2(G);
	OutDs2(G);
	ZeroOutDs2(G);

	DestroyAdj(G);

	return 1;
}