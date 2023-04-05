#include "btree.cpp"

int MinBranch(BTNode *b)
{	int min1,min2,min;
	if (b==NULL) return 0;
	min1=MinBranch(b->lchild);			//递归遍历左子树
    min2=MinBranch(b->rchild);			//递归遍历右子树
    if(min1==0) return min2+1;			//左子树为空
    else if(min2==0) return min1+1;		//右子树为空
    else return min1>min2?min1:min2+1;	//存在左右子树
}

int main()
{
	BTNode *b;
	CreateBTree(b,"A(B(,E(G,H)),C(,F(I)))");
	printf("b:"); DispBTree(b); printf("\n");

	printf("最小枝长:%d\n",MinBranch(b));

	DestroyBTree(b);
	return 1;
}
