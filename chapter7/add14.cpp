#include "btree.cpp"

int LevelLeafkCount(BTNode *b,int h,int k)
{	//h的初值为1
	int num1,num2,num=0;
	if (b!=NULL)
	{	if (h==k && b->lchild==NULL && b->rchild==NULL)
			num++;
		num1=LevelLeafkCount(b->lchild,h+1,k);
		num2=LevelLeafkCount(b->rchild,h+1,k);
		num+=num1+num2;
		return num;
	}
	else return 0;
}
int LevelLeafk(BTNode *b,int k)	//求b中第k层上叶子节点个数
{
	return LevelLeafkCount(b,1,k);
}


int main()
{
	BTNode *b;
	CreateBTree(b,"A(B(D,E(G,H)),C(,F(I)))");	//图7.11的二叉树
	printf("b:"); DispBTree(b); printf("\n");
	int k=4;

	printf("第%d层上叶子结点个数:%d\n",k,LevelLeafk(b,k));

	DestroyBTree(b);
	return 1;
}
