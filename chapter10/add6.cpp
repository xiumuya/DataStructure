#include "linklist.cpp"			//单链表基本运算算法

void SelSort(LinkNode *&L)
{
	LinkNode *p=L->next,*q,*minp;
	ElemType tmp;
	while(p->next!=NULL)			//至少有两个数据节点
    {
		minp=p;						//minp指向p节点开始的最小节点
		q=p->next;
		while (q!=NULL)				//找最小节点minp
		{
			if (q->data<minp->data)
				minp=q;
			q=q->next;
		}
		if (minp!=p)				//若minp节点不是p节点，交换两个节点值
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
	printf("排序前R:"); DispList(L);

	SelSort(L);
	
	printf("排序后L:"); DispList(L);

	DestroyList(L);

	return 1;
}


