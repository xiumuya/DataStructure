#include "linklist.cpp"

LinkNode *Findlist(LinkNode *str1,LinkNode *str2)
{
	int m,n;
	LinkNode *p,*q;
	m=ListLength(str1);			//������str1�ĳ���m
	n=ListLength(str2);			//������str2�ĳ���n
	for (p=str1;m>n;m--)		//��m����str1����m-n+1���ڵ�
		p=p->next;
	for (q=str2;m<n;n--)		//��n����str1����n-m+1���ڵ�
		q=q->next;
	while (p->next!=NULL && p->next!=q->next)
	{	p=p->next;				//p��q���������ҵ�һ��ָ��ֵ��ȵĽڵ�
		q=q->next;
	}
	return p->next;
}
