#include "linklist.cpp"

void Sort(LinkNode *&L)		//�Ե�����L�ݼ�����
{	LinkNode *p,*q,*pre;
	p=L->next->next;		//pָ���2�����ݽڵ�
	L->next->next=NULL;
	while (p!=NULL)
	{	q=p->next;
		pre=L;
		while (pre->next!=NULL && pre->next->data>p->data)
			pre=pre->next;
		p->next=pre->next;	//�ڽڵ�pre֮�����p�ڵ�
		pre->next=p;
		p=q;
	}
}

void fun(LinkNode *&L)			//��ɱ�����㷨
{	printf("����ǰ������L:"); 
	DispList(L);				//���û��������㷨
	Sort(L);
	printf("���������L:"); 
	DispList(L);				//���û��������㷨
	printf("�ͷŵ�����L\n");
	DestroyList(L);				//���û��������㷨
}

int main()
{
	LinkNode *L;
	int n=8;
	ElemType a[]={1,2,3,4,5,6,7,8};
	CreateListR(L,a,n);
	fun(L);
	return 1;
}