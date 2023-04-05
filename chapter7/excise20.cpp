#include "btree.cpp"
bool Symm(BTNode *b1,BTNode *b2)	//判断二叉树b1和b2是否同构
{	if (b1==NULL && b2==NULL)
		return true;
	else if (b1==NULL || b2==NULL)
		return false;
	else
		return (Symm(b1->lchild,b2->lchild) &	Symm(b1->rchild,b2->rchild));
}
bool Symmtree(BTNode *b)		//判断二叉树的左、右子树是否同构
{	if (b==NULL)
		return true;
	else
		return Symm(b->lchild,b->rchild);
}
int main()
{	BTNode *b,*b1;
	CreateBTree(b,"A(B(D(,G)),C(E,F))");
	printf("二叉树b:");DispBTree(b);printf("\n");
	printf("b是否同构:%d\n",Symmtree(b)); 
	CreateBTree(b1,"A(B(C,D),E(F,G)))");
	printf("二叉树b1:");DispBTree(b1);printf("\n");
	printf("b1是否同构:%d\n",Symmtree(b1)); 


	DestroyBTree(b);
	DestroyBTree(b1);
	return 1;
}
