//ѭ��˫���������㷨
#include <stdio.h>
#include <malloc.h>
typedef int ElemType;
typedef struct DNode		//����˫����ڵ�����
{
	ElemType data;
	struct DNode *prior;	//ָ��ǰ���ڵ�
	struct DNode *next;		//ָ���̽ڵ�
} DLinkNode;
void CreateListF(DLinkNode *&L,ElemType a[],int n)
//ͷ�巨����ѭ��˫����
{
	DLinkNode *s;int i;
	L=(DLinkNode *)malloc(sizeof(DLinkNode));  	//����ͷ�ڵ�
	L->next=NULL;
	for (i=0;i<n;i++)
	{	
		s=(DLinkNode *)malloc(sizeof(DLinkNode));//�����½ڵ�
		s->data=a[i];
		s->next=L->next;			//���ڵ�s����ԭ��ʼ�ڵ�֮ǰ,ͷ�ڵ�֮��
		if (L->next!=NULL) L->next->prior=s;
		L->next=s;s->prior=L;
	}
	s=L->next;	
	while (s->next!=NULL)			//����β�ڵ�,��sָ����
		s=s->next;
	s->next=L;						//β�ڵ�next��ָ��ͷ�ڵ�
	L->prior=s;						//ͷ�ڵ��prior��ָ��β�ڵ�

}
void CreateListR(DLinkNode *&L,ElemType a[],int n)
//β�巨����ѭ��˫����
{
	DLinkNode *s,*r;int i;
	L=(DLinkNode *)malloc(sizeof(DLinkNode));  //����ͷ�ڵ�
	L->next=NULL;
	r=L;					//rʼ��ָ��β�ڵ�,��ʼʱָ��ͷ�ڵ�
	for (i=0;i<n;i++)
	{	
		s=(DLinkNode *)malloc(sizeof(DLinkNode));//�����½ڵ�
		s->data=a[i];
		r->next=s;s->prior=r;	//���ڵ�s����ڵ�r֮��
		r=s;
	}
	r->next=L;				//β�ڵ�next��ָ��ͷ�ڵ�
	L->prior=r;				//ͷ�ڵ��prior��ָ��β�ڵ�
}
void InitList(DLinkNode *&L)
{
	L=(DLinkNode *)malloc(sizeof(DLinkNode));  	//����ͷ�ڵ�
	L->prior=L->next=L;
}
void DestroyList(DLinkNode *&L)
{
	DLinkNode *p=L,*q=p->next;
	while (q!=L)
	{
		free(p);
		p=q;
		q=p->next;
	}
	free(p);
}
bool ListEmpty(DLinkNode *L)
{
	return(L->next==L);
}
int ListLength(DLinkNode *L)
{
	DLinkNode *p=L;
	int i=0;
	while (p->next!=L)
	{
		i++;
		p=p->next;
	}
	return(i);
}
void DispList(DLinkNode *L)
{
	DLinkNode *p=L->next;
	while (p!=L)
	{
		printf("%d ",p->data);
		p=p->next;
	}
	printf("\n");
}
bool GetElem(DLinkNode *L,int i,ElemType &e)
{
	int j=0;
	DLinkNode *p;
	if (L->next!=L)		//˫����Ϊ�ձ�ʱ
	{
		if (i==1)
		{
			e=L->next->data;
			return true;
		}
		else			//i��Ϊ1ʱ
		{
			p=L->next;
			while (j<i-1 && p!=L)
			{
				j++;
				p=p->next;
			}
			if (p==L)
				return false;
			else
			{
				e=p->data;
				return true;
			}
		}
	}
	else				//˫����Ϊ�ձ�ʱ
		return 0;
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
	if (p->next==L)					//ԭ˫����Ϊ�ձ�ʱ
	{	
		s=(DLinkNode *)malloc(sizeof(DLinkNode));	//�����½ڵ�s
		s->data=e;
		p->next=s;s->next=p;
		p->prior=s;s->prior=p;
		return true;
	}
	else if (i==1)					//ԭ˫����Ϊ�ձ�i=1ʱ
	{
		s=(DLinkNode *)malloc(sizeof(DLinkNode));	//�����½ڵ�s
		s->data=e;
		s->next=p->next;p->next=s;	//���ڵ�s���뵽�ڵ�p֮��
		s->next->prior=s;s->prior=p;
		return true;
	}
	else
	{	
		p=L->next;
		while (j<i-2 && p!=L)
		{	j++;
			p=p->next;
		}
		if (p==L)				//δ�ҵ���i-1���ڵ�
			return false;
		else					//�ҵ���i-1���ڵ�*p
		{
			s=(DLinkNode *)malloc(sizeof(DLinkNode));	//�����½ڵ�s
			s->data=e;	
			s->next=p->next;	//���ڵ�s���뵽�ڵ�p֮��
			if (p->next!=NULL) p->next->prior=s;
			s->prior=p;
			p->next=s;
			return true;
		}
	}
}
bool ListDelete(DLinkNode *&L,int i,ElemType &e)
{
	int j=0;
	DLinkNode *p=L,*q;
	if (p->next!=L)					//ԭ˫����Ϊ�ձ�ʱ
	{	
		if (i==1)					//i==1ʱ
		{	
			q=L->next;				//ɾ����1���ڵ�
			e=q->data;
			L->next=q->next;
			q->next->prior=L;
			free(q);
			return true;
		}
		else						//i��Ϊ1ʱ
		{	
			p=L->next;
			while (j<i-2 && p!=NULL)		
			{
				j++;
				p=p->next;
			}
			if (p==NULL)				//δ�ҵ���i-1���ڵ�
				return false;
			else						//�ҵ���i-1���ڵ�p
			{
				q=p->next;				//qָ��Ҫɾ���Ľڵ�
				if (q==NULL) return 0;	//�����ڵ�i���ڵ�
				e=q->data;
				p->next=q->next;		//�ӵ�������ɾ��q�ڵ�
				if (p->next!=NULL) p->next->prior=p;
				free(q);				//�ͷ�q�ڵ�
				return true;
			}
		}
	}
	else return false;					//ԭ˫����Ϊ�ձ�ʱ
}
