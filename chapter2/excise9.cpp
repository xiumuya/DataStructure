#include "linklist.cpp"

void Insertbeforex(LinkNode *&L,ElemType x)
{	LinkNode *p=L->next,*pre=L;
	LinkNode *maxp=p,*maxpre=L,*s;
	while (p!=NULL)
	{	if (maxp->data<p->data)
		{	maxp=p;
			maxpre=pre;
		}
		pre=p; p=p->next;
	}
	s=(LinkNode *)malloc(sizeof(LinkNode));
	s->data=x;
	s->next=maxpre->next;
	maxpre->next=s;
}


int main()
{
	LinkNode *L;
	int n=4;
	ElemType a[]={10,2,3,4};
	CreateListR(L,a,n);
	printf("L:");DispList(L);
	Insertbeforex(L,20);
	printf("L:");DispList(L);
	DestroyList(L);
	return 1;
}