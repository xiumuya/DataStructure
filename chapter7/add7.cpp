#include "btree.cpp"

bool isomorphism(BTNode *b)
{
	if (b==NULL) return true;
	if ((b->lchild==NULL && b->rchild!=NULL) ||
		(b->lchild!=NULL && b->rchild==NULL))
		return false;
	return isomorphism(b->lchild) & isomorphism(b->rchild);
}

int main()
{
	BTNode *b1,*b2;
	CreateBTree(b1,"A(B(D,E(G,H)),C(,F(I)))");	//图7.11的二叉树
	CreateBTree(b2,"A(B(D,E),C(F,G))");
	printf("b1:"); DispBTree(b1); printf("\n");
	printf("b1的对称同构性:%d\n",isomorphism(b1));
	printf("b2:"); DispBTree(b2); printf("\n");
	printf("b2的对称同构性:%d\n",isomorphism(b2));

	DestroyBTree(b1);
	DestroyBTree(b2);
	return 1;
}
