#include "btree.cpp"
bool CompBTree(BTNode *b)
{	BTNode *Qu[MaxSize],*p;				//定义一个队列，用于层次遍历
	int front=0,rear=0;				//环形队列的队头队尾指针
	bool cm=true;						//cm为真表示二叉树为完全二叉树
	bool bj=true;						//bj为真表示到目前为止所有结点均有左右孩子
	if (b==NULL) return true;			//空树当成特殊的完全二叉树
	rear++;
	Qu[rear]=b;						//根结点进队
	while (front!=rear)				//队列不空
	{	front=(front+1)%MaxSize;
		p=Qu[front];					//出队结点p
		if (p->lchild==NULL)			//p结点没有左孩子
		{	bj=false;					//出现结点p缺左孩子的情况
			if (p->rchild!=NULL)		//没有左孩子但有右孩子,违反(1),
				cm=false;
		}
		else							//p结点有左孩子
		{	if (!bj) cm=false;			//bj为假而结点p还有左孩子，违反(2)
			rear=(rear+1)%MaxSize;
			Qu[rear]=p->lchild;		//左孩子进队
			if (p->rchild==NULL)
				bj=false;				//出现结点p缺右孩子的情况
			else						//p有左右孩子,则继续判断
			{	rear=(rear+1)%MaxSize;	
				Qu[rear]=p->rchild;	//将p结点的右孩子进队
			}
		}
	}
	return cm;
}
int main()
{	BTNode *b,*b1;
	CreateBTree(b,"A(B(D(,G)),C(E,F))");
	printf("二叉树b:");DispBTree(b);printf("\n");
	printf("b是否同构:%d\n",CompBTree(b)); 
	CreateBTree(b1,"A(B(C,D),E(F,G)))");
	printf("二叉树b1:");DispBTree(b1);printf("\n");
	printf("b1是否同构:%d\n",CompBTree(b1)); 


	DestroyBTree(b);
	DestroyBTree(b1);
	return 1;
}
