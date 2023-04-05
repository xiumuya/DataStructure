#include "bst.cpp"   //二叉排序树基本运算算法

int abs(int x,int y)	//求两个整数差的绝对值
{
	int z=x-y;
	return z>0?z:-z;
}
void JudgeAVT(BSTNode *bt,bool &balance,int &h)
{	//h为bt的高度,balance表示bt的平衡性
	int hl,hr;
	bool bl,br;
	if (bt==NULL)							//空树是平衡的
	{
		h=0;
		balance=true;
	}
	//else if (bt->lchild==NULL && bt->rchild==NULL)	//只有一个节点的树是平衡的 
	//{
	//	h=1;
	//	balance=true;
	//}
	else 
	{
		JudgeAVT(bt->lchild,bl,hl);		//求出左子树的平衡性bl和高度hl
		JudgeAVT(bt->rchild,br,hr);		//求出右子树的平衡性br和高度hr
		h=(hl>hr?hl:hr)+1;
		if (abs(hl,hr)<=1)
			balance=bl & br;			//&为逻辑与运算符
		else
			balance=false;
		printf("当前结点:%d,lefth=%d,righth=%d, h:%d, bal:%d\n",bt->key,hl,hr,h,balance);
	}
}

int main()
{
	BSTNode *bt;
	//KeyType keys[]={5,2,3,4,1,8,6,7,9};
	KeyType keys[]={5,4,8,6,9};
	int n=5;
	bt=CreateBST(keys,n);		//创建二叉排序树
	printf("BST:"); DispBST(bt); printf("\n");

	bool balance;
	int h;
	JudgeAVT(bt,balance,h);
	if (balance)
		printf("该BST树是平衡的\n");
	else
		printf("该BST树是不平衡的\n");
	printf("该BST树高度:%d\n",h);
	
	DestroyBST(bt);
	return 1;
}
