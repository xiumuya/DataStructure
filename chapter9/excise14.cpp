#include "bst.cpp"   //二叉排序树基本运算算法
int Level(BSTNode *bt,KeyType k)
{	int lv=1;						//层次lv置初值1
	BSTNode *p=bt;
	while (p!=NULL && p->key!=k)	//二叉排序树未找完或未找到则循环
	{	if (k<p->key)
			p=p->lchild;			//在左子树中查找
		else
			p=p->rchild;			//在右子树中查找
		lv++;					//层次增1
	}
	if (p!=NULL)					//找到后返回其层次
		return lv;
	else
		return(0);				//表示未找到
}

int main()
{
	BSTNode *bt;
	KeyType a[]={5,2,1,6,7,4,8,3,9},n=9;
	bt=CreateBST(a,n);		//创建一棵二叉排序树
	printf("BST:");DispBST(bt);printf("\n");
	int k=4;
	printf("结果:%d\n",Level(bt,k));

	DestroyBST(bt);
	return 1;
}
