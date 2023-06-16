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

struct Node{
    int data;
    Node* next;
};

struct List{
    Node* head;
    Node* tail;
};


void Init(List& L){
    L.head = L.tail = NULL;
}


void addTail(List& L, int x){
    Node* p = new Node;
    p->data = x;
    p->next = NULL;
    if (L.head == NULL){
        L.head = L.tail = p;
    }
    else{
        L.tail->next = p;
        L.tail = p;
    }
}


void inputList(List& L, int n){
    for (int i=0; i<n; i++){
        int x; cin>>x;
        addTail(L,x);
    }
}


void outputList(List L){
    if (L.head == NULL){
        cout<<"List is empty"<<endl;
    }
    else{
        Node* p = L.head;
        while (p != NULL){
            cout<<p->data<<" ";
            p = p->next;
        }
        cout<<endl;
    }
}


void concate(List& L1, List L2){
    if (L1.head == NULL){
        L1 = L2;
    }
    else if (L2.head != NULL){
        L1.tail->next = L2.head;
        L1.tail = L2.tail;
    }
}
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

int main()
{
    List L1, L2;
    Init(L1);Init(L2);

    int n; cin>>n;
    inputList(L1,n);
    cout<<"Created 1st List: "<<endl;
    outputList(L1);
    cout<<endl;

    cin>>n;
    inputList(L2,n);
    cout<<"Created 2nd List: "<<endl;
    outputList(L2);
    cout<<endl;

    concate(L1,L2); // Noi L2 vao L1
    cout<<"Updated L1: "<<endl;
    outputList(L1);

    return 0;
}
