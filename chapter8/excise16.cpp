#include "graph.cpp"				//ͼ�Ļ��������㷨

int visited[MAXV];					//ȫ�ֱ�������
void Cycle(AdjGraph *G,int u,int v,int d,bool &has)
{	//����ʱhas�ó�ֵfalse,dΪ-1
	ArcNode *p;	int w;
	visited[u]=1; d++;				//���ѷ��ʱ��
	p=G->adjlist[u].firstarc;		//pָ�򶥵�u�ĵ�һ���ڽӵ�
	while (p!=NULL)
	{	w=p->adjvex;
		if (visited[w]==0)			//������wδ����,�ݹ������
			Cycle(G,w,v,d,has);		//�Ӷ���w��������
		else if (w==v && d>1)		//u��v����һ�����һ�·���ȴ���1
		{
			has=true;
			return;
		}
		p=p->nextarc;				//����һ���ڽӵ�
	}
}

bool hasCycle(AdjGraph *G,int v)   //�ж���ͨͼG���Ƿ��о�������v�Ļ�·
{
	bool has=false;
	Cycle(G,v,v,-1,has);			//�Ӷ���v��������	
	return has;
}

int main()
{
	AdjGraph *G;
	int A[MAXV][MAXV]={
		{0,1,1,1},
		{1,0,0,1},
		{1,0,0,0},
		{1,1,0,0}};
	int n=4, e=4;
	CreateAdj(G,A,n,e);
	printf("ͼG���ڽӱ�:\n");
	DispAdj(G);					//����ڽӱ�
	for (int i=0;i<n;i++)
		visited[i]=0;
	if (hasCycle(G,3))
		printf("G�д��ڻ�·\n");
	else
		printf("G��û�л�·\n");

	DestroyAdj(G);

	return 1;
}