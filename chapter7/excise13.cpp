#include "btree.cpp"
int SSonNodes(BTNode *b)
{	int num1,num2,n;
	if (b==NULL)
		return 0;
	else if ((b->lchild==NULL && b->rchild!=NULL) ||
		(b->lchild!=NULL && b->rchild==NULL))
		n=1;					//Ϊ����֧���
	else 
		n=0;					//�������
	num1=SSonNodes(b->lchild);	//�ݹ����������е���֧�����
	num2=SSonNodes(b->rchild);	//�ݹ����������е���֧�����
	return (num1+num2+n);
}


int main()
{	BTNode *b;
	CreateBTree(b,"A(B(D(,G)),C(E,F))");
	printf("������:");DispBTree(b);printf("\n");
	printf("����֧������=%d\n",SSonNodes(b));

	DestroyBTree(b);
	return 1;
}
