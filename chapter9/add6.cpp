#include "bst.cpp"   //二叉排序树基本运算算法

bool Findseq(BSTNode *bt,int k,int a[],int n)
{	BSTNode *p=bt;
	int i=0;
	if (a[n-1]!=k)						//未找到k，返回false
		return false;
	while (i<n && p!=NULL)
	{
		if (p->key!=a[i])				//若不等，表示a不是k的查找序列
			return false;				//返回false
		if (k<p->key) p=p->lchild;		//在左子树中查找
		else if (k>p->key) p=p->rchild;	//在右子树中查找
		i++;							//查找序列指向下一个关键字
	}
	if (p!=NULL) return true;			//找到了k，返回true
	else return false;					//未找到k，返回false
}


int main()
{
	BSTNode *bt;
	KeyType keys[]={5,2,3,4,1,6,8,7,9};
	int m=9;
	bt=CreateBST(keys,m);		//创建二叉排序树
	printf("BST:"); DispBST(bt); printf("\n");
	int n=4;
	KeyType a[]={5,2,3,9};
	KeyType k=9;
	if (Findseq(bt,k,a,n))
		printf("Yes\n");
	else
		printf("No\n");

	DestroyBST(bt);
	return 1;
}