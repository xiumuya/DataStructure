#include "seqlist.cpp"			//˳�����������㷨

int partition(RecType R[],int s,int t)	//һ�˻���
{	int i=s,j=t;
	RecType tmp=R[i];			//��R[i]Ϊ��׼
	while (i<j)  				//�����˽������м�ɨ��,ֱ��i=jΪֹ
	{	while (j>i && R[j].key>=tmp.key)
			j--;				//��������ɨ��,��һ��С��tmp.key��R[j]
		R[i]=R[j];			//�ҵ�������R[j],����R[i]��
		while (i<j && R[i].key<=tmp.key)
			i++;				//��������ɨ��,��һ������tmp.key��R[i]
		R[j]=R[i];			//�ҵ�������R[i],����R[j]��
	}
	R[i]=tmp;
	return i;
}

void QuickSort1(RecType R[],int n)		//��R[0..n-1]���п�������
{	int i,low,high,top=-1;
	struct 
	{	int low,high;
	} St[MAXL];
	RecType tmp;
	top++;								//��ջ
	St[top].low=0; St[top].high=n-1;	
	while (top>-1)						//ջ����ȡ��һ�������н��л���
	{
		low=St[top].low;high=St[top].high;	//��ջ
		top--;
		if (low<high)					//���������ٴ�������Ԫ�ص����
		{
			i=partition(R,low,high);
			top++;
			St[top].low=low;St[top].high=i-1;
			top++;
			St[top].low=i+1;St[top].high=high;
		}
	}
}

int main()
{
	RecType R[MAXL];
	int n=10;
	int a[]={1,2,3,4,5,10,9,8,7,5};
	//int a[]={2,7,10,6,1,5,9,4,3,8};
	CreateList(R,a,n);
	printf("����ǰR:"); DispList(R,n);

	QuickSort1(R,n);
	
	printf("�����R:"); DispList(R,n);
	return 1;
}


