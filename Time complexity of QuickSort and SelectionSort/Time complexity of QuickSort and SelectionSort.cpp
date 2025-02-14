// Time complexity of QuickSort and SelectionSort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <ctime>

using namespace std;

void quickSort(int left, int right, int* arr) {

    time_t t0, t1;
    clock_t c0, c1;

    t0 = time(NULL);
    c0 = clock();

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
    cout << "Elapsed CPU time / selectionSort: " << (float)(c1 - c0) / CLOCKS_PER_SEC << " s " << endl;

    double timeSelection = (float)(c1 - c0) / CLOCKS_PER_SEC;
    return timeSelection;
}



int main()
{
    int size[9] = { 20000, 30000, 40000, 50000, 60000, 70000, 80000, 90000, 100000 };
    for (int i = 0; i < 9; i++) {
        cout << "\nArray size: " << size[i] << endl;

        // Генериране на неподреден масив
        int* originalArray = new int[size[i]];
        for (int j = 0; j < size[i]; j++) {
            originalArray[j] = j;
        }

        // Временен масив, който е копие на генерирания 
        int* tempArray = new int[size[i]];

        // 1. Сортиране чрез quick sort
        for (int j = 0; j < size[i]; j++) {
            tempArray[j] = originalArray[j];
        }
        quickSort(0, size[i] - 1, tempArray);

        // Измерване на времето за quickSort
        time_t t0 = time(NULL);
        clock_t c0 = clock();
        quickSort(0, size[i] - 1, tempArray); // Подаваме правилния масив и размер
        clock_t c1 = clock();
        time_t t1 = time(NULL);
        cout << "Elapsed CPU time / quicksort: " << (float)(c1 - c0) / CLOCKS_PER_SEC << " s " << endl;

        // 2. Сортиране чрез selection sort
        for (int j = 0; j < size[i]; j++) {
            tempArray[j] = originalArray[j];
        }
        selectionSort(tempArray, size[i]);

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
