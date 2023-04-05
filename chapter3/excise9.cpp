#include "listack.cpp"

bool judge(char str[],int n)
{	int i=0; ElemType x;
	LinkStNode *ls;
	bool flag=true;
	InitStack(ls);
	while (i<n && flag) 
	{	if (str[i]=='I')			//进栈
			Push(ls,str[i]);
		else if (str[i]=='O')		//出栈
		{	if (StackEmpty(ls))
				flag=false;			//栈空时
			else
				Pop(ls,x);
		}
		else 
			flag=false;			//其他值无效
		i++;
	}
	if (!StackEmpty(ls)) flag=false;
	DestroyStack(ls);
	return flag;
}

int main()
{
	char stra[]="IOIIOIOO";
	printf("A:%d\n",judge(stra,8));
	char strb[]="IOOIOIIO";
	printf("B:%d\n",judge(strb,8));
	char strc[]="IIIOIOIO";
	printf("C:%d\n",judge(strc,8));
	char strd[]="IIIOOIOO";
	printf("D:%d\n",judge(strd,8));
	return 1;
}