// Measuring the time complexity of an algorithm.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

double selectionSort(int* array, int n) {

    time_t t0, t1;
    clock_t c0, c1;

    t0 = time(NULL);
    c0 = clock();

    for (int i = 0; i < n - 1; i++) {
        int min = array[i];
        int k = i;

        for (int j = i + 1; j < n; j++) {
            if (min > array[j]) {
                min = array[j];
                k = j;
            }
        }

        int x = array[i];
        array[i] = array[k];
        array[k] = x;
    }

    c1 = clock();
    t1 = time(NULL);
    cout << "Elapsed wall clock time / selection: " << ((long)(t1 - t0)) << " s " << endl;
    cout << "Elapsed CPU time / selection: " << (float)(c1 - c0) / CLOCKS_PER_SEC << " s " << endl;

    double timeSelection = (float)(c1 - c0) / CLOCKS_PER_SEC;
    return timeSelection;
}

double insertionSort(int* array, int n) {

    time_t t0, t1;
    clock_t c0, c1;

    t0 = time(NULL);
    c0 = clock();

    for (int i = 1; i < n; i++) {
        int x = array[i];
        int j = i - 1;

        while (j >= 0 && array[j] > x) {
            array[j + 1] = array[j];
            j--;
        }

        array[j + 1] = x;
    }

    c1 = clock();
    t1 = time(NULL);
    cout << "Elapsed wall clock time / insertion: " << ((long)(t1 - t0)) << " s " << endl;
    cout << "Elapsed CPU time / insertion: " << (float)(c1 - c0) / CLOCKS_PER_SEC << " s " << endl;

    double timeInsertion = (float)(c1 - c0) / CLOCKS_PER_SEC;
    return timeInsertion;
}

double bubbleSort(int* array, int n) {

    time_t t0, t1;
    clock_t c0, c1;

    t0 = time(NULL);
    c0 = clock();

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                int x = array[j];
                array[j] = array[j + 1];
                array[j + 1] = x;
            }
        }
    }

    c1 = clock();
    t1 = time(NULL);
    cout << "Elapsed wall clock time / bubble: " << ((long)(t1 - t0)) << " s" << endl;
    cout << "Elapsed CPU time / bubble: " << (float)(c1 - c0) / CLOCKS_PER_SEC << " s" << endl;

    double timeBubble = (float)(c1 - c0) / CLOCKS_PER_SEC;
    return timeBubble;
}

int main()
{
    srand(time(NULL));

    int size[10] = { 10000, 20000, 30000, 40000, 50000, 60000, 70000, 80000, 90000, 100000 };
    for (int i = 0; i < 10; i++) {
        cout << "\nArray size: " << size[i] << endl;

        // Генериране на неподреден масив
        int* originalArray = new int[size[i]];
        for (int j = 0; j < size[i]; j++) {
            originalArray[j] = rand() % 120000;
        }

        // Временен масив, който е копие на генерирания 
        int* tempArray = new int[size[i]];

        // 1. Сортиране чрез selection sort
        for (int j = 0; j < size[i]; j++) {
            tempArray[j] = originalArray[j];
        }
        selectionSort(tempArray, size[i]);

        // 2. Сортиране чрез insertion sort
        for (int j = 0; j < size[i]; j++) {
            tempArray[j] = originalArray[j];
        }
        insertionSort(tempArray, size[i]);

        // 3. Сортиране чрез bubble sort
        for (int j = 0; j < size[i]; j++) {
            tempArray[j] = originalArray[j];
        }
        bubbleSort(tempArray, size[i]);

        // Освобождаване на паметта
        delete[] originalArray;
        delete[] tempArray;
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
