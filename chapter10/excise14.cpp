#include "seqlist.cpp"			//˳�����������㷨
#include <malloc.h>
#define Max 3
typedef struct node
{	RecType Rec;
	struct node *next;
} NodeType;
void RadixSort1(RecType R[],int n)
{	NodeType *head[Max],*tail[Max],*p,*t;	//��������ӵ���βָ��
	int i,k;
	for (i=0;i<Max;i++)						//��ʼ���������ס�βָ��
		head[i]=tail[i]=NULL;
	for (i=0;i<n;i++)
	{	p=(NodeType *)malloc(sizeof(NodeType));	//�����½ڵ�
		p->Rec=R[i];
		p->next=NULL;
		k=R[i].key;							//�ҵ�k������,k=0,1��2
		if (head[k]==NULL)   				//���з���,����ǰ�巨����
		{	head[k]=p;
			tail[k]=p;
		}
		else
		{	tail[k]->next=p;
			tail[k]=p;
		}
	}
	p=NULL;
	for (i=0;i<Max;i++)			//����ÿһ�����ӽ���ѭ���ռ�
		if (head[i]!=NULL)		//������pΪ�׽ڵ�ָ��ĵ�����
		{	if (p==NULL)
			{	p=head[i];
				t=tail[i];
			}
			else
			{	t->next=head[i];
				t=tail[i];
			}
		}
		i=0;
		while (p!=NULL)			//�������Ľ���ŵ�R[]������
		{	R[i++]=p->Rec;
			p=p->next;
		}
}
int main()
{	int i,n=5;
	RecType R[MAXL]={{1,'A'},{0,'B'},{0,'C'},{2,'D'},{1,'F'}};
	printf("����ǰ:\n  ");
	for (i=0;i<n;i++)
		printf("[%d,%c] ",R[i].key,R[i].data);
	printf("\n");
	RadixSort1(R,n);
	printf("�����:\n  ");
	for (i=0;i<n;i++)
		printf("[%d,%c] ",R[i].key,R[i].data);
	printf("\n");
	return 1;
}


