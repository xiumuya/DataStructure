#include "bst.cpp"   //�������������������㷨

KeyType predt=-32768; //predtΪȫ�ֱ���,���浱ǰ�ڵ�����ǰ����ֵ,��ֵΪ-��
bool JudgeBST(BSTNode *bt)
{
	bool b1,b2;
	if (bt==NULL)
		return true;
	else
	{
		b1=JudgeBST(bt->lchild);	//�ж�������
		if (b1==false)				//����������BST�����ؼ�
			return false;
		if (bt->key<predt)			//��ǰ�ڵ�Υ��BST���ʣ����ؼ�
			return false;
		predt=bt->key;
		b2=JudgeBST(bt->rchild);	//�ж�������
		return b2;
	}
}

int main()
{
	BSTNode *bt;
	KeyType a[]={5,2,1,6,7,4,8,3,9},n=9;
	bt=CreateBST(a,n);		//����һ�ö���������
	printf("BST:");DispBST(bt);printf("\n");

	printf("���:%d\n",JudgeBST(bt));

	DestroyBST(bt);
	return 1;
}
