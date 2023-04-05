#include "seqlist.cpp"			//˳�����������㷨

KeyType QuickSelect(RecType R[],int s,int t,int k)	//��R[s..t]�������ҵ�kС��Ԫ��
{	int i=s,j=t;
	RecType tmp;
	if (s<t) 					//���������ٴ���2��Ԫ�ص����
	{	tmp=R[s];				//������ĵ�1����¼��Ϊ��׼
		while (i!=j)			//���������˽������м�ɨ��,ֱ��i=jΪֹ
		{	while (j>i && R[j].key>=tmp.key) 
				j--;			//��������ɨ��,�ҵ�1���ؼ���С��tmp��R[j]
			R[i]=R[j];			//��R[j]ǰ�Ƶ�R[i]��λ��
			while (i<j && R[i].key<=tmp.key) 
				i++;			//��������ɨ��,�ҵ�1���ؼ��ִ���tmp��R[i]
			R[j]=R[i];			//��R[i]���Ƶ�R[j]��λ��
		}
		R[i]=tmp;
		if (k-1==i) return R[i].key;
		else if (k-1<i) return QuickSelect(R,s,i-1,k);	//���������еݹ����
		else return QuickSelect(R,i+1,t,k);				//���������еݹ����
	}
	else if (s==t && s==k-1)	//������ֻ��һ��Ԫ����ΪR[k-1]
		return R[k-1].key;
	else
		return -1;				//k���󷵻�����ֵ-1
}

int main()
{
	RecType R[MAXL];
	int n=10;
	int a[]={2,7,10,6,1,5,9,4,3,8};
	CreateList(R,a,n);
	printf("����ǰR:"); DispList(R,n);

	int k=20;
	printf("��%dС��Ԫ�عؼ���:%d\n",k,QuickSelect(R,0,n-1,k));
	return 1;
}


