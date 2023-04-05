#include "btree.cpp"	//二叉树基本运算算法
void LongPath(BTNode *b,ElemType path[],int pathlen,ElemType longpath[],
	int &longpathlen)	//pathlen和longpathlen的初值为0
{
	if (b==NULL)
	{	if (pathlen>longpathlen)	//若当前路径更长,将路径保存在longpath中
		{	for (int i=pathlen-1;i>=0;i--)
				longpath[i]=path[i];
			longpathlen=pathlen;
		}
	}
	else
	{	path[pathlen]=b->data;		//将当前节点放入路径中
		pathlen++;					//路径长度增1
		LongPath(b->lchild,path,pathlen,longpath,longpathlen);
			//递归扫描左子树
		LongPath(b->rchild,path,pathlen,longpath,longpathlen);
			//递归扫描右子树
	}
}


int main()
{
	BTNode *b;
	CreateBTree(b,"A(B(D,E(G,H)),C(,F(I)))");	//图7.11的二叉树
	printf("b:"); DispBTree(b); printf("\n");

	ElemType path[MaxSize],longpath[MaxSize];
	int longpathlen=0;

	LongPath(b,path,0,longpath,longpathlen);

	printf("第一条最长逆路径长度:%d\n",longpathlen);
	printf("第一条最长逆路径:");
	for (int i=longpathlen-1;i>=0;i--)
		printf("%c ",longpath[i]);
	printf("\n");

	DestroyBTree(b);
	return 1;
}
