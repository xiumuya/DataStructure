#include "seqlist.cpp"   //˳�����������㷨

int SeqSearch1(RecType R[],int n,KeyType k,int i)
//��ʼ����ʱi=0
{	if (i>=n)
		return 0;
	else if (R[i].key==k)
		return i+1;
	else
		return(SeqSearch1(R,n,k,i+1));
}


int main()
{
	KeyType keys[]={1,2,3,4,5,6,7,8,9};
	int n=9,i;
	RecType R[MAXL];
	CreateList(R,keys,n);
	printf("R:"); DispList(R,n);

	KeyType k=9;
	i=SeqSearch1(R,n,k,0);
	if (i>0)
		printf("���:R[%d]=%d\n",i,k);
	else
		printf("δ�ҵ�%d\n",k);

	return 1;
}