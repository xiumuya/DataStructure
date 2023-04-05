//循环单链表运算算法
#include <stdio.h>
#include <malloc.h>
typedef int ElemType;
typedef struct LNode		//定义单链表节点类型
{
	ElemType data;
    struct LNode *next;
} LinkNode;
void CreateListF(LinkNode *&L,ElemType a[],int n)
//头插法建立循环单链表
{
	LinkNode *s;int i;
	L=(LinkNode *)malloc(sizeof(LinkNode));  	//创建头节点
	L->next=NULL;
	for (i=0;i<n;i++)
	{	
		s=(LinkNode *)malloc(sizeof(LinkNode));//创建新节点
		s->data=a[i];
		s->next=L->next;			//将节点s插在原开始节点之前,头节点之后
		L->next=s;
	}
	s=L->next;	
	while (s->next!=NULL)			//查找尾节点,由s指向它
		s=s->next;
	s->next=L;						//尾节点next域指向头节点

}
void CreateListR(LinkNode *&L,ElemType a[],int n)
//尾插法建立循环单链表
{
	LinkNode *s,*r;int i;
	L=(LinkNode *)malloc(sizeof(LinkNode));  	//创建头节点
	L->next=NULL;
	r=L;					//r始终指向终端节点,开始时指向头节点
	for (i=0;i<n;i++)
	{	
		s=(LinkNode *)malloc(sizeof(LinkNode));//创建新节点
		s->data=a[i];
		r->next=s;			//将节点s插入节点r之后
		r=s;
	}
	r->next=L;				//尾节点next域指向头节点
}
void InitList(LinkNode *&L)
{
	L=(LinkNode *)malloc(sizeof(LinkNode));	//创建头节点
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
	if (L->next!=L)		//单链表不为空表时
	{
		if (i==1)
		{
			e=L->next->data;
			return true;
		}
		else			//i不为1时
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
	else				//单链表为空表时
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
	if (p->next==L || i==1)		//原单链表为空表或i==1时
	{
		s=(LinkNode *)malloc(sizeof(LinkNode));	//创建新节点s
		s->data=e;								
		s->next=p->next;		//将节点s插入到节点p之后
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
		if (p==L)				//未找到第i-1个节点
			return false;
		else					//找到第i-1个节点p
		{
			s=(LinkNode *)malloc(sizeof(LinkNode));	//创建新节点s
			s->data=e;								
			s->next=p->next;						//将节点s插入到节点p之后
			p->next=s;
			return true;
		}
	}
}
bool ListDelete(LinkNode *&L,int i,ElemType &e)
{
	int j=0;
	LinkNode *p=L,*q;
	if (p->next!=L)					//原单链表不为空表时
	{
		if (i==1)					//i==1时
		{
			q=L->next;				//删除第1个节点
			e=q->data;
			L->next=q->next;
			free(q);
			return true;
		}
		else						//i不为1时
		{
			p=L->next;
			while (j<i-2 && p!=L)
			{
				j++;
				p=p->next;
			}
			if (p==L)				//未找到第i-1个节点
				return false;
			else					//找到第i-1个节点p
			{
				q=p->next;			//q指向要删除的节点
				e=q->data;
				p->next=q->next;	//从单链表中删除q节点
				free(q);			//释放q节点
				return true;
			}
		}
	}
	else return false;
}
