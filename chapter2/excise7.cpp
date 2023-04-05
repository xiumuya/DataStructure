#include "linklist.cpp"
void Reverse(LinkNode *&L)
{	LinkNode *p=L->next,*q;
	L->next=NULL;
	while (p!=NULL)				//扫描所有的节点
	{	q=p->next;				//q临时保存p节点的后继节点
		p->next=L->next;		//总是将p节点作为首节点插入
		L->next=p;
		p=q;					//让p指向下一个节点
	}
}

int main()
{
	LinkNode *L;
	int n=10;
	ElemType a[]={1,3,2,9,0,4,7,6,5,8};
	CreateListR(L,a,n);
	printf("L:");DispList(L);
	Reverse(L);
	printf("L:");DispList(L);
	DestroyList(L);
	return 1;
}