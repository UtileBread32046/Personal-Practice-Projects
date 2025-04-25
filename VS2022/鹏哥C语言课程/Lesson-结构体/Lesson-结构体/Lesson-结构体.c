#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stddef.h> // ����offsetof()����

// �ṹ��һЩֵ�ļ���, ��Щֵ��Ϊ��Ա����. �ṹ��ÿ����Ա�����ǲ�ͬ���͵ı���

// �ṹ�����͵�����
struct Book // Ҳ���Էŵ�main�������������
{
	char book_name[20];
	char author[20];
	float price; // ���������ڴ����п����޷���ȷ����(���������ֵ��Ԥ�ڲ���)
	char id[19];
}b4, b5, b6; // ���ɺ��Դ˴��ķֺ�;!!!
// �������ṹ��(ȫ��)�����Ĵ���(����)(������}�ͷֺ�;���м䶨�������)

// �ṹ�����������(����ȫ����)
struct // �����ṹ��(������ṹ�������)(ֻ��ʹ��һ��)
{
	char c;
	int i;
	double d;
}s1, s2;

// �ṹ���������
// ͨ���ṹ���ָ��Ľ����������
typedef struct Node // �Խṹ������������
{
	int data; // ������(�������)
	struct Node* next; // ָ����(��ŵ�ַ); �˴�������ȥ���Ǻ�*, ����ṹ���ڴ��޷����㵼�±���; �˴���ʹ�ýṹ��ԭ�������Զ�������
}Node; // �˴�ʹ��typedef�ؼ��ֽ�struct Node��дΪNode

// �ṹ���ڴ����
// �ṹ��ĳ�Ա���ڴ��д���"����"����, һ˵��ƽ̨ԭ��, һ˵������ԭ��(�����ڴ��ȡ����, ʱ�临�Ӷ�ת��Ϊ�ռ临�Ӷ�)
// Ϊ��ʡ�ռ�, ����ռ�ÿռ�С�ĳ�Ա������һ��
/* �������
   1.�ṹ��ĵ�һ����Ա���뵽�ͽṹ�������ʼλ��ƫ����Ϊ0�ĵ�ַ��
   2.������Ա����Ҫ���뵽ĳ������(������)���������ĵ�ַ��; ������ = min{������Ĭ�϶�����, �ó�Ա������С}; VS��Ĭ�϶�����Ϊ8; Linux��gccû��Ĭ�϶�����(��������Ϊ��Ա�����С)
   3.�ṹ���ܴ�СΪ��������(�ṹ����ÿ����Ա�����Ķ������е����ֵ)��������
   4.�����ڽṹ��Ƕ��ʱ, Ƕ�׵Ľṹ���Ա���뵽�Լ��ĳ�Ա��������������������, �ṹ��������С����������������(��Ƕ�׽ṹ���г�Ա�Ķ�����)��������
*/
struct S1
{
	char c1; // 1
	char c2; // 1 -> 4
	int n; // 4
};
struct S2
{
	char c1; // 1 -> 4
	int n; // 4
	char c2; // 1 -> 4
};
struct S3
{
	double d; // 8
	char c; // 1 -> 4
	int i; // 4
};
struct S4
{
	char c1; // 1 -> 4
	struct S3 s3; // 16
	double d; // 8
};

// �޸�Ĭ�϶�����
#pragma pack(1) // ��Ĭ�϶���������Ϊ1
struct S5
{
	char c1;
	int n;
	char c2;
};
#pragma pack() // ����Ĭ�϶�����

struct S
{
	int arr[1000];
	int n;
	char ch;
};

void print1(struct S tmp)
{
	for (int i = 0; i < 10; i++)
		printf("%d ", tmp.arr[i]);
	printf("\n");
	printf("n = %d\n", tmp.n);
	printf("ch = %c\n", tmp.ch);
}

void print2(struct S* ps)
{
	for (int i = 0; i < 10; i++)
		printf("%d ", ps->arr[i]);
	printf("\n");
	printf("n = %d\n", ps->n);
	printf("ch = %c\n", ps->ch);
}

