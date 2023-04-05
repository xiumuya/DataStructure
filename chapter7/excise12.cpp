#include "btree.cpp"
typedef char SqBTree[MaxSize];
void Ctree(BTNode *b,SqBTree a,int i)
{	if (b!=NULL)
	{	a[i]=b->data;
		Ctree(b->lchild,a,2*i);
		Ctree(b->rchild,a,2*i+1);
	}
	else a[i]='#';
}

int LeafNodes(SqBTree t,int i)
{	//i的初值为1
	int num1,num2,num=0;
	if (i<MaxSize)
	{	if (t[i]!='#')
		{	if (t[2*i]=='#' && t[2*i+1]=='#')
				num++;			//叶子结点个数增1
			else
			{	num1=LeafNodes(t,2*i);
				num2=LeafNodes(t,2*i+1);
				num+=num1+num2;
			}
			return num;
		}
		else return 0;
	}
	else return 0;
}


int main()
{	BTNode *b;
	CreateBTree(b,"A(B(D(,G)),C(E,F))");
	printf("二叉树:");DispBTree(b);printf("\n");
	SqBTree a;
	Ctree(b,a,1);
	printf("a: ");
	for(int i=1;i<10;i++)
		printf("%c",a[i]);
	printf("\n");
	printf("叶子结点个数=%d\n",LeafNodes(a,1));

	DestroyBTree(b);
	return 1;
}
