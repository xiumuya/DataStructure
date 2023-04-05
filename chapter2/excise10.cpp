#include "linklist.cpp"

void Sort(LinkNode *&L)		//对单链表L递减排序
{	LinkNode *p,*q,*pre;
	p=L->next->next;		//p指向第2个数据节点
	L->next->next=NULL;
	while (p!=NULL)
	{	q=p->next;
		pre=L;
		while (pre->next!=NULL && pre->next->data>p->data)
			pre=pre->next;
		p->next=pre->next;	//在节点pre之后插入p节点
		pre->next=p;
		p=q;
	}
}

void fun(LinkNode *&L)			//完成本题的算法
{	printf("排序前单链表L:"); 
	DispList(L);				//调用基本运算算法
	Sort(L);
	printf("排序后单链表L:"); 
	DispList(L);				//调用基本运算算法
	printf("释放单链表L\n");
	DestroyList(L);				//调用基本运算算法
}

int main()
{
	LinkNode *L;
	int n=8;
	ElemType a[]={1,2,3,4,5,6,7,8};
	CreateListR(L,a,n);
	fun(L);
	return 1;
}