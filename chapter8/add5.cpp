#include "graph.cpp"		//ͼ�Ļ��������㷨
#define MaxSize 100

//-------DFS------------------------------------
int visited[MAXV];
void DFS(AdjGraph *G,int v)  
{
	ArcNode *p;
	visited[v]=1;                   //���ѷ��ʱ��
	//printf("%d  ",v); 			//��������ʶ���ı��
	p=G->adjlist[v].firstarc;      	//pָ�򶥵�v�ĵ�һ�����Ļ�ͷ���
	while (p!=NULL) 
	{
		if (visited[p->adjvex]==0)	//��p->adjvex����δ����,�ݹ������
			DFS(G,p->adjvex);    
		p=p->nextarc;              	//pָ�򶥵�v����һ�����Ļ�ͷ���
	}
}
//------BFS-------------------------------------
typedef int ElemType;
typedef struct 
{	
	ElemType data[MaxSize];
	int front,rear;		//���׺Ͷ�βָ��
} SqQueue;
void InitQueue(SqQueue *&q)
{	q=(SqQueue *)malloc (sizeof(SqQueue));
	q->front=q->rear=0;
}
void DestroyQueue(SqQueue *&q)
{
	free(q);
}
bool QueueEmpty(SqQueue *q)
{
	return(q->front==q->rear);
}
bool enQueue(SqQueue *&q,ElemType e)
{	if ((q->rear+1)%MaxSize==q->front)	//���������
		return false;
	q->rear=(q->rear+1)%MaxSize;
	q->data[q->rear]=e;
	return true;
}
bool deQueue(SqQueue *&q,ElemType &e)
{	if (q->front==q->rear)				//�ӿ������
		return false;
	q->front=(q->front+1)%MaxSize;
	e=q->data[q->front];
	return true;
}

void BFS(AdjGraph *G,int v)  
{
	int w,i;
	ArcNode *p;
	SqQueue *qu;							//���廷�ζ���ָ��
	InitQueue(qu);							//��ʼ������
	//int visited[MAXV];            		//���嶥����ʱ�־����
	//for (i=0;i<G->n;i++) visited[i]=0;	//���ʱ�־�����ʼ��
	//printf("%2d",v); 						//��������ʶ���ı��
	visited[v]=1;              				//���ѷ��ʱ��
	enQueue(qu,v);
	while (!QueueEmpty(qu))       			//�Ӳ���ѭ��
	{	
		deQueue(qu,w);						//����һ������w
		p=G->adjlist[w].firstarc; 			//ָ��w�ĵ�һ���ڽӵ�
		while (p!=NULL)						//����w�������ڽӵ�
		{	
			if (visited[p->adjvex]==0) 		//����ǰ�ڽӵ�δ������
			{
				//printf("%2d",p->adjvex);  //���ʸ��ڽӵ�
				visited[p->adjvex]=1;		//���ѷ��ʱ��
				enQueue(qu,p->adjvex);		//�ö������
           	}
           	p=p->nextarc;              		//����һ���ڽӶ���
		}
	}
	printf("\n");
}

//---------------------------------------------------------
bool DFSTrave(AdjGraph *G,int i,int j)
{	int k;
	for (k=0;k<G->n;k++)
		visited[k]=0;
	DFS(G,i);			//�Ӷ���i��ʼ����������ȱ���
	if (visited[j]==0)
		return false;
	else
		return true;
}
bool BFSTrave(AdjGraph *G,int i,int j)
{	int k;
	for (k=0;k<G->n;k++)
		visited[k]=0;
	BFS(G,i);			//�Ӷ���i��ʼ���й�����ȱ���
	if (visited[j]==0)
		return false;
	else
		return true;
}

int main()
{ 
	int n=6, e=7;
	int A[MAXV][MAXV]={
		{0,1,1,0,0,0},{0,0,1,0,0,0},{0,0,0,1,1,0},
		{0,0,0,0,1,0},{1,0,0,0,0,0},{0,0,0,0,0,0}};	

	AdjGraph *G;
	CreateAdj(G,A,n,e);			////����ͼ���ڽӱ�
	printf("ͼG:\n");DispAdj(G);//����ڽӱ�

	for (int k=0;k<G->n;k++)
		visited[k]=0;

	int i=4,j=1;
	printf("����%d��%d�Ƿ���·��:%d\n",i,j,BFSTrave(G,i,j));	

	DestroyAdj(G);				//�����ڽӱ�
	return 1;
}