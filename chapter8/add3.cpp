#include "graph.cpp"		//ͼ�Ļ��������㷨

void AllInNeig(AdjGraph *G,int i)
{	int j;
	ArcNode *p;
	if (i<0 || i>G->n)
		return;
	for (j=0;j<G->n;j++)
	{	p=G->adjlist[j].firstarc;
		while (p!=NULL)
		{	if (p->adjvex==i)
			{	printf("%d ",j);
				break;
			}
			p=p->nextarc;
		}
	}
	printf("\n");
}

int main()
{ 
	int n=5, e=7;
	int A[MAXV][MAXV]={
		{0,1,1,0,0},{0,0,1,0,0},{0,0,0,1,1},
		{0,0,0,0,1},{1,0,0,0,0}};	

	AdjGraph *G;
	CreateAdj(G,A,n,e);			////����ͼ8.19���ڽӱ�
	printf("ͼG:\n");DispAdj(G);//����ڽӱ�

	int i=2;
	printf("����%d������ڽӵ�:",i); AllInNeig(G,i);	

	DestroyAdj(G);				//�����ڽӱ�
	return 1;
}