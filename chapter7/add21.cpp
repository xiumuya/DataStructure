#include "btree.cpp"
void addparent11(BTNode* b,BTNode* p)	//结点b的双亲为结点p 
{
	if (b!=NULL)
	{
		b->parent=p;
		addparent11(b->lchild,b);
		addparent11(b->rchild,b);
	}
}

void addparent1(BTNode *&b)		//解法1：递归先序遍历求解 
{
	addparent11(b,NULL);
}

void addparent2(BTNode *&b)		//解法2：层次遍历求解 
{
	BTNode* Qu[MaxSize];			//定义顺序非循环队列
	int front,rear;					//定义队首和队尾指针
	front=rear=0;					//置队列为空队
	rear++;	
	Qu[rear]=b;						//根结点进队
	b->parent=NULL;					//根结点的双亲为NULL 
	while (rear!=front)				//队列不为空
	{	front++;
		b=Qu[front];				//出队结点b 
		if (b->lchild!=NULL)		//若存在左孩子
		{	b->lchild->parent=b;
			rear++;					//左孩子进队 
			Qu[rear]=b->lchild;
		}
		if (b->rchild!=NULL)		//若存在右孩子
		{	b->rchild->parent=b;
			rear++;					//右孩子进队 
			Qu[rear]=b->rchild;
		}
	}
}
void disppath1(BTNode *b)
{
	printf("%c: ",b->data);
	while(b!=NULL)
	{
		printf("%c ",b->data);
		b=b->parent;
	}
	printf("\n");
}
void disppath(BTNode *b)
{
	if (b!=NULL)
	{
		if(b->lchild==NULL && b->rchild==NULL)
			disppath1(b);
		disppath(b->lchild);	
		disppath(b->rchild);
	}
}
int main()
{
	BTNode *b;
	CreateBTree(b,"A(B(D,E(G,H)),C(,F(I)))");	//图7.11的二叉树
	printf("b:"); DispBTree(b); printf("\n");
	addparent1(b);
	disppath(b);
	
	DestroyBTree(b);
	return 1;
}
