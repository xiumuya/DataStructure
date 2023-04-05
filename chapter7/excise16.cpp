#include "btree.cpp"
int LevelkCount(BTNode *b,int k,int h)
{	//h�ĳ�ֵΪ1
	int num1,num2,num=0;
	if (b!=NULL)
	{	if (h==k && b->lchild==NULL && b->rchild==NULL)
			num++;
		num1=LevelkCount(b->lchild,k,h+1);
		num2=LevelkCount(b->rchild,k,h+1);
		num+=num1+num2;
		return num;
	}
	return 0;
}
int Levelkleaf(BTNode *b,int k)	//���ض�����b�е�k����Ҷ�ӽ�����
{
	return LevelkCount(b,k,1);
}
int main()
{	BTNode *b;
	CreateBTree(b,"A(B(D(,G)),C(E,F))");
	printf("������b:");DispBTree(b);printf("\n");
	int k=3; 
	printf("��%d���Ҷ�ӽ�����=%d\n",k,Levelkleaf(b,k));
	DestroyBTree(b);
	return 1;
}
