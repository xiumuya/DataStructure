#include "btree.cpp"

BTNode* ancestor(BTNode *b,char x,char y)		//�ǵݹ���������x��y������������� 
{	BTNode* St[MaxSize],*p,*r;
	int top=-1,i;								//ջ��ָ��top�ó�ֵ
	bool flag,findx=false,findy=false;
	BTNode* anorx[MaxSize];
	BTNode* anory[MaxSize];
	int cx=0,cy=0;
	p=b;
	do
	{	while (p!=NULL)						//��p�����������ջ
		{	top++;St[top]=p;
			p=p->lchild;
		}
		r=NULL;								//rָ��ǰ����ǰһ���ѷ��ʵĽ��
		flag=true;							//flagΪ���ʾ���ڴ���ջ�����
		while (top!=-1 && flag)
		{
			p=St[top];					//ȡ����ǰ��ջ�����p
			if (p->rchild==r)			//�����������ڻ��ѱ�����,����֮
			{
				if (p->data==x)			//Ҫ���ʵĽ��Ϊ���x
				{
					findx=true;
					for (i=0;i<=top;i++) 	//���������x��·������anorx[0..cx-1]��
						anorx[cx++]=St[i];
				}
			 	else if (p->data==y)	//Ҫ���ʵĽ��Ϊ���y
				{
					findy=true;
					for (i=0;i<=top;i++) 	//���������y��·������anory[0..cy-1]��
						anory[cy++]=St[i];
				}
				if(findx && findy)
				{
					i=0;
					while(i<cx && i<cy && anorx[i]->data==anory[i]->data) 
						i++;						//��anorx��anory�����һ����ͬ�Ľ��
					return anorx[i-1];
				}
				top--;
				r=p;				//rָ��շ��ʹ��Ľ��
			}
			else
			{	p=p->rchild;			//pָ���Һ��ӽ�� 
				flag=false;				//��ʾ��ǰ���Ǵ���ջ�����
			}
		}
	} while (top!=-1);
	return NULL;
}

BTNode *ancestor1(BTNode *b,char x,char y)
{
	BTNode *p,*q;
	if (b==NULL) return NULL;
	if (b->data==x || b->data==y)
		return b;
	p=ancestor1(b->lchild,x,y);
	q=ancestor1(b->rchild,x,y);
	if (p!=NULL && q!=NULL) return b;
	if (p!=NULL) return p;
	if (q!=NULL) return q;
	return NULL;
}

int main()
{
	BTNode *b;
	CreateBTree(b,"A(B(D,E(G,H)),C(,F(I)))");	//ͼ7.11�Ķ�����
	printf("b:"); DispBTree(b); printf("\n");
	char x='D',y='I';
	BTNode *p=ancestor1(b,x,y);
	
	printf("%c��%c��LCA=%c\n",x,y,p->data);

	DestroyBTree(b);
	return 1;
}
