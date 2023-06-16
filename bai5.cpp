/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
###End banned keyword*/

#include <iostream>
#include <cstring>
#include <string>
using namespace std;

//###INSERT CODE HERE -

struct Node {
    int data;
    Node *next;
};

struct List {
    Node *pHead;
    Node *pTail;
};

// HÃ m thÃÂªm Node mÃ¡Â»Âi vÃ o cuÃ¡Â»Âi danh sÃÂ¡ch
void inputList(List &L, int n) {
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        Node *p = new Node;
        p->data = x;
        p->next = NULL;
        if (L.pHead == NULL) {
            L.pHead = L.pTail = p;
        } else {
            L.pTail->next = p;
            L.pTail = p;
        }
    }
}

// HÃ m xuÃ¡ÂºÂ¥t danh sÃÂ¡ch
void outputList(List L) {
    if (L.pHead == NULL) {
        cout << "List is empty";
    } else {
        Node *p = L.pHead;
        while (p != NULL) {
            cout << p->data << " ";
            p = p->next;
        }
    }
}

// HÃ m di chuyÃ¡Â»Ân Node cuÃ¡Â»Âi lÃÂªn ÃÂÃ¡ÂºÂ§u danh sÃÂ¡ch
void moveLastToFront(List &L) {
    if (L.pHead == NULL || L.pHead == L.pTail) {
        return;
    }
    Node *p = L.pHead;
    while (p->next != L.pTail) {
        p = p->next;
    }
    p->next = NULL;
    L.pTail->next = L.pHead;
    L.pHead = L.pTail;
    L.pTail = p;
}

int main()
{
    List L;
    L.pHead=L.pTail=NULL;
    int n; cin>>n;
    inputList(L,n);
    cout<<"Created List: "<<endl;
    outputList(L);
    cout<<endl;

    moveLastToFront(L); //di chuyen node cuoi ve dau danh sach
    cout<<"Updated List after moving the last element to front of L: "<<endl;
    outputList(L);
    return 0;
}
