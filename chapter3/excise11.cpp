#include "sqqueue.cpp"

void fun()
{
	ElemType a,e;
	SqQueue *qu;						//�������ָ��
	InitQueue(qu);
	while (true)
	{	printf("����a:");
		scanf("%s",&a);
		if (a>='0' && a<='9')			//Ϊ�����ַ�
		{
			if (!enQueue(qu,a)) 
				printf("  ������,���ܽ���\n");
		}
		else if (a>='a' && a<='z')		//ΪСд��ĸ
		{
			if (!deQueue(qu,e)) 
				printf("  ���п�,���ܳ���\n");
			else
				printf("  ����Ԫ��:%c\n",e);
		}
		else break;						//Ϊ�����ַ�
	}
	DestroyQueue(qu);
}


int main()
{
	fun();
	return 1;
}