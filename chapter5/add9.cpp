#include <stdio.h>
#include <string.h>
const int MAX=100;
char c[MAX][3];
int st=0,sp,n;			//ȫ�ֱ�����st��¼�ƶ��Ĳ��裬spָ��Ϊ'-'������
void print()				//���һ���ƶ�����
{	printf("  step%-2d:",++st);
	for (int i=1;i<=2*n+2;i++)
		printf("%s",c[i]);
	printf("\n");
}
void mvtosp(int k)		//��c[k]��c[k+1]����������'--'����
{	for (int j=0;j<=1;j++)
	{	strcpy(c[sp+j],c[k+j]);
		strcpy(c[k+j],"�D");
	}
	sp=k;			//spָ��"--"������
	print();			//���һ����
}
void mv(int n)		//���2n�������ƶ�����
{	if (n==4)			//�ݹ����
	{	mvtosp(4); mvtosp(8); mvtosp(2);
		mvtosp(7); mvtosp(1);
	}
	else				//���n>4�����
	{	mvtosp(n);
		mvtosp(2*n-1);
		mv(n-1); 
	}
}
void init(int n)		//��ʼ��c����
{	int i;
	st=0;
	sp=2*n+1;			//spָ���2n+1�����ӣ���"--"
	for (i=1;i<=n;i++)
		strcpy(c[i],"��");
	for (i=n+1;i<=2*n;i++)
		strcpy(c[i],"��");
	strcpy(c[2*n+1],"�D");
	strcpy(c[2*n+2],"�D");
}
int main()
{	do
	{	printf("����nֵ(4-20):");
		scanf("%d",&n);
	} while (n>20 || n<4);
	init(n);
	printf("�ƶ���������:\n");
	mv(n);
	printf("\n");
	return 1;
}

