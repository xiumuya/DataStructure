#include"tuples.cpp"
bool diagonal(TSMatrix a,ElemType &sum)
{	sum=0;
	if (a.rows!=a.cols)				//�кŲ������кţ�����false
	{	printf("���ǶԽǾ���\n");
		return false;
	}
	for (int i=0;i<a.nums;i++)
		if (a.data[i].r==a.data[i].c)	//�кŵ����к�
			sum+=a.data[i].d;
	return true;
}

 
int main()
{
	TSMatrix t,tb;
	int A[6][7]={
		{0,0,1,0,0,0,0},
		{0,2,0,0,0,0,0},
		{3,0,0,0,0,0,0},
		{0,0,0,5,0,0,0},
		{0,0,0,0,6,0,0},
		{0,0,0,0,0,7,4}};
	CreatMat(t,A);
	printf("b:\n"); DispMat(t);
	int sum=0;
	printf("ans=%d\n",diagonal(tb,sum));
	return 1;
}

