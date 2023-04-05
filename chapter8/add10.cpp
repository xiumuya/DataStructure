#include "graph.cpp"

void DFSTrav(MatGraph g,int parent,int child,int &len)
{	int clen,v=0,maxlen;
	clen=len;
	maxlen=len;
	while (v<g.n && g.edges[child][v]==0)	//��child�ĵ�һ���ڽӵ�v
		v++;
	while (v<g.n)							//�����ڽӵ�ʱѭ��
	{	if (v!=parent)
		{	len=len+g.edges[child][v];
			DFSTrav(g,child,v,len);
			if (len>maxlen)					//�Ƚ������ֵ
				maxlen=len;
		}
		v++;
		while (v<g.n && g.edges[child][v]==0)//��child����һ���ڽӵ�
			v++;
		len=clen;
	}
	len=maxlen;
}
int Diameter(MatGraph g,int v)
{	int maxlen1=0;		//��ŵ�Ŀǰ�ҵ���v��Ҷ�ڵ�����ֵ
	int maxlen2=0;		//��ŵ�Ŀǰ�ҵ���v��Ҷ�ڵ�Ĵδ�ֵ
	int len=0;			//��¼������ȱ����е�ĳ��Ҷ�ڵ�ľ���
	int w=0;			//���v���ڽӶ���
	while (w<g.n && g.edges[v][w]==0)	//����v���ڵĵ�һ������w
		w++;
	while (w<g.n)						//�����ڽӵ�ʱѭ��
	{	len=g.edges[v][w];
		DFSTrav(g,v,w,len);
		if (len>maxlen1)
		{	maxlen2=maxlen1;
			maxlen1=len;
		}
		else if (len>maxlen2)
			maxlen2=len;
		w++;
		while (w<g.n && g.edges[v][w]==0)	//��v����һ���ڽӵ�w
			w++;
	}
	return maxlen1+maxlen2;
}
int MaxDiameter(MatGraph g)		//��g��ֱ��
{
	int i,diam,d;
	diam=Diameter(g,0);
	for (i=1;i<g.n;i++)			//�ҳ������ж������ֱ�������ֵ
	{	d=Diameter(g,i);
		if (diam<d) diam=d;
	}
	return diam;
}

int main()
{
	MatGraph g;
	int A[MAXV][MAXV]={{0,2,0,0,0,0},{2,0,4,0,12,5},{0,4,0,2,0,0},
		{0,0,2,0,0,0},{0,12,0,0,0,0},{0,5,0,0,0,0}};
	int n=6,e=5;
	CreateMat(g,A,n,e);
	printf("ͼG���ڽӾ���:\n");DispMat(g);

	printf("T��ֱ��=%d\n",MaxDiameter(g));

	return 1;
}
