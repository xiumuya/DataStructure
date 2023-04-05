#include <stdio.h>
#define MaxSize 100
typedef char ElemType;
typedef struct 
{	ElemType S[MaxSize];		//存放共享栈中的元素
	int top1,top2;				//两个栈顶指针
} StackType;					//声明共享栈类型
//-----栈初始化算法------
void InitStack1(StackType &st)
{	st.top1=-1;
	st.top2=MaxSize;
}
//-----判栈空算法------
bool StackEmpty1(StackType st,int i)	//i=1:栈1，i=2:栈2
{	if (i==1)
		return(st.top1==-1);
	else 	//i=2
		return(st.top2==MaxSize);
}
//-----进栈算法------
bool Push1(StackType &st,int i,ElemType x)	//i=1:栈1，i=2:栈2
{	if (st.top1==st.top2-1)			//栈满
		return false;
	if (i==1)						//x进栈S1
	{	st.top1++;
		st.S[st.top1]=x;
	}
	else if (i==2)					//x进栈S2
	{	st.top2--;
		st.S[st.top2]=x;
	}
	else							//参数i错误返回false
		return false;
	return true;					//操作成功返回true
}
//-----出栈算法------
bool Pop1(StackType &st,int i,ElemType &x) //i=1:栈1，i=2:栈2
{	if (i==1)						//S1出栈
	{	if (st.top1==-1)			//S1栈空
			return false;
		else						//出栈S1的元素
		{	x=st.S[st.top1];
			st.top1--;
		}
	}
	else if (i==2)					//S2出栈
	{	if (st.top2==MaxSize)		//S2栈空
			return false;
		else						//出栈S2的元素
		{	x=st.S[st.top2];
			st.top2++;
		}
	}
	else							//参数i错误返回false
		return false;
	return true;					//操作成功返回true
}
