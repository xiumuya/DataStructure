#include "seqlist.cpp"   //˳�����������㷨

void swap(RecType &x,RecType &y)
{
	RecType tmp=x;
	x=y; y=tmp;
}

int SeqSearch2(RecType R[],int n,KeyType k)
{	int i=0;
	while (i<n && R[i].key!=k)
		i++;
	if (i<n)				//�ҵ��˹ؼ���Ϊk��Ԫ��R[i]
	{
		if (i>0)			//i>0ʱR[i]ǰ��һλ
		{
			swap(R[i], R[i-1]);
			return i;		//����R[i]��λ�õ��߼����
		}
		else return i+1;	//i=0ʱ�����ƶ�R[i]������1
	}
	return 0;
}

int main()
{
	KeyType keys[]={1,2,3,4,5,6,7,8,9};
	int n=9,i;
	RecType R[MAXL];
	CreateList(R,keys,n);
	printf("R:"); DispList(R,n);

	KeyType k;
	while (true)
	{
		printf("k(����-1����):"); scanf("%d",&k);
		if (k==-1) break;
		i=SeqSearch2(R,n,k);
		if (i>0)
			printf("���:R[%d]=%d\n",i,k);
		else
			printf("δ�ҵ�%d\n",k);
		printf("R:"); DispList(R,n);
	}

	return 1;
}