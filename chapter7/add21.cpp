#include "btree.cpp"
void addparent11(BTNode* b,BTNode* p)	//���b��˫��Ϊ���p 
{
	if (b!=NULL)
	{
		b->parent=p;
		addparent11(b->lchild,b);
		addparent11(b->rchild,b);
	}
}

void addparent1(BTNode *&b)		//�ⷨ1���ݹ����������� 
{
	addparent11(b,NULL);
}

void addparent2(BTNode *&b)		//�ⷨ2����α������ 
{
	BTNode* Qu[MaxSize];			//����˳���ѭ������
	int front,rear;					//������׺Ͷ�βָ��
	front=rear=0;					//�ö���Ϊ�ն�
	rear++;	
	Qu[rear]=b;						//��������
	b->parent=NULL;					//������˫��ΪNULL 
	while (rear!=front)				//���в�Ϊ��
	{	front++;
		b=Qu[front];				//���ӽ��b 
		if (b->lchild!=NULL)		//����������
		{	b->lchild->parent=b;
			rear++;					//���ӽ��� 
			Qu[rear]=b->lchild;
		}
		if (b->rchild!=NULL)		//�������Һ���
		{	b->rchild->parent=b;
			rear++;					//�Һ��ӽ��� 
			Qu[rear]=b->rchild;
		}
	}
}
void disppath1(BTNode *b)
{
	printf("%c: ",b->data);
	while(b!=NULL)
	{
		printf("%c ",b->data);
		b=b->parent;
	}
	printf("\n");
}
void disppath(BTNode *b)
{
	if (b!=NULL)
	{
		if(b->lchild==NULL && b->rchild==NULL)
			disppath1(b);
		disppath(b->lchild);	
		disppath(b->rchild);
	}
}
int main()
{
	BTNode *b;
	CreateBTree(b,"A(B(D,E(G,H)),C(,F(I)))");	//ͼ7.11�Ķ�����
	printf("b:"); DispBTree(b); printf("\n");
	addparent1(b);
	disppath(b);
	
	DestroyBTree(b);
	return 1;
}
