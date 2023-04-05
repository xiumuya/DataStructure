#include <stdio.h>
#define MaxSize 100
typedef struct					//集合结构体类型
{
	int data[MaxSize];			//存放集合中的元素，其中MaxSize为常量
	int length;					//存放集合中实际元素个数
} Set;							//将集合结构体类型用一个新类型名Set表示

void createset(Set &s,int a[],int n)	//创建一个集合
{
	int i;
	for (i=0;i<n;i++)
		s.data[i]=a[i];
	s.length=n;
}
bool inset(Set s,int e)			//判断e是否在集合s中
{	int i;
	for (i=0;i<s.length;i++)
		if (s.data[i]==e)
			return true;
	return false;
}
void add(Set s1,Set s2,Set &s3)	//求集合的并集
{	int i;
	for (i=0;i<s1.length;i++)	//将集合s1的所有元素复制到s3中
		s3.data[i]=s1.data[i];
	s3.length=s1.length;
	for (i=0;i<s2.length;i++)	//将s2中不在s1中出现的元素复制到s3中
		if (!inset(s1,s2.data[i]))
		{	s3.data[s3.length]=s2.data[i];
			s3.length++;
		}
}
void sub(Set s1,Set s2,Set &s3)	//求集合的差集
{	int i;
	s3.length=0;
	for (i=0;i<s1.length;i++)	//将s1中不出现在s2中的元素复制到s3中
		if (!inset(s2,s1.data[i]))
		{	s3.data[s3.length]=s1.data[i];
			s3.length++;
		}
}
void intersection(Set s1,Set s2,Set &s3)	//求集合的交集
{	int i;
	s3.length=0;
	for (i=0;i<s1.length;i++)		//将s1中出现在s2中的元素复制到s3中
		if (inset(s2,s1.data[i]))
		{	s3.data[s3.length]=s1.data[i];
			s3.length++;
		}
}
void dispset(Set s)		//输出一个集合
{
	int i;
	for (i=0;i<s.length;i++)
		printf("%d ",s.data[i]);
	printf("\n");
}
int main (void)
{
	Set s1,s2,s3,s4,s5;
	int a[]={1,2,3,4,5};
	int b[]={2,3,4,5,6,7,8};
	int n=5,m=7;
	createset(s1,a,n);
	createset(s2,b,m);
	printf(" s1:"); dispset(s1);
	printf(" s2:"); dispset(s2);
	printf(" s3=s1 ∪ s2\n");
	add(s1,s2,s3);
	printf(" s3:"); dispset(s3);
	printf(" s4=s1-s2\n");
	sub(s1,s2,s4);
	printf(" s4:"); dispset(s4);
	printf(" s5=s1 ∩ s2\n");
	intersection(s1,s2,s5);
	printf(" s5:"); dispset(s5);
}