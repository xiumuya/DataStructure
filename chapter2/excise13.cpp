#include "cdlinklist.cpp"

void Insert(DLinkNode *&ha, DLinkNode *&hb,int i)
{	DLinkNode *p=ha->next,*post;
	int lena=1,j;
	while (p->next!=ha)				//���ha�ĳ���lena
	{	lena++;
		p=p->next;
	}
	if (i==0)						//��hb���뵽ha��ǰ��
	{	p=hb->prior;				//pָ��hb��β�ڵ�
		p->next=ha->next;			//���ڵ�p����ha���׽ڵ�ǰ��
		ha->next->prior=p;
		ha->next=hb->next;
		hb->next->prior=ha; 		//��haͷ�ڵ���hb���׽ڵ�������
	}
	else if (i<lena)				//��hb���뵽ha�м�
	{	j=1;
		p=ha->next;
		while (j<i)					//��ha�в��ҵ�i���ڵ�p
		{	p=p->next;
			j++;
		}
		post=p->next;				//postָ��p�ڵ�ĺ�̽ڵ�
		p->next=hb->next;			//��hb���׽ڵ���Ϊp�ڵ�ĺ�̽ڵ�	
		hb->next->prior=p;			
		hb->prior->next=post;		//��post�ڵ���Ϊhbβ�ڵ�ĺ�̽ڵ�
		post->prior=hb->prior;
	}
	else							//��hb����ha֮��
	{	ha->prior->next=hb->next; 	//ha->priorָ��ha��β�ڵ�
		hb->next->prior=ha->prior;
		hb->prior->next=ha;
		ha->prior=hb->prior;
	}
	free(hb);						//�ͷ�hbͷ�ڵ�
}

int main()
{
	ElemType a[]={1,2,3,4};
	ElemType b[]={5,6,7,8,9,10};
	DLinkNode *L1,*L2;
	CreateListR(L1,a,4);
	printf("L1:");DispList(L1);
	CreateListR(L2,b,6);
	printf("L2:");DispList(L2);
	Insert(L1,L2,10);
	printf("L1:");DispList(L1);
	DestroyList(L1);
	return 1;
}
