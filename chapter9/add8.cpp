#include "bst.cpp"		//�������������������㷨
#define MaxSize 100 
void SearchPath(BSTNode *bt,KeyType k,KeyType path[],int d)
{	//d��ʾpath�����ؼ��ֵ��±꣬��ʼֵΪ-1
	if (bt==NULL)
		return;
	else if (k==bt->key)
	{
		d++;
		path[d]=bt->key;		//��ӵ�·����
		for (int i=0;i<=d;i++)
			printf("%2d",path[i]);
		printf("\n");
	}
	else
	{
		d++;
		path[d]=bt->key;		//��ӵ�·����
		if (k<bt->key)
			SearchPath(bt->lchild,k,path,d);	//���������еݹ����
		else
			SearchPath(bt->rchild,k,path,d);		//���������еݹ����
	}
}

int main()
{
	BSTNode *bt;
	KeyType k=3;
	KeyType a[]={5,2,1,6,7,4,8,3,9},n=9;
	printf("(1)�������������bt\n");
	bt=CreateBST(a,n);		//����һ�ö���������
	printf("(2)���BST:");DispBST(bt);printf("\n");
	int path[MaxSize];
	printf("(3)����%d�ؼ���:",k);SearchPath(bt,k,path,-1);
	printf("(4)����bt"); DestroyBST(bt); printf("\n");
	return 1;
}
