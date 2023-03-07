#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
//Определить количество отрицательных чисел в каждой строке.

int** ArrayAllocate1(int rows, int cols) {
	//инициализация массива;
	int** mas = (int**)malloc(sizeof(int*) * rows);
	if (mas == NULL) {
		printf("Массив не был заполнен\n");
		exit(1);
	}
	for (int i = 0; i < rows; i++) {
		mas[i] = (int*)malloc(sizeof(int) * cols);
	}


	return mas;
}

int* ArrayAllocate2(int rows) {
	//инициализация массива;

	int* result = (int*)malloc(rows * sizeof(int));

	if (result == NULL) {
		printf("Массив не был заполнен\n");
		exit(1);
	}
	return result;
}

int** CreateArray1(int& rows, int& cols) {
	do {
		printf("Введите размер двумерного массива\n");
		scanf_s("%d", &rows); scanf_s("%d", &cols);
	} while (rows < 1 or rows > 100 or cols < 1 or cols > 100);
	return ArrayAllocate1(rows, cols);
}

//int* CreateArray2(int& cols) {
//	/*do {
//		printf("Введите размер массива\n");
//		scanf_s("%d", &cols);
//	} while (cols < 1 or cols > 100);*/
//	return ArrayAllocate2(cols);
//}

void FillArray(int** mas, int rows, int cols) {
	//Заполнение массива
	printf("Введите элементы массива\n");
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			scanf_s("%d", &mas[i][j]);
		}
	}

}

void MemoryRelease1(int** mas, int rows) {
	for (int i = 0; i < rows; i++)
		free(mas[i]);
	free(mas);
}

void MemoryRelease2(int* result) {
	free(result);
}

void NegativeNumbers(int** mas, int* result, int rows, int cols) {
	int counter = 0;
	for (int i = 0; i < rows; i++) {

		for (int j = 0; j < cols; j++) {
			if (mas[i][j] < 0) {
				counter++;
			}
		}
		result[i] = counter;
		counter = 0;
	}

}

void PrintArray(int** mas, int rows, int cols) {
	printf("Вывод массива\n");
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			printf("%d ", mas[i][j]);
		}
		printf("\n");
	}
}

int main() {
	system("chcp 1251");
	int rows = 0, cols = 0;
	int** mas = CreateArray1(rows, cols);
	int* result = ArrayAllocate2(rows);

	FillArray(mas, rows, cols);

	NegativeNumbers(mas, result, rows, cols);

	MemoryRelease1(mas, rows);

	printf("Количество отрицательных чисел в строке\n");
	for (int i = 0; i < rows; i++) {
		printf("%d: %d\n", i + 1, result[i]);
	}

	MemoryRelease2(result);
}