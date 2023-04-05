#include "bst.cpp"   //�������������������㷨

int abs(int x,int y)	//������������ľ���ֵ
{
	int z=x-y;
	return z>0?z:-z;
}
void JudgeAVT(BSTNode *bt,bool &balance,int &h)
{	//hΪbt�ĸ߶�,balance��ʾbt��ƽ����
	int hl,hr;
	bool bl,br;
	if (bt==NULL)							//������ƽ���
	{
		h=0;
		balance=true;
	}
	//else if (bt->lchild==NULL && bt->rchild==NULL)	//ֻ��һ���ڵ������ƽ��� 
	//{
	//	h=1;
	//	balance=true;
	//}
	else 
	{
		JudgeAVT(bt->lchild,bl,hl);		//�����������ƽ����bl�͸߶�hl
		JudgeAVT(bt->rchild,br,hr);		//�����������ƽ����br�͸߶�hr
		h=(hl>hr?hl:hr)+1;
		if (abs(hl,hr)<=1)
			balance=bl & br;			//&Ϊ�߼��������
		else
			balance=false;
		printf("��ǰ���:%d,lefth=%d,righth=%d, h:%d, bal:%d\n",bt->key,hl,hr,h,balance);
	}
}

int main()
{
	BSTNode *bt;
	//KeyType keys[]={5,2,3,4,1,8,6,7,9};
	KeyType keys[]={5,4,8,6,9};
	int n=5;
	bt=CreateBST(keys,n);		//��������������
	printf("BST:"); DispBST(bt); printf("\n");

	bool balance;
	int h;
	JudgeAVT(bt,balance,h);
	if (balance)
		printf("��BST����ƽ���\n");
	else
		printf("��BST���ǲ�ƽ���\n");
	printf("��BST���߶�:%d\n",h);
	
	DestroyBST(bt);
	return 1;
}
