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


void AddBefore(product*& primacy, int target_id, int id1, int q) {
    if (primacy == NULL) {
        cout << "List is empty" << endl;
        return;
    }
    if (primacy->id == target_id) {
        AddFirst(primacy, id1, q);
        return;
    }
    product* current = primacy;
    while (current->next != NULL && current->next->id != target_id) {
        current = current->next;
    }
    if (current->next == NULL) {
        cout << "Target id not found in list" << endl;
        return;
    }
    product* newproduct = new product{ id1, q, current->next };
    current->next = newproduct;
}

void AddAfter(product*& primacy, int target_id, int id1, int q) {
    product* current = primacy;
    while (current != NULL && current->id != target_id) {
        current = current->next;
    }
    if (current == NULL) {
        cout << "Target id not found in list" << endl;
        return;
    }
    product* newproduct = new product{ id1, q, current->next };
    current->next = newproduct;
}


void PrintList(product* primacy) {
    if (primacy == NULL) {
        cout << "List is empty" << endl;
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

void Delete(product*& primacy, int target_id) {
    product** current = &primacy;

    while (*current != nullptr && (*current)->id != target_id) {
        current = &(*current)->next;
    }

    if (*current != nullptr) {
        product* toDelete = *current;
        *current = (*current)->next;
        delete toDelete;
        cout << "Element with id => " << target_id << " has been deleted." << endl;
    }
    else {
        cout << "Element with id => " << target_id << " not found." << endl;
    }
}


void PrintElement(product* primacy, int position) {
    if (primacy == NULL) {
        cout << "List is empty." << endl;
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

    AddAfter(head, 2, 4, 9);
    PrintList(head);

    cout << "*****\n";

    AddBefore(head, 1, 5, 2);
    PrintList(head);

    cout << "<><><><><><><><><><><><><><><><><><><><><>\n";
    
    Delete(head, 3);
    PrintList(head);

    cout << "======= &&&&&&&&&&&&&&& =======\n";
    PrintElement(head, 2); 
    PrintElement(head, 777);
    PrintElement(head, 5); 

    return 0;
}