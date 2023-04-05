//广义表基本运算算法
#include <stdio.h>
#include <malloc.h>
#include "glnode.h"
int GLLength(GLNode *g)			//求广义表g的长度
{
	int n=0;
	GLNode *g1;
	g1=g->val.sublist;			//g指向广义表的第一个元素
	while (g1!=NULL)
	{	
		n++;					//累加元素个数
		g1=g1->link;
	}
	return n;
}
int GLDepth(GLNode *g)			//求广义表g的深度
{
	GLNode *g1;
	int maxd=0,dep;
	if (g->tag==0)				//为原子时返回0
		return 0;
	g1=g->val.sublist;			//g1指向第一个元素
	if (g1==NULL)				//为空表时返回1
		return 1;
	while (g1!=NULL)			//遍历表中的每一个元素
	{	
		if (g1->tag==1)			//元素为子表的情况
		{
			dep=GLDepth(g1);	//递归调用求出子表的深度
			if (dep>maxd)		//maxd为同一层所求过的子表中深度的最大值
				maxd=dep;
		}
		g1=g1->link;			//使g1指向下一个元素
	}
	return(maxd+1);				//返回表的深度
}
GLNode *CreateGL(char *&s)				//创建由括号表示法表示s的广义表链式存储结构
{
	GLNode *g;
	char ch=*s++;						//取一个字符
	if (ch!='\0')						//串未结束判断
	{
		g=(GLNode *)malloc(sizeof(GLNode));//创建一个新结点
		if (ch=='(')					//当前字符为左括号时
		{
			g->tag=1;					//新结点作为表头结点
			g->val.sublist=CreateGL(s); //递归构造子表并链到表头结点
		}
		else if (ch=='#')				//遇到'#'字符，表示为空表
			g=NULL;
		else							//为原子字符
		{
			g->tag=0;					//新结点作为原子结点
			g->val.data=ch;
		}
	}
	else								//串结束,g置为空
		g=NULL;
	ch=*s++;                           	//取下一个字符
	if (g!=NULL)                      	//串未结束，继续构造兄递结点
	{
		if (ch==',')                  	//当前字符为','
			g->link=CreateGL(s);   		//递归构造兄递结点
		else                            //没有兄弟了,将兄弟指针置为NULL
			g->link=NULL;
	}
	return g;                     		//返回广义表g
}
void DestroyGL(GLNode *&g)		//销毁广义表
{
	GLNode *g1,*g2;
	g1=g->val.sublist;			//g1指向广义表的第一个元素
	while (g1!=NULL)			//遍历所有元素
	{
		if (g1->tag==0)			//若为原子结点
		{	g2=g1->link;		//g2临时保存兄弟结点
			free(g1);			//释放g1所指原子结点
			g1=g2;				//g1指向后继兄弟结点
		}
		else					//若为子表
		{	g2=g1->link;		//g2临时保存兄弟结点
			DestroyGL(g1);		//递归释放g1所指子表的空间
			g1=g2;				//g1指向后继兄弟结点
		}
	}
	free(g);					//释放头结点空间
}

void DispGL(GLNode *g)					//输出广义表g
{
	if (g!=NULL)                 		//表不为空判断
	{									//先处理g的元素
		if (g->tag==0)               	//g的元素为原子时
			printf("%c", g->val.data);  //输出原子值
		else							//g的元素为子表时
		{
			printf("(");                //输出'('
			if (g->val.sublist==NULL)  	//为空表时
				printf("#");
			else						//为非空子表时
				DispGL(g->val.sublist); //递归输出子表
			printf(")");               	//输出')'
		}
		if (g->link!=NULL) 
		{
			printf(",");
			DispGL(g->link);            //递归输出后续表的内容
		}
	}
}
