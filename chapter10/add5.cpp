#include "seqlist.cpp"			//˳�����������㷨
#define MaxSize 100

int partition(RecType R[],int s,int t)	//һ�˻���
{	int i=s,j=t;
	RecType tmp=R[i];			//��R[i]Ϊ��׼
	while (i<j)  				//�����˽������м�ɨ��,ֱ��i=jΪֹ
	{	while (j>i && R[j].key>=tmp.key)
			j--;				//��������ɨ��,��һ��С��tmp.key��R[j]
		R[i]=R[j];				//�ҵ�������R[j],����R[i]��
		while (i<j && R[i].key<=tmp.key)
			i++;				//��������ɨ��,��һ������tmp.key��R[i]
		R[j]=R[i];				//�ҵ�������R[i],����R[j]��
	}
	R[i]=tmp;
	return i;
}

void QuickSort2(RecType R[],int n)	//��R[0..n-1]���п�������
{	int i,low,high;
	int front=-1,rear=-1;			//���ס���βָ��
	struct 
	{	int low;
		int high;
	} Qu[MaxSize];
	rear++;								//����
	Qu[rear].low=0;Qu[rear].high=n-1;
	while (front!=rear)					//�Ӳ���ȡ��һ����������л���
	{	front=(front+1)%MaxSize;
		low=Qu[front].low;high=Qu[front].high;	//����
		i=partition(R,low,high);
		rear=(rear+1)%MaxSize;
		Qu[rear].low=low;Qu[rear].high=i-1;//���������
		rear=(rear+1)%MaxSize;
		Qu[rear].low=i+1;Qu[rear].high=high;//���������
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

	QuickSort2(R,n);
	
	printf("�����R:"); DispList(R,n);
	return 1;
}


