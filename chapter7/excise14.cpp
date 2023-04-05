#include "btree.cpp"
void FindMinNode(BTNode *b,char &min)
{	if (b==NULL) return;
	if(b->data<min)
		min=b->data;
	FindMinNode(b->lchild,min);		//��������������С���ֵ
	FindMinNode(b->rchild,min); 	//��������������С���ֵ
}
char MinNode(BTNode *b)				//�����С���ֵ
{	if (b!=NULL)
	{	char min=b->data;
		FindMinNode(b,min);
		return min;
	}
}

int main()
{	BTNode *b;
	CreateBTree(b,"A(B(D(,G)),C(E,F))");
	printf("������:");DispBTree(b);printf("\n");
	printf("��С���ֵ=%c\n",MinNode(b));

	DestroyBTree(b);
	return 1;
}
