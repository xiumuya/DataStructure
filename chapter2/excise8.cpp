#include "linklist.cpp"

ElemType Midnode(LinkNode *L)
{
	LinkNode *p=L->next,*q=p;
	while (p->next!=NULL && p->next->next!=NULL)
	{	p=p->next->next;
		q=q->next;
	}
	return q->data;
}


int main()
{
	LinkNode *L;
	int n=4;
	ElemType a[]={1,2,3,4};
	CreateListR(L,a,n);
	printf("L:");DispList(L);
	printf("中间位置的元素:%d\n",Midnode(L));
	DestroyList(L);
	return 1;
}