#include "cdlinklist.cpp"

void Insert(DLinkNode *&ha, DLinkNode *&hb,int i)
{	DLinkNode *p=ha->next,*post;
	int lena=1,j;
	while (p->next!=ha)				//求出ha的长度lena
	{	lena++;
		p=p->next;
	}
	if (i==0)						//将hb插入到ha的前面
	{	p=hb->prior;				//p指向hb的尾节点
		p->next=ha->next;			//将节点p链到ha的首节点前面
		ha->next->prior=p;
		ha->next=hb->next;
		hb->next->prior=ha; 		//将ha头节点与hb的首节点链起来
	}
	else if (i<lena)				//将hb插入到ha中间
	{	j=1;
		p=ha->next;
		while (j<i)					//在ha中查找第i个节点p
		{	p=p->next;
			j++;
		}
		post=p->next;				//post指向p节点的后继节点
		p->next=hb->next;			//将hb的首节点作为p节点的后继节点	
		hb->next->prior=p;			
		hb->prior->next=post;		//将post节点作为hb尾节点的后继节点
		post->prior=hb->prior;
	}
	else							//将hb链到ha之后
	{	ha->prior->next=hb->next; 	//ha->prior指向ha的尾节点
		hb->next->prior=ha->prior;
		hb->prior->next=ha;
		ha->prior=hb->prior;
	}
	free(hb);						//释放hb头节点
}

int main()
{
	ElemType a[]={1,2,3,4};
	ElemType b[]={5,6,7,8,9,10};
	DLinkNode *L1,*L2;
	CreateListR(L1,a,4);
	printf("L1:");DispList(L1);
	CreateListR(L2,b,6);
	printf("L2:");DispList(L2);
	Insert(L1,L2,10);
	printf("L1:");DispList(L1);
	DestroyList(L1);
	return 1;
}
