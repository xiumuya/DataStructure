#include "linklist.cpp"

void Union1(LinkNode *ha,LinkNode *hb,LinkNode *&hc)
{	LinkNode *pa=ha->next,*pb=hb->next,*pc,*rc;
	hc=(LinkNode *)malloc(sizeof(LinkNode));
	rc=hc;
	while (pa!=NULL)		//将A复制到C中
	{	pc=(LinkNode *)malloc(sizeof(LinkNode));
		pc->data=pa->data;
		rc->next=pc;
		rc=pc;
		pa=pa->next;
	}
	while (pb!=NULL)		//将B中不属于A的元素复制到C中
	{	pa=ha->next;
		while (pa!=NULL && pa->data!=pb->data)
			pa=pa->next;
		if (pa==NULL)		//pb->data不在A中
		{	pc=(LinkNode *)malloc(sizeof(LinkNode));
			pc->data=pb->data;
			rc->next=pc;
			rc=pc;
		}
		pb=pb->next;
	}
	rc->next=NULL;
}

void Union2(LinkNode *ha,LinkNode *hb,LinkNode *&hc)
{	LinkNode *pa=ha->next,*pb=hb->next,*pc,*rc;
	hc=(LinkNode *)malloc(sizeof(LinkNode));
	rc=hc;
	while (pa!=NULL && pb!=NULL)
	{	if (pa->data<pb->data)		//将较小的节点pa复制到hc中
		{	pc=(LinkNode *)malloc(sizeof(LinkNode));
			pc->data=pa->data;
			rc->next=pc;
			rc=pc;
			pa=pa->next;
		}
		else if (pa->data>pb->data)	//将较小的节点pb复制到hc中
		{	pc=(LinkNode *)malloc(sizeof(LinkNode));
			pc->data=pb->data;
			rc->next=pc;
			rc=pc;
			pb=pb->next;
		}
		else						//相等的节点只复制一个到hc中
		{	pc=(LinkNode *)malloc(sizeof(LinkNode));
			pc->data=pa->data;
			rc->next=pc;
			rc=pc;
			pa=pa->next;
			pb=pb->next;
		}
	}
	if (pb!=NULL) pa=pb;			//让pa指向没有扫描完的单链表节点
	while (pa!=NULL)				
	{	pc=(LinkNode *)malloc(sizeof(LinkNode));
		pc->data=pa->data;
		rc->next=pc;
		rc=pc;
		pa=pa->next;
	}
	rc->next=NULL;				//尾节点next域置为空
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
	Union2(L1,L2,L3);
	printf("L3:");DispList(L3);
	DestroyList(L1);
	DestroyList(L2);
	DestroyList(L3);
	return 1;
}
