//循环双链表运算算法
#include <stdio.h>
#include <malloc.h>
typedef int ElemType;
typedef struct DNode		//定义双链表节点类型
{
	ElemType data;
	struct DNode *prior;	//指向前驱节点
	struct DNode *next;		//指向后继节点
} DLinkNode;
void CreateListF(DLinkNode *&L,ElemType a[],int n)
//头插法建立循环双链表
{
	DLinkNode *s;int i;
	L=(DLinkNode *)malloc(sizeof(DLinkNode));  	//创建头节点
	L->next=NULL;
	for (i=0;i<n;i++)
	{	
		s=(DLinkNode *)malloc(sizeof(DLinkNode));//创建新节点
		s->data=a[i];
		s->next=L->next;			//将节点s插在原开始节点之前,头节点之后
		if (L->next!=NULL) L->next->prior=s;
		L->next=s;s->prior=L;
	}
	s=L->next;	
	while (s->next!=NULL)			//查找尾节点,由s指向它
		s=s->next;
	s->next=L;						//尾节点next域指向头节点
	L->prior=s;						//头节点的prior域指向尾节点

}
void CreateListR(DLinkNode *&L,ElemType a[],int n)
//尾插法建立循环双链表
{
	DLinkNode *s,*r;int i;
	L=(DLinkNode *)malloc(sizeof(DLinkNode));  //创建头节点
	L->next=NULL;
	r=L;					//r始终指向尾节点,开始时指向头节点
	for (i=0;i<n;i++)
	{	
		s=(DLinkNode *)malloc(sizeof(DLinkNode));//创建新节点
		s->data=a[i];
		r->next=s;s->prior=r;	//将节点s插入节点r之后
		r=s;
	}
	r->next=L;				//尾节点next域指向头节点
	L->prior=r;				//头节点的prior域指向尾节点
}
void InitList(DLinkNode *&L)
{
	L=(DLinkNode *)malloc(sizeof(DLinkNode));  	//创建头节点
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
	if (L->next!=L)		//双链表不为空表时
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
	else				//双链表为空表时
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
	if (p->next==L)					//原双链表为空表时
	{	
		s=(DLinkNode *)malloc(sizeof(DLinkNode));	//创建新节点s
		s->data=e;
		p->next=s;s->next=p;
		p->prior=s;s->prior=p;
		return true;
	}
	else if (i==1)					//原双链表不为空表但i=1时
	{
		s=(DLinkNode *)malloc(sizeof(DLinkNode));	//创建新节点s
		s->data=e;
		s->next=p->next;p->next=s;	//将节点s插入到节点p之后
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
		if (p==L)				//未找到第i-1个节点
			return false;
		else					//找到第i-1个节点*p
		{
			s=(DLinkNode *)malloc(sizeof(DLinkNode));	//创建新节点s
			s->data=e;	
			s->next=p->next;	//将节点s插入到节点p之后
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
	if (p->next!=L)					//原双链表不为空表时
	{	
		if (i==1)					//i==1时
		{	
			q=L->next;				//删除第1个节点
			e=q->data;
			L->next=q->next;
			q->next->prior=L;
			free(q);
			return true;
		}
		else						//i不为1时
		{	
			p=L->next;
			while (j<i-2 && p!=NULL)		
			{
				j++;
				p=p->next;
			}
			if (p==NULL)				//未找到第i-1个节点
				return false;
			else						//找到第i-1个节点p
			{
				q=p->next;				//q指向要删除的节点
				if (q==NULL) return 0;	//不存在第i个节点
				e=q->data;
				p->next=q->next;		//从单链表中删除q节点
				if (p->next!=NULL) p->next->prior=p;
				free(q);				//释放q节点
				return true;
			}
		}
	}
	else return false;					//原双链表为空表时
}
