//双链表运算算法
#include <stdio.h>
#include <malloc.h>
typedef int ElemType;
typedef struct DNode		//定义双链表节点类型
{
	ElemType data;
	struct DNode *prior;	//指向前驱节点
	struct DNode *next;		//指向后继节点
	int freq;				//用于2.11题
} DLinkNode;
void CreateListF(DLinkNode *&L,ElemType a[],int n)
//头插法建双链表
{
	DLinkNode *s;int i;
	L=(DLinkNode *)malloc(sizeof(DLinkNode));  	//创建头节点
	L->prior=L->next=NULL;
	for (i=0;i<n;i++)
	{	
		s=(DLinkNode *)malloc(sizeof(DLinkNode));//创建新节点
		s->data=a[i];
		s->next=L->next;			//将节点s插在原开始节点之前,头节点之后
		if (L->next!=NULL) L->next->prior=s;
		L->next=s;s->prior=L;
	}
}
void CreateListR(DLinkNode *&L,ElemType a[],int n)
//尾插法建双链表
{
	DLinkNode *s,*r;int i;
	L=(DLinkNode *)malloc(sizeof(DLinkNode));  	//创建头节点
	L->prior=L->next=NULL;
	r=L;					//r始终指向终端节点,开始时指向头节点
	for (i=0;i<n;i++)
	{	
		s=(DLinkNode *)malloc(sizeof(DLinkNode));//创建新节点
		s->data=a[i];
		s->freq=0;					//用于2.11题
		r->next=s;s->prior=r;	//将节点s插入节点r之后
		r=s;
	}
	r->next=NULL;				//尾节点next域置为NULL
}
void InitList(DLinkNode *&L)
{
	L=(DLinkNode *)malloc(sizeof(DLinkNode));  	//创建头节点
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
		printf("%d[%d] ",p->data,p->freq);		//用于练习题
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
	if (p==NULL)				//未找到第i-1个节点
		return false;
	else						//找到第i-1个节点p
	{
		s=(DLinkNode *)malloc(sizeof(DLinkNode));	//创建新节点s
		s->data=e;	
		s->next=p->next;		//将节点s插入到节点p之后
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
	if (p==NULL)				//未找到第i-1个节点
		return false;
	else						//找到第i-1个节点p
	{
		q=p->next;				//q指向要删除的节点
		if (q==NULL) 
			return false;		//不存在第i个节点
		e=q->data;
		p->next=q->next;		//从单链表中删除*q节点
		if (p->next!=NULL) p->next->prior=p;
		free(q);				//释放q节点
		return true;
	}
}
