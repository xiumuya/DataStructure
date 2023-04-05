#include "btree.cpp"

BTNode *postfirst(BTNode *b)
{
	BTNode *p=b;
	if (b!=NULL)
		while (p->lchild!=NULL || p->rchild!=NULL)
		{
			while (p->lchild!=NULL)	//先找到节点p的最左下节点
				p=p->lchild;
			if (p->rchild!=NULL)	//若节点p有右孩子，转向该右孩子
				p=p->rchild;
		}
	return p;	//找到的第一个叶子节点p即为所求
}

int main()
{
	BTNode *b,*p;
	CreateBTree(b,"A(B(D,E(G,H)),C(,F(I)))");	//图7.11的二叉树
	printf("b:"); DispBTree(b); printf("\n");

	p=postfirst(b);
	if (p!=NULL)
		printf("结果:%c\n",p->data);

	DestroyBTree(b);
	return 1;
}
