// Factorial with recursion.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int counter = 0;

int factorial(int n) {
	int temp;
	int localCounter = counter;
	counter++;

	if (n >= 1) {
		cout << "Iteration: " << localCounter << " / input: " << n << endl;
		temp = factorial(n - 1) * n;
		cout << "Iteration: " << localCounter << " calculated " << temp << endl;
	} else {
		cout << "We hit the bottom of the stack!" << endl;
		temp = 1;
	}

	return temp;
}

int main()
{
	int n, result;
	cout << "Calculating the factorial of ";
	cin >> n;
	result = factorial(n);
	cout << "\nResult: " << result << endl;


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
