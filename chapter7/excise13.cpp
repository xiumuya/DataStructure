#include "btree.cpp"
int SSonNodes(BTNode *b)
{	int num1,num2,n;
	if (b==NULL)
		return 0;
	else if ((b->lchild==NULL && b->rchild!=NULL) ||
		(b->lchild!=NULL && b->rchild==NULL))
		n=1;					//为单分支结点
	else 
		n=0;					//其他结点
	num1=SSonNodes(b->lchild);	//递归求左子树中单分支结点数
	num2=SSonNodes(b->rchild);	//递归求右子树中单分支结点数
	return (num1+num2+n);
}


int main()
{	BTNode *b;
	CreateBTree(b,"A(B(D(,G)),C(E,F))");
	printf("二叉树:");DispBTree(b);printf("\n");
	printf("单分支结点个数=%d\n",SSonNodes(b));

	DestroyBTree(b);
	return 1;
}
