// Time complexity of merge sort algorithm.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <ctime>
using namespace std;

void merge(int left, int mid, int right, int* A) {
    int* C = new int[right - left + 1]; // Временен масив за обединяване
    int j = left; // Начало на първия подмасив
    int k = mid + 1; // Начало на втория подмасив
    int i = 0; // Индекс за обединения масив


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

    // Копиране на подредения обединен масив обратно в оригиналния масив
    for (int h = left; h <= right; h++) {
        A[h] = C[h - left];
    }

    delete[] C;
}

void mergeSort(int left, int right, int* A) {
    int mid = (left + right) / 2;

    if (left < right) {
        // cout << "Потъване наляво\t ляв индекс: " << left << "\tдесен индекс: " << mid << endl;
        mergeSort(left, mid, A);
        // cout << "Потъване наляво\t ляв индекс: " << mid + 1 << "\tдесен индекс: " << right << endl;
        mergeSort(mid + 1, right, A);
        // cout << "Сливане на подмасиви: ";
        // for (int i = left; i < mid + 1; i++)
        //   cout << arr[i] << " ";
        // cout << "\ti: ";
        // for (int i = mid + 1; i < right + 1; i++)
        //   cout << arr[i] << " ";
        // cout << endl;
        merge(left, mid, right, A);

    }
}

void quickSort(int left, int right, int* arr) {

    if (left < right) {
        int j = left, k = right;
        int etalon = arr[(left + right) / 2];


        //Започва разделянето на дяловете на масива
        do {
            while (arr[j] < etalon) j++;
            while (arr[k] > etalon) k--;
            if (j <= k) {
                int temp = arr[j];
                arr[j] = arr[k];
                arr[k] = temp;
                j++;
                k--;
            }
        } while (j <= k);

        quickSort(left, k, arr);
        quickSort(j, right, arr);
    }
}

int main() {

    const int len[5] = { 100000, 200000, 300000, 400000, 500000 };

    for (int i = 0; i < 5; i++) {
        int* originalArray = new int[len[i]];
        int* array1 = new int[len[i]];
        int* array2 = new int[len[i]];

        srand(time(NULL));
        for (int j = 0; j < len[i]; j++) {
            originalArray[j] = rand() % 120000;
        }

        // Копиране на оригиналния масив в array1 и array2
        for (int k = 0; k < len[i]; k++) {
            array1[k] = originalArray[k];
            array2[k] = originalArray[k];
        }

        double time_execution = 0;
        clock_t c0, c1;

        // Изпълнение на Merge Sort
        c0 = clock();
        mergeSort(0, len[i] - 1, array1);
        c1 = clock();
        time_execution = (double)(c1 - c0) / CLOCKS_PER_SEC;
		cout << "Array length = " << len[i] << endl;
        cout << "Merge Sort execution time: " << time_execution << " seconds" << endl;

        // Изпълнение на Quick sort
        c0 = clock();
        quickSort(0, len[i] - 1, array1);
        c1 = clock();
        time_execution = (double)(c1 - c0) / CLOCKS_PER_SEC;
        cout << "Quick Sort execution time: " << time_execution << " seconds" << endl;

        // Освобождаване на динамично заделената памет
        delete[] originalArray;
        delete[] array1;
        delete[] array2;

        cout << endl;
    }

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
