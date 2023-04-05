#include "btree.cpp"
int LevelkCount(BTNode *b,int k,int h)
{	//h的初值为1
	int num1,num2,num=0;
	if (b!=NULL)
	{	if (h==k && b->lchild==NULL && b->rchild==NULL)
			num++;
		num1=LevelkCount(b->lchild,k,h+1);
		num2=LevelkCount(b->rchild,k,h+1);
		num+=num1+num2;
		return num;
	}
	return 0;
}
int Levelkleaf(BTNode *b,int k)	//返回二叉树b中第k层上叶子结点个数
{
	return LevelkCount(b,k,1);
}
int main()
{	BTNode *b;
	CreateBTree(b,"A(B(D(,G)),C(E,F))");
	printf("二叉树b:");DispBTree(b);printf("\n");
	int k=3; 
	printf("第%d层的叶子结点个数=%d\n",k,Levelkleaf(b,k));
	DestroyBTree(b);
	return 1;
}
