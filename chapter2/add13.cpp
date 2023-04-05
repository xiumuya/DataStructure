#include "linklist.cpp"

void Move(LinkNode *&L)
{	LinkNode *p=L->next,*pre=p;
	while (p!=NULL)
	{	if (p->data<0)
		{	pre->next=p->next;
			p->next=L->next;
			L->next=p;
			p=pre->next;
		}
		else
		{	pre=p;
			p=p->next;
		}
	}
}

int main()
{
	LinkNode *L;
	ElemType a[]={1,3,-4,6,2,1,-2,3,5};
	CreateListR(L,a,9);
	printf("L:");DispList(L);
	Move(L);
	printf("L:");DispList(L);
	DestroyList(L);
	return 1;
}