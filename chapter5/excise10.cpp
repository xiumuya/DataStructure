#include "linklist.cpp"		//单链表的基本运算算法

ElemType maxnode(LinkNode *L)
{
	ElemType max;
	if (L->next==NULL)
		return L->data;
	max=maxnode(L->next);
	if (max>L->data) return max;
	else return L->data;
}
ElemType minnode(LinkNode *L)
{
	ElemType min;
	if (L->next==NULL)
		return L->data;
	min=minnode(L->next);
	if (min>L->data) return L->data;
	else return min;
}

int main()
{
	LinkNode *L;
	int n=8;
	ElemType a[]={1,2,3,2,5,3,2,8};
	CreateListR(L,a,n);
	printf("L:"); DispList(L);

	printf("Max:%d\n",maxnode(L->next));
	printf("Min:%d\n",minnode(L->next));

	DestroyList(L);
	return 1;
}