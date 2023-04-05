#include"glist.cpp"

bool Same(GLNode *g1,GLNode *g2)
{	if (g1==NULL && g2==NULL)				//��ΪNULL�����
		return true;						//������
	else if (g1==NULL || g2==NULL)			//һ��ΪNULL,��һ��ΪNULL�����
		return false;						//���ؼ�
	else									//�����յ����
	{	if (g1->tag==0 && g2->tag==0)		//��Ϊԭ�ӵ����
		{	if (g1->val.data!=g2->val.data)	//ԭ�Ӳ����
				return false;				//���ؼ�
			return(Same(g1->link,g2->link));	//�����ֵܱȽϵĽ��
		}
		else if (g1->tag==1 && g2->tag==1)	//��Ϊ�ӱ�����
			return(Same(g1->val.sublist,g2->val.sublist) 
				& Same(g1->link,g2->link));
		else								//һ��Ϊԭ��,��һΪ�ӱ�����
			return false;					//���ؼ�
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


