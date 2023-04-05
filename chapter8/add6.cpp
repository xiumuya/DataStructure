#include "graph.cpp"		//ͼ�Ļ��������㷨

void ReAdj(AdjGraph *G1,AdjGraph *&G2)
{
	int i,j;
	ArcNode *p,*q;
	G2=(AdjGraph *)malloc(sizeof(AdjGraph));
	G2->n=G1->n; G2->e=G1->e;
	for (i=0;i<G2->n;i++)
		G2->adjlist[i].firstarc=NULL;
	for (i=0;i<G1->n;i++)
	{	p=G1->adjlist[i].firstarc;
		while (p!=NULL)
		{	j=p->adjvex;
			q=(ArcNode *)malloc(sizeof(ArcNode));
			q->adjvex=i;
			q->weight=p->weight;
			q->nextarc=G2->adjlist[j].firstarc;
			G2->adjlist[j].firstarc=q;
			p=p->nextarc;
		}
	}
}


int main()
{
	AdjGraph *G1,*G2;
	int n=5, e=7;
	int A[MAXV][MAXV]={
		{0,1,1,0,0},{0,0,1,0,0},{0,0,0,1,1},
		{0,0,0,0,1},{1,0,0,0,0}};	
	CreateAdj(G1,A,n,e);			////�������̡̳���ͼ8.19���ڽӱ�
	printf("�ڽӱ�G1:\n");
	DispAdj(G1);					//����ڽӱ�G1
	printf("��G1�������ڽӱ�G2\n");
	ReAdj(G1,G2);
	printf("�ڽӱ�G2:\n");
	DispAdj(G2);					//����ڽӱ�G2

	DestroyAdj(G1);					//�����ڽӱ�G1
	DestroyAdj(G2);					//�����ڽӱ�G2
	return 1;
}