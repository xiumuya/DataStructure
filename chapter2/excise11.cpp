#include "dlinklist.cpp"

bool LocateNode(DLinkNode *h,ElemType x)
{	DLinkNode *p=h->next,*pre;
	while (p!=NULL && p->data!=x)
		p=p->next;							//��data��ֵΪx�Ľڵ�p
	if (p==NULL)							//δ�ҵ������
		return false;
	else									//�ҵ������
	{	p->freq++;							//Ƶ����1
		pre=p->prior;						//�ڵ�preΪ�ڵ�p��ǰ���ڵ�
		while (pre!=h && pre->freq<p->freq) 
		{	p->prior=pre->prior;
			p->prior->next=p;				//�����ڵ�p�ͽڵ�pre��λ��
			pre->next=p->next;
			if (pre->next!=NULL)			//��p�ڵ㲻��β�ڵ�ʱ
				pre->next->prior=pre;
			p->next=pre;pre->prior=p;
			pre=p->prior;					//q��ָ��ڵ�p��ǰ���ڵ�
		}
		return true;
	}
}

int main()
{
	int x;
	ElemType a[]={1,2,3,4,5,6,7,8,9,10};
	DLinkNode *L;
	CreateListR(L,a,10);
	printf("L:");DispList(L);
	while (true)
	{
		printf("(-1�˳�)x:"); scanf("%d",&x);
		if (x==-1) break;
		LocateNode(L,x);
		printf("L:");DispList(L);
	}
	DestroyList(L);
	return 1;
}
