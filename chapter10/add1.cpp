#include "seqlist.cpp"			//˳�����������㷨

typedef struct
{	KeyType key;	//�ؼ���
	int no;			//���
} IndexType;		//��������

void CreateIndex(RecType R[],IndexType idx[],int n) //����R������idx
{
	IndexType tmp;
	int i,j;
	for (i=0;i<n;i++)			//����idx
	{
		idx[i].key=R[i].key;
		idx[i].no=i;
	}
	for (i=1;i<n;i++)			//��idx��key����
	{	if (idx[i].key<idx[i-1].key) 
		{	tmp=idx[i];
			j=i-1; 
			do
			{	idx[j+1]=idx[j]; 
				j--;
			}  while  (j>=0 && idx[j].key>tmp.key);
			idx[j+1]=tmp;
		} 
	}
}


int main()
{
	RecType R[MAXL];
	IndexType idx[MAXL];
	int n=10;
	int a[]={2,7,10,6,1,5,9,4,3,8};
	CreateList(R,a,n);
	printf("����:\n");
	printf("λ  ��:");
	for (int i=0;i<n;i++)
		printf("%3d",i);
	printf("\n");
	printf("�ؼ���:");
	for (i=0;i<n;i++)
		printf("%3d",R[i].key);
	printf("\n");
	CreateIndex(R,idx,n);
	printf("����:\n");
	printf("�ؼ���:");
	for (i=0;i<n;i++)
		printf("%3d",idx[i].key);
	printf("\n");
	printf("λ  ��:");
	for (i=0;i<n;i++)
		printf("%3d",idx[i].no);
	printf("\n");

	return 1;
}


