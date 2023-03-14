#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
//���������� ���������� ������������� ����� � ������ ������.

int* ArrayAllocate1(int rows, int cols) {
	//������������� �������;
	int* mas = (int*)malloc(sizeof(int*) * rows * cols);
	if (mas == NULL) {
		printf("������ �� ��� ��������\n");
		exit(1);
	}

	return mas;
}

int* ArrayAllocate2(int rows) {
	//������������� �������;

	int* result = (int*)malloc(rows * sizeof(int));

	if (result == NULL) {
		printf("������ �� ��� ��������\n");
		exit(1);
	}
	return result;
}

int* CreateArray1(int& rows, int& cols) {
	do {
		printf("������� ������ ���������� �������\n");
		scanf_s("%d", &rows); scanf_s("%d", &cols);
	} while (rows < 1 or rows > 100 or cols < 1 or cols > 100);
	return ArrayAllocate1(rows, cols);
}


void FillArray(int* mas, int rows, int cols) {
	//���������� �������
	printf("������� �������� �������\n");
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			scanf_s("%d", (mas + i * cols + j));
		}
	}

}

void MemoryRelease1(int* mas, int rows) {
	free(mas);
}

void MemoryRelease2(int* result) {
	free(result);
}

void NegativeNumbers(int* mas, int* result, int rows, int cols) {
	int counter = 0;
	for (int i = 0; i < rows; i++) {

		for (int j = 0; j < cols; j++) {
			if (*(mas + i * cols + j) < 0) {
				counter++;
			}
		}
		result[i] = counter;
		counter = 0;
	}

}

void PrintArray(int** mas, int rows, int cols) {
	printf("����� �������\n");
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
	int* mas = CreateArray1(rows, cols);
	int* result = ArrayAllocate2(rows);

	FillArray(mas, rows, cols);

	NegativeNumbers(mas, result, rows, cols);

	MemoryRelease1(mas, rows);

	printf("���������� ������������� ����� � ������\n");
	for (int i = 0; i < rows; i++) {
		printf("%d: %d\n", i + 1, result[i]);
	}

	MemoryRelease2(result);
}