// �ṹ��ʵ��λ��
// λ: �������е�λ; ��ʹ��λ�ν�һ����ʡ�ռ�
// λ�ε�������ṹ������, ��λ�εĳ�Ա������int, unsigned int, signed int(��C99��Ҳ��ѡ����������)), ��λ�εĳ�Ա������һ��ð�ź�һ������
// λ�ε��ڴ����
// λ�εĳ�Ա������int, unsigned int, signed int, char
// λ�εĿռ��ǰ�����Ҫ��4���ֽ�(int)��1���ֽ�(char)�ķ�ʽ�����ٵ�
// intλ����û�з��Ų�ȷ��; λ�������λ��Ŀ��ȷ��; λ�γ�Ա���ڴ��еķ��䷽���ޱ�׼; λ�γ�Ա�޷���������ʣ��λʱ, ʣ��λ���û��˷Ѳ�ȷ��
// λ�ο��Դﵽ��ṹ��ͬ��Ч��, ���ҿ��Ժܺõؽ�ʡ�ռ�; λ�β���ƽ̨, ע�ؿ���ֲ�ĳ���Ӧ������ʹ��λ��; λ�ο���Ӧ��������Э����, ����������ĳ�ͨ
// λ��ʹ�õ�ע������
// λ�εļ�����Ա����һ���ֽ�, ���в��ֳ�Ա����ʼλ�ò��ڸ��ֽڵ���ʼλ��, ��û�е�ַ(�ֽ��е�ַ, �ֽ��ڲ���bitλû�е�ַ), ���Բ���ʹ��scanf( , &��Ա��)�ķ�ʽֱ�Ӹ���Ա����ֵ, �����������һ��������ͨ��������ֵ����Ա
struct A
{
	// _������ Ϊһ��ϰ��, ��ʾ��Ϊһ����Ա����
	int _a : 2; // ռ2������λ
	int _b : 5;
	int _c : 10;
	int _d : 30; // ����ֵ���ɳ���32(���α���4���ֽ����ռ32������λ)
};

int main()
{
	struct Book b1; // �ṹ��(�ֲ�)�����Ĵ���(��һ)
	struct Book b2 = {"����C����", "����", 38.8f, "PG20240520"}; // �ṹ������ĳ�ʼ��(˳��)
	struct Book b3 = {.id="DG20240520", .book_name="����Linux", .author="����", .price=55.5f}; // �ṹ������ĳ�ʼ��(����):.��Ա��=
	struct S4 s4;
	printf("%s %s %f %s\n", b2.book_name, b2.author, b2.price, b2.id);
	printf("%s %s %f %s\n", b3.book_name, b3.author, b3.price, b3.id);
	printf("\n");

	// offsetof: C�����е�һ�ֺ�(һ��Ԥ����Ĵ���Ƭ��, �����ڳ����н����滻, �ṩһ�ַ���ķ�ʽ������һЩ���������һЩ�򵥵Ĵ����滻����)
	// ����ṹ���Ա�ཻ�ڽṹ�������ʼλ�õ�ƫ����
	printf("%zd ", offsetof(struct S1, c1));
	printf("%zd ", offsetof(struct S1, c2));
	printf("%zd ", offsetof(struct S1, n));
	printf("sum = %zd\n", sizeof(struct S1));

	printf("%zd ", offsetof(struct S2, c1));
	printf("%zd ", offsetof(struct S2, n));
	printf("%zd ", offsetof(struct S2, c2));
	printf("sum = %zd\n", sizeof(struct S2));

	printf("%zd ", offsetof(struct S3, d));
	printf("%zd ", offsetof(struct S3, c));
	printf("%zd ", offsetof(struct S3, i));
	printf("sum = %zd\n", sizeof(struct S3));

	printf("%zd ", offsetof(struct S4, c1));
	printf("%zd ", offsetof(struct S4, s3));
	printf("%zd ", offsetof(struct S4, d));
	printf("sum = %zd\n", sizeof(struct S4));

	printf("%zd ", offsetof(struct S5, c1));
	printf("%zd ", offsetof(struct S5, n));
	printf("%zd ", offsetof(struct S5, c2));
	printf("sum = %zd\n", sizeof(struct S5));
	printf("\n");

	// �ṹ�崫��
	struct S s = { {1,2,3,4,5,6,7,8,9,10}, 10, 'w' };
	print1(s); // ��ֵ����; ���ٴδ���һ���ڴ��Сһ���Ľṹ��, ���Ŀռ�; ��������ʱ������Ҫѹջ, ��ʱ��Ϳռ��ϵ�ϵͳ����, ���������½�
	print2(&s); // ���ݵ�ַ, ���Ŀռ���; ���Խṹ�崫��ʱ, Ҫ���ݽṹ��ĵ�ַ(���Ҵ��ݵ�ַ�����޸�ԭ����(����const����ָ��ָ�������, ��ֹ�޸�����), ������ֵ������)
	printf("\n");

	printf("%zd\n", sizeof(struct A));


	return 0;
}