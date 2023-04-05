//˫���������㷨
#include <stdio.h>
#include <malloc.h>
typedef int ElemType;
typedef struct DNode		//����˫����ڵ�����
{
	ElemType data;
	struct DNode *prior;	//ָ��ǰ���ڵ�
	struct DNode *next;		//ָ���̽ڵ�
	int freq;				//����2.11��
} DLinkNode;
void CreateListF(DLinkNode *&L,ElemType a[],int n)
//ͷ�巨��˫����
{
	DLinkNode *s;int i;
	L=(DLinkNode *)malloc(sizeof(DLinkNode));  	//����ͷ�ڵ�
	L->prior=L->next=NULL;
	for (i=0;i<n;i++)
	{	
		s=(DLinkNode *)malloc(sizeof(DLinkNode));//�����½ڵ�
		s->data=a[i];
		s->next=L->next;			//���ڵ�s����ԭ��ʼ�ڵ�֮ǰ,ͷ�ڵ�֮��
		if (L->next!=NULL) L->next->prior=s;
		L->next=s;s->prior=L;
	}
}
void CreateListR(DLinkNode *&L,ElemType a[],int n)
//β�巨��˫����
{
	DLinkNode *s,*r;int i;
	L=(DLinkNode *)malloc(sizeof(DLinkNode));  	//����ͷ�ڵ�
	L->prior=L->next=NULL;
	r=L;					//rʼ��ָ���ն˽ڵ�,��ʼʱָ��ͷ�ڵ�
	for (i=0;i<n;i++)
	{	
		s=(DLinkNode *)malloc(sizeof(DLinkNode));//�����½ڵ�
		s->data=a[i];
		s->freq=0;					//����2.11��
		r->next=s;s->prior=r;	//���ڵ�s����ڵ�r֮��
		r=s;
	}
	r->next=NULL;				//β�ڵ�next����ΪNULL
}
void InitList(DLinkNode *&L)
{
	L=(DLinkNode *)malloc(sizeof(DLinkNode));  	//����ͷ�ڵ�
	L->prior=L->next=NULL;
}
void DestroyList(DLinkNode *&L)
{
	DLinkNode *p=L,*q=p->next;
	while (q!=NULL)
	{
		free(p);
		p=q;
		q=p->next;
	}
	free(p);
}
bool ListEmpty(DLinkNode *L)
{
	return(L->next==NULL);
}
int ListLength(DLinkNode *L)
{
	DLinkNode *p=L;
	int i=0;
	while (p->next!=NULL)
	{
		i++;
		p=p->next;
	}
	return(i);
}
void DispList(DLinkNode *L)
{
	DLinkNode *p=L->next;
	while (p!=NULL)
	{
		printf("%d[%d] ",p->data,p->freq);		//������ϰ��
		//printf("%d ",p->data);
		p=p->next;
	}
	printf("\n");
}
bool GetElem(DLinkNode *L,int i,ElemType &e)
{
	int j=0;
	DLinkNode *p=L;
	while (j<i && p!=NULL)
	{
		j++;
		p=p->next;
	}
	if (p==NULL)
		return false;
	else
	{
		e=p->data;
		return true;
	}
}
int LocateElem(DLinkNode *L,ElemType e)
{
	int n=1;
	DLinkNode *p=L->next;
	while (p!=NULL && p->data!=e)
	{
		n++;
		p=p->next;
	}
	if (p==NULL)
		return(0);
	else
		return(n);
}
bool ListInsert(DLinkNode *&L,int i,ElemType e)
{
	int j=0;
	DLinkNode *p=L,*s;
	while (j<i-1 && p!=NULL)
	{
		j++;
		p=p->next;
	}
	if (p==NULL)				//δ�ҵ���i-1���ڵ�
		return false;
	else						//�ҵ���i-1���ڵ�p
	{
		s=(DLinkNode *)malloc(sizeof(DLinkNode));	//�����½ڵ�s
		s->data=e;	
		s->next=p->next;		//���ڵ�s���뵽�ڵ�p֮��
		if (p->next!=NULL) 
			p->next->prior=s;
		s->prior=p;
		p->next=s;
		return true;
	}
}
bool ListDelete(DLinkNode *&L,int i,ElemType &e)
{
	int j=0;
	DLinkNode *p=L,*q;
	while (j<i-1 && p!=NULL)
	{
		j++;
		p=p->next;
	}
	if (p==NULL)				//δ�ҵ���i-1���ڵ�
		return false;
	else						//�ҵ���i-1���ڵ�p
	{
		q=p->next;				//qָ��Ҫɾ���Ľڵ�
		if (q==NULL) 
			return false;		//�����ڵ�i���ڵ�
		e=q->data;
		p->next=q->next;		//�ӵ�������ɾ��*q�ڵ�
		if (p->next!=NULL) p->next->prior=p;
		free(q);				//�ͷ�q�ڵ�
		return true;
	}
}
