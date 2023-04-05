#include "bst.cpp"		//�������������������㷨
BSTNode* getnodek(BSTNode* bt,int k,BSTNode*& f,BSTNode*& firstL)
{	BSTNode *p=bt;
    	while(p!=NULL)
    	{	if(k==p->key)
         		return p;					//���ҳɹ�����p
        	f=p;
        	if(k>p->key)
            	p=p->rchild;				//���������в���
        	else
        	{	firstL=p;					//������յ㣬firstR������һ����յ�
        		p=p->lchild;				//���������в��� 
        	}
    	}
    	return NULL;
}
BSTNode* getsucc(BSTNode* bt,int k)		//����㷨
{	BSTNode* f=NULL;
	BSTNode* firstL=NULL;
	BSTNode* p=getnodek(bt,k,f,firstL);
	if(p==NULL)
		return NULL;
	if(p->rchild!=NULL) 				///���(1)���p��������
	{	BSTNode* succ=p->rchild;
		while(succ->lchild!=NULL)
			succ=succ->lchild;
		return succ;
	}
	if(f==NULL)
		return NULL; 					//���(2)���������
	if(p==f->lchild) 					//���(2)��������� 
		return f;
	else								//���(2)��������� 
		return firstL;
}

int main()
{
	BSTNode *bt;
	KeyType a[]={5,2,1,6,7,4,8,3,9},n=9;
	printf("(1)�������������bt\n");
	bt=CreateBST(a,n);		//����һ�ö���������
	printf("(2)���BST:");DispBST(bt);printf("\n");
	KeyType k=4;
	printf("(3)k=%d�ĺ�̽��: ",k);
	BSTNode* p=getsucc(bt,k);
	if(p!=NULL)
		printf("%d\n",p->key);
	else
		printf("������\n"); 
	
	printf("(4)����bt"); DestroyBST(bt); printf("\n");
	return 1;
}
