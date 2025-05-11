// Create a stack using pointers.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;

typedef struct Element* po;

struct Element {
    char data;
    po next;
};

void push(po& top, char value) {
    po newElement = new Element;
    newElement->data = value;
    newElement->next = top;
    top = newElement;
}

char pop(po& top) {
    if (top == nullptr) {
        cerr << "Stack underflow!" << endl;
        return '\0';
    }
    po temp = top;
    char value = temp->data;
    top = top->next;
    delete temp;
    return value;
}

bool isEmpty(po top) {
    return top == nullptr;
}

int main() {
    po stack = nullptr;

    cout << "Въведете текст, който да се отпечата наобратно: ";
    string input;
    getline(cin, input);

    for (char ch : input) {
        push(stack, ch);
    }

    cout << "Изход на програмата: ";

    while (!isEmpty(stack)) {
        cout << pop(stack);
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
