#include"linklist.cpp"
void release(LinkNode *h)
{	if (h!=NULL)
	{	release(h->next);
		free(h);				//ÊÍ·Åh½áµã
	}
}
int main()
{
	LinkNode* h;
	InitList(h);
	ListInsert(h,1,1);
	ListInsert(h,2,3);
	ListInsert(h,2,2);

	printf("h: "); DispList(h);
	
	release(h->next);
	free(h);
	return 0;
}
	
