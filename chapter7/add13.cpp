#include "btree.cpp"

int MinBranch(BTNode *b)
{	int min1,min2,min;
	if (b==NULL) return 0;
	min1=MinBranch(b->lchild);			//�ݹ����������
    min2=MinBranch(b->rchild);			//�ݹ����������
    if(min1==0) return min2+1;			//������Ϊ��
    else if(min2==0) return min1+1;		//������Ϊ��
    else return min1>min2?min1:min2+1;	//������������
}

int main()
{
	BTNode *b;
	CreateBTree(b,"A(B(,E(G,H)),C(,F(I)))");
	printf("b:"); DispBTree(b); printf("\n");

	printf("��С֦��:%d\n",MinBranch(b));

	DestroyBTree(b);
	return 1;
}
