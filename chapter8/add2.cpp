#include "graph.cpp"		//ͼ�Ļ��������㷨

void DelEdge(AdjGraph *&G,int i,int j)
{	ArcNode *pre,*p;
	pre=G->adjlist[i].firstarc;
	if (pre==NULL) return;
	if (pre->adjvex==j)
	{	G->adjlist[i].firstarc=pre->nextarc;
		free(pre);
		G->e--;
	}
	else
	{	p=pre->nextarc;
		while (p!=NULL && p->adjvex!=j)
		{	pre=p;
			p=p->nextarc;
		}
		pre->nextarc=p->nextarc;
		free(p);
		G->e--;
	}
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

	int i=0,j=2;
	printf("ɾ����<%d,%d>\n",i,j);
	DelEdge(G,i,j);
	printf("ͼG:\n");DispAdj(G);//����ڽӱ�

	DestroyAdj(G);				//�����ڽӱ�
	return 1;
}