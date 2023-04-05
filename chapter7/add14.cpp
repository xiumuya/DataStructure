#include "btree.cpp"

int LevelLeafkCount(BTNode *b,int h,int k)
{	//h�ĳ�ֵΪ1
	int num1,num2,num=0;
	if (b!=NULL)
	{	if (h==k && b->lchild==NULL && b->rchild==NULL)
			num++;
		num1=LevelLeafkCount(b->lchild,h+1,k);
		num2=LevelLeafkCount(b->rchild,h+1,k);
		num+=num1+num2;
		return num;
	}
	else return 0;
}
int LevelLeafk(BTNode *b,int k)	//��b�е�k����Ҷ�ӽڵ����
{
	return LevelLeafkCount(b,1,k);
}


int main()
{
	BTNode *b;
	CreateBTree(b,"A(B(D,E(G,H)),C(,F(I)))");	//ͼ7.11�Ķ�����
	printf("b:"); DispBTree(b); printf("\n");
	int k=4;

	printf("��%d����Ҷ�ӽ�����:%d\n",k,LevelLeafk(b,k));

	DestroyBTree(b);
	return 1;
}
