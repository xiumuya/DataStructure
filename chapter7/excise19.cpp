#include "btree.cpp"

BTNode *Swap(BTNode *b)
{	BTNode *t,*t1,*t2;
	if (b==NULL)
		t=NULL;
	else
	{	t=(BTNode *)malloc(sizeof(BTNode));	//����һ�����ڵ�
		t->data=b->data;
		t1=Swap(b->lchild);
		t2=Swap(b->rchild);
		t->lchild=t2;
		t->rchild=t1;
	}
	return t;
}

int main()
{	BTNode *b,*b1;
	CreateBTree(b,"A(B(D(,G)),C(E,F))");
	printf("����ǰ�Ķ�����:");DispBTree(b);printf("\n");
	b1=Swap(b);
	printf("������Ķ�����:");DispBTree(b1);printf("\n");
	DestroyBTree(b);
	DestroyBTree(b1);
	return 1;
}
