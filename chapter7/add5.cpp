#include "btree.cpp"
void Findparent(BTNode *b,char x,BTNode *&p)
{	if (b!=NULL)
	{	if (b->data==x) p=NULL;
		else if (b->lchild!=NULL && b->lchild->data==x)
			p=b;
		else if (b->rchild!=NULL && b->rchild->data==x)
			p=b;
		else
		{	Findparent(b->lchild,x,p);
			if (p==NULL)
				Findparent(b->rchild,x,p);
		}
	}
	else p=NULL;
}
int main()
{
	BTNode *b,*p;
	CreateBTree(b,"A(B(D,E(G,H)),C(,F(I)))");	//图7.11的二叉树
	printf("b:"); DispBTree(b); printf("\n");
	for(char x='A';x<='J';x++)
	{	
		Findparent(b,x,p);
		if (p!=NULL)
			printf("%c结点的双亲:%c\n",x,p->data);
		else
			printf("%c结点没有双亲或者不存在\n",x);
	}
	DestroyBTree(b);
	return 1;
}
