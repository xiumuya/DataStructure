#include "bst.cpp"   //�������������������㷨

bool Findseq(BSTNode *bt,int k,int a[],int n)
{	BSTNode *p=bt;
	int i=0;
	if (a[n-1]!=k)						//δ�ҵ�k������false
		return false;
	while (i<n && p!=NULL)
	{
		if (p->key!=a[i])				//�����ȣ���ʾa����k�Ĳ�������
			return false;				//����false
		if (k<p->key) p=p->lchild;		//���������в���
		else if (k>p->key) p=p->rchild;	//���������в���
		i++;							//��������ָ����һ���ؼ���
	}
	if (p!=NULL) return true;			//�ҵ���k������true
	else return false;					//δ�ҵ�k������false
}


int main()
{
	BSTNode *bt;
	KeyType keys[]={5,2,3,4,1,6,8,7,9};
	int m=9;
	bt=CreateBST(keys,m);		//��������������
	printf("BST:"); DispBST(bt); printf("\n");
	int n=4;
	KeyType a[]={5,2,3,9};
	KeyType k=9;
	if (Findseq(bt,k,a,n))
		printf("Yes\n");
	else
		printf("No\n");

	DestroyBST(bt);
	return 1;
}