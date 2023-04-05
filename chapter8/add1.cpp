#include "graph.cpp"		//ͼ�Ļ��������㷨

void AddEdge(AdjGraph *&G,int i,int j,int w)
{
	ArcNode *p;
	p=(ArcNode *)malloc(sizeof(ArcNode));
	p->adjvex=j;
	p->weight=w;
	p->nextarc=G->adjlist[i].firstarc;
	G->adjlist[i].firstarc=p;
	G->e++;
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

	int i=1,j=4,w=1;
	printf("���ӱ�<%d,%d>:%d\n",i,j,w);
	AddEdge(G,i,j,w);
	printf("ͼG:\n");DispAdj(G);//����ڽӱ�

	DestroyAdj(G);				//�����ڽӱ�
	return 1;
}