#include <stdio.h>
#define MaxSize 100
struct stacknode
{	int data[MaxSize];
	int top;
} st;							//ȫ�ֱ���������˳��ջ
int n=4;					//ȫ�ֱ����������������е�Ԫ�ظ���
char str[]="abcd";				//ȫ�ֱ�����ָ����ջ����
int sum=0;						//ȫ�ֱ������ۼƳ�ջ���и���
//---------ջ����--------------------------------
void initstack()				//��ʼ��˳��ջ
{
	st.top=-1;
}
void push(int x)					//Ԫ��x��ջ����
{	st.top++;
	st.data[st.top]=x;
}
int pop()							//��ջ����
{	int temp;
	temp=st.data[st.top];
	st.top--;
	return temp;
}
bool empty()						//�ж�ջ�շ�����
{	if (st.top==-1)
		return true;
	else
		return false;
}
//---------------------------------------------

void process(int i,int a[],int j)		//����C������iλ�õ�Ԫ��
{	int x,k;
	if (i>=n && empty())				//���һ�ֿ��ܵķ���
	{	printf("  ");
		for (k=0;k<j;k++)				//���a�е�Ԫ�����У�����һ�ֳ�ջ����
			printf("%c ",str[a[k]]);
		printf("\n");
		sum++;							//��ջ���и�����1
	}
	if (i<n)							//���i��Ԫ�ؽ�ջʱ�ݹ�
	{	push(i);						//i��ջ
		process(i+1,a,j);				//�ݹ飺�Ӹ�״̬�����������ƵĲ���
		pop();							//��ջ�Իָ�����
	}
	if (!empty())		 				//��ջʱ�ݹ�
	{	x=pop();						//��ջx
		a[j]=x;							//��x�����a��
		j++;							//a��Ԫ�ظ�����1
		process(i,a,j);					//�ݹ飺�Ӹ�״̬�����������ƵĲ���
		push(x);						//��ջ�Իָ�����
	}
}
int main()
{	int a[MaxSize];
	initstack();
	printf("���г�ջ����:\n");
	process(0,a,0);					//i��0��ʼ��j��0��ʼ
	printf("��ջ���и���:%d\n",sum);
	return 1;
}
