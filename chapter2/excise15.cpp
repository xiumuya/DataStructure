#include "linklist.cpp"

void Sub1(LinkNode *ha,LinkNode *hb,LinkNode *&hc)
{	LinkNode *prea=ha,*pa=ha->next,*pb,*p,*post;
	hc=ha;					//ha��ͷ�ڵ���Ϊhc��ͷ�ڵ�
	while (pa!=NULL)			//ɾ��A������B�Ľڵ�
	{	pb=hb->next;
		while (pb!=NULL && pb->data!=pa->data)
			pb=pb->next;
		if (pb!=NULL)			//pa->data��B��,��A��ɾ���ڵ�pa
		{	prea->next=pa->next;
			free(pa);
			pa=prea->next;
		}
		else
		{	prea=pa;			//prea��paͬ������
			pa=pa->next;
		}
	}
	p=hb; post=hb->next;		//�ͷ�B�����нڵ�
	while (post!=NULL)
	{	free(p);
		p=post;
		post=post->next;
	}
	free(p);
}

void Sub2(LinkNode *ha,LinkNode *hb,LinkNode *&hc)
{	LinkNode *prea=ha,*pa=ha->next;
	LinkNode *preb=hb,*pb=hb->next;
	LinkNode *rc;
	hc=ha;							//ha��ͷ�ڵ���Ϊhc��ͷ�ڵ�
	rc=hc;
	while (pa!=NULL && pb!=NULL)
	{	if (pa->data<pb->data)		//����С�Ľڵ�pa����hc֮��
		{	rc->next=pa;
			rc=pa;
			prea=pa;				//prea��pͬ������
			pa=pa->next;
		}
		else if (pa->data>pb->data)	//ɾ���ϴ�Ľڵ�pb
		{	preb->next=pb->next;
			free(pb);
			pb=preb->next;
		}
		else						//ɾ����ȵ�pa�ڵ��pb�ڵ�
		{	prea->next=pa->next;
			free(pa);
			pa=prea->next;
			preb->next=pb->next;
			free(pb);
			pb=preb->next;
		}
	}
	while (pb!=NULL)				//ɾ��pb���µĽڵ�
	{	preb->next=pb->next;
		free(pb);
		pb=preb->next;
	}
	free(hb);						//ɾ��hb��ͷ�ڵ�
	rc->next=NULL;					//β�ڵ�next����Ϊ��
}


int main()
{
	LinkNode *L1,*L2,*L3;
	ElemType a[]={1,2,3,4};
	ElemType b[]={3,4,5,6,7,8,9};
	CreateListR(L1,a,4);
	printf("L1:");DispList(L1);
	CreateListR(L2,b,7);
	printf("L2:");DispList(L2);
	Sub1(L1,L2,L3);
	printf("L3:");DispList(L3);
	DestroyList(L3);
	return 1;
}
