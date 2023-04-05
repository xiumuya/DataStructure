#define MaxSize 100			//��������ϣ����
#define NULLKEY -1				//����չؼ���ֵ
typedef int KeyType;			//�ؼ�������
typedef char * InfoType;		//������������
typedef struct
{	KeyType key;				//�ؼ�����
	InfoType data;			//����������
	int count;				//̽�������
} HashTable[MaxSize];			//��ϣ������
int SearchHT1(HashTable ha,int p,int m,KeyType k)	//�ڹ�ϣ���в��ҹؼ���k
{	int adr,adr1,i=1,sign;
	adr=adr1=k % p;			//���ϣ����ֵ
	sign=1;
	while (ha[adr].key!=NULLKEY && ha[adr].key!=k)	//�ҵ���λ�ò���
	{	adr=(adr1+sign*i*i) % m;
		if (sign==1)
			sign=-1;
		else					//sign==-1
		{	sign=1;
			i++;
		}
	}
	if (ha[adr].key==k)			//���ҳɹ�
		return adr;
	else						//����ʧ��
		return -1;
}

