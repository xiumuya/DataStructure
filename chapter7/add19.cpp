#include "btree.cpp"

BTNode* ancestor(BTNode *b,char x,char y)		//非递归后序遍历求x和y的最近公共祖先 
{	BTNode* St[MaxSize],*p,*r;
	int top=-1,i;								//栈顶指针top置初值
	bool flag,findx=false,findy=false;
	BTNode* anorx[MaxSize];
	BTNode* anory[MaxSize];
	int cx=0,cy=0;
	p=b;
	do
	{	while (p!=NULL)						//将p的所有左结点进栈
		{	top++;St[top]=p;
			p=p->lchild;
		}
		r=NULL;								//r指向当前结点的前一个已访问的结点
		flag=true;							//flag为真表示正在处理栈顶结点
		while (top!=-1 && flag)
		{
			p=St[top];					//取出当前的栈顶结点p
			if (p->rchild==r)			//右子树不存在或已被访问,访问之
			{
				if (p->data==x)			//要访问的结点为结点x
				{
					findx=true;
					for (i=0;i<=top;i++) 	//将根到结点x的路径存入anorx[0..cx-1]中
						anorx[cx++]=St[i];
				}
			 	else if (p->data==y)	//要访问的结点为结点y
				{
					findy=true;
					for (i=0;i<=top;i++) 	//将根到结点y的路径存入anory[0..cy-1]中
						anory[cy++]=St[i];
				}
				if(findx && findy)
				{
					i=0;
					while(i<cx && i<cy && anorx[i]->data==anory[i]->data) 
						i++;						//找anorx和anory中最后一个相同的结点
					return anorx[i-1];
				}
				top--;
				r=p;				//r指向刚访问过的结点
			}
			else
			{	p=p->rchild;			//p指向右孩子结点 
				flag=false;				//表示当前不是处理栈顶结点
			}
		}
	} while (top!=-1);
	return NULL;
}

BTNode *ancestor1(BTNode *b,char x,char y)
{
	BTNode *p,*q;
	if (b==NULL) return NULL;
	if (b->data==x || b->data==y)
		return b;
	p=ancestor1(b->lchild,x,y);
	q=ancestor1(b->rchild,x,y);
	if (p!=NULL && q!=NULL) return b;
	if (p!=NULL) return p;
	if (q!=NULL) return q;
	return NULL;
}

int main()
{
	BTNode *b;
	CreateBTree(b,"A(B(D,E(G,H)),C(,F(I)))");	//图7.11的二叉树
	printf("b:"); DispBTree(b); printf("\n");
	char x='D',y='I';
	BTNode *p=ancestor1(b,x,y);
	
	printf("%c和%c的LCA=%c\n",x,y,p->data);

	DestroyBTree(b);
	return 1;
}
