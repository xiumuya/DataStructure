#include "graph.cpp"

int visited[MAXV];				//ȫ�ֱ���
void MDFS(MatGraph g,int v)		//�����ڽӾ����������ȱ����㷨
{	int w;
	visited[v]=1;				//�÷��ʱ��
	for (w=0;w<g.n;w++)			//�Ҷ���v�������ڽӵ�
		if (g.edges[v][w]!=0 && g.edges[v][w]!=INF && visited[w]==0)
			MDFS(g,w);			//�Ҷ���v��δ���ʹ����ڽӵ�w
}
int DGRoot(MatGraph g)			//����������ȱ�����ͼ�ĸ�
{
	int i,j,k,n;
	for (i=0;i<g.n;i++)
	{	for (j=0;j<g.n;j++)
			visited[j]=0;
		MDFS(g,i);
		n=0;					//�ۼƴӶ���i�������ʵ��Ķ������
		for (k=0;k<g.n;k++)
			if (visited[k]==1) n++;
		if (n==g.n) return(i);	//���������ж���,�򶥵�iΪ��
	}
	return(-1);					//ͼû�и�
}

int main()
{
	MatGraph g;
	int A[MAXV][MAXV]={{0,INF,1,INF,INF},{INF,0,INF,1,INF},
			{INF,INF,0,INF,INF},{INF,INF,INF,0,INF},{1,1,1,1,0}};
	int n=5, e=6;
	CreateMat(g,A,n,e);			//�������̡̳���ͼ8.1(a)���ڽӾ���
	printf("ͼG���ڽӾ���:\n");
	DispMat(g);					//����ڽӾ���g

	printf("��:%d\n",DGRoot(g));

	return 1;
}
