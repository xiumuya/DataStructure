#include "btree.cpp"
void AllPath1(BTNode *b,ElemType path[],int pathlen)
{	//bΪ���ڵ�ʱ��pathlen��ʼֵΪ0
	int i;
	if (b!=NULL)
	{	if (b->lchild==NULL && b->rchild==NULL)	//bΪҶ�ӽڵ�
		{	printf("  %c�����ڵ���·��: %c ",b->data,b->data);
			for (i=pathlen-1;i>=0;i--)
				printf("%c ",path[i]);
			printf("\n");
		}
		else
		{	path[pathlen]=b->data;			//����ǰ�ڵ����·����
			pathlen++;						//·��������1
			AllPath1(b->lchild,path,pathlen);//�ݹ�ɨ��������
			AllPath1(b->rchild,path,pathlen);//�ݹ�ɨ��������
			pathlen--;						//�ָ�����
		}
	}
}


int main()
{
	BTNode *b;
	CreateBTree(b,"A(B(D,E(G,H)),C(,F(I)))");	//ͼ7.11�Ķ�����
	printf("b:"); DispBTree(b); printf("\n");
	ElemType path[MaxSize];
	AllPath1(b,path,0);
	DestroyBTree(b);
	return 1;
}
