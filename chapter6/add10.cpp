#include"glist.cpp"
int AtomSum(GLNode *g)
{	int s=0;
	if (g!=NULL)
	{	if (g->tag==1)			//Ϊ�ӱ�ʱ
			s+=AtomSum(g->val.sublist);
		else						//Ϊԭ��ʱ
			s+=g->val.data-'0';
		s+=AtomSum(g->link);		//���ֵܵ�ԭ��֮��
	}
	return s;
}

int main()
{
	GLNode *g;
	char *str="((1),4,(2,3))";
	g=CreateGL(str);
	printf("g: "); DispGL(g); printf("\n");
	printf("ԭ�Ӻ�=%d\n",AtomSum(g));
	DestroyGL(g);
	return 1;
}


