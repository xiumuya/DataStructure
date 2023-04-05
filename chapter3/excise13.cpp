
#include <stdio.h>
#include <malloc.h>
#define MAXQNode 10							//���еĸ���
typedef struct node
{	int data;
	struct node *next;
} QNode;
void Insert(QNode *QH[],QNode *QT[],int x)  //��x���뵽��Ӧ������
{	QNode *s;
	s=(QNode *)malloc(sizeof(QNode));		//����һ���ڵ�s
	s->data=x; s->next=NULL;
	if (QH[x]==NULL)						//x�Ŷ���Ϊ�ն�ʱ
	{	QH[x]=s;
		QT[x]=s;
	}
	else									//x�Ŷ��в��ն�ʱ
	{	QT[x]->next=s;						//��s�ڵ�����QT[x]��ָ�ڵ�֮��
		QT[x]=s;							//��QT[x]��ָ��β�ڵ�
	}
}
void Create(QNode *QH[],QNode *QT[])		//�����û����봴������
{	int n,x,i;
	printf("n:");
	scanf("%d",&n);
	for (i=0;i<n;i++)
	{	do
		{	printf("�����%d����:",i+1);
			scanf("%d",&x);
		} while (x<0 || x>10);
		Insert(QH,QT,x);
	}
}
void DestroyList(QNode *&head)			//�ͷŵ�����
{
	QNode *pre=head,*p=pre->next;
	while (p!=NULL)
	{
		free(pre);
		pre=p; p=p->next;
	}
	free(pre);
}
void DispList(QNode *head)				//�������������нڵ�ֵ
{
	printf("\n�������Ԫ��:");
	while (head!=NULL)
	{	printf("%d ",head->data);
		head=head->next;
	}
	printf("\n");
}
QNode *Link(QNode *QH[],QNode *QT[])	//���ǿն����������������
{
	QNode *head=NULL,*tail;				//��������׽ڵ�ָ���β�ڵ�ָ��
	int i;
	for (i=0;i<MAXQNode;i++)			//ɨ�����ж���
		if (QH[i]!=NULL)				//i�Ŷ��в���		
		{
			if (head==NULL)				//��i�Ŷ���Ϊ��һ���ǿն���
			{
				head=QH[i];
				tail=QT[i];
			}
			else						//��i�Ŷ��в��ǵ�һ���ǿն���
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
	QNode *QH[MAXQNode],*QT[MAXQNode];	//�����еĶ�ͷQH�Ͷ�βָ��QT
	for (i=0;i<MAXQNode;i++)
		QH[i]=QT[i]=NULL;				//�ó�ֵ��
	Create(QH,QT);						//��������
	head=Link(QH,QT);					//���Ӹ����в���������
	DispList(head);						//���������
	DestroyList(head);					//���ٵ�����
	return 1;
}
