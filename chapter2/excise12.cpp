#include "clinklist.cpp"

void Merge(LinkNode *ha, LinkNode *hb, LinkNode *&hc)
{	LinkNode *p=ha->next;
	hc=ha;
	while (p->next!=ha)	//�ҵ�ha��β�ڵ�p
		p=p->next;
	p->next=hb->next;	//���ڵ�p��nextָ��hb���׽ڵ�
	while (p->next!=hb) 
		p=p->next;		//�ҵ�hb��β�ڵ�p
	p->next=hc;			//����ѭ��������
	free(hb);			//�ͷ�hb�������ͷ�ڵ�
}

int main()
{
	ElemType a[]={1,2,3};
	ElemType b[]={6,7,8,9};
	LinkNode *ha,*hb,*hc;
	CreateListR(ha,a,3);
	printf("ha:");DispList(ha);
	CreateListR(hb,b,4);
	printf("hb:");DispList(hb);
	Merge(ha,hb,hc);
	printf("hc:");DispList(hc);
	DestroyList(hc);
	return 1;
}
