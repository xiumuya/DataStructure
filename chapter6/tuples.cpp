//ϡ��������Ԫ���ʾ-�㷨
#include <stdio.h>
#define M 6
#define N 7
#define MaxSize  100         //�����з���Ԫ��������
typedef int ElemType;
typedef struct
{
	int r;					//�к�
	int c;					//�к�
	ElemType d;				//Ԫ��ֵ
} TupNode;					//��Ԫ�鶨��
typedef struct 
{	
	int rows;				//����
	int cols;				//����
	int nums;				//����Ԫ�ظ���
	TupNode data[MaxSize];
} TSMatrix;					//��Ԫ��˳���

void CreatMat(TSMatrix &t,ElemType A[M][N])  //��һ����άϡ����󴴽�����Ԫ���ʾ
{
	int i,j;
	t.rows=M;t.cols=N;t.nums=0;
	for (i=0;i<M;i++)
	{
		for (j=0;j<N;j++) 
			if (A[i][j]!=0) 	//ֻ�洢����Ԫ��
			{
				t.data[t.nums].r=i;t.data[t.nums].c=j;
				t.data[t.nums].d=A[i][j];t.nums++;
			}
	}
}
bool Value(TSMatrix &t,ElemType x,int i,int j)  //��Ԫ��Ԫ�ظ�ֵ
{
	int k=0,k1;
	if (i>=t.rows || j>=t.cols)
		return false;				//ʧ��ʱ����false
	while (k<t.nums && i>t.data[k].r) k++;					//������
	while (k<t.nums && i==t.data[k].r && j>t.data[k].c) k++;//������
	if (t.data[k].r==i && t.data[k].c==j)	//����������Ԫ��
		t.data[k].d=x;
	else									//������������Ԫ��ʱ����һ��Ԫ��
	{	
		for (k1=t.nums-1;k1>=k;k1--)
		{
			t.data[k1+1].r=t.data[k1].r;
			t.data[k1+1].c=t.data[k1].c;
			t.data[k1+1].d=t.data[k1].d;
		}
		t.data[k].r=i;t.data[k].c=j;t.data[k].d=x;
		t.nums++;
	}
	return true;						//�ɹ�ʱ����true
}

bool Assign(TSMatrix t,ElemType &x,int i,int j)  //��ָ��λ�õ�Ԫ��ֵ��������
{
	int k=0;
	if (i>=t.rows || j>=t.cols)
		return false;			//ʧ��ʱ����false
	while (k<t.nums && i>t.data[k].r) k++;					//������
	while (k<t.nums && i==t.data[k].r && j>t.data[k].c) k++;//������
	if (t.data[k].r==i && t.data[k].c==j)
		x=t.data[k].d;
	else
		x=0;				//����Ԫ����û���ҵ���ʾ����Ԫ��
	return true;			//�ɹ�ʱ����true
}
void DispMat(TSMatrix t)		//�����Ԫ��
{
	int i;
	if (t.nums<=0)			//û�з���Ԫ��ʱ����
		return;
	printf("\t%d\t%d\t%d\n",t.rows,t.cols,t.nums);
	printf("\t------------------\n");
	for (i=0;i<t.nums;i++)
		printf("\t%d\t%d\t%d\n",t.data[i].r,t.data[i].c,t.data[i].d);
}
void TranTat(TSMatrix t,TSMatrix &tb)		//����ת��
{
	int p,q=0,v;					//qΪtb.data���±�
	tb.rows=t.cols;tb.cols=t.rows;tb.nums=t.nums;
	if (t.nums!=0)					//�����ڷ���Ԫ��ʱִ��ת��
	{
		for (v=0;v<t.cols;v++)		//tb.data[q]�еļ�¼��c��Ĵ�������
			for (p=0;p<t.nums;p++)	//pΪt.data���±�
				if (t.data[p].c==v)
				{
					tb.data[q].r=t.data[p].c;
					tb.data[q].c=t.data[p].r;
					tb.data[q].d=t.data[p].d;
					q++;
				}
	}
}

