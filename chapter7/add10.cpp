#include "btree.cpp"	//二叉树基本运算算法
void Width1(BTNode *b,int l,int width[])
{	//l的初值为1
	if (b!=NULL)
	{	width[l]++;
		Width1(b->lchild,l+1,width);
		Width1(b->rchild,l+1,width);
	}
}
int Width(BTNode *b)	//求二叉树b的宽度
{	int i,max=0;
	int width[MaxSize];
	for (i=1;i<MaxSize;i++)
		width[i]=0;
	Width1(b,1,width);
	for (i=1;i<MaxSize;i++)
		if (width[i]>max) max=width[i];
	return max;
}


int main()
{
	BTNode *b;
	CreateBTree(b,"A(B(D,E(G,H)),C(,F(I)))");	//图7.11的二叉树
	printf("b:"); DispBTree(b); printf("\n");

	printf("宽度:%d\n",Width(b));

	DestroyBTree(b);
	return 1;
}
