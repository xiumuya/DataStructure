#include "btree.cpp"
BTNode* parent(BTNode *b,char x)
{	if(b==NULL) return NULL;
	if(b->lchild!=NULL && b->lchild->data==x)		//���x�ǽ��b������
		return b;
	if(b->rchild!=NULL && b->rchild->data==x)		//���x�ǽ��b���Һ���
		return b;
	BTNode* p=parent(b->lchild,x);					//���������в��� 
	if(p!=NULL)										//�����������ҵ�˫��pʱ����p 
		return p;
	else
		return parent(b->rchild,x);					//�������������еĲ��ҽ�� 
}

BTNode* parent1(BTNode *b,char x)
{
	BTNode* qu[MaxSize];
	int front=0,rear=0;
	if(b==NULL || b->data==x)
		return NULL; 
	rear=(rear+1)%MaxSize;				//�������� 
	qu[rear]=b;
	while(front!=rear)					//�Ӳ���ʱѭ��
	{
		front=(front+1)%MaxSize;		//���ӽ��p 
		BTNode* p=qu[front];
		if(p->lchild!=NULL)				//���p�������� 
		{
			if(p->lchild->data==x)		//�����ǽ��x 
				return p;
			else
			{
				rear=(rear+1)%MaxSize;	//���ӽ��� 
				qu[rear]=p->lchild;
			}
		}
		if(p->rchild!=NULL)				//���p�����Һ��� 
		{
			if(p->rchild->data==x)		//�Һ����ǽ��x 
				return p;
			else
			{
				rear=(rear+1)%MaxSize;	//�Һ��ӽ��� 
				qu[rear]=p->rchild;
			}
		}
	}
}


int main()
{	BTNode *b;
	CreateBTree(b,"A(B(D(,G)),C(E,F))");
	printf("������b:");DispBTree(b);printf("\n");
	char x='G';
	BTNode* p=parent1(b,x);
	if(p!=NULL)
		printf("%c��˫����%c\n",x,p->data);
	else
		printf("%c��˫�ײ�����\n",x);
	DestroyBTree(b);
	return 1;
}
