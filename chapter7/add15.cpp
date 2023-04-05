#include "btree.cpp"

BTNode *postfirst(BTNode *b)
{
	BTNode *p=b;
	if (b!=NULL)
		while (p->lchild!=NULL || p->rchild!=NULL)
		{
			while (p->lchild!=NULL)	//���ҵ��ڵ�p�������½ڵ�
				p=p->lchild;
			if (p->rchild!=NULL)	//���ڵ�p���Һ��ӣ�ת����Һ���
				p=p->rchild;
		}
	return p;	//�ҵ��ĵ�һ��Ҷ�ӽڵ�p��Ϊ����
}

int main()
{
	BTNode *b,*p;
	CreateBTree(b,"A(B(D,E(G,H)),C(,F(I)))");	//ͼ7.11�Ķ�����
	printf("b:"); DispBTree(b); printf("\n");

	p=postfirst(b);
	if (p!=NULL)
		printf("���:%c\n",p->data);

	DestroyBTree(b);
	return 1;
}
