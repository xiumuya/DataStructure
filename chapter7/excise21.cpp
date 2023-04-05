#include "btree.cpp"
bool CompBTree(BTNode *b)
{	BTNode *Qu[MaxSize],*p;				//����һ�����У����ڲ�α���
	int front=0,rear=0;				//���ζ��еĶ�ͷ��βָ��
	bool cm=true;						//cmΪ���ʾ������Ϊ��ȫ������
	bool bj=true;						//bjΪ���ʾ��ĿǰΪֹ���н��������Һ���
	if (b==NULL) return true;			//���������������ȫ������
	rear++;
	Qu[rear]=b;						//��������
	while (front!=rear)				//���в���
	{	front=(front+1)%MaxSize;
		p=Qu[front];					//���ӽ��p
		if (p->lchild==NULL)			//p���û������
		{	bj=false;					//���ֽ��pȱ���ӵ����
			if (p->rchild!=NULL)		//û�����ӵ����Һ���,Υ��(1),
				cm=false;
		}
		else							//p���������
		{	if (!bj) cm=false;			//bjΪ�ٶ����p�������ӣ�Υ��(2)
			rear=(rear+1)%MaxSize;
			Qu[rear]=p->lchild;		//���ӽ���
			if (p->rchild==NULL)
				bj=false;				//���ֽ��pȱ�Һ��ӵ����
			else						//p�����Һ���,������ж�
			{	rear=(rear+1)%MaxSize;	
				Qu[rear]=p->rchild;	//��p�����Һ��ӽ���
			}
		}
	}
	return cm;
}
int main()
{	BTNode *b,*b1;
	CreateBTree(b,"A(B(D(,G)),C(E,F))");
	printf("������b:");DispBTree(b);printf("\n");
	printf("b�Ƿ�ͬ��:%d\n",CompBTree(b)); 
	CreateBTree(b1,"A(B(C,D),E(F,G)))");
	printf("������b1:");DispBTree(b1);printf("\n");
	printf("b1�Ƿ�ͬ��:%d\n",CompBTree(b1)); 


	DestroyBTree(b);
	DestroyBTree(b1);
	return 1;
}
