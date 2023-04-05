#include "btree.cpp"
void Output(BTNode *p)			//输出以p为根结点的子树
{	if (p!=NULL)
	{	printf("%c ",p->data);
		Output(p->lchild);
		Output(p->rchild);
	}
}
void Child(BTNode *b,char x)	//输出x结点的子孙
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
	printf("二叉树:");DispBTree(b);printf("\n");
	printf("A的子孙:");
	Child(b,'A');
	DestroyBTree(b);
	return 1;
}
