#include"glist.cpp"
ElemType MaxAtom(GLNode *g)
{	char max='a',m;						//max����ֵΪ��ССд��ĸ'a'
	while (g!=NULL)
	{	if (g->tag==1)					//�ӱ�����
		{	m=MaxAtom(g->val.sublist);		//���ӱ�ݹ����
			if (m>max) max=m;
		}
		else
		{	if (g->val.data>max)			//Ϊԭ��ʱ������ԭ�ӱȽ�
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
	printf("���ԭ��=%c\n",MaxAtom(g));
	DestroyGL(g);
	return 1;
}


