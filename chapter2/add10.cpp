#include "linklist.cpp"

bool subseq(LinkNode *ha,LinkNode *hb)
{
	LinkNode *pa=ha->next,*pb,*pa1,*pb1;
	while (pa!=NULL)
	{
		pb=hb->next;		//pb指向hb的首节点
		pa1=pa; pb1=pb;
		while (pa1!=NULL && pb1!=NULL && pa1->data==pb1->data)
		{					//若相等，继续比较后续节点
			pa1=pa1->next;
			pb1=pb1->next;
		}
		if (pb1==NULL)		//匹配成功返回true
			return true;
		pa=pa->next;		//从ha的下一个节点继续匹配
	}
	return false;
}

int main()
{
	LinkNode *L1,*L2;
	ElemType a[]={1,3,4,6,2,1,2,3,5};
	CreateListR(L1,a,9);
	printf("L1:");DispList(L1);

	ElemType b[]={1,2,5};
	CreateListR(L2,b,3);
	printf("L2:");DispList(L2);

	printf("%d\n",subseq(L1,L2)); 
	DestroyList(L1);
	DestroyList(L2);
	return 1;
}