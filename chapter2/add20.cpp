#include "linklist.cpp"

void merge(LinkNode *A,LinkNode *B,LinkNode *&C)
{
	LinkNode *p=A->next,*q=B->next,*r;
	free(B);
	C=A;
	C->next=NULL;						//�½���һ���յĵ�����C
	while (p!=NULL && q!=NULL)
	{
		if (p->data<q->data)			//��p�ڵ����ͷ�巨���뵽C��
		{
			r=p->next;
			p->next=C->next;
			C->next=p;
			p=r;
		}
		else							//��q�ڵ����ͷ�巨���뵽C��
		{
			r=q->next;
			q->next=C->next;
			C->next=q;
			q=r;
		}
	}
	if (q!=NULL) p=q;
	while (p!=NULL)						//�����µĽڵ����ͷ�巨���뵽C��
	{
		r=p->next;
		p->next=C->next;
		C->next=p;
		p=r;
	}
}

int main(void)
{
	LinkNode *L1,*L2,*L3;
	ElemType a[]={1,3,4,6};
	CreateListR(L1,a,4);
	printf("L1:");DispList(L1);

	ElemType b[]={1,2,5};
	CreateListR(L2,b,3);
	printf("L2:");DispList(L2);

	merge(L1,L2,L3);
	printf("L3:");DispList(L3);

	DestroyList(L3);
	return 1;
}