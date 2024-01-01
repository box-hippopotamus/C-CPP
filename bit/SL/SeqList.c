#include "SeqList.h"
 
//��˳����ʼ�� 
void SLInit(SL* ps)
{
	ps->a = NULL;
	ps->size = 0;//��Ч���ݸ���
	ps->capacity = 0;//˳���ǰ�ռ��С
}

//����˳���
void SLDestroy(SL* ps) 
{
	if(ps->a)
		free(ps->a);
	ps->a = NULL;
	ps->size = 0;
	ps->capacity = 0;
}

//���ڶദʹ��capacity�ڴ��飬�˴���װ����
void SLCheckCapacity(SL* ps)
{
	//��ֹ��ָ��
	assert(ps != NULL);
	//˳����ʼ����Ĭ��capacityΪ0����ʱ��Ȼ��Ҫ���ٿռ�
	//���ڿ��ٿռ���Ҫ�õ�capacity*2����������������˳�����Զ�޷��ɹ����ٿռ�
	//��˳���ռ�Ϊ0���ȸ�ֵ4����ʱ����newcapacity������������ʱ���������ڴ�
	//��˳���ռ䲻Ϊ0��ֱ�Ӱ�capacity*2��ֵ��newcapacity������newcapacity�����ڴ�
	int NewCapacity = ps->capacity == 0 ? 4 : 2 * ps->capacity;

	if (ps->size == ps->capacity)//���ռ��㹻�����������ڴ棬ֱ�ӽ���β�岽��
	{
		//�ռ䲻����β��,�����ڴ�
		SLDataType* tmp = (SLDataType*)realloc(ps->a, NewCapacity * sizeof(SLDataType));
		//�����м�ָ��tmp����ֹ����ʧ�ܵ��½ṹ��ָ�뱻�ÿ�
		if (tmp == NULL)//ȷ���ռ俪�ٳɹ������˴�Ϊ��ָ�룬˵��realloc����ʧ��
		{
			perror("realloc fail!\n");
			return;
		}
		ps->a = tmp;
		ps->capacity = NewCapacity;
	}
}

//����˳����Ƿ�Ϊ��
bool SLIsEmpty(SL* ps)
{
	assert(ps != NULL);
	return ps->size == 0; 
}

//ͷ��
void SLPushFront(SL* ps, SLDataType x)
{
	//��ֹ��ָ��
	assert(ps != NULL);
	//��֤�ռ��㹻
	SLCheckCapacity(ps);
	//��ʷ���ݺ���һλ
	for (size_t i = ps->size; i > 0; i--)
	{
		ps->a[i] = ps->a[i - 1];//�Ӻ���ǰ���ƣ���ֹ��һ��ʹ�õ����ݱ�����
	}
	ps->a[0] = x;//ͷ������  
	ps->size++;
}
//β��
void SLPushBack(SL* ps, SLDataType x)
{
	//��ֹ��ָ��
	assert(ps != NULL);
	//��֤�ռ��㹻
	SLCheckCapacity(ps);
	//β�����룬size����������һλ���ĺ�һλ���±꣬ʹ�ú���++
	ps->a[ps->size++] = x;
}

//ͷɾ
void SLPopFront(SL* ps)
{

}
//βɾ 
void SLPopBack(SL* ps)  
{
	//��ֹ��ָ��
	assert(ps != NULL);
	//��ֹ��û�п���ɾ����ʱ��βɾ
	assert(!SLIsEmpty(ps));
	ps->size--;//ֱ�Ӱ�sizeǰ��һλ��
}

//���˳���
void SLPrint(SL* ps)
{
	assert(ps != NULL);
	for (size_t i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->a[i]);
	}
	printf("\n");
}
