#include <stdio.h>
void reverse()
{	char ch;
	scanf("%c",&ch);
	if (ch!='.')
	{	reverse();
		printf("%c",ch);
	}
}
int main()
{
	reverse();
	return 1;
}
	
