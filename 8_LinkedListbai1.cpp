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
    Node* next;
};
struct List {
    Node* head;
    Node* tail;
};
void Init(List& L) {
    L.head = L.tail = NULL;
}
void addTail(List& L, int x) {
    // Node* p = new Node;
    // p->data = x;
    // p->next = NULL;
    // if (L.head == NULL)
    //     L.head = L.tail = p;
    // else {
    //     L.tail->next = p;
    //     L.tail = p;
    // }
    Node* p = new Node;
    p->data = x;
    p->next = NULL;
    if(L.head == nullptr) {
        L.head = L.tail = p;
    }
    else  {
        L.tail->next = p;
        L.tail = p;
    }
}
void inputList(List& L, int n)
{
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        addTail(L, x);
    }
}
void outputList(List L) {
    if (L.head == NULL) {
        cout << "List is empty";
        return;
    }
    Node* p = L.head;
    while (p != NULL) {
        cout << p->data << " ";
        p = p->next;
    }
}
int main()
{
    List L; // Khai bao 1 danh sach
    Init(L); // Khoi tao danh sach
    int n; cout<<"Enter a number: "; cin>>n; // Nhap so luong phan tu cua ds
    cout<<"\nEnter a sequence of "<<n<<" numbers: ";
    inputList(L,n); // Nhap 1 day gom n so va luu vao ds. Phan tu moi duoc them vao cuoi ds
    cout<<"\nThe created Linked List: ";
    outputList(L); // Xuat ds. Neu ds rong thi xuat thong bao "List is empty"

    return 0;
}
