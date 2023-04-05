#include "linklist.cpp"		//单链表的基本运算算法

void del(LinkNode *&L,ElemType x)
{
	LinkNode *t;
	if (L==NULL) return;
	if (L->data==x)
	{
		t=L;
		L=L->next;
		free(t);
		return;
	}
	del(L->next,x);
}
void delall(LinkNode *&L,ElemType x)
{
	LinkNode *t;
	if (L==NULL) return;
	if (L->data==x)
	{
		t=L;
		L=L->next;
		free(t);
	}
	delall(L->next,x);
}



int main()
{
	LinkNode *L1,*L2;
	int n=8;
	ElemType a[]={1,2,3,2,5,3,2,8};
	CreateListR(L1,a,n);
	CreateListR(L2,a,n);
	printf("L1:"); DispList(L1);
	printf("del:3\n"); del(L1->next,3);
	printf("L1:"); DispList(L1);

	printf("L2:"); DispList(L2);
	printf("delall:2\n"); delall(L2->next,2);
	printf("L2:"); DispList(L2);

	DestroyList(L1);
	DestroyList(L2);
	return 1;
}