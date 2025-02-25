// Tower of Hanoi algorithm.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <ctime>
using namespace std;

int counter = 1;

void hanoi(int n, char from, char to, char help) {
	if (n > 1) {
		hanoi(n - 1, from, help, to);
		cout << counter <<". Move disk " << n << " from " << from << " to " << to << endl;
		counter++;
		hanoi(n - 1, help, to, from);
	} else {
		cout << "Duno!" << endl;
		cout << counter <<". Move disk 1 from " << from << " to " << to << endl;
		counter++;
	}
}

int main()
{
	int n;
	cout << "Enter the number of disks: ";
	cin >> n;

	char from, to, help;
	cout << "Enter the names of the pegs: ";
	cin >> from >> to >> help;

	time_t t0, t1;
	clock_t c0, c1;
	double time_execution;

	t0 = time(NULL);
	c0 = clock();

	hanoi(n, from, to, help);

	c1 = clock();
	t1 = time(NULL);
	time_execution = (double)(c1 - c0) / CLOCKS_PER_SEC;
	cout << "Time of execution: " << time_execution << " seconds\n";

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
