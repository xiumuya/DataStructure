#include "btree.cpp"
int DSonNodes(BTNode *b)
{	int num1,num2,n;
	if (b==NULL)
		return 0;
	else if (b->lchild!=NULL && b->rchild!=NULL)
		n=1;					//为双分支结点
	else 
		n=0;					//其他
	num1=DSonNodes(b->lchild);	//递归求左子树的双分支结点数
	num2=DSonNodes(b->rchild);	//递归求右子树的双分支结点数
	return (num1+num2+n);
}

int main()
{
	BTNode *b;
	CreateBTree(b,"A(B(D,E(G,H)),C(,F(I)))");	//图7.11的二叉树
	printf("b:"); DispBTree(b); printf("\n");
	printf("双分支节点个数:%d\n",DSonNodes(b));
	DestroyBTree(b);
	return 1;
}
