#include "btree.cpp"
bool Brother(BTNode *b,char x,char y)
{	bool flag;
	if (b==NULL)
		return false;
	else
	{	if (b->lchild!=NULL && b->rchild!=NULL)
		{	if ((b->lchild->data==x && b->rchild->data==y) ||
				(b->lchild->data==y && b->rchild->data==x))
				return true;
		}
		flag=Brother(b->lchild,x,y);
		if (flag==true)
			return true;
		else
			return Brother(b->rchild,x,y);
	}
}
int main()
{	BTNode *b;
	CreateBTree(b,"A(B(D(,G)),C(E,F))");
	printf("¶þ²æÊ÷b:");DispBTree(b);printf("\n");
	char x='F',y='E';
	printf("ans=%d\n",Brother(b,x,y));
	x='D'; y='E';
	printf("ans=%d\n",Brother(b,x,y));
	DestroyBTree(b);
	return 1;
}
