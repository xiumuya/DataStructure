//ѭ�������������㷨
#include <stdio.h>
#include <malloc.h>
typedef int ElemType;
typedef struct LNode		//���嵥����ڵ�����
{
	ElemType data;
    struct LNode *next;
} LinkNode;
void CreateListF(LinkNode *&L,ElemType a[],int n)
//ͷ�巨����ѭ��������
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
	s=L->next;	
	while (s->next!=NULL)			//����β�ڵ�,��sָ����
		s=s->next;
	s->next=L;						//β�ڵ�next��ָ��ͷ�ڵ�

}
void CreateListR(LinkNode *&L,ElemType a[],int n)
//β�巨����ѭ��������
{
	LinkNode *s,*r;int i;
	L=(LinkNode *)malloc(sizeof(LinkNode));  	//����ͷ�ڵ�
	L->next=NULL;
	r=L;					//rʼ��ָ���ն˽ڵ�,��ʼʱָ��ͷ�ڵ�
	for (i=0;i<n;i++)
	{	
		s=(LinkNode *)malloc(sizeof(LinkNode));//�����½ڵ�
		s->data=a[i];
		r->next=s;			//���ڵ�s����ڵ�r֮��
		r=s;
	}
	r->next=L;				//β�ڵ�next��ָ��ͷ�ڵ�
}
void InitList(LinkNode *&L)
{
	L=(LinkNode *)malloc(sizeof(LinkNode));	//����ͷ�ڵ�
	L->next=L;
}
void DestroyList(LinkNode *&L)
{
	LinkNode *p=L,*q=p->next;
	while (q!=L)
	{
		free(p);
		p=q;
		q=p->next;
	}
	free(p);
}
bool ListEmpty(LinkNode *L)
{
	return(L->next==L);
}
int ListLength(LinkNode *L)
{
	LinkNode *p=L;int i=0;
	while (p->next!=L)
	{
		i++;
		p=p->next;
	}
	return(i);
}
void DispList(LinkNode *L)
{
	LinkNode *p=L->next;
	while (p!=L)
	{
		printf("%d ",p->data);
		p=p->next;
	}
	printf("\n");
}
bool GetElem(LinkNode *L,int i,ElemType &e)
{
	int j=0;
	LinkNode *p;
	if (L->next!=L)		//������Ϊ�ձ�ʱ
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
	else				//������Ϊ�ձ�ʱ
		return false;
}
int LocateElem(LinkNode *L,ElemType e)
{
	LinkNode *p=L->next;
	int n=1;
	while (p!=L && p->data!=e)
	{
		p=p->next;
		n++;
	}
	if (p==L)
		return(0);
	else
		return(n);
}
bool ListInsert(LinkNode *&L,int i,ElemType e)
{
	int j=0;
	LinkNode *p=L,*s;
	if (p->next==L || i==1)		//ԭ������Ϊ�ձ��i==1ʱ
	{
		s=(LinkNode *)malloc(sizeof(LinkNode));	//�����½ڵ�s
		s->data=e;								
		s->next=p->next;		//���ڵ�s���뵽�ڵ�p֮��
		p->next=s;
		return true;
	}
	else
	{
		p=L->next;
		while (j<i-2 && p!=L)
		{
			j++;
			p=p->next;
		}
		if (p==L)				//δ�ҵ���i-1���ڵ�
			return false;
		else					//�ҵ���i-1���ڵ�p
		{
			s=(LinkNode *)malloc(sizeof(LinkNode));	//�����½ڵ�s
			s->data=e;								
			s->next=p->next;						//���ڵ�s���뵽�ڵ�p֮��
			p->next=s;
			return true;
		}
	}
}
bool ListDelete(LinkNode *&L,int i,ElemType &e)
{
	int j=0;
	LinkNode *p=L,*q;
	if (p->next!=L)					//ԭ������Ϊ�ձ�ʱ
	{
		if (i==1)					//i==1ʱ
		{
			q=L->next;				//ɾ����1���ڵ�
			e=q->data;
			L->next=q->next;
			free(q);
			return true;
		}
		else						//i��Ϊ1ʱ
		{
			p=L->next;
			while (j<i-2 && p!=L)
			{
				j++;
				p=p->next;
			}
			if (p==L)				//δ�ҵ���i-1���ڵ�
				return false;
			else					//�ҵ���i-1���ڵ�p
			{
				q=p->next;			//qָ��Ҫɾ���Ľڵ�
				e=q->data;
				p->next=q->next;	//�ӵ�������ɾ��q�ڵ�
				free(q);			//�ͷ�q�ڵ�
				return true;
			}
		}
	}
	else return false;
}
