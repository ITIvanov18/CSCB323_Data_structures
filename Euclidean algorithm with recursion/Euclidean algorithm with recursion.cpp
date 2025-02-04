// Euclidean algorithm with recursion.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int result = 0;
int counter = 1;

void gcd(int a, int b) {
	if (a % b != 0) {
		counter++;
		int r = a % b;
		cout << a << " % " << b << " = " << a/b << " (" << r << ")" 
			 << " / counter: " << counter << endl;
		gcd(b, r);
		cout << "Unwinding the recursion..." << endl;
		counter--;
		cout << a << " % " << b << " = " << a / b << " (" << r << ")" 
			 << " / counter: " << counter << endl;
	} else {
		result = b;
	}
}

int main()
{
	int a, b;
	cout << "Enter two numbers: " << endl;
	cin >> a;
	cin >> b;

	if (a < b) {
		cout << "A has to be greater than B!" << endl;
	}

	cout << "Recursion depth..." << endl;
	gcd(a, b);

	cout << "The GCD of " << a << " and " << b 
		 << " is " << result << endl;
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
