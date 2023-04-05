//Floyd�㷨
#include "graph.cpp"
void Disp(int A[MAXV][MAXV],int path[MAXV][MAXV],int n,int k)
{
	int i,j;
	printf("A[%d]\t\t\t\t\t\tpath[%d]\n",k,k);
	for (i=0;i<n;i++)
	{
		for (j=0;j<n;j++)
			if (A[i][j]!=INF)
				printf("%4d",A[i][j]);
			else
				printf("%4s","��");
		printf("\t\t");
		for (j=0;j<n;j++)
			printf("%4d",path[i][j]);
		printf("\n");
	}
}

void Dispath(MatGraph g,int A[][MAXV],int path[][MAXV])
{	int i,j,k,s;
	int apath[MAXV],d;		//���һ�����·���м䶥��(����)���䶥�����
	for (i=0;i<g.n;i++)
		for (j=0;j<g.n;j++)
		{	if (A[i][j]!=INF && i!=j)			//������i��j֮�����·��
			{	printf("  ��%d��%d��·��Ϊ:",i,j);
				k=path[i][j];
				d=0; apath[d]=j;				//·��������յ�
				while (k!=-1 && k!=i)			//·��������м��
				{	d++; apath[d]=k;
					k=path[i][k];
				}
				d++; apath[d]=i;				//·����������
				printf("%d",apath[d]);			//������
				for (s=d-1;s>=0;s--)			//���·���ϵ��м䶥��
					printf(",%d",apath[s]);
				printf("\t·������Ϊ:%d\n",A[i][j]);
			}
		}
}

void Floyd(MatGraph g)							//Floyd�㷨
{	int A[MAXV][MAXV],path[MAXV][MAXV];
	int i,j,k;
	for (i=0;i<g.n;i++)
		for (j=0;j<g.n;j++) 
		{	A[i][j]=g.edges[i][j];
			if (i!=j && g.edges[i][j]<INF)
				path[i][j]=i;					//����i��j�б�ʱ
			else
				path[i][j]=-1;					//����i��jû�б�ʱ
		}
	for (k=0;k<g.n;k++)							//���ο������ж���
	{
		printf("k=%d\n",k);
		for (i=0;i<g.n;i++)
			for (j=0;j<g.n;j++)
				if (A[i][j]>A[i][k]+A[k][j])
				{
					A[i][j]=A[i][k]+A[k][j];	//�޸����·������
					path[i][j]=path[k][j];		//�޸����·��
					printf("A[%d][%d]=%d,path[%d][%d]=%d\n",i,j,A[i][j],i,j,path[i][j]);
				}
		//Disp(A,path,g.n,k);

	}
	Dispath(g,A,path);							//������·��
}

int main()
{
	MatGraph g;
	int A[MAXV][MAXV]={
		{0,  7,  11, INF,INF, INF},
		{7,  0,  10, 9,  INF, INF},
		{11, 10, 0,  5,  7,   8},
		{INF,9,  5,  0,  INF, INF},
		{INF,INF,7,  INF,0,   6},
		{INF,INF,8,  INF,6,   0} };
	int n=6, e=8;
	CreateMat(g,A,n,e);			//����ͼ���ڽӾ���
	printf("ͼG���ڽӾ���:\n");
	DispMat(g);					//����ڽӾ���
	printf("������Ե����·��:\n");
	Floyd(g);
	return 1;
}