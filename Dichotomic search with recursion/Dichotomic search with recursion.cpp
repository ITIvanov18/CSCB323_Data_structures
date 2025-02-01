// Dichotomic search with recursion.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int arr[10000], target;

int dihoRecursion(int left, int right) {
	int mid = (right + left) / 2;
	if (target != arr[mid] && left < right) {
		if (target > arr[mid]) {
			dihoRecursion(mid + 1, right);
		} else {
			dihoRecursion(left, mid - 1);
		}
	}
	else 
	{
		if (target == arr[mid]) {
			return mid;
		} else {
			return -1;
		}
	}
}

int main()
{
	int size;
	cout << "Enter array size: ";
	cin >> size;

	for (int i = 1; i < size + 1; i++){
		arr[i] = i;
	}
	cout << "Enter what you're looking for: ";
	cin >> target;

	int index = dihoRecursion(0, size);
	cout << "The target is found at index " << index << endl;
	
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
