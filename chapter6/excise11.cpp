#include"glist.cpp"

bool Same(GLNode *g1,GLNode *g2)
{	if (g1==NULL && g2==NULL)				//均为NULL的情况
		return true;						//返回真
	else if (g1==NULL || g2==NULL)			//一个为NULL,另一不为NULL的情况
		return false;						//返回假
	else									//均不空的情况
	{	if (g1->tag==0 && g2->tag==0)		//均为原子的情况
		{	if (g1->val.data!=g2->val.data)	//原子不相等
				return false;				//返回假
			return(Same(g1->link,g2->link));	//返回兄弟比较的结果
		}
		else if (g1->tag==1 && g2->tag==1)	//均为子表的情况
			return(Same(g1->val.sublist,g2->val.sublist) 
				& Same(g1->link,g2->link));
		else								//一个为原子,另一为子表的情况
			return false;					//返回假
	}
}

int main()
{
	GLNode *g1,*g2;
	char *str1="((a),b,(c,d))";
	g1=CreateGL(str1);
	printf("g1: "); DispGL(g1);	printf("\n");

	char *str2="((a),b,(c,x))";
	g2=CreateGL(str2);
	printf("g2: "); DispGL(g2);	printf("\n");

	printf("ans=%d\n",Same(g1,g2));
	DestroyGL(g1);
	DestroyGL(g2);
	return 1;
}


