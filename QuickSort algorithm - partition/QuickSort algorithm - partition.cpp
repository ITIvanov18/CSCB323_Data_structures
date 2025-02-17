// QuickSort algorithm - partition.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int arr[7] = {11, 5, 4, 30, 4 , 4, 6 };
int copies = 0;

void quickSort(int left, int right) {
	copies++;
	int localCopy = copies;
	cout << "\nКопие: " << localCopy << endl;
	cout << "Граници на дяла от " << left << " до " << right << endl;

	cout << "Начално състояние на масива: " << endl;
	for (int i = 0; i < 7; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;

	if (left < right) {
		int j = left, k = right;
		int etalon = arr[(left + right) / 2];
		cout << "Еталон: " << etalon << endl;


		//Започва разделянето на дяловете на масива
		do {
			while (arr[j] < etalon) j++;
			cout << "Спирам на j: " << j << " arr[j]: " << arr[j] << endl;
			while (arr[k] > etalon) k--;
			cout << "Спирам на k: " << k << " arr[k]: " << arr[k] << endl;

			if (j <= k) {
				cout << "   Размяна на " << arr[j] << " и " << arr[k] << endl;
				int temp = arr[j];
				arr[j] = arr[k];
				arr[k] = temp;
				j++;
				k--;
			}
		} while (j <= k);

		// Рекурсивно сортиране на поддялата наляво и надясно
		cout << "Потъване наляво" << endl;
		quickSort(left, k);

		cout << "Потъване надясно" << endl;
		quickSort(j, right);
	} else {
		cout << "Дъно!" << endl;
		return;
	}

	cout << "Изплуване" << endl;

}

int main()
{
	int size = 7;

	cout << "Начално състояние на масива: " << endl;
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}

	cout << endl;
	for (int i = 0; i < size; i++) {
		cout << i << " ";
	}
	cout << endl;

	quickSort(0, size - 1);

	cout << "\nКрайно състояние на масива: ";
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;

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
