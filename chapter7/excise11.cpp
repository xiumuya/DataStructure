#include "btree.cpp"
typedef char SqBTree[MaxSize];
void Ctree(BTNode *b,SqBTree a,int i)
{	if (b!=NULL)
	{	a[i]=b->data;
		Ctree(b->lchild,a,2*i);
		Ctree(b->rchild,a,2*i+1);
	}
	else a[i]='#';
}



int main()
{	BTNode *b;
	CreateBTree(b,"A(B(D(,G)),C(E,F))");
	printf("¶þ²æÊ÷:");DispBTree(b);printf("\n");
	SqBTree a;
	Ctree(b,a,1);
	printf("a: ");
	for(int i=1;i<10;i++)
		printf("%c",a[i]);
	printf("\n");

	DestroyBTree(b);
	return 1;
}
