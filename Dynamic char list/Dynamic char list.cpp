// Dynamic char list.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <ctype.h>
using namespace std;

typedef struct kutiq* p;

struct kutiq {
    p next;
    char letter;
};

int main() {
    p end = NULL;
    p beg = NULL;
    p vkarai;
    char neshto = 'a';

    while (isalpha(neshto)) {
        vkarai = new kutiq;
        neshto = cin.get();
        vkarai->letter = neshto;
        vkarai->next = NULL;

        if (beg == NULL) {
            beg = vkarai;
            end = vkarai;
        }
        else {
            end->next = vkarai; // Добавяне към края
            end = vkarai;       // Обновяване на последния елемент
        }
    }

    // Обхождане и отпечатване на списъка
    p iterator = beg;
    while (iterator != NULL) {
        cout << iterator->letter << " ";
        iterator = iterator->next;
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
