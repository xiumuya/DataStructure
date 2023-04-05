#include "bst.cpp"   //�������������������㷨

void Output(BSTNode *bt,KeyType k)
{
	if (bt==NULL)
		return;
	if (bt->rchild!=NULL)
		Output(bt->rchild,k);
	if (bt->key>=k)
		printf("%d ",bt->key);
	if (bt->lchild!=NULL)
		Output(bt->lchild,k);
}


int main()
{
	BSTNode *bt;
	KeyType keys[]={5,2,3,4,1,6,8,7,9};
	int n=9;
	bt=CreateBST(keys,n);		//��������������
	printf("BST:"); DispBST(bt); printf("\n");
	KeyType k;
	while (true)
	{
		printf("k(����-1����):"); scanf("%d",&k);
		if (k==-1) break;
		Output(bt,k);  printf("\n");
	}

	DestroyBST(bt);
	return 1;
}