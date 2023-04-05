#include "btree.cpp"	//���������������㷨
void Width1(BTNode *b,int l,int width[])
{	//l�ĳ�ֵΪ1
	if (b!=NULL)
	{	width[l]++;
		Width1(b->lchild,l+1,width);
		Width1(b->rchild,l+1,width);
	}
}
int Width(BTNode *b)	//�������b�Ŀ��
{	int i,max=0;
	int width[MaxSize];
	for (i=1;i<MaxSize;i++)
		width[i]=0;
	Width1(b,1,width);
	for (i=1;i<MaxSize;i++)
		if (width[i]>max) max=width[i];
	return max;
}


int main()
{
	BTNode *b;
	CreateBTree(b,"A(B(D,E(G,H)),C(,F(I)))");	//ͼ7.11�Ķ�����
	printf("b:"); DispBTree(b); printf("\n");

	printf("���:%d\n",Width(b));

	DestroyBTree(b);
	return 1;
}
