#include <stdio.h>
#define MaxSize 100
typedef char ElemType;
typedef ElemType SqBinTree[MaxSize];

ElemType ancestor(SqBinTree a,int i,int j)
{	int p=i,q=j;
	while (p!=q)
	{ 
		if (p>q)
			p=p/2;		//向上找i的祖先
		else
			q=q/2;		//向上找j的祖先
	} 
	return a[p];
}

int main()
{	
	SqBinTree bt="#ABCDE#F##GH##I##";
	int i=2,j=7;
	printf("最近的公共祖先:%c\n",ancestor(bt,i,j));
	return 1;
}
