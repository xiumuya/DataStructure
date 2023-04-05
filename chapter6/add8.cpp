#include"glist.cpp"
void Change(GLNode *&g,ElemType s,ElemType t)
{	if (g!=NULL)
	{	if (g->tag==1)			//子表的情况
			Change(g->val.sublist,s,t);
		else if (g->val.data==s)	//原子且data域值为s的情况
			g->val.data=t;
		Change(g->link,s,t);
	}
}

int main()
{
	GLNode *g;
	char *str="((a),a,(c,a))";
	g=CreateGL(str);
	printf("g: "); DispGL(g); printf("\n");
	printf("a->x\n");
	Change(g,'a','x');
	printf("g: "); DispGL(g); printf("\n");
	
	DestroyGL(g);
	return 1;
}


