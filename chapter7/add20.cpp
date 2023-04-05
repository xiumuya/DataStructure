#include "btree.cpp"

int BTWidth(BTNode *b)
{	struct
	{	int lno;					//�ڵ�Ĳ�α��
		BTNode *p;					//�ڵ�ָ��
	} Qu[MaxSize];					//����˳���ѭ������
	int front,rear;					//������׺Ͷ�βָ��
	int lnum,max,i,n;
	front=rear=0;					//�ö���Ϊ�ն�
	if (b!=NULL)
	{	rear++;	
		Qu[rear].p=b;				//���ڵ�ָ�����
		Qu[rear].lno=1;				//���ڵ�Ĳ�α��Ϊ1
		while (rear!=front)			//���в�Ϊ��
		{	front++;
			b=Qu[front].p;			//��ͷ����
			lnum=Qu[front].lno;
			if (b->lchild!=NULL)		//�������
			{	rear++;
				Qu[rear].p=b->lchild;
				Qu[rear].lno=lnum+1;
			}
			if (b->rchild!=NULL)		//�Һ������
			{	rear++;
				Qu[rear].p=b->rchild;
				Qu[rear].lno=lnum+1;
			}
		}
		printf("���ڵ�Ĳ���:\n");
		for (i=1;i<=rear;i++)
			printf("   %c,%d\n",Qu[i].p->data,Qu[i].lno);
		max=0;lnum=1;i=1;
		while (i<=rear)
		{	n=0;
			while (i<=rear && Qu[i].lno==lnum)
			{	n++;
				i++;
			}
			lnum=Qu[i].lno;
			if (n>max) max=n;
		}
		return max;
	}
	else
		return 0;
}


int main()
{
	BTNode *b;
	CreateBTree(b,"A(B(D,E(G,H)),C(,F(I)))");	//ͼ7.11�Ķ�����
	printf("b:"); DispBTree(b); printf("\n");
	printf("�������Ŀ��:%d\n",BTWidth(b));

	DestroyBTree(b);
	return 1;
}
