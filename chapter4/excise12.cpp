#include "listring.cpp"

void deleteall(LinkStrNode *&s,char x)
{
	LinkStrNode *pre=s,*p=s->next;
	while (p!=NULL)
	{	if (p->data==x)
		{	pre->next=p->next;
			free(p);
			p=pre->next;
		}
		else
		{	pre=p;
			p=p->next;
		}
	}
}

int main()
{
	LinkStrNode *s;
	StrAssign(s,"aabcabcd");
	printf("s:");DispStr(s);
	deleteall(s,'a');
	printf("s:");DispStr(s);
	DestroyStr(s);
	return 1;
}
