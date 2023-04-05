#include "sqlist.cpp"
void swap(ElemType &x,ElemType &y)
{
	ElemType tmp=x;
	x=y; y=tmp;
}
void merge1(SqList *A, SqList *B, SqList *&C)
{
	int i=0,j=0,k=0;
	C=(SqList *)malloc(sizeof(SqList));
	while (i<A->length && j<B->length)
	{
		if (A->data[i]<B->data[j])
		{
			C->data[k]=A->data[i];i++;k++;  
		}
		else
		{
			C->data[k]=B->data[j];j++;k++;  
		}
	}
	while (i<A->length)
	{
		C->data[k]=A->data[i];i++;k++;  
	}
	while (j<B->length)
	{
		C->data[k]=B->data[j];j++;k++;  
	}
	C->length=k;
}
/*
void merge2(SqList *A,SqList *&B)
{
	int i=0,j=0,k;
	while (i<A->length)
	{
		if (A->data[i]>B->data[B->length-1])	//A->data[i]大于B中所有元素
		{
			B->data[B->length]=A->data[i];		//将A->data[i]插入到B末尾
			B->length++;i++;
		}
		else if (A->data[i]<B->data[j])		//将A->data[i]插入到B中
		{	for (k=B->length-1;k>=j;k--)		//将B->data[j]及之后的元素后移
				B->data[k+1]=B->data[k];
			B->data[j]=A->data[i];			//将A->data[i]插入B->data[j]处
			B->length++;						//顺序表B的长度增1
			i++;j++;
		}
		else j++;
	}
}
*/
void merge2(SqList *&A,SqList *B)
{
	int i=A->length-1,j=B->length-1;
	int k=A->length+B->length-1;
	A->length=A->length+B->length;		//重置A的长度
	while (i>=0 && j>=0)				//A[0..m-1]和B[0..n-1]都没有扫描完毕时
	{
		if (A->data[i]>=B->data[j])		//将较大元素A->data[i]复制到新表A的尾部
		{
			A->data[k]=A->data[i];
			i--; k--;
		}
		else							//将较小元素B->data[j]复制到新表A的尾部
		{
			A->data[k]=B->data[j];
			j--; k--;
		}
	}
	while (j>=0)						//将B的余下元素复制到新表A的尾部
	{
		A->data[k]=B->data[j];
		j--; k--;
	}
}
/*
void merge3(SqList *&A,int k)
{
	int i=0,i1,j=k;		//j扫描后半部分的有序表,同时记录前半部分有序表的长度
	ElemType tmp;
	while (j<A->length && i<j)
	{
		if (A->data[j]>A->data[j-1])		//整个表已递增有序,退出循环
			break;
		else if (A->data[j]<A->data[i])		//将A->data[j]插入到前半部分中
		{
			tmp=A->data[j];
			for (i1=j-1;i1>=i;i1--)			//将A->data[i]及之后的元素后移
				A->data[i1+1]=A->data[i1];
			A->data[i]=tmp;					//将A->data[j]插入A->data[i]处
			i++;j++;
		}
		else i++;
	}
}
*/
void merge3(SqList *&A,int k)
{
	int i=0,i1,j=k;		//j扫描后半部分的有序表,同时记录前半部分有序表的长度
	ElemType tmp;
	while (j<A->length && i<j)
	{
		if (A->data[j]>A->data[j-1])		//整个表已递增有序,退出循环
			break;
		else if (A->data[j]<A->data[i])		//将A->data[j]插入到前半部分中
		{
			tmp=A->data[j];
			for (i1=j-1;i1>=i;i1--)			//将A->data[i]及之后的元素后移
				A->data[i1+1]=A->data[i1];
			A->data[i]=tmp;					//将A->data[j]插入A->data[i]处
			i++;j++;
		}
		else i++;
	}
}
int main()
{
	ElemType a[]={1,3,5};
	ElemType b[]={2,4,6,8,10};
	//ElemType c[]={6,7,8,1,2,3,4,5,10};
	SqList *A,*B,*C;
	CreateList(A,a,3);
	printf("A:");DispList(A);
	CreateList(B,b,5);
	printf("B:");DispList(B);
	merge2(A,B);
	printf("A:");DispList(A);
	DestroyList(A);
	DestroyList(B);
	return 1;
}