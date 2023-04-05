#include "btree.cpp"

ElemType maxnode(BTNode *b)
{
	ElemType max=b->data,max1;
	if (b!=NULL)
	{
		if (b->lchild==NULL && b->rchild==NULL)	//ֻ��һ���ڵ�ʱ
			return b->data;
		else
		{	if (b->data>max)
				max=b->data;
			if (b->lchild!=NULL)
				max1=maxnode(b->lchild);		//����������
			if (max1>max) max=max1;
			if (b->rchild!=NULL)
				max1=maxnode(b->rchild);		//����������
			if (max1>max) max=max1;				//�����ֵ
			return max;							//�������ֵ
		}
	}
	return '0';
}

int main()
{
	BTNode *b;
	CreateBTree(b,"A(B(D,E(G,H)),C(,F(I)))");
	printf("b:"); DispBTree(b); printf("\n");
	
	printf("���:%c\n",maxnode(b));

	DestroyBTree(b);
	return 1;
}
