#include "listack.cpp"

bool judge(char str[],int n)
{	int i=0; ElemType x;
	LinkStNode *ls;
	bool flag=true;
	InitStack(ls);
	while (i<n && flag) 
	{	if (str[i]=='I')			//��ջ
			Push(ls,str[i]);
		else if (str[i]=='O')		//��ջ
		{	if (StackEmpty(ls))
				flag=false;			//ջ��ʱ
			else
				Pop(ls,x);
		}
		else 
			flag=false;			//����ֵ��Ч
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