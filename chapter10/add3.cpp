#include "seqlist.cpp"			//˳�����������㷨

void OeSort(RecType R[],int n)
{	int i;
	bool sorted=false;
	while (!sorted)
	{	sorted=true;
		for (i=0;i<n-1;i+=2)		//����ɨ��
			if (R[i].key>R[i+1].key)
			{	sorted=false;
				swap(R[i],R[i+1]);
			}
		for (i=1;i<n-1;i+=2)		//ż��ɨ��
			if (R[i].key>R[i+1].key)
			{	sorted=false;
				swap(R[i],R[i+1]);
			}
	}
}

int main()
{
	RecType R[MAXL];
	int n=10;
	int a[]={2,7,10,6,1,5,9,4,3,8};
	CreateList(R,a,n);
	printf("����ǰR:"); DispList(R,n);

	OeSort(R,n);
	
	printf("�����R:"); DispList(R,n);
	return 1;
}


