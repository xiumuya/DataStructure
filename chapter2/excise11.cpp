#include "dlinklist.cpp"

bool LocateNode(DLinkNode *h,ElemType x)
{	DLinkNode *p=h->next,*pre;
	while (p!=NULL && p->data!=x)
		p=p->next;							//找data域值为x的节点p
	if (p==NULL)							//未找到的情况
		return false;
	else									//找到的情况
	{	p->freq++;							//频度增1
		pre=p->prior;						//节点pre为节点p的前驱节点
		while (pre!=h && pre->freq<p->freq) 
		{	p->prior=pre->prior;
			p->prior->next=p;				//交换节点p和节点pre的位置
			pre->next=p->next;
			if (pre->next!=NULL)			//若p节点不是尾节点时
				pre->next->prior=pre;
			p->next=pre;pre->prior=p;
			pre=p->prior;					//q重指向节点p的前驱节点
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
		printf("(-1退出)x:"); scanf("%d",&x);
		if (x==-1) break;
		LocateNode(L,x);
		printf("L:");DispList(L);
	}
	DestroyList(L);
	return 1;
}
