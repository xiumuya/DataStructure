
#include <stdio.h>
#include <malloc.h>
#define MAXQNode 10							//队列的个数
typedef struct node
{	int data;
	struct node *next;
} QNode;
void Insert(QNode *QH[],QNode *QT[],int x)  //将x插入到相应队列中
{	QNode *s;
	s=(QNode *)malloc(sizeof(QNode));		//创建一个节点s
	s->data=x; s->next=NULL;
	if (QH[x]==NULL)						//x号队列为空队时
	{	QH[x]=s;
		QT[x]=s;
	}
	else									//x号队列不空队时
	{	QT[x]->next=s;						//将s节点链到QT[x]所指节点之后
		QT[x]=s;							//让QT[x]仍指向尾节点
	}
}
void Create(QNode *QH[],QNode *QT[])		//根据用户输入创建队列
{	int n,x,i;
	printf("n:");
	scanf("%d",&n);
	for (i=0;i<n;i++)
	{	do
		{	printf("输入第%d个数:",i+1);
			scanf("%d",&x);
		} while (x<0 || x>10);
		Insert(QH,QT,x);
	}
}
void DestroyList(QNode *&head)			//释放单链表
{
	QNode *pre=head,*p=pre->next;
	while (p!=NULL)
	{
		free(pre);
		pre=p; p=p->next;
	}
	free(pre);
}
void DispList(QNode *head)				//输出单链表的所有节点值
{
	printf("\n输出所有元素:");
	while (head!=NULL)
	{	printf("%d ",head->data);
		head=head->next;
	}
	printf("\n");
}
QNode *Link(QNode *QH[],QNode *QT[])	//将非空队列链接起来并输出
{
	QNode *head=NULL,*tail;				//总链表的首节点指针和尾节点指针
	int i;
	for (i=0;i<MAXQNode;i++)			//扫描所有队列
		if (QH[i]!=NULL)				//i号队列不空		
		{
			if (head==NULL)				//若i号队列为第一个非空队列
			{
				head=QH[i];
				tail=QT[i];
			}
			else						//若i号队列不是第一个非空队列
			{
				tail->next=QH[i];
				tail=QT[i];
			}
		}
	tail->next=NULL;
	return head;
}
int main()
{
	int i;
	QNode *head;
	QNode *QH[MAXQNode],*QT[MAXQNode];	//各队列的队头QH和队尾指针QT
	for (i=0;i<MAXQNode;i++)
		QH[i]=QT[i]=NULL;				//置初值空
	Create(QH,QT);						//建立队列
	head=Link(QH,QT);					//链接各队列产生单链表
	DispList(head);						//输出单链表
	DestroyList(head);					//销毁单链表
	return 1;
}
