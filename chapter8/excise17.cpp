#include "graph.cpp"

int visited[MAXV];					//ȫ������
void DFS2(AdjGraph *G,int v,int &vn,int &en)
{	//������ȱ���ͼG,������������Ķ�����vn�ͱ���en
	ArcNode *p;
	visited[v]=1;vn++;			//�������Ķ�������1
	p=G->adjlist[v].firstarc;
	while (p!=NULL) 
	{	en++;					//�������ı�����1
		if (visited[p->adjvex]==0)
			DFS2(G,p->adjvex,vn,en);
		p=p->nextarc;
	}
}
int IsTree(AdjGraph *G)			//�ж�����ͼG�Ƿ���һ����
{	int vn=0,en=0,i;
	for (i=0;i<G->n;i++)
		visited[i]=0;
	DFS2(G,1,vn,en);
	if (vn==G->n && en==2*(G->n-1))
		return 1;				//��������ΪG->n��,��������Ϊ2(G->n-1),��Ϊ��
	else
		return 0;
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

	printf("���:%d\n",IsTree(G));
	
	DestroyAdj(G);				//�����ڽӱ�
	return 1;
}
