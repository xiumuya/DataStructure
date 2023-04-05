#include "btree.cpp"
bool Symm(BTNode *b1,BTNode *b2)	//�ж϶�����b1��b2�Ƿ�ͬ��
{	if (b1==NULL && b2==NULL)
		return true;
	else if (b1==NULL || b2==NULL)
		return false;
	else
		return (Symm(b1->lchild,b2->lchild) &	Symm(b1->rchild,b2->rchild));
}
bool Symmtree(BTNode *b)		//�ж϶����������������Ƿ�ͬ��
{	if (b==NULL)
		return true;
	else
		return Symm(b->lchild,b->rchild);
}
int main()
{	BTNode *b,*b1;
	CreateBTree(b,"A(B(D(,G)),C(E,F))");
	printf("������b:");DispBTree(b);printf("\n");
	printf("b�Ƿ�ͬ��:%d\n",Symmtree(b)); 
	CreateBTree(b1,"A(B(C,D),E(F,G)))");
	printf("������b1:");DispBTree(b1);printf("\n");
	printf("b1�Ƿ�ͬ��:%d\n",Symmtree(b1)); 


	DestroyBTree(b);
	DestroyBTree(b1);
	return 1;
}
