#include "graph.cpp"		//ͼ�Ļ��������㷨

void InDs1(MatGraph g)		//���ͼG��ÿ����������
{	int i,j,n;
	printf("���������:\n");
	for (j=0;j<g.n;j++)
	{	n=0;
		for (i=0;i<g.n;i++)
			if (g.edges[i][j]!=0)
				n++;		//n�ۼ������
		printf("  ����%d:%d\n",j,n);
	}
}
void OutDs1(MatGraph g)		//���ͼG��ÿ������ĳ���
{	int i,j,n;
	printf("���������:\n");
	for (i=0;i<g.n;i++)
	{	n=0;
		for (j=0;j<g.n;j++)
			if (g.edges[i][j]!=0)
				n++;			//n�ۼƳ�����
		printf("  ����%d:%d\n",i,n);
	}
}

void ZeroOutDs1(MatGraph g)		//���ͼG�г���Ϊ0�Ķ������
{	int i,j,n;
	printf("����Ϊ0�Ķ���:");
	for (i=0;i<g.n;i++)
	{	n=0;
		for (j=0;j<g.n;j++)
			if (g.edges[i][j]!=0)	//����һ����
				n++;
		if (n==0)
			printf("%2d\n",i);
	}
	printf("\n");
}


int main()
{
	MatGraph g;
	int A[MAXV][MAXV]={
		{0,1,0,1,0},
		{0,0,1,1,0},
		{0,0,0,1,1},
		{0,0,0,0,0},
		{1,0,0,1,0}};
	int n=5, e=8;
	CreateMat(g,A,n,e);			//�������̡̳���ͼ8.1(b)���ڽӾ���
	printf("ͼG���ڽӾ���:\n");
	DispMat(g);					//����ڽӾ���

	InDs1(g);
	OutDs1(g);
	ZeroOutDs1(g);

	return 1;
}