#include"glist.cpp"
int AtomSum(GLNode *g)
{	int s=0;
	if (g!=NULL)
	{	if (g->tag==1)			//为子表时
			s+=AtomSum(g->val.sublist);
		else						//为原子时
			s+=g->val.data-'0';
		s+=AtomSum(g->link);		//求兄弟的原子之和
	}
	return s;
}

int main()
{
	GLNode *g;
	char *str="((1),4,(2,3))";
	g=CreateGL(str);
	printf("g: "); DispGL(g); printf("\n");
	printf("原子和=%d\n",AtomSum(g));
	DestroyGL(g);
	return 1;
}


