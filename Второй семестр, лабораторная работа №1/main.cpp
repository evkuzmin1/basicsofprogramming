#include <iostream>
using namespace std;

struct product {
    int id;
    int q;
    product* next;
};

void AddFirst(product*& primacy, int id1, int q) {
    product* newproduct = new product;
    newproduct->id = id1;
    newproduct->q = q;
    product* tmp = primacy;
    while (tmp != NULL) {
        if (tmp->id == id1) {
            cout << "Element with this id already in list\n" << endl;
            return;
        }
        tmp = tmp->next;
    }
    newproduct->next = primacy;
    primacy = newproduct;
}

void AddAfterFirst(product*& primacy, int id1, int q) {
    if (primacy == NULL) {
        cout << "This list is empty" << endl;
        AddFirst(primacy, id1, q);
        return;
    }
    product* newproduct = new product{ id1, q, primacy->next };
    primacy->next = newproduct;
}

void AddBeforeLast(product*& primacy, int id1, int q) {
    if (primacy == NULL || primacy->next == NULL) {
        cout << "List is too short" << endl;
        AddFirst(primacy, id1, q);
        return;
    }
    product* current = primacy;
    while (current->next->next != NULL) {
        current = current->next;
    }
    product* newproduct = new product{ id1, q, current->next };
    current->next = newproduct;
}

void PrintList(product* primacy) {
    if (primacy == NULL) {
        cout << "This list is empty" << endl;
        return;
    }
    product* tmp = primacy;
    while (tmp != NULL) {
        cout << "Product id: " << tmp->id << " q: " << tmp->q << endl;
        tmp = tmp->next;
    }
}

void GetLast(product*& primacy, int id1, int q) {
    if (primacy == NULL) {
        cout << "List is empty" << endl;
        return;
    }
    product* tmp = primacy;
    while (tmp->next != NULL) {
        tmp = tmp->next;
    }
    product* newproduct = new product;
    newproduct->id = id1;
    newproduct->q = q;
    newproduct->next = NULL;
    tmp->next = newproduct;
}

void PrintElement(product* primacy, int position) {
    if (primacy == NULL) {
        cout << "The list is empty." << endl;
        return;
    }
    int index = 1; 
    product* tmp = primacy;
    while (tmp != NULL && index < position) {
        tmp = tmp->next;
        index++;
    }
    if (tmp == NULL) {
        cout << "No element found at position " << position << "." << endl;
    }
    else {
        cout << "Product at position " << position << ": id = " << tmp->id << ", q = " << tmp->q << endl;
    }
}

int main() {
    product* head = NULL;

    int id1 = 1;
    int q1 = 5;

    int id2 = 2;
    int q2 = 11;

    PrintList(head);
    cout << "++++++++++++++++++++++++++++++++++\n";

    AddFirst(head, id1, q1);
    PrintList(head);
    cout << "===================================\n";

    AddFirst(head, id2, q2);
    PrintList(head);
    cout << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n";

    GetLast(head, 3, 7);
    PrintList(head);

    cout << "*****\n";

    AddAfterFirst(head, 4, 9);
    PrintList(head);

    cout << "*****\n";

    AddBeforeLast(head, 5, 2);
    PrintList(head);

    cout << "======= &&&&&&&&&&&&&&& =======\n";
    PrintElement(head, 2); 
    PrintElement(head, 777);
    PrintElement(head, 5); 

    return 0;
}