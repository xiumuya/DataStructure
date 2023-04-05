#include "btree.cpp"

int LessNodes(BTNode *b,char x)
{	int num1,num2,num=0;
	if (b==NULL) 
		return 0;
	else
	{	num1=LessNodes(b->lchild,x);
		num2=LessNodes(b->rchild,x);
		num+=num1+num2;
		if (b->data<x) num++;
		return num;
	}
}


int main()
{
	BTNode *b;
	CreateBTree(b,"A(B(D,E(G,H)),C(,F(I)))");	//图7.11的二叉树
	printf("b:"); DispBTree(b); printf("\n");
	
	printf("结果:%d\n",LessNodes(b,'E'));

	DestroyBTree(b);
	return 1;
}
