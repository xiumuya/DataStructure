#include <stdio.h>
void swap(char& x,char &y)
{
	char tmp=x;
	x=y; y=tmp;
}
void print(char str[],int n)	//���һ������
{	for (int i=0;i<n;i++)
		printf("%c ",str[i]);
	printf("\n");
}
void perm(char str[],int k,int n)
{	int i;
	if (k==n-1)
		print(str,n);
	else
	{	for (i=k;i<n;i++)
		{	swap(str[k],str[i]);	//����str[k]��str[i]
			perm(str,k+1,n);
			swap(str[k],str[i]);	//����str[k]��str[i]
		}
	}
}
int main()
{	int n=3;
	char a[4]="123";
	printf("123��ȫ��������:\n");
	perm(a,0,n);
	return 1;
}
	
