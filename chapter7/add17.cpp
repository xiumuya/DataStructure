#include "btree.cpp"

ElemType maxnode(BTNode *b)
{
	ElemType max=b->data,max1;
	if (b!=NULL)
	{
		if (b->lchild==NULL && b->rchild==NULL)	//只有一个节点时
			return b->data;
		else
		{	if (b->data>max)
				max=b->data;
			if (b->lchild!=NULL)
				max1=maxnode(b->lchild);		//遍历左子树
			if (max1>max) max=max1;
			if (b->rchild!=NULL)
				max1=maxnode(b->rchild);		//遍历右子树
			if (max1>max) max=max1;				//求最大值
			return max;							//返回最大值
		}
	}
	return '0';
}

int main()
{
	BTNode *b;
	CreateBTree(b,"A(B(D,E(G,H)),C(,F(I)))");
	printf("b:"); DispBTree(b); printf("\n");
	
	printf("结果:%c\n",maxnode(b));

	DestroyBTree(b);
	return 1;
}
