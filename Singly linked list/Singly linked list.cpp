// Singly linked list.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <ctype.h>
using namespace std;

int main() {
    typedef struct element* po;

    struct element {
        char letter;
        po next;
    };

    po p;
    po q;
    po na = NULL;
    char bukva;

    do {
        // Създаване на нов елемент
        p = new element;

        cout << "Въведете елемент, който да влезе в списъка: ";
        cin >> bukva;

        // Записване на буквата в елемента и свързване в списъка
        p->letter = bukva;
        p->next = na;
        na = p;
    } while (isalpha(bukva));

    // Премахване на последния въведен символ (който не е буква)
    na = na->next;

    // Обхождане на списъка и отпечатване на буквите
    p = na;
    while (p != NULL) {
        cout << p->letter;
        p = p->next;
    }

    /*
    q = new element;
    cout << "В новия q има " << q->letter << "\n";
    q = p;
    cout << "Сега q е равно на p и сочи елемент с буква " << q->letter << "\n";
    p = NULL;
    cout << "Сега нулирахме p и той сочи " << p->letter;
    */

    return 0;
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu