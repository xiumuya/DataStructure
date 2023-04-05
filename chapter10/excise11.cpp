#include "seqlist.cpp"			//˳�����������㷨

void DBubbleSort(RecType R[],int n)	//��R[0..n-1]�����������˫��ð������
{	int i=0,j;
	bool exchange=true;			//exchange��ʶ�����Ƿ������Ԫ�ؽ���
	while (exchange) 
	{	exchange=false;
		for (j=n-i-1;j>i;j--)
			if (R[j].key<R[j-1].key)	//�ɺ���ǰð��СԪ��
			{	exchange=true;
				swap(R[j],R[j-1]);		//R[j]��R[j-1]����
			}
		for (j=i;j<n-i-1;j++)
			if (R[j].key>R[j+1].key)  	//��ǰ���ð�ݴ�Ԫ��
			{	exchange=true;
				swap(R[j],R[j+1]);		//R[j]��R[j+1]����
			}
		if (!exchange) return;
		i++;
	}
}
int main()
{
	RecType R[MAXL];
	int n=10;
	int a[]={2,7,10,6,1,5,9,4,3,8};
	CreateList(R,a,n);
	printf("����ǰR:"); DispList(R,n);
	DBubbleSort(R,n);
	printf("�����R:"); DispList(R,n);
	return 1;
}


