#include "linklist.cpp"			//��������������㷨

void SelSort(LinkNode *&L)
{
	LinkNode *p=L->next,*q,*minp;
	ElemType tmp;
	while(p->next!=NULL)			//�������������ݽڵ�
    {
		minp=p;						//minpָ��p�ڵ㿪ʼ����С�ڵ�
		q=p->next;
		while (q!=NULL)				//����С�ڵ�minp
		{
			if (q->data<minp->data)
				minp=q;
			q=q->next;
		}
		if (minp!=p)				//��minp�ڵ㲻��p�ڵ㣬���������ڵ�ֵ
		{
			tmp=minp->data;
			minp->data=p->data;
			p->data=tmp;
		}
		p=p->next;
	}
}

int main()
{
	LinkNode *L;
	int n=10;
	int a[]={1,2,3,4,5,10,9,8,7,5};
	//int a[]={2,7,10,6,1,5,9,4,3,8};
	CreateListR(L,a,n);
	printf("����ǰR:"); DispList(L);

	SelSort(L);
	
	printf("�����L:"); DispList(L);

	DestroyList(L);

	return 1;
}


