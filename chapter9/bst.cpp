//�����������㷨
#include <stdio.h>
#include <malloc.h>
typedef int KeyType;
typedef char InfoType[10];
typedef struct node           		//��¼����
{
	KeyType key;              		//�ؼ�����
	InfoType data;             		//����������
	struct node *lchild,*rchild;	//���Һ���ָ��
} BSTNode;
bool InsertBST(BSTNode *&bt,KeyType k)	
//�ڶ���������bt�в���һ���ؼ���Ϊk�Ľڵ㡣����ɹ������棬���򷵻ؼ�
{	if (bt==NULL)						//ԭ��Ϊ�գ��²���Ľڵ�Ϊ���ڵ�
	{	bt=(BSTNode *)malloc(sizeof(BSTNode));
		bt->key=k; bt->lchild=bt->rchild=NULL;
		return true;
	}
	else if (k==bt->key) 				//���д�����ͬ�ؼ��ֵĽڵ㣬���ؼ�
		return false;
	else if (k<bt->key) 
		return InsertBST(bt->lchild,k);	//���뵽��������
	else
		return InsertBST(bt->rchild,k);	//���뵽��������
}

BSTNode *CreateBST(KeyType A[],int n)		//��������������
//����BST�����ڵ�ָ��
{	BSTNode *bt=NULL;				//��ʼʱbtΪ����
	int i=0;
	while (i<n)
	{	InsertBST(bt,A[i]);			//���ؼ���A[i]�������������bt��
		i++;
	}
	return bt;						//���ؽ����Ķ����������ĸ�ָ��
}

void DispBST(BSTNode *bt)		//���һ�����������
{
	if (bt!=NULL)
	{	printf("%d",bt->key);
		if (bt->lchild!=NULL || bt->rchild!=NULL)
		{	printf("(");						//�к��ӽڵ�ʱ�����(
			DispBST(bt->lchild);				//�ݹ鴦��������
			if (bt->rchild!=NULL) printf(",");	//���Һ��ӽڵ�ʱ�����,
			DispBST(bt->rchild);				//�ݹ鴦��������
			printf(")");						//�к��ӽڵ�ʱ�����)
		}
	}
}
BSTNode *SearchBST(BSTNode *bt,KeyType k)
{ 
    if (bt==NULL || bt->key==k)      	//�ݹ��ս�����
		return bt;
	if (k<bt->key)
       	return SearchBST(bt->lchild,k);  //���������еݹ����
    else
     	return SearchBST(bt->rchild,k);  //���������еݹ����
}
BSTNode *SearchBST1(BSTNode *bt,KeyType k,BSTNode *f1,BSTNode *&f)	
/*��bt�в��ҹؼ���Ϊk�Ľڵ�,�����ҳɹ�,�ú������ظýڵ��ָ��,
f������˫�׽ڵ�;����,�ú�������NULL��
����÷�������:
	         SearchBST(bt,x,NULL,f);
����ĵ�3������f1�����м����,������f,��ʼ��ΪNULL*/
{ 
	if (bt==NULL)
	{	
		f=NULL;
		return(NULL);
	}
	else if (k==bt->key) 
	{	
		f=f1;
		return(bt);
	}
	else if (k<bt->key)
       	return SearchBST1(bt->lchild,k,bt,f);  //���������еݹ����
    else
     	return SearchBST1(bt->rchild,k,bt,f);  //���������еݹ����
}

void Delete1(BSTNode *p,BSTNode *&r)  //����ɾp�ڵ�����������ʱ��ɾ������
{
	BSTNode *q;
	if (r->rchild!=NULL)
		Delete1(p,r->rchild);	//�ݹ��������½ڵ�r
	else						//�ҵ��������½ڵ�r
	{	p->key=r->key;			//��r�ڵ��ֵ�����ڵ�p
		q=r;					
		r=r->lchild;			//ֱ�ӽ����������ĸ��ڵ���ڱ�ɾ�ڵ��λ����
		free(q);				//�ͷ�ԭ�ڵ�r�Ŀռ�
	}
}
void Delete(BSTNode *&p)		//�Ӷ�����������ɾ��p�ڵ�
{
	BSTNode *q;
	if (p->rchild==NULL)		//p�ڵ�û�������������
	{
		q=p;
		p=p->lchild;			//ֱ�ӽ����������ĸ��ڵ���ڱ�ɾ�ڵ��λ����
		free(q);  
	}
	else if (p->lchild==NULL)	//p�ڵ�û�������������
	{
		q=p;
		p=p->rchild;			//��p�ڵ����������Ϊ˫�׽ڵ����Ӧ����
		free(q);  
	}
	else Delete1(p,p->lchild);	//p�ڵ��û����������û�������������
}
int DeleteBST(BSTNode *&bt,KeyType k)	//��bt��ɾ���ؼ���Ϊk�Ľڵ�
{
	if (bt==NULL) 
		return 0;				//����ɾ��ʧ��
	else 
	{	
		if (k<bt->key) 
			return DeleteBST(bt->lchild,k);	//�ݹ�����������ɾ��Ϊk�Ľڵ�
		else if (k>bt->key) 
			return DeleteBST(bt->rchild,k);	//�ݹ�����������ɾ��Ϊk�Ľڵ�
		else 
		{
			Delete(bt);		//����Delete(bt)����ɾ��*bt�ڵ�
			return 1;
		}
	}
}

void DestroyBST(BSTNode *&bt)		//���ٶ���������bt
{
	if (bt!=NULL)
	{
		DestroyBST(bt->lchild);
		DestroyBST(bt->rchild);
		free(bt);
	}
}