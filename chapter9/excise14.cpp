#include "bst.cpp"   //�������������������㷨
int Level(BSTNode *bt,KeyType k)
{	int lv=1;						//���lv�ó�ֵ1
	BSTNode *p=bt;
	while (p!=NULL && p->key!=k)	//����������δ�����δ�ҵ���ѭ��
	{	if (k<p->key)
			p=p->lchild;			//���������в���
		else
			p=p->rchild;			//���������в���
		lv++;					//�����1
	}
	if (p!=NULL)					//�ҵ��󷵻�����
		return lv;
	else
		return(0);				//��ʾδ�ҵ�
}

int main()
{
	BSTNode *bt;
	KeyType a[]={5,2,1,6,7,4,8,3,9},n=9;
	bt=CreateBST(a,n);		//����һ�ö���������
	printf("BST:");DispBST(bt);printf("\n");
	int k=4;
	printf("���:%d\n",Level(bt,k));

	DestroyBST(bt);
	return 1;
}
