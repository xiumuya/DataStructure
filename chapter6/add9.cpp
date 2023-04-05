#include"glist.cpp"
ElemType MaxAtom(GLNode *g)
{	char max='a',m;						//max赋初值为最小小写字母'a'
	while (g!=NULL)
	{	if (g->tag==1)					//子表的情况
		{	m=MaxAtom(g->val.sublist);		//对子表递归调用
			if (m>max) max=m;
		}
		else
		{	if (g->val.data>max)			//为原子时，进行原子比较
				max=g->val.data;
		}
		g=g->link;
	}
	return max;
}

int main()
{
	GLNode *g;
	char *str="((a),e,(c,d))";
	g=CreateGL(str);
	printf("g: "); DispGL(g); printf("\n");
	printf("最大原子=%c\n",MaxAtom(g));
	DestroyGL(g);
	return 1;
}


