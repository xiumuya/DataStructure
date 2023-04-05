#include "graph.cpp"

int visited[MAXV];				//ȫ�ֱ���
void MDFS(MatGraph g,int v)
{	int w;
	printf("%d  ",v);			//���ʶ���v
	visited[v]=1;				//�÷��ʱ��
	for (w=0;w<g.n;w++)			//�Ҷ���v�������ڽӵ�
		if (g.edges[v][w]!=0 && g.edges[v][w]!=INF && visited[w]==0)
			MDFS(g,w);			//�Ҷ���v��δ���ʹ����ڽӵ�w
}


int main()
{
	MatGraph g;
	int A[MAXV][MAXV]={{0,1,0,1,1},{1,0,1,1,0},
			{0,1,0,1,1},{1,1,1,0,1},{1,0,1,1,0}};
	int n=5, e=8;
	CreateMat(g,A,n,e);			//�������̡̳���ͼ8.1(a)���ڽӾ���
	printf("ͼG���ڽӾ���:\n");
	DispMat(g);					//����ڽӾ���g

	for (int i=0;i<g.n;i++) visited[i]=0;
	printf("DFS:"); MDFS(g,0); printf("\n");

	return 1;
}
