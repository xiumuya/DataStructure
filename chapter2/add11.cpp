#include "linklist.cpp"

bool increase(LinkNode *L)
{
	LinkNode *p=L->next,*post;	//p指向首节点
	post=p->next;				//post指向p节点的后继节点
	while (post!=NULL)
	{
		if (post->data>p->data)	//若正序则继续判断下一个节点
		{
			p=post;				//p、post同步后移
			post=post->next;
		}
		else
			return false;
	}
	return true;
}


int main()
{
	LinkNode *L;
	ElemType a[]={2,1};
	CreateListR(L,a,2);
	printf("L:");DispList(L);
	printf("%d\n",increase(L)); 
	DestroyList(L);
	return 1;
}