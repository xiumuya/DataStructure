#include "linklist.cpp"

int MinLast(LinkNode *L)
{	LinkNode *p=L->next,*minp=p;
	int i=1,mini=i;
	while (p!=NULL)
	{	if (minp->data>=p->data)
		{	minp=p;
			mini=i;
		}
		i++;
		p=p->next;
	}
	return mini;
}

int main()
{
	LinkNode *L;
	ElemType a[]={2,3,1,5,1,9};
	CreateListR(L,a,6);
	printf("L:");DispList(L);
	printf("%d\n",MinLast(L)); 
	DestroyList(L);
	return 1;
}