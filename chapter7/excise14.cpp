#include "btree.cpp"
void FindMinNode(BTNode *b,char &min)
{	if (b==NULL) return;
	if(b->data<min)
		min=b->data;
	FindMinNode(b->lchild,min);		//在左子树中找最小结点值
	FindMinNode(b->rchild,min); 	//在右子树中找最小结点值
}
char MinNode(BTNode *b)				//输出最小结点值
{	if (b!=NULL)
	{	char min=b->data;
		FindMinNode(b,min);
		return min;
	}
}

int main()
{	BTNode *b;
	CreateBTree(b,"A(B(D(,G)),C(E,F))");
	printf("二叉树:");DispBTree(b);printf("\n");
	printf("最小结点值=%c\n",MinNode(b));

	DestroyBTree(b);
	return 1;
}
