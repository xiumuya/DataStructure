#include <stdio.h>
#define MaxSize 100
struct stacknode
{	int data[MaxSize];
	int top;
} st;							//全局变量，定义顺序栈
int n=4;					//全局变量，定义输入序列的元素个数
char str[]="abcd";				//全局变量，指定进栈序列
int sum=0;						//全局变量，累计出栈序列个数
//---------栈操作--------------------------------
void initstack()				//初始化顺序栈
{
	st.top=-1;
}
void push(int x)					//元素x进栈运算
{	st.top++;
	st.data[st.top]=x;
}
int pop()							//退栈运算
{	int temp;
	temp=st.data[st.top];
	st.top--;
	return temp;
}
bool empty()						//判断栈空否运算
{	if (st.top==-1)
		return true;
	else
		return false;
}
//---------------------------------------------

void process(int i,int a[],int j)		//处理C序列中i位置的元素
{	int x,k;
	if (i>=n && empty())				//输出一种可能的方案
	{	printf("  ");
		for (k=0;k<j;k++)				//输出a中的元素序列，构成一种出栈序列
			printf("%c ",str[a[k]]);
		printf("\n");
		sum++;							//出栈序列个数增1
	}
	if (i<n)							//编号i的元素进栈时递归
	{	push(i);						//i进栈
		process(i+1,a,j);				//递归：从该状态继续进行类似的操作
		pop();							//出栈以恢复环境
	}
	if (!empty())		 				//出栈时递归
	{	x=pop();						//出栈x
		a[j]=x;							//将x输出到a中
		j++;							//a中元素个数增1
		process(i,a,j);					//递归：从该状态继续进行类似的操作
		push(x);						//进栈以恢复环境
	}
}
int main()
{	int a[MaxSize];
	initstack();
	printf("所有出栈序列:\n");
	process(0,a,0);					//i从0开始，j从0开始
	printf("出栈序列个数:%d\n",sum);
	return 1;
}
