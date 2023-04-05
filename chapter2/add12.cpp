#include "linklist.cpp"

LinkNode *Findlist(LinkNode *str1,LinkNode *str2)
{
	int m,n;
	LinkNode *p,*q;
	m=ListLength(str1);			//求单链表str1的长度m
	n=ListLength(str2);			//求单链表str2的长度n
	for (p=str1;m>n;m--)		//若m大，则str1后移m-n+1个节点
		p=p->next;
	for (q=str2;m<n;n--)		//若n大，则str1后移n-m+1个节点
		q=q->next;
	while (p->next!=NULL && p->next!=q->next)
	{	p=p->next;				//p、q两步后移找第一个指针值相等的节点
		q=q->next;
	}
	return p->next;
}
