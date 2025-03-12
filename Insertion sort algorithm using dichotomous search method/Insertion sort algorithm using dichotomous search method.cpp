// Insertion sort algorithm using dichotomous search method.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8};

int dihoSearch(int target, int left, int right) {
    while (left <= right) {
        int mid = (left + right) / 2;

        if (target >= arr[mid]) {
            left = mid + 1; // Продължаваме търсенето вдясно
        } else {
            right = mid - 1; // Продължаваме търсенето вляво
        }
    }
    return left; 
    // Връщаме директно 'left', защото съдържа индекса за вмъкване
}

void insertionSort(int size) {
    for (int i = 1; i < size; i++) {
        int pivot = arr[i];
        int j = dihoSearch(pivot, 0, i - 1);

        // Преместваме елементите, за да освободим място за pivot-a
        for (int k = i; k > j; k--) {
            arr[k] = arr[k - 1];
        }
        arr[j] = pivot;
    }
}


int main() {
    int arrSize = sizeof(arr) / sizeof(arr[0]);

    cout << "Shuffled array: ";
    for (int i = 0; i < arrSize; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    insertionSort(arrSize);

    cout << "Sorted array: ";
    for (int i = 0; i < arrSize; i++) {
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
