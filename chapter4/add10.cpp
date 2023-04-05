#include "listring.cpp"
int LastPos(LinkStrNode *s,LinkStrNode *t)
{	int i=0,idx=0;
	LinkStrNode *p=s->next,*q,*r;
	while (p!=NULL)
	{	i++;
		q=p;
		r=t->next;
		while (q!=NULL && r!=NULL && q->data==r->data)
		{	q=q->next;
			r=r->next;
		}
		if (r==NULL)			//ÕÒµ½×Ó´®
			idx=i;
		p=p->next;
	}
	return idx;
}
int main()
{
	LinkStrNode *s,*t;
	StrAssign(s,"ababcd");
	StrAssign(t,"abcd");
	printf("s:");DispStr(s);
	printf("t:");DispStr(t);

	printf("%d\n",LastPos(s,t));
	DestroyStr(s);
	DestroyStr(t);

	return 1;
}

