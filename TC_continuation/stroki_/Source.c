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
	printf("Введите строку: ");
	gets(str);
	puts(str);
    system("cls");
	printf("Выберете действия над строкой");
	printf("\n1. Заменить строку");
	printf("\n2. Обрезать строку");
	printf("\n3. Заменить один символ на другой");
	printf("\nВведите число - ");
	scanf_s("%d", &num);

	while (str[size] != '\0') {
		size++;
	}
	if (num == 1) {
		goto link1;
	}
	else if (num == 2) {
		printf("Введите число, до которого обрезать строку - ");
		scanf_s("%d", &num1);
		str[num1] = '\0';
	}
	else if (num == 3) {
		printf("Введите символ, который хотит заменить - ");
		str1 = getchar();
		printf("Введите символ, на который хотите заменить - ");
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