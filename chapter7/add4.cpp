#include "btree.cpp"
void Delx(BTNode *&b,ElemType x)
{
	if (b!=NULL)
	{	if (b->data==x)
		{	DestroyBTree(b);
			b=NULL;
		}
		else
		{	Delx(b->lchild,x);
			Delx(b->rchild,x);
		}
	}
}


int main()
{
	BTNode *b;
	CreateBTree(b,"A(B(D,E(G,H)),C(,F(I)))");	//ͼ7.11�Ķ�����
	printf("b:"); DispBTree(b); printf("\n");
	ElemType x='E';
	Delx(b,x);
	printf("b:"); DispBTree(b); printf("\n");
	DestroyBTree(b);
	return 1;
}
