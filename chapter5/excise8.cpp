#include "linklist.cpp"		//单链表的基本运算算法

void traverse(LinkNode *L)
{
	if (L==NULL) return;
	printf("%d ",L->data);
	traverse(L->next);
}
void traverseR(LinkNode *L)
{
	if (L==NULL) return;
	traverseR(L->next);
	printf("%d ",L->data);
}


int main()
{
	LinkNode *L;
	int n=8;
	ElemType a[]={1,2,3,4,5,6,7,8};
	CreateListR(L,a,n);

	printf(" traverse:"); traverse(L->next); printf("\n");
	printf("traverseR:"); traverseR(L->next); printf("\n");

	DestroyList(L);
	return 1;
}