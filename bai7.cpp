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
    node *next;
};

struct List {
    node *head;
    node *tail;
};

// Khá»i táº¡o danh sÃ¡ch rá»ng
void Init(List &L) {
    L.head = L.tail = NULL;
}

// ThÃªm má»t pháº§n tá»­ vÃ o Äáº§u danh sÃ¡ch
void addHead(List &L, int x) {
    node *p = new node;
    p->info = x;
    p->next = NULL;

    if (L.head == NULL) {
        L.head = L.tail = p;
    }
    else {
        p->next = L.head;
        L.head = p;
    }
}

// ThÃªm má»t pháº§n tá»­ vÃ o cuá»i danh sÃ¡ch
void addTail(List &L, int x) {
    node *p = new node;
    p->info = x;
    p->next = NULL;

    if (L.head == NULL) {
        L.head = L.tail = p;
    }
    else {
        L.tail->next = p;
        L.tail = p;
    }
}

// Nháº­p danh sÃ¡ch
void inputList(List &L, int n) {
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        addTail(L, x); // ThÃªm pháº§n tá»­ vÃ o Äáº§u danh sÃ¡ch Äá» táº¡o danh sÃ¡ch Äáº£o ngÆ°á»£c
    }
}

// Xuáº¥t danh sÃ¡ch
void outputList(List L) {
    if(L.head == nullptr) {
        cout << "List is empty";
    }
    else {
    for (node *p = L.head; p != NULL; p = p->next) {
        cout << p->info << " ";
    }
    }
}

// TÃ¬m pháº§n tá»­ thá»© i tá»« cuá»i danh sÃ¡ch
node* findElementFromEnd(List L, int i) {
    if(L.head == nullptr) {
        cout << "List is empty";
        return 0;
    }
    else {
    node *p = L.head;
    int cnt = 0;

    // Äáº¿m sá» pháº§n tá»­ cá»§a danh sÃ¡ch
    while (p != NULL) {
        cnt++;
        p = p->next;
    }

    // Kiá»m tra Äiá»u kiá»n index
    if (i <= 0 || i > cnt) {
        cout << "The index is invalid";
        return NULL;
    }

    p = L.head;
    for (int j = 1; j < cnt-i+1; j++) { // Duyá»t Äáº¿n pháº§n tá»­ thá»© cnt-i+1
        p = p->next;
    }

    return p;
    }
}
int main()
{
    List L;
    Init(L);
    int n; cout<<"Enter a number: "; cin>>n;
    cout<<"\nEnter a sequence of "<<n<<" numbers: ";
    inputList(L,n);
    cout<<"\nThe created Linked List: ";
    outputList(L);

    int i; cout<<"\nEnter a number: "; cin>>i;
    cout<<"\nThe element at index "<<i<<" (from the end of L): ";
    node *p = findElementFromEnd(L,i);
    if(p) cout<<p->info;


    return 0;
}
