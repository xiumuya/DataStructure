#include "btree.cpp"
void AllPath1(BTNode *b,ElemType path[],int pathlen)
{	//b为根节点时，pathlen初始值为0
	int i;
	if (b!=NULL)
	{	if (b->lchild==NULL && b->rchild==NULL)	//b为叶子节点
		{	printf("  %c到根节点逆路径: %c ",b->data,b->data);
			for (i=pathlen-1;i>=0;i--)
				printf("%c ",path[i]);
			printf("\n");
		}
		else
		{	path[pathlen]=b->data;			//将当前节点放入路径中
			pathlen++;						//路径长度增1
			AllPath1(b->lchild,path,pathlen);//递归扫描左子树
			AllPath1(b->rchild,path,pathlen);//递归扫描右子树
			pathlen--;						//恢复环境
		}
	}
}


int main()
{
	BTNode *b;
	CreateBTree(b,"A(B(D,E(G,H)),C(,F(I)))");	//图7.11的二叉树
	printf("b:"); DispBTree(b); printf("\n");
	ElemType path[MaxSize];
	AllPath1(b,path,0);
	DestroyBTree(b);
	return 1;
}
