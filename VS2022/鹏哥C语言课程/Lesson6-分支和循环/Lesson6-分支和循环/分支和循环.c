#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h> // ʹ������ѧͷ�ļ�, ʹ�ü�����صĿ⺯��
#include <string.h> // ʹ�����ַ���ͷ�ļ�, ʹ��strcmp����
#include <time.h> // ʹ����timeͷ�ļ�, �Ӷ�����time����
#include <stdlib.h> // ʹ������׼��ͷ�ļ�, �ɵ���system, rand, srand�ȿ⺯��ִ��ϵͳ����; standard+library=stdlib
// system("shutdown -s -t 60"); // ����ϵͳָ��ʹ�������60���ػ�
// system("shutdown -a"); // ȡ�������ػ�ָ��

// ���庯�����ɷŵ�main������
void menu() // ʹ��void�Զ���һ�������ؾ���ֵ�ĺ���
{
	printf("------------\n");
	printf("|  1.PLAY  |\n");
	printf("|          |\n");
	printf("|  2.EXIT  |\n");
	printf("------------\n");
}

int main()
{
	// if��֧
	// if�ж����ĩβ���ɼ���;, �����ִ�п���������ж�
	// Ĭ�������if��else����ֻ�ܸ�һ�����, ����������ᱨ������ж���������, ������Ӷ�������ʹ��{}
	// �����б����볣���ıȽ�ʱ, ������������==����Է�ֹ�ٴ�=
	int judge = 0;
	printf("������һ������(�ж����):");
	scanf("%d", &judge);
	if (0 == judge) // ���(Ϊ��)��ִ��; ==:�ж���ȷ��� !=:�жϲ���ȷ���; =:��ֵ, �޷��Ƚϴ�С�ͳ䵱����
		printf("�ж�Ϊ��\n");
	else // ����
		printf("�ж�Ϊ��\n");

	// �ж�������żС��
	int num = 0;
	printf("������һ������(�ж�������ż):");
	scanf("%d", &num);
	if (num == 0)
		printf("0Ϊ��\nһ�з�����Ϊ��\n");
	else if (num > 0) // Ƕ��(�򻯰�); ���е�else if������ĩβ��elseǰ��
		printf("%dΪ����\n", num);
	else
		printf("%dΪ����\n", num);
	if (num % 2 == 1) // �ж�����numֵ����2�������Ƿ�Ϊ1
		printf("%dΪ����\n", num);
	else
		printf("%dΪż��\n", num);


	// �ж�����С��
	int age = 0;
	printf("�����꼸����(������ϵͳ)?\n");
	scanf("%d", &age);
	if (age >= 18)
	// ʹ��{}���ƶ������:�����(�������)
	{ 
		printf("���ѳ���\n");
		printf("��ϲ���������ѽ��!\n");
	}
	else
	{
		printf("��δ����\n");
		printf("���ź���δ�ܽ������������\n");
	}


	// C������else��;��������if����ƥ��, �����������޹�
	// ��һ:��һ��if�����else;��ִ�п���������ж�
	// ����:���ڶ����ж��������{}��(�ɲ����else)
	int a = 0;
	int b = 0;
	int c = 0;
	printf("��ֱ�����a, b, c��ֵ:");
	scanf("%d%*c%d%*c%d", &a, &b, &c);
	if (a == 1)
	{
		if (b == 0)
		{
			printf("a=1��b=0\n");
		}
	} 
	else // �����else��Ĭ������»�����������ifƥ��(�˴�����{}������Ӱ��)
	{
		printf("a��1\n");
	}

	// ��ϵ�������������, ��a < b < c�ȼ���(a < b) < c, ��(a < b)Ϊ�������1��c���бȽ�
	if (a < b && b < c) // &&:����(and)
	{
		printf("a<b<c\n");
	}

	// ����������(��Ŀ������) exp1 ? exp2 : exp3:���exp1Ϊ��, ��exp2���м���, ��֮exp3���м���, ����Ľ�����������ʽ�Ľ��
	b = a > 5 ? 3 : -3;
	// �ȼ���
	/*if (a > 5)
	*     b = 3;
	* else
	*     b = -3;
	*/
	printf("a = %d\nb = %d\n", a, b);
	 
	// �߼������� !:ȡ��, �ı䵥�����ʽ�����; &&:��, ͬ���Ϊ��; ||:��, ͬ�ٲ�Ϊ��
	// ��·��ֵ: ��ʹ���߼�������ʱ, ��������������������֪���������ʽ�Ľ��, ���ٽ����Ҳ�����������
	int number0 = 0;
	int number1 = 0;
	int number2 = 0;
	int number3 = 0;
	int number4 = 0;
	number0 = (++number1 && number2++ || ++number3 && number4++); // ++number1(�ȼ����ֵ):�ȼ���number1 = number1 + 1, ������Ϊ1(�ж�Ϊ��) \
	��������number2++(�ȸ�ֵ�����): number2 = number2 + 1, ������Ϊ0(�ж�Ϊ��), ��ֹ||ǰ����Ľ��� \
	��������||�������, �Դ�����... \
	()��Ϊ�߼��ж�, �����������Ϊ����number0 = 1, ��֮number0 = 0
	printf("number0 = %d\nnumber1 = %d\nnumber2 = %d\nnumber3 = %d\nnumber4 = %d\n", number0, number1, number2, number3, number4);


	// switch:һ��������ʽ��if...else�ṹ, �����ж������ж����������, �Ѷ��else if�ĳɸ�����, �ɶ��Ը��õ���ʽ
	// case/defaultִ�����������ʵ����Ҫ����break, ���������������ͨ��ƥ�����µ����
	// ���ж����������������ʱ, ��ʹ�������е�case�������һ���жϺ����break�Խ��м�����д
	// ����С��
	int n = 0;
	printf("������һ������(�ж��Ƿ�ɱ�3����):");
	scanf("%d", &n);
	switch (n % 3) // ()�ڱ���Ϊ���α��ʽ
	{
	case 0: // case���ֵ����Ϊ���γ������ʽ(�����ַ�����)
		printf("%d���Ա�3����\n", n);
		break;
	case 1:
		printf("%d�����Ա�3����, ����Ϊ1\n", n);
		break;
	default: // caseƥ��ʧ��ʱִ��(�������ж�����ֵ�Ƿ��ڿ��з�Χ��)(default��case���û��˳������)
		printf("%d�����Ա�3����, ����Ϊ2\n", n);
		break;
	}


	// whileѭ��
	// while��if�﷨����, ִ�ж����ʱ��ʹ��{}
	// whileѭ�����һֱ���������ͻ������ѭ��(����ֹѭ��)
	// whileѭ����ʼ�����жϱ��ʽ��Է�ɢ
	// ���ֵ���С��
	int reverse = 0;
	printf("������һ������, ֮�󽫶�����е���: ");
	scanf("%d", &reverse);
	while (reverse >= 1) // �˴�()�ڿ�ֱ��дreserve���ж���ֵ�Ƿ�Ϊ0
	{
		printf("%d", reverse % 10);
		reverse = reverse / 10;
	}
	printf("\n");


	// forѭ��
	// ִ�ж����ʱͬ����Ҫ{}
	// for(���ʽ1; ���ʽ2; ���ʽ3) 1:��ʼ�����ʽ 2:�жϱ��ʽ 3:����
	// ��forѭ�����ж�������һ��ʼΪ������Զ�������ѭ��
	// Ѱ�ұ���С��
	int i = 0;
	int sum = 0;
	printf("1~100��3�α�����:");
	for (i = 1; i <= 100; i++) // ���ж�i��100���ڶ���ֱ���ж��Ƿ���3�ı�����ȷ��ѭ������������
	// Ϊ�򻯲���Ҳ�ɽ�����i��ʼ��Ϊ3��ÿ��+3, ����ʡȥ������жϲ���	
	{
		if (i % 3 == 0) // ��ѭ���ڲ����б����ж�
		// �˴������˼�{}!
		{
			printf("%d, ", i);
			sum += i;
		}
	}
	printf("��Щ�����ܺ�Ϊ%d\n", sum);


	// do whileѭ��
	// do whileѭ�����Ƚ���һ��ѭ�������ж��Ƿ������һ�ε�ѭ��(ѭ��������ִ��һ��)
	i = 1;
	do
	{
		printf("%d ", i);
		i++;
	}
	while (i <= 10);
	printf("\n");

	// �ж�λ��С��
	int input = 0;
	int numRead = 0;
	sum = 0;
	for (;;)
	{
		printf("������һ��������(�ж�λ��):");
		numRead = scanf("%d", &input);
		if (numRead == 1 && input > 0) // �ж���������Ϊ��������Ϊ��(�˴��޷��ų�С������)
		{
			for (; input > 0; input = input / 10)
				sum++;
			printf("�����������%dλ��\n", sum);
			break;
		}
		else
		{
			printf("����������ֲ�������������\n");
			while (getchar() != '\n'); // ������������ַ�, ��ֹ���������ѭ��
		}
	}


	// break��� 
	// break������������ѭ��, ����ִ�к�������(һ��breakֻ������һ��forѭ��)
	i = 1;
	while (i <= 10)
	{
		if (i == 5)
			break; // ����������ʱ�˳�ѭ��ִ�к�������
		printf("%d ", i);
		i++;
	}
	printf("\n");

	for (i = 1; i <= 10; i++)
	{
		if (i == 5)
			break;
		printf("%d ", i);
	}
	printf("\n");

	i = 1;
	do
	{
		if (i == 5)
			break;
		printf("%d ", i);
		i++;
	} 
	while (i <= 10);
	printf("\n");


	// continue���
	// continue������������ѭ����continue����Ĵ���(��forѭ����whileѭ�����в���)
	i = 0;
	while (i < 10) // �˴���д��i<=10����ں�����ͨ��i++��ӡ��11, ������Ϊi<10
	{
		i++; // �˴������i++˳��, ��ֹ������ӡ������
		if (i == 5)
			continue; // ����������ʱ��������Ĵ�ӡ�������¿�ʼѭ��
		printf("%d ", i);
	}
	printf("\n");

	for (i = 1; i <= 10; i++)
	{
		if (i == 5)
			continue;
		printf("%d ", i);
	}
	printf("\n");
	

	// ������ӡС��(�Գ���)
	int j = 2;
	int input_begin = 0;
	int input_over = 0;
	int count = 0;
	for (;;)
	{
		printf("�������������ĸ���������Ѱ������: \n");
		scanf("%d", &input_begin);
		scanf("%d", &input_over);
		if (input_begin <= input_over) // �ж�����������Ƿ��������������?
			break;
		else
		{
			printf("������ķ�Χ������!\n");
			while (getchar() != '\n'); // ������������ַ�, ��ֹ���������ѭ��
		}
	}
	for (i = input_begin; i <= input_over; i++) // �˴���ͨ����ʼ��iΪ�Դ����������i+=2���ų�ż�������������, ���㷨
	{
		if (i == 1)
			continue;
		/* �����жϼ��㷨: ������m = a*b, ��a��b��������һ������ < ��m (ͨ���˷����ɼ������������) */
		for (j = 2; j <= sqrt(i); j++) // ѭ���ж���1~��i�������Ƿ����i��Լ��, ����ɸѡ������; ����������ֱ�ӱȽ�i��j�Ĵ�С��ϵ
		// sqrt(): ����ƽ�������� square root: ƽ����, ���θ�
		{
			if (i % j == 0)
				break;
		}
		if (j > sqrt(i)) // �����жϿ�����j>sqrt(i)֮ǰ��ǰ����(ѭ������Ϊj>��i�Ž�����������Ϊ�ҵ���Լ���Ž���, ��ͬ������ȷ����ʱ��iΪ����), ������Ҫ��һ���ж����ߵĴ�С��ϵ
		{
			printf("%d ", i);
			count++;
		}
	}
	if (count == 0)
		printf("��");
	printf("\n��ѡȡ�ķ�Χ�ڹ���%d��������", count);
	printf("\n");


	// goto���
	// goto����ʵ����ͬһ����������ת�����úõı�Ŵ�, �������ڶ��ѭ�������п�������, ��ʹ�ò�������ҳ����ִ������, ����������ѭ��(��������)
	/* (e.g.) �˴���ʹ��3��break�ſ�����3��ѭ��Ƕ��(һ��breakֻ������һ��forѭ��), ��ʹ��goto�Ϳɿ�������
	for (...)
	{
		for (...)
		{
			for (...)
				{
					if (disaster)
						goto error;
				}
		}
	}
	error:
		... */


	// �ַ����Ƚ�С��
	// �ڽ��������ַ����ıȽ�ʱ������==, Ӧ��strcmp����; string+compare=strcmp
	char string_input[100] = { 0 };
	again:
	printf("ԭ����Ҳ��???");
	scanf("%s", string_input);
	if (strcmp("ԭ��", string_input) == 0) // strcmp( , )���ж����ʱ�����ֵΪ0
		printf("%s, ����!", string_input);
	else
	{
		printf("�ش����!\n");
		goto again; // �˴�Ҳ������ѭ��ֱ�ӱ�д����, ��������goto���
	}
	printf("\n");


	// rand():α��������ɺ���(�����<stdlib.h>ͷ�ļ�), ()����Ҫ��Ӳ���; random:�����
	// rand�������ɵ��������ΧΪ0~RAND_MAX(һ�������Ϊ32767)
	// rand�����ǶԳ�Ϊ"����"�Ļ�׼ֵ�����������ɵ�α�����, ��Ĭ������Ϊ1, ����ֱ�ӵ��ö���ظ���������ᷢ���仯
	// srand():����������������ú��� seed+random=srand; srand����()����Ҫunsigned int���͵Ĳ���, ()��Ĭ������Ϊ1
	// Unixʱ���: ��1970��1��1������������������(����������)
	// time(timer):ʱ���ȡ����(�����<time.h>ͷ�ļ�), ��timer�ǿ�ָ��NULLʱ����һ��Unixʱ���
	// time��������������time_t����(������Ϊ32��64λ�����ͱ���)
	// ������С��
	int num_random = 0;
	int num_guess = 0;
	int times = 1;
	GuessAgain: // ��������
	srand((unsigned int)time(NULL)); // �˴�ͨ��time������ȡʱ���, ͬʱ��time_t���͵Ĳ���ǿ��ת��Ϊsrand��������Ҫ��unsigned int���Ͳ����и�ֵ, �Ӷ����һ��ʱ�̸ı�������Խ���α�����������
	num_random = rand() % 100 + 1; // ͨ����rand()���ɵ�α���������100�����Եõ�0~99֮���α�����(������Ӻ����������޸ľ��巶Χ)
	printf("��ӭ����������С��Ϸ, �����1~100��������ѡ��һ����, �볢����7�����ڲ³���: ");
	scanf("%d", &num_guess);
	for (;;)
	{
		if (times >= 7)
		{
			printf("δ����7��֮�ڲ¶�, ��Ϸʧ��!\n");
			printf("��ȷ����: %d\n", num_random);
			break;
		}
		if (num_guess > num_random)
		{
			while (getchar() != '\n');
			printf("���ź���´���, ��ʾ: �´���!\n");
			printf("���ٴγ���(ʣ�����:%d��): ", 7 - times);
			scanf("%d", &num_guess);
			times++;
			// �˴�whileѭ����printf���������в��˽���˳��, ��whileѭ������, ����ڴ�ӡ������whileѭ�����ٴν���forѭ�����ظ���ӡһ�� \
			����whileѭ������ʱ, �����´�ѭ���󲻻�ֱ�ӽ��д�ӡ
		}
		else if (num_guess < num_random)
		{
			while (getchar() != '\n');
			printf("���ź���´���, ��ʾ: ��С��!\n");
			printf("���ٴγ���(ʣ�����:%d��): ", 7 - times);
			scanf("%d", &num_guess);
			times++;
		}
		else
		{
			printf("��ϲ������!\n");
			break;
		}
	}
	times = 1; // ���ò²����

	int guess_again = 0;
	menu(); // ����ǰ�涨���menu����
	printf("����һ���밴1, �˳���Ϸ�밴2: ");
	scanf("%d", &guess_again);
	for (;;)
	{
		switch (guess_again)
		{
		case 1:
			goto GuessAgain;
			break;
		case 2:
			printf("��Ϸ���˳�!\n");
			return 0; // return����:��������ִ��
		default:
			printf("δ��ѯ���ò˵�, ������ѡ��: ");
			scanf("%d", &guess_again);
			break;
		}
	}


	return 0;
}