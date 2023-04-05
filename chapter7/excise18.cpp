#include "btree.cpp"
void Output(BTNode *p)			//�����pΪ����������
{	if (p!=NULL)
	{	printf("%c ",p->data);
		Output(p->lchild);
		Output(p->rchild);
	}
}
void Child(BTNode *b,char x)	//���x��������
{	if (b!=NULL)
	{	if (b->data==x)
		{	if (b->lchild!=NULL)
				Output(b->lchild);
			if (b->rchild!=NULL)
				Output(b->rchild);
			return;
		}
		Child(b->lchild,x);
		Child(b->rchild,x);
	}
}
int main()
{	BTNode *b;
	CreateBTree(b,"A(B(D(,G)),C(E,F))");
	printf("������:");DispBTree(b);printf("\n");
	printf("A������:");
	Child(b,'A');
	DestroyBTree(b);
	return 1;
}
