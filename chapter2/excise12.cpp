#include "clinklist.cpp"

void Merge(LinkNode *ha, LinkNode *hb, LinkNode *&hc)
{	LinkNode *p=ha->next;
	hc=ha;
	while (p->next!=ha)	//找到ha的尾节点p
		p=p->next;
	p->next=hb->next;	//将节点p的next指向hb的首节点
	while (p->next!=hb) 
		p=p->next;		//找到hb的尾节点p
	p->next=hc;			//构成循环单链表
	free(hb);			//释放hb单链表的头节点
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
