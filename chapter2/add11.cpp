#include "linklist.cpp"

bool increase(LinkNode *L)
{
	LinkNode *p=L->next,*post;	//pָ���׽ڵ�
	post=p->next;				//postָ��p�ڵ�ĺ�̽ڵ�
	while (post!=NULL)
	{
		if (post->data>p->data)	//������������ж���һ���ڵ�
		{
			p=post;				//p��postͬ������
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