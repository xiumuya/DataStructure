//�����������㷨
#include <stdio.h>
#include <malloc.h>
typedef int ElemType;
typedef struct LNode  		//����������ڵ�����
{
	ElemType data;
	struct LNode *next;		//ָ���̽ڵ�
} LinkNode;
void CreateListF(LinkNode *&L,ElemType a[],int n)
//ͷ�巨����������
{
	LinkNode *s;int i;
	L=(LinkNode *)malloc(sizeof(LinkNode));  	//����ͷ�ڵ�
	L->next=NULL;
	for (i=0;i<n;i++)
	{	
		s=(LinkNode *)malloc(sizeof(LinkNode));//�����½ڵ�
		s->data=a[i];
		s->next=L->next;			//���ڵ�s����ԭ��ʼ�ڵ�֮ǰ,ͷ�ڵ�֮��
		L->next=s;
	}
}
void CreateListR(LinkNode *&L,ElemType a[],int n)
//β�巨����������
{
	LinkNode *s,*r;int i;
	L=(LinkNode *)malloc(sizeof(LinkNode));  	//����ͷ�ڵ�
	L->next=NULL;
	r=L;					//rʼ��ָ���ն˽ڵ�,��ʼʱָ��ͷ�ڵ�
	for (i=0;i<n;i++)
	{	
		s=(LinkNode *)malloc(sizeof(LinkNode));//�����½ڵ�
		s->data=a[i];
		r->next=s;			//���ڵ�s���뵽�ڵ�r֮��
		r=s;
	}
	r->next=NULL;			//�ն˽ڵ�next����ΪNULL
}
void InitList(LinkNode *&L)
{
	L=(LinkNode *)malloc(sizeof(LinkNode));  	//����ͷ�ڵ�
	L->next=NULL;
}
void DestroyList(LinkNode *&L)
{
	LinkNode *p=L,*q=p->next;
	while (q!=NULL)
	{	free(p);
		p=q;
		q=p->next;
	}
	free(p);	//��ʱqΪNULL,pָ��β�ڵ�,�ͷ���
}
bool ListEmpty(LinkNode *L)
{
	return(L->next==NULL);
}
int ListLength(LinkNode *L)
{
	LinkNode *p=L;int i=0;
	while (p->next!=NULL)
	{	i++;
		p=p->next;
	}
	return(i);
}
void DispList(LinkNode *L)
{
	LinkNode *p=L->next;
	while (p!=NULL)
	{	printf("%d ",p->data);
		p=p->next;
	}
	printf("\n");
}
bool GetElem(LinkNode *L,int i,ElemType &e)
{
	int j=0;
	LinkNode *p=L;
	while (j<i && p!=NULL)
	{	j++;
		p=p->next;
	}
	if (p==NULL)			//�����ڵ�i�����ݽڵ�
		return false;
	else					//���ڵ�i�����ݽڵ�
	{	e=p->data;
		return true;
	}
}
int LocateElem(LinkNode *L,ElemType e)
{
	LinkNode *p=L->next;
	int n=1;
	while (p!=NULL && p->data!=e)
	{	p=p->next;
		n++;
	}
	if (p==NULL)
		return(0);
	else
		return(n);
}
bool ListInsert(LinkNode *&L,int i,ElemType e)
{
	int j=0;
	LinkNode *p=L,*s;
	while (j<i-1 && p!=NULL) //���ҵ�i-1���ڵ�
	{	j++;
		p=p->next;
	}
	if (p==NULL)								//δ�ҵ�λ��Ϊi-1�Ľڵ�
		return false;
	else										//�ҵ�λ��Ϊi-1�Ľڵ�p
	{	s=(LinkNode *)malloc(sizeof(LinkNode));	//�����½ڵ�s
		s->data=e;
		s->next=p->next;						//��s���뵽p֮��
		p->next=s;
		return true;
	}
}
bool ListDelete(LinkNode *&L,int i,ElemType &e)
{
	int j=0;
	LinkNode *p=L,*q;
	while (j<i-1 && p!=NULL)	//���ҵ�i-1���ڵ�
	{	j++;
		p=p->next;
	}
	if (p==NULL)				//δ�ҵ�λ��Ϊi-1�Ľڵ�
		return false;
	else						//�ҵ�λ��Ϊi-1�Ľڵ�p
	{	q=p->next;				//qָ��Ҫɾ���Ľڵ�
		if (q==NULL) 
			return false;		//�������ڵ�i���ڵ�,����false
		e=q->data;
		p->next=q->next;		//�ӵ�������ɾ��q�ڵ�
		free(q);				//�ͷ�q�ڵ�
		return true;
	}
}
