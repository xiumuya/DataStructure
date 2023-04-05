//单链表运算算法
#include <stdio.h>
#include <malloc.h>
typedef int ElemType;
typedef struct LNode  		//声明单链表节点类型
{
	ElemType data;
	struct LNode *next;		//指向后继节点
} LinkNode;
void CreateListF(LinkNode *&L,ElemType a[],int n)
//头插法建立单链表
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
}
void CreateListR(LinkNode *&L,ElemType a[],int n)
//尾插法建立单链表
{
	LinkNode *s,*r;int i;
	L=(LinkNode *)malloc(sizeof(LinkNode));  	//创建头节点
	L->next=NULL;
	r=L;					//r始终指向终端节点,开始时指向头节点
	for (i=0;i<n;i++)
	{	
		s=(LinkNode *)malloc(sizeof(LinkNode));//创建新节点
		s->data=a[i];
		r->next=s;			//将节点s插入到节点r之后
		r=s;
	}
	r->next=NULL;			//终端节点next域置为NULL
}
void InitList(LinkNode *&L)
{
	L=(LinkNode *)malloc(sizeof(LinkNode));  	//创建头节点
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
	free(p);	//此时q为NULL,p指向尾节点,释放它
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
	if (p==NULL)			//不存在第i个数据节点
		return false;
	else					//存在第i个数据节点
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
	while (j<i-1 && p!=NULL) //查找第i-1个节点
	{	j++;
		p=p->next;
	}
	if (p==NULL)								//未找到位序为i-1的节点
		return false;
	else										//找到位序为i-1的节点p
	{	s=(LinkNode *)malloc(sizeof(LinkNode));	//创建新节点s
		s->data=e;
		s->next=p->next;						//将s插入到p之后
		p->next=s;
		return true;
	}
}
bool ListDelete(LinkNode *&L,int i,ElemType &e)
{
	int j=0;
	LinkNode *p=L,*q;
	while (j<i-1 && p!=NULL)	//查找第i-1个节点
	{	j++;
		p=p->next;
	}
	if (p==NULL)				//未找到位序为i-1的节点
		return false;
	else						//找到位序为i-1的节点p
	{	q=p->next;				//q指向要删除的节点
		if (q==NULL) 
			return false;		//若不存在第i个节点,返回false
		e=q->data;
		p->next=q->next;		//从单链表中删除q节点
		free(q);				//释放q节点
		return true;
	}
}
