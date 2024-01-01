#include "SeqList.h"
 
//对顺序表初始化 
void SLInit(SL* ps)
{
	ps->a = NULL;
	ps->size = 0;//有效数据个数
	ps->capacity = 0;//顺序表当前空间大小
}

//销毁顺序表
void SLDestroy(SL* ps) 
{
	if(ps->a)
		free(ps->a);
	ps->a = NULL;
	ps->size = 0;
	ps->capacity = 0;
}

//由于多处使用capacity内存检查，此处分装函数
void SLCheckCapacity(SL* ps)
{
	//防止空指针
	assert(ps != NULL);
	//顺序表初始化，默认capacity为0，此时必然需要开辟空间
	//由于开辟空间需要用到capacity*2，若不额外操作则此顺序表永远无法成功开辟空间
	//若顺序表空间为0，先赋值4给临时变量newcapacity，后续利用临时变量开辟内存
	//若顺序表空间不为0，直接把capacity*2赋值给newcapacity，利用newcapacity开辟内存
	int NewCapacity = ps->capacity == 0 ? 4 : 2 * ps->capacity;

	if (ps->size == ps->capacity)//若空间足够，跳过开辟内存，直接进入尾插步骤
	{
		//空间不足以尾插,开辟内存
		SLDataType* tmp = (SLDataType*)realloc(ps->a, NewCapacity * sizeof(SLDataType));
		//创建中间指针tmp，防止开辟失败导致结构体指针被置空
		if (tmp == NULL)//确保空间开辟成功，若此处为空指针，说明realloc开辟失败
		{
			perror("realloc fail!\n");
			return;
		}
		ps->a = tmp;
		ps->capacity = NewCapacity;
	}
}

//检验顺序表是否为空
bool SLIsEmpty(SL* ps)
{
	assert(ps != NULL);
	return ps->size == 0; 
}

//头插
void SLPushFront(SL* ps, SLDataType x)
{
	//防止空指针
	assert(ps != NULL);
	//保证空间足够
	SLCheckCapacity(ps);
	//历史数据后移一位
	for (size_t i = ps->size; i > 0; i--)
	{
		ps->a[i] = ps->a[i - 1];//从后往前后移，防止下一次使用的数据被覆盖
	}
	ps->a[0] = x;//头部插入  
	ps->size++;
}
//尾插
void SLPushBack(SL* ps, SLDataType x)
{
	//防止空指针
	assert(ps != NULL);
	//保证空间足够
	SLCheckCapacity(ps);
	//尾部插入，size本身就是最后一位数的后一位的下标，使用后置++
	ps->a[ps->size++] = x;
}

//头删
void SLPopFront(SL* ps)
{

}
//尾删 
void SLPopBack(SL* ps)  
{
	//防止空指针
	assert(ps != NULL);
	//防止在没有可以删除的时候尾删
	assert(!SLIsEmpty(ps));
	ps->size--;//直接把size前移一位，
}

//输出顺序表
void SLPrint(SL* ps)
{
	assert(ps != NULL);
	for (size_t i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->a[i]);
	}
	printf("\n");
}
