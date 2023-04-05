#include "btree.cpp"

int BTWidth(BTNode *b)
{	struct
	{	int lno;					//节点的层次编号
		BTNode *p;					//节点指针
	} Qu[MaxSize];					//定义顺序非循环队列
	int front,rear;					//定义队首和队尾指针
	int lnum,max,i,n;
	front=rear=0;					//置队列为空队
	if (b!=NULL)
	{	rear++;	
		Qu[rear].p=b;				//根节点指针入队
		Qu[rear].lno=1;				//根节点的层次编号为1
		while (rear!=front)			//队列不为空
		{	front++;
			b=Qu[front].p;			//队头出队
			lnum=Qu[front].lno;
			if (b->lchild!=NULL)		//左孩子入队
			{	rear++;
				Qu[rear].p=b->lchild;
				Qu[rear].lno=lnum+1;
			}
			if (b->rchild!=NULL)		//右孩子入队
			{	rear++;
				Qu[rear].p=b->rchild;
				Qu[rear].lno=lnum+1;
			}
		}
		printf("各节点的层编号:\n");
		for (i=1;i<=rear;i++)
			printf("   %c,%d\n",Qu[i].p->data,Qu[i].lno);
		max=0;lnum=1;i=1;
		while (i<=rear)
		{	n=0;
			while (i<=rear && Qu[i].lno==lnum)
			{	n++;
				i++;
			}
			lnum=Qu[i].lno;
			if (n>max) max=n;
		}
		return max;
	}
	else
		return 0;
}


int main()
{
	BTNode *b;
	CreateBTree(b,"A(B(D,E(G,H)),C(,F(I)))");	//图7.11的二叉树
	printf("b:"); DispBTree(b); printf("\n");
	printf("二叉树的宽度:%d\n",BTWidth(b));

	DestroyBTree(b);
	return 1;
}
