#define MaxSize 100			//定义最大哈希表长度
#define NULLKEY -1				//定义空关键字值
typedef int KeyType;			//关键字类型
typedef char * InfoType;		//其他数据类型
typedef struct
{	KeyType key;				//关键字域
	InfoType data;			//其他数据域
	int count;				//探测次数域
} HashTable[MaxSize];			//哈希表类型
int SearchHT1(HashTable ha,int p,int m,KeyType k)	//在哈希表中查找关键字k
{	int adr,adr1,i=1,sign;
	adr=adr1=k % p;			//求哈希函数值
	sign=1;
	while (ha[adr].key!=NULLKEY && ha[adr].key!=k)	//找到的位置不空
	{	adr=(adr1+sign*i*i) % m;
		if (sign==1)
			sign=-1;
		else					//sign==-1
		{	sign=1;
			i++;
		}
	}
	if (ha[adr].key==k)			//查找成功
		return adr;
	else						//查找失败
		return -1;
}

