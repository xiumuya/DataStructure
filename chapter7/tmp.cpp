#include "btree.cpp"
BTNode* parent(BTNode *b,char x)
{	if(b==NULL) return NULL;
	if(b->lchild!=NULL && b->lchild->data==x)		//结点x是结点b的左孩子
		return b;
	if(b->rchild!=NULL && b->rchild->data==x)		//结点x是结点b的右孩子
		return b;
	BTNode* p=parent(b->lchild,x);					//在左子树中查找 
	if(p!=NULL)										//在左子树中找到双亲p时返回p 
		return p;
	else
		return parent(b->rchild,x);					//返回在右子树中的查找结果 
}

BTNode* parent1(BTNode *b,char x)
{
	BTNode* qu[MaxSize];
	int front=0,rear=0;
	if(b==NULL || b->data==x)
		return NULL; 
	rear=(rear+1)%MaxSize;				//根结点进队 
	qu[rear]=b;
	while(front!=rear)					//队不空时循环
	{
		front=(front+1)%MaxSize;		//出队结点p 
		BTNode* p=qu[front];
		if(p->lchild!=NULL)				//结点p存在左孩子 
		{
			if(p->lchild->data==x)		//左孩子是结点x 
				return p;
			else
			{
				rear=(rear+1)%MaxSize;	//左孩子进队 
				qu[rear]=p->lchild;
			}
		}
		if(p->rchild!=NULL)				//结点p存在右孩子 
		{
			if(p->rchild->data==x)		//右孩子是结点x 
				return p;
			else
			{
				rear=(rear+1)%MaxSize;	//右孩子进队 
				qu[rear]=p->rchild;
			}
		}
	}
}


int main()
{	BTNode *b;
	CreateBTree(b,"A(B(D(,G)),C(E,F))");
	printf("二叉树b:");DispBTree(b);printf("\n");
	char x='G';
	BTNode* p=parent1(b,x);
	if(p!=NULL)
		printf("%c的双亲是%c\n",x,p->data);
	else
		printf("%c的双亲不存在\n",x);
	DestroyBTree(b);
	return 1;
}
