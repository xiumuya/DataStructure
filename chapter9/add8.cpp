#include "bst.cpp"		//二叉排序树基本运算算法
#define MaxSize 100 
void SearchPath(BSTNode *bt,KeyType k,KeyType path[],int d)
{	//d表示path中最后关键字的下标，初始值为-1
	if (bt==NULL)
		return;
	else if (k==bt->key)
	{
		d++;
		path[d]=bt->key;		//添加到路径中
		for (int i=0;i<=d;i++)
			printf("%2d",path[i]);
		printf("\n");
	}
	else
	{
		d++;
		path[d]=bt->key;		//添加到路径中
		if (k<bt->key)
			SearchPath(bt->lchild,k,path,d);	//在左子树中递归查找
		else
			SearchPath(bt->rchild,k,path,d);		//在右子树中递归查找
	}
}

int main()
{
	BSTNode *bt;
	KeyType k=3;
	KeyType a[]={5,2,1,6,7,4,8,3,9},n=9;
	printf("(1)构造二叉排序树bt\n");
	bt=CreateBST(a,n);		//创建一棵二叉排序树
	printf("(2)输出BST:");DispBST(bt);printf("\n");
	int path[MaxSize];
	printf("(3)查找%d关键字:",k);SearchPath(bt,k,path,-1);
	printf("(4)销毁bt"); DestroyBST(bt); printf("\n");
	return 1;
}
