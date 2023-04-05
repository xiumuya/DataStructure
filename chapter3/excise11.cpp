#include "sqqueue.cpp"

void fun()
{
	ElemType a,e;
	SqQueue *qu;						//定义队列指针
	InitQueue(qu);
	while (true)
	{	printf("输入a:");
		scanf("%s",&a);
		if (a>='0' && a<='9')			//为数字字符
		{
			if (!enQueue(qu,a)) 
				printf("  队列满,不能进队\n");
		}
		else if (a>='a' && a<='z')		//为小写字母
		{
			if (!deQueue(qu,e)) 
				printf("  队列空,不能出队\n");
			else
				printf("  出队元素:%c\n",e);
		}
		else break;						//为其他字符
	}
	DestroyQueue(qu);
}


int main()
{
	fun();
	return 1;
}