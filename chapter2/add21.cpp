#include "linklist.cpp"

void Delnodes(LinkNode *&L,ElemType min,ElemType max)
{
	LinkNode *p=L->next,*pre=L;		//pre指向节点p的前趋节点
	while (p!=NULL && p->data<=min)	//查找刚刚大于min的节点p
	{	pre=p;						//pre、p同步后移
		p=p->next;
	}
	while (p!=NULL && p->data<max)	//删除所有小于max的节点
	{
		pre->next=p->next;
		free(p);
		p=pre->next;
	}
}


int main()
{
	LinkNode *L;
	ElemType a[]={1,2,3,4,5,6,7,8,9};
	CreateListR(L,a,9);
	printf("L:");DispList(L);
	Delnodes(L,0,10);
	printf("L:");DispList(L);
	DestroyList(L);
	return 1;
}