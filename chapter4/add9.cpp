#include "listring.cpp"
bool Equal(LinkStrNode *s,LinkStrNode *t)
{	LinkStrNode *p=s,*q=t;
	while (p!=NULL && q!=NULL) 
	{	if (p->data!=q->data)
			return false;
		p=p->next;
		q=q->next;
	}
	if (p!=NULL || q!=NULL)
		return false;
	else
		return true;
}
int main()
{
	LinkStrNode *s,*t;
	StrAssign(s,"abcd");
	StrAssign(t,"abcd");
	printf("s:");DispStr(s);
	printf("t:");DispStr(t);

	printf("%d\n",Equal(s,t));
	DestroyStr(s);
	DestroyStr(t);

	return 1;
}

