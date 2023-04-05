#include "linklist.cpp"		//单链表的基本运算算法

int count(LinkNode *L)
{
	if (L==NULL)
		return 0;
	else
		return count(L->next)+1;
} 

int main()
{
	LinkNode *L;
	int n=8;
	ElemType a[]={1,2,3,4,5,6,7,8};
	CreateListR(L,a,n);
	printf("count:%d\n",count(L->next));
	DestroyList(L);
	return 1;
}