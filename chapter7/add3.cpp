#include "btree.cpp"
int DSonNodes(BTNode *b)
{	int num1,num2,n;
	if (b==NULL)
		return 0;
	else if (b->lchild!=NULL && b->rchild!=NULL)
		n=1;					//Ϊ˫��֧���
	else 
		n=0;					//����
	num1=DSonNodes(b->lchild);	//�ݹ�����������˫��֧�����
	num2=DSonNodes(b->rchild);	//�ݹ�����������˫��֧�����
	return (num1+num2+n);
}

int main()
{
	BTNode *b;
	CreateBTree(b,"A(B(D,E(G,H)),C(,F(I)))");	//ͼ7.11�Ķ�����
	printf("b:"); DispBTree(b); printf("\n");
	printf("˫��֧�ڵ����:%d\n",DSonNodes(b));
	DestroyBTree(b);
	return 1;
}
