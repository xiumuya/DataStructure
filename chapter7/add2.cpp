#include <stdio.h>
#define MaxSize 30
typedef char ElemType;
typedef ElemType SqBinTree[MaxSize];

void PreOrder1(SqBinTree a,int i)
//a数组存储二叉树（大小为MaxSize）,i初值为1
{
	if (i<MaxSize)
	{
		if (a[i]!='#')
		{	printf("%c ",a[i]);		//访问根节点
			PreOrder1(a,2*i);		//遍历左子树
			PreOrder1(a,2*i+1);		//遍历右子树
		}
	}
}

void PreOrder2(SqBinTree a) //a数组存储二叉树（大小为MaxSize）
{	int St[MaxSize],top=-1,i=1;
	top++;						//根节点1进栈
	St[top]=i;
	while (top>-1)
	{
		i=St[top];top--;		//出栈节点i
		printf("%c ",a[i]);
		if (2*i+1<MaxSize && a[2*i+1]!='#')	//右孩子进栈
		{	top++;
			St[top]=2*i+1;
		}
		if (2*i<MaxSize && a[2*i]!='#')		//左孩子进栈
		{	top++;
			St[top]=2*i;
		}
	}
}

int main()
{	
	SqBinTree bt="#ABCDE#F##GH##I##";
	printf("  先序遍历的递归算法:"); PreOrder1(bt,1);printf("\n");
	printf("先序遍历的非递归算法:"); PreOrder2(bt);printf("\n");
	return 1;
}
