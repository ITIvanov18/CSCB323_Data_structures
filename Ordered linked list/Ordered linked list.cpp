// Ordered linked list.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

typedef struct kutiq* p;

struct kutiq {
    p next;
    int letter;
    int data;
};


int main() {
    p na = NULL;
    p pamet;
    p help;
    int neshto = 0;

    // Създаване на списък
    while (neshto != 0) {
        pamet = new kutiq;
        cin >> neshto;
        pamet->data = neshto;
        pamet->next = NULL;
		if (na == NULL) {
			na = pamet;
        } else {
            while (pamet->next->data < pamet->data && pamet->next != NULL) {
                pamet->next = pamet->next->next;
            }

            p vmuk = na;
            while (vmuk->next != pamet->next) {
                vmuk = vmuk->next;
            }
            //Вмъкване на елемент
			pamet->next = vmuk->next;
		}
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
