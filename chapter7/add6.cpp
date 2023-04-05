#include "btree.cpp"
void MinlenLeaf(BTNode *b,int l,int &min,char &x)
{	//l的初值为1,min取最大整数，x为所求的叶子节点
	if (b!=NULL)
	{	if (b->lchild==NULL && b->rchild==NULL)
		{	if (l<min)
			{	min=l;
				x=b->data;
			}
		}
		MinlenLeaf(b->lchild,l+1,min,x);
		MinlenLeaf(b->rchild,l+1,min,x);
	}
}

int main()
{
	BTNode *b;
	CreateBTree(b,"A(B(D,E(G,H)),C(,F(I)))");	//图7.11的二叉树
	printf("b:"); DispBTree(b); printf("\n");
	ElemType x;
	int min=1000;
	MinlenLeaf(b,1,min,x);
	printf("距离根节点最近的叶子节点:%c\n",x);
	DestroyBTree(b);
	return 1;
}
