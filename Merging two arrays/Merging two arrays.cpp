// Merge sort algorithm.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <ctime>
using namespace std;


int main() {
	int A[5] = { 2,4,6,8,10 };
	int B[10] = { 3,5,7,9,11,12,14,16,18,20 };
	int C[15];

	// Указатели за текущата позиция в масивите A и B
	int j = 0, k = 0;

	// Индекс за позицията в масива C
	int i = 0;

    // Започваме измерване на време
    clock_t start_time = clock();
    double time_execution;

    cout << "Масив A: ";
    for (int x = 0; x < 5; x++) {
        cout << A[x] << " ";
    }
    cout << "\nМасив B: ";
    for (int x = 0; x < 10; x++) {
        cout << B[x] << " ";
    }

    cout << "\n\nПроцес на сливане:\n";
    while (j < 5 && k < 10) {
        if (A[j] < B[k]) {
            C[i] = A[j];
            cout << "Взето от A[" << j << "]: " << A[j] << endl;
            j++;
        }
        else {
            C[i] = B[k];
            cout << "Взето от B[" << k << "]: " << B[k] << endl;
            k++;
        }
        i++;
    }

    // Добавяне на останалите елементи от B, ако A е изчерпан
    while (k < 10) {
        C[i] = B[k];
        cout << "Добавяне на останалите от B[" << k << "]: " << B[k] << endl;
        k++;
        i++;
    }

    // Добавяне на останалите елементи от A, ако B е изчерпан
    while (j < 5) {
        C[i] = A[j];
        cout << "Добавяне на останалите от A[" << j << "]: " << A[j] << endl;
        j++;
        i++;
    }

	// Отпечатваме крайния сортиран масив C
	for (int i = 0; i < 15; i++) {
		cout << C[i] << "  ";
	}

    cout << endl;

    // Измерваме края на времето
    clock_t end_time = clock();  // Записваме края на времето
    time_execution = double(end_time - start_time) / CLOCKS_PER_SEC;
    cout << "Time of execution: " << time_execution << " seconds\n";
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
