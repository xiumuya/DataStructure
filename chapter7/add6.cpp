#include "btree.cpp"
void MinlenLeaf(BTNode *b,int l,int &min,char &x)
{	//l�ĳ�ֵΪ1,minȡ���������xΪ�����Ҷ�ӽڵ�
	if (b!=NULL)
	{	if (b->lchild==NULL && b->rchild==NULL)
		{	if (l<min)
			{	min=l;
				x=b->data;
			}
		}
		MinlenLeaf(b->lchild,l+1,min,x);
		MinlenLeaf(b->rchild,l+1,min,x);
	}
}

int main()
{
	BTNode *b;
	CreateBTree(b,"A(B(D,E(G,H)),C(,F(I)))");	//ͼ7.11�Ķ�����
	printf("b:"); DispBTree(b); printf("\n");
	ElemType x;
	int min=1000;
	MinlenLeaf(b,1,min,x);
	printf("������ڵ������Ҷ�ӽڵ�:%c\n",x);
	DestroyBTree(b);
	return 1;
}
