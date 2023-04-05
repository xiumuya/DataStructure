#include "linklist.cpp"

void Delnodes(LinkNode *&L,ElemType min,ElemType max)
{
	LinkNode *p=L->next,*pre=L;		//preָ��ڵ�p��ǰ���ڵ�
	while (p!=NULL && p->data<=min)	//���Ҹոմ���min�Ľڵ�p
	{	pre=p;						//pre��pͬ������
		p=p->next;
	}
	while (p!=NULL && p->data<max)	//ɾ������С��max�Ľڵ�
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