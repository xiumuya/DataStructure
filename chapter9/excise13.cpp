#include "bst.cpp"   //二叉排序树基本运算算法

KeyType predt=-32768; //predt为全局变量,保存当前节点中序前驱的值,初值为-∞
bool JudgeBST(BSTNode *bt)
{
	bool b1,b2;
	if (bt==NULL)
		return true;
	else
	{
		b1=JudgeBST(bt->lchild);	//判断左子树
		if (b1==false)				//左子树不是BST，返回假
			return false;
		if (bt->key<predt)			//当前节点违反BST性质，返回假
			return false;
		predt=bt->key;
		b2=JudgeBST(bt->rchild);	//判断右子树
		return b2;
	}
}

int main()
{
	BSTNode *bt;
	KeyType a[]={5,2,1,6,7,4,8,3,9},n=9;
	bt=CreateBST(a,n);		//创建一棵二叉排序树
	printf("BST:");DispBST(bt);printf("\n");

	printf("结果:%d\n",JudgeBST(bt));

	DestroyBST(bt);
	return 1;
}
