#include <stdio.h>
#include <malloc.h>
#include <locale.h>
int main() {
	setlocale(LC_ALL, "russian");
	char* str;
	char str1, str2;
	int num, size = 0, num1, i;
	str = (char*)malloc(sizeof(char) * 100);
link1:
	printf("������� ������: ");
	gets(str);
	puts(str);
    system("cls");
	printf("�������� �������� ��� �������");
	printf("\n1. �������� ������");
	printf("\n2. �������� ������");
	printf("\n3. �������� ���� ������ �� ������");
	printf("\n������� ����� - ");
	scanf_s("%d", &num);

	while (str[size] != '\0') {
		size++;
	}
	if (num == 1) {
		goto link1;
	}
	else if (num == 2) {
		printf("������� �����, �� �������� �������� ������ - ");
		scanf_s("%d", &num1);
		str[num1] = '\0';
	}
	else if (num == 3) {
		printf("������� ������, ������� ����� �������� - ");
		str1 = getchar();
		printf("������� ������, �� ������� ������ �������� - ");
		str2 = getchar();

		for (i = 0; i < size; i++) {
			if (str[i] == str1) {
				str[i] = str2;
			}
		}


	}
	printf("%s", str);

	



	free(str);
	return 0;
	
	





}