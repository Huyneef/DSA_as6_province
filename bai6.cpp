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
struct node {
    int info;
    node *pNext;
};

struct List {
    node *pHead;
    node *pTail;
};

void createList(List &L) {
    L.pHead = L.pTail = NULL;
}

node* createNode(int value) {
    node *p = new node;
    p->info = value;
    p->pNext = NULL;
    return p;
}

void addTail(List &L, node *p) {
    if (L.pHead == NULL)
        L.pHead = L.pTail = p;
    else {
        L.pTail->pNext = p;
        L.pTail = p;
    }
}

void inputList(List &L, int n) {
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        node *p = createNode(x);
        addTail(L, p);
    }
}

void outputList(List L) {
    if (L.pHead == NULL)
        cout << "List is empty";
    else {
        node *p = L.pHead;
        while (p != NULL) {
            cout << p->info << " ";
            p = p->pNext;
        }
    }
}

node* findMiddle(List L) {
    if (L.pHead == NULL)
        return NULL;

    node *p1 = L.pHead;
    node *p2 = L.pHead;

    while (p2 != NULL && p2->pNext != NULL) {
        p2 = p2->pNext->pNext;
        p1 = p1->pNext;
    }

    return p1;
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

    node *p=findMiddle(L); //Neu so phan tu chan thi co 2 phan tu chinh giua, chi xuat phan tu chinh giua thu 2
    if(p)cout<<"The middle element is "<<p->info;

    return 0;
}
