#define _CRT_SECURE_NO_WARNINGS
#include "time.h"
#include "stdio.h"
#include "stdlib.h"
#include "malloc.h"


int main(void)
{
	int m;
	printf("Enter amount of peaks: \n");
	scanf("%d", &m);

	int** a;
	a = (int**)malloc((m) * sizeof(int*));
	srand(time(NULL));
	// 1
	printf("   ");
	for (int j = 0; j < m; j++) {  // цикл по столбцам
		printf("%5d", (j + 1));
	}
	printf("\n   ");
	for (int j = 0; j < m; j++) {  // цикл по столбцам
		printf("-----");
	}
	for (int i = 0; i < m; i++) {
		a[i] = (int*)malloc(m * sizeof(int));// Выделение памяти под хранение строк

		printf("\n %d |", (i + 1)); // цикл по столбцам
		for (int j = 0; j < m; j++) {
			a[i][j] = 0;
			if (j <= i) {
				a[i][j] = a[j][i];
				printf("%4d ", a[i][j]);
			}
			else {
				a[i][j] = rand() % 2;
				printf("%4d ", a[i][j]);
			}
		}
	}
	// 2
	int count = 0;
	for (int i = 0; i < m; i++) {
		for (int j = i + 1; j < m; j++) {
			count += a[i][j];
		}
	}
	printf("\n\nAmount of sides - %d\n", count);
	// 3
	int detect = 0;
	for (int i = 0; i < m; i++) {
		detect = 0;
		for (int j = 0; j < m; j++) {
			if (a[i][j] != 0)
				detect++;
		}
		if (a[i][i] != 0)
			detect--;
		if (detect == 0)
			printf("\n Peak %d is isolated", (i + 1));
		else if (detect == 1)
			printf("\n Peak %d is the edge", (i + 1));
		else if (detect == (m - 1))
			printf("\n Peak %d is dominant", (i + 1));

	}
	//------------------

	printf("\n\n(2)\n");
	int** b;
	int k = count, countY = 0;
	b = (int**)malloc((m) * sizeof(int*));
	printf("   ");
	for (int j = 0; j < k; j++) {  // цикл по столбцам
		printf("%3d-S", (j + 1));
	}
	printf("\n   ");
	for (int j = 0; j < k; j++) {  // цикл по столбцам
		printf("-----");
	}
	for (int i = 0; i < m; i++) {
		b[i] = (int*)malloc(k * sizeof(int));
		for (int j = 0; j < k; j++) {
			b[i][j] = 0;
		}
	}
	for (int i = 0; i < m; i++) {
		printf("\n %d |", (i + 1)); // цикл по столбцам

		for (int j = 0; j < m; j++) {
			if (a[i][j] == 1 && i < j) {
				b[i][countY] = 1;
				b[j][countY] = 1;
				countY++;
			}
		}
		for (int j = 0; j < k; j++) {
			printf("%4d ", b[i][j]);
		}
	}
	// (2)
	printf("\n\nAmount of sides - %d", k);
	// (3)
	for (int i = 0; i < m; i++) {
		detect = 0;
		for (int j = 0; j < k; j++) {
			detect += b[i][j];
		}
		if (detect == 0)
			printf("\n Peak %d is isolated", (i + 1));
		else if (detect == 1)
			printf("\n Peak %d is the edge", (i + 1));
		else if (detect == (m - 1))
			printf("\n Peak %d is dominant", (i + 1));
	}

	free(a);
	free(b);
	getchar();
	getchar();
	return(0);
}