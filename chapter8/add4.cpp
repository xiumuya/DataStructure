#include "graph.cpp"		//ͼ�Ļ��������㷨

int visited[MAXV];			//ȫ�ֱ�������
void DFS(AdjGraph *G,int v)  
{
	ArcNode *p;
	visited[v]=1;                   //���ѷ��ʱ��
	printf("%d  ",v); 				//��������ʶ���ı��
	p=G->adjlist[v].firstarc;      	//pָ�򶥵�v�ĵ�һ�����Ļ�ͷ���
	while (p!=NULL) 
	{
		if (visited[p->adjvex]==0)	//��p->adjvex����δ����,�ݹ������
			DFS(G,p->adjvex);    
		p=p->nextarc;              	//pָ�򶥵�v����һ�����Ļ�ͷ���
	}
}
int DFSTrave(AdjGraph *G)
{
	int k,num=0;			//num��¼��ͨ�����ĸ���
	for (k=0;k<G->n;k++)
		visited[k]=0;
	for (k=0;k<G->n;k++)
		if (visited[k]==0)
		{	num++;
			printf("��%d����ͨ�������㼯:",num);
			DFS(G,k);		//DFS�ǡ��̡̳���������ȱ����㷨
			printf("\n");
		}
	return num;
}


int main()
{
	AdjGraph *G;
	int A[MAXV][MAXV]={{0,1,0,1,1},{1,0,1,1,0},
			{0,1,0,1,1},{1,1,1,0,1},{1,0,1,1,0}};
	int n=5, e=8;
	CreateAdj(G,A,n,e);			//�������̡̳���ͼ8.1(a)���ڽӱ�
	printf("ͼG���ڽӱ�:\n");
	DispAdj(G);					//����ڽӱ�G

	printf("��ͨ��������:%d\n",DFSTrave(G));

	DestroyAdj(G);				//�����ڽӱ�
	return 1;
}