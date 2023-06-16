/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
###End banned keyword*/

#include <iostream>
using namespace std;


//###INSERT CODE HERE -

struct Node {
    int value;
    Node *next;
    Node(int val) {
        value = val;
        next = NULL;
    }
};

Node *head = NULL;
Node *tail = NULL;

void addFront(int val) {
    Node *newNode = new Node(val);
    if (head == NULL) {
        head = newNode;
        tail = newNode;
    }
    else {
        newNode->next = head;
        head = newNode;
    }
}

void addBack(int val) {
    Node *newNode = new Node(val);
    if (tail == NULL) {
        head = newNode;
        tail = newNode;
    }
    else {
        tail->next = newNode;
        tail = newNode;
    }
}

void removeFront() {
    if(head == nullptr) return;
    Node *temp = head;
    if(head == tail) {
        delete head;
        head = tail = nullptr;
        
    }
    else {
        head = temp->next;
        delete temp;
    }
    // if (head == NULL) return;
    // if (head == tail) {
    //     delete head;
    //     head = NULL;
    //     tail = NULL;
    // }
    // else {
    //     Node *temp = head;
    //     head = head->next;
    //     delete temp;
    // }
}

void removeBack() {
    if (tail == NULL) return;
    if (head == tail) {
        delete head;
        head = NULL;
        tail = NULL;
    }
    else {
        Node *current = head;
        while(current->next != tail) {
            current = current->next;
        }
        current->next = NULL;
        delete tail;
        tail = current;
        // while (current->next != tail) {
        //     current = current->next;
        // }
        // current->next = NULL;
        // delete tail;
        // tail = current;
    }
}

int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        char op, pos;
        int val;
        cin >> op >> pos >> val;
        if(op == '+') {
            if(pos == 'H') addFront(val);
            else addBack(val);
        }
        else {
            if(pos == 'H') removeFront();
            else removeBack();
        }
        Node *p = head;
        while(p != nullptr) {
            cout << p->value << " ";
            p = p->next;
        }
    }
    // for (int i = 0; i < n; i++) {
    //     char op;
    //     char pos;
    //     int val;
    //     cin >> op >> pos >> val;

    //     if (op == '+') {
    //         if (pos == 'H') addFront(val);
    //         else addBack(val);
    //     }
    //     else {
    //         if (pos == 'H') removeFront();
    //         else removeBack();
    //     }
    // }

    // Node *current = head;
    // while (current != NULL) {
    //     cout << current->value << " ";
    //     current = current->next;
    // }
    // cout << endl;

    return 0;
}