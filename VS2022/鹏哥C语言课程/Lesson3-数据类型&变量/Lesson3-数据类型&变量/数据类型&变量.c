#include <stdio.h>
#include <stdbool.h> // ʹ��������ͷ�ļ�; ��������:�ж���ٵ�һ����������

// {}�ⴴ���ı�����Ϊ ȫ�ֱ��� g_:global
int g_num = 100; // ȫ�ֱ����������г�ʼ����Ĭ��Ϊ0(�ֲ�������ͬ)

// {}�ڴ����ı�����Ϊ �ֲ�����(�ֲ�����)
int main()
{
	_Bool TorF = false; // ���岼�����ͱ���; ȡֵΪfalse(0)��true(1); 0��ʾ��, һ�з�0��ʾ��
	bool TorF2 = true; // ���岼�����ͱ�������һ��д��

	if (TorF)
	{
		printf("�ж�Ϊ��\n");
	}
	else
	{
		printf("�ж�Ϊ��\n");;
	}

	printf("%zd\n", sizeof(char)); // sizeof():�������ͳ���(��λ:�ֽ�Byte)������һ������ֵ 1Byte=8bit (1��2����λ�Ĵ洢��Ҫһ��bit����λ�οռ�0
	
	int a = 10;
	// sizeof�ļ�����Ϊsize_t����, ��Ҫ��%zd����ʽ���д�ӡ
	// sizeof������ʽ����ʱ��ʡ��(), �ñ��ʽ�������ʵ������, ����Ӱ�����ս�����
	printf("%zd\n", sizeof a);
	
	signed int num1 = -100; // signed:�з���(-����); signed int=int: ����Ϊ�����ɸ���������0
	unsigned int num2 = 100; // unsigned:�޷���(-����); unsigned int=unsigned: ����Ϊ�Ǹ�����
	printf("%d ", num1); // ��ӡsigned int��ʹ��%d
	printf("%u", num2); // ��ӡunsigned int��ʹ��%u

	int age = 18; // ��ʼ��:��������������һ����ֵ (p.s.)�ڴ�������ʱ���г�ʼ����һ�ֺõı��ϰ��, ��������г�ʼ��, �еı������ᱨ��
	age = 20; // ��ֵ:�������ĵ�ǰֵ�滻����ֵ
	char ch = 'a';
	float score = 3.14f; // ĩβ���f��ȷ��Ϊfloat����
	double weight = 4.5;
	bool flag = true;
	return 0;
}