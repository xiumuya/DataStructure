#include "btree.cpp"	//���������������㷨
void Link(BTNode *b,BTNode *&head,BTNode *&tail)
{	
	if (b!=NULL)
	{
		if (b->lchild==NULL && b->rchild==NULL)	//Ҷ�ӽڵ�
		{
			if (head==NULL)						//��һ��Ҷ�ӽڵ�
			{	head=b;
				tail=b;
			}
			else								//����Ҷ�ӽڵ�
			{	tail->rchild=b;
				tail=b;
			}
		}
		Link(b->lchild,head,tail);
		Link(b->rchild,head,tail);
	}
}

int main()
{
	BTNode *b,*tail,*head=NULL;
	CreateBTree(b,"A(B(D,E(G,H)),C(,F(I)))");	//���̡̳�ͼ7.11�Ķ�����
	printf("b:"); DispBTree(b); printf("\n");

	Link(b,head,tail);
	printf("������:");
	while (head!=NULL)
	{	printf("%c ",head->data);
		head=head->rchild;
	}
	printf("\n");

	//DestroyBTree(b);ָ�뷢���ı䣬�޷�����
	return 1;
}
