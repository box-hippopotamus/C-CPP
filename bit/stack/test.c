#include "stack.h"

int main()
{
	ST s;
	STInit(&s);

	STPush(&s, 1);
	STPush(&s, 2);
	STPush(&s, 3);
	STPush(&s, 4);
	STPush(&s, 5);

	//����ջ�����ʣ�ÿ��ֻ�ܷ���ջ����Ԫ�أ���Ҫ��������Ԫ�أ������ջ
	//�����ջ˳��̶�����ջ˳����ʵ���̶���������ĳ��ֵ��ջ��ͬʱ��ջ������û����ȫ��ջ�ͳ�ջ�˲�������
	while (!STEmpty(&s))
	{
		printf("%d ", STTop(&s));
		STPop(&s);
	}
	printf("\n");
	return 0;
}