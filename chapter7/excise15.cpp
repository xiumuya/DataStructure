#include "btree.cpp"
void Copy(BTNode *b1,BTNode *&b2)
{	if (b1==NULL)
		b2=NULL;
	else
	{	b2=(BTNode *)malloc(sizeof(BTNode));
		b2->data=b1->data;
		Copy(b1->lchild,b2->lchild);
		Copy(b1->rchild,b2->rchild);
	}
}
int main()
{	BTNode *b1,*b2;
	CreateBTree(b1,"A(B(D(,G)),C(E,F))");
	printf("¶þ²æÊ÷b1:");DispBTree(b1);printf("\n");
	printf("b1->b2\n");
	Copy(b1,b2);
	printf("¶þ²æÊ÷b2:");DispBTree(b2);printf("\n");

	DestroyBTree(b1);
	DestroyBTree(b2);
	return 1;
}
