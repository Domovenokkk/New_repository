#include <stdio.h>
#include <math.h>
#include <locale.h>
#include <stdlib.h>
int main() {
	setlocale(LC_ALL, "russian");
	int mas[100000];
	int size;
	printf("выберите размер массива до 100000: ");
	do {
		scanf_s("%d", &size);
	} while (size < 0 || size > 100000);

	for (int i = 0; i <= size - 1; i ++) {
		mas[i] = -10 + rand() % 21;
		printf("%d ", mas[i]);
	}
	return 0;
}