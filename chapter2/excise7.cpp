#include "linklist.cpp"
void Reverse(LinkNode *&L)
{	LinkNode *p=L->next,*q;
	L->next=NULL;
	while (p!=NULL)				//ɨ�����еĽڵ�
	{	q=p->next;				//q��ʱ����p�ڵ�ĺ�̽ڵ�
		p->next=L->next;		//���ǽ�p�ڵ���Ϊ�׽ڵ����
		L->next=p;
		p=q;					//��pָ����һ���ڵ�
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