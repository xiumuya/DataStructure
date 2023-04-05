#include "bst.cpp"		//二叉排序树基本运算算法
BSTNode* getnodek(BSTNode* bt,int k,BSTNode*& f,BSTNode*& firstL)
{	BSTNode *p=bt;
    	while(p!=NULL)
    	{	if(k==p->key)
         		return p;					//查找成功返回p
        	f=p;
        	if(k>p->key)
            	p=p->rchild;				//在右子树中查找
        	else
        	{	firstL=p;					//出现左拐点，firstR建立第一个左拐点
        		p=p->lchild;				//在左子树中查找 
        	}
    	}
    	return NULL;
}
BSTNode* getsucc(BSTNode* bt,int k)		//求解算法
{	BSTNode* f=NULL;
	BSTNode* firstL=NULL;
	BSTNode* p=getnodek(bt,k,f,firstL);
	if(p==NULL)
		return NULL;
	if(p->rchild!=NULL) 				///情况(1)结点p有右子树
	{	BSTNode* succ=p->rchild;
		while(succ->lchild!=NULL)
			succ=succ->lchild;
		return succ;
	}
	if(f==NULL)
		return NULL; 					//情况(2)中子情况①
	if(p==f->lchild) 					//情况(2)中子情况② 
		return f;
	else								//情况(2)中子情况③ 
		return firstL;
}

int main()
{
	BSTNode *bt;
	KeyType a[]={5,2,1,6,7,4,8,3,9},n=9;
	printf("(1)构造二叉排序树bt\n");
	bt=CreateBST(a,n);		//创建一棵二叉排序树
	printf("(2)输出BST:");DispBST(bt);printf("\n");
	KeyType k=4;
	printf("(3)k=%d的后继结点: ",k);
	BSTNode* p=getsucc(bt,k);
	if(p!=NULL)
		printf("%d\n",p->key);
	else
		printf("不存在\n"); 
	
	printf("(4)销毁bt"); DestroyBST(bt); printf("\n");
	return 1;
}
