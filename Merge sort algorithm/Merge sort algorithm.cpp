// Merge sort algorithm.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int SIZE = 10;
int* A = new int[SIZE] {1, 6, 3, 9, 33, 51, 47, 15, 73, 87};

void printArray(int* arr, int start, int end) {
	for (int i = start; i <= end; i++) {
		cout << arr[i] << " ";
	}
}

// Функция за обединяване на два подмасива в един, като ги подрежда по ред
void merge(int left, int right, int* A) {
	int* C = new int[SIZE]; // Временен масив за обединяване
	int mid = (left + right) / 2;
	int j = left; // Начало на първия подмасив
	int k = mid + 1; // Начало на втория подмасив
	int i = left; // Индекс за обединения масив

	cout << "Сливане на ляв: ";
	printArray(A, left, mid);
	cout << "и десен подмасив: ";
	printArray(A, mid + 1, right);
	cout << endl;



	// Сливане на двата подмасива по възходящ ред
	while (j <= mid && k <= right) {
		if (A[j] < A[k]) {
			C[i++] = A[j++];
		} else {
			C[i++] = A[k++];
		}
	}

	// Копиране на останалите елементи от първия подмасив (ако има)
	while (j <= mid) {
		C[i++] = A[j++];
	}

	// Копиране на останалите елементи от втория подмасив (ако има)
	while (k <= right) {
		C[i++] = A[k++];
	}
	cout << endl;

	// Копиране на подредения обединен масив обратно в оригиналния масив
	for (int h = left; h <= right; h++) {
		A[h] = C[h];
	}

	// Отпечатване на резултата след сливането
	cout << "Резултат след сливането: ";
	printArray(A, left, right);
	cout << endl << endl;

	delete[] C;
}

void mergeSort(int left, int right, int* A) {

	if (left < right) {
		int mid = (left + right) / 2;


		// Рекурсивно сортиране на левия подмасив
		cout << "Потъвам наляво: left = " << left << " right = " << right << endl;
		mergeSort(left, mid, A);

		// Рекурсивно сортиране на десния подмасив
		cout << "Потъвам надясно: left = " << left << " right = " << right << endl;
		mergeSort(mid + 1, right, A);

		cout << "Сливам в C и прехвърлям в A" << endl;
		// Обединяване на двата подмасива
		merge(left, right, A);
		cout << "Масивът е нареден от index " << left << " до " << right << endl;
	}
	else {
		cout << "Дъно!" << endl;
	}

}

int main() {

	cout << "Shuffled array: ";
	for (int i = 0; i < SIZE; i++) {
		cout << A[i] << " ";
	}
	cout << endl;

	mergeSort(0, SIZE - 1, A);

	cout << "Sorted array: ";
	for (int i = 0; i < SIZE; i++) {
		cout << A[i] << " ";
	}
	cout << endl;

	delete[] A;
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
