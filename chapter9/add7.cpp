#include "bst.cpp"   //二叉排序树基本运算算法

bool Delk(BSTNode *&bt,KeyType k)
{
	if (bt==NULL)
		return false;
	if (bt->key==k)
	{
		DestroyBST(bt->lchild);
		bt->lchild=NULL;
		return true;
	}
	else if (k<bt->key)
		Delk(bt->lchild,k);
	else
		Delk(bt->rchild,k);
}

int main()
{
	BSTNode *bt;
	KeyType keys[]={5,2,3,4,1,6,8,7,9};
	int n=9;
	bt=CreateBST(keys,n);		//创建二叉排序树
	printf("BST:"); DispBST(bt); printf("\n");
	KeyType k=2;

	Delk(bt,k);
	printf("BST:"); DispBST(bt); printf("\n");
	
	DestroyBST(bt);
	return 1;
}