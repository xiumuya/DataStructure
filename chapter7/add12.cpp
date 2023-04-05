#include "btree.cpp"	//二叉树基本运算算法
void Link(BTNode *b,BTNode *&head,BTNode *&tail)
{	
	if (b!=NULL)
	{
		if (b->lchild==NULL && b->rchild==NULL)	//叶子节点
		{
			if (head==NULL)						//第一个叶子节点
			{	head=b;
				tail=b;
			}
			else								//其他叶子节点
			{	tail->rchild=b;
				tail=b;
			}
		}
		Link(b->lchild,head,tail);
		Link(b->rchild,head,tail);
	}
}

int main()
{
	BTNode *b,*tail,*head=NULL;
	CreateBTree(b,"A(B(D,E(G,H)),C(,F(I)))");	//《教程》图7.11的二叉树
	printf("b:"); DispBTree(b); printf("\n");

	Link(b,head,tail);
	printf("单链表:");
	while (head!=NULL)
	{	printf("%c ",head->data);
		head=head->rchild;
	}
	printf("\n");

	//DestroyBTree(b);指针发生改变，无法销毁
	return 1;
}
