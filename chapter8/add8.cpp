#include "graph.cpp"

void MBFS(MatGraph g,int v)
{
	int Qu[MAXV],front=0,rear=0;			//����ѭ�����в���ʼ��
	int visited[MAXV];						//�����Žڵ�ķ��ʱ�־������
	int w,i;
	for (i=0;i<g.n;i++) visited[i]=0;		//���ʱ�־�����ʼ��
	printf("%3d",v);						//��������ʶ���ı��
	visited[v]=1;							//���ѷ��ʱ��
	rear=(rear+1)%MAXV;
	Qu[rear]=v;								//v����
	while (front!=rear)						//�����в���ʱѭ��
	{	front=(front+1)%MAXV;
		w=Qu[front];						//���Ӳ�����w
		for (i=0;i<g.n;i++)					//���붥��w���ڵĶ���
			if (g.edges[w][i]!=0 && g.edges[w][i]!=INF && visited[i]==0)
			{	//����ǰ�ڽӶ���iδ������
				printf("%3d",i);			//�������ڶ���i
				visited[i]=1;				//�øö����ѱ����ʵı�־
				rear=(rear+1)%MAXV;			//�ö������
				Qu[rear]=i;
			}
	}
	printf("\n");
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

	printf("BFS:"); MBFS(g,0); printf("\n");

	return 1;
}
