// Create linked list with pointers.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;

struct Node {
    string data;
    Node* next;

    Node(string value) : data(value), next(nullptr) {}
};

void insertInOrder(Node*& head, const string& value) {
    Node* newNode = new Node(value);

    if (!head || head->data >= value) {
        newNode->next = head;
        head = newNode;
        return;
    }

    Node* current = head;
    while (current->next && current->next->data < value) {
        current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;
}

void displayList(Node* head) {
    Node* current = head;
    cout << "Contents of the list:" << endl;
    while (current) {
        cout << current->data << endl;
        current = current->next;
    }
}

void deleteList(Node*& head) {
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}


int main() {
    Node* head = nullptr;

    string firstName, middleName, lastName;
    cout << "Enter your first name: ";
    getline(cin, firstName);
    cout << "Enter your middle name: ";
    getline(cin, middleName);

    cout << "Enter your last name: ";
    getline(cin, lastName);

    insertInOrder(head, firstName);
    insertInOrder(head, middleName);
    insertInOrder(head, lastName);

    displayList(head);

    deleteList(head);

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
