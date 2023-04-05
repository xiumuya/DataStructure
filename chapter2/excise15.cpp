#include "linklist.cpp"

void Sub1(LinkNode *ha,LinkNode *hb,LinkNode *&hc)
{	LinkNode *prea=ha,*pa=ha->next,*pb,*p,*post;
	hc=ha;					//ha的头节点作为hc的头节点
	while (pa!=NULL)			//删除A中属于B的节点
	{	pb=hb->next;
		while (pb!=NULL && pb->data!=pa->data)
			pb=pb->next;
		if (pb!=NULL)			//pa->data在B中,从A中删除节点pa
		{	prea->next=pa->next;
			free(pa);
			pa=prea->next;
		}
		else
		{	prea=pa;			//prea和pa同步后移
			pa=pa->next;
		}
	}
	p=hb; post=hb->next;		//释放B中所有节点
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
	hc=ha;							//ha的头节点作为hc的头节点
	rc=hc;
	while (pa!=NULL && pb!=NULL)
	{	if (pa->data<pb->data)		//将较小的节点pa链到hc之后
		{	rc->next=pa;
			rc=pa;
			prea=pa;				//prea和p同步后移
			pa=pa->next;
		}
		else if (pa->data>pb->data)	//删除较大的节点pb
		{	preb->next=pb->next;
			free(pb);
			pb=preb->next;
		}
		else						//删除相等的pa节点和pb节点
		{	prea->next=pa->next;
			free(pa);
			pa=prea->next;
			preb->next=pb->next;
			free(pb);
			pb=preb->next;
		}
	}
	while (pb!=NULL)				//删除pb余下的节点
	{	preb->next=pb->next;
		free(pb);
		pb=preb->next;
	}
	free(hb);						//删除hb的头节点
	rc->next=NULL;					//尾节点next域置为空
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
