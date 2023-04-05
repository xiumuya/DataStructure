#include "btree.cpp"	//���������������㷨
void LongPath(BTNode *b,ElemType path[],int pathlen,ElemType longpath[],
	int &longpathlen)	//pathlen��longpathlen�ĳ�ֵΪ0
{
	if (b==NULL)
	{	if (pathlen>longpathlen)	//����ǰ·������,��·��������longpath��
		{	for (int i=pathlen-1;i>=0;i--)
				longpath[i]=path[i];
			longpathlen=pathlen;
		}
	}
	else
	{	path[pathlen]=b->data;		//����ǰ�ڵ����·����
		pathlen++;					//·��������1
		LongPath(b->lchild,path,pathlen,longpath,longpathlen);
			//�ݹ�ɨ��������
		LongPath(b->rchild,path,pathlen,longpath,longpathlen);
			//�ݹ�ɨ��������
	}
}


int main()
{
	BTNode *b;
	CreateBTree(b,"A(B(D,E(G,H)),C(,F(I)))");	//ͼ7.11�Ķ�����
	printf("b:"); DispBTree(b); printf("\n");

	ElemType path[MaxSize],longpath[MaxSize];
	int longpathlen=0;

	LongPath(b,path,0,longpath,longpathlen);

	printf("��һ�����·������:%d\n",longpathlen);
	printf("��һ�����·��:");
	for (int i=longpathlen-1;i>=0;i--)
		printf("%c ",longpath[i]);
	printf("\n");

	DestroyBTree(b);
	return 1;
}
