#include "seqlist.cpp"   //˳�����������㷨

void Binsert(RecType R[],int &n,RecType x)
{	int low=0,high=n-1,mid,pos,i;
	bool find=false;
	while (low<=high && !find)	//���ֲ���
	{	mid=(low+high)/2;
		if (x.key<R[mid].key)
			high=mid-1;
		else if (x.key>R[mid].key)
			low=mid+1;
		else 
		{	i=mid;
			find=true;
		}
	}
	if (find)				//������ֵͬ��Ԫ��,���ڸ�mid������Ԫ��
		pos=mid;
	else 					//��δ����ֵͬ��Ԫ��,���ڸ�high+1������Ԫ��
		pos=high+1;
	for (i=n-1;i>=pos;i--)	//R[pos..n-1]������һλ
		R[i+1]=R[i];
	R[pos]=x;				//����Ԫ��x
	n++;					//Ԫ�ظ�������1
}


int main()
{
	KeyType keys[]={1,3,5,7,9,11,13,15,17};
	int n=9;
	RecType R[MAXL];
	CreateList(R,keys,n);
	printf("R:"); DispList(R,n);
	KeyType k;
	RecType x;
	while (true)
	{
		printf("k(����-1����):"); scanf("%d",&k);
		if (k==-1) break;
		x.key=k;
		Binsert(R,n,x);
		printf("R:"); DispList(R,n);
	}

	return 1;
}