#include <bits/stdc++.h>
using namespace std;

struct DNode
{
	int info;
	DNode *pNext;
    DNode *pPrev;
};

struct DList
{
	DNode *pHead, *pTail;
};
void init(DList &l) {
    l.pHead = NULL;
    l.pTail = NULL;
}
DNode* getDNode(int x) {
    DNode* p = new DNode;
    p->info = x;
    p->pNext = NULL;
    p->pPrev = NULL;

    return p;
}
void addTail(DList &l, int x) {
    DNode *p = getDNode(x);
        if(l.pHead == nullptr) {
            l.pHead = p;
            l.pTail = p;
        }
        else {
            l.pTail->pNext = p;
            p->pPrev = l.pTail;
            l.pTail = p;
        }
}
void addHead(DList &l, int x) {
    DNode* p = getDNode(x);
    if(l.pHead == NULL) {
        l.pHead = p;
        l.pTail = p;
    }
    else {
        p->pNext = l.pHead;
        l.pHead->pPrev = p;
        l.pHead = p;
    }
}
void createList(DList &l) {
    while(true) {
        int x; cin >> x;
        if(x == -1) break;
        else {
        addTail(l,x);
        }
    }
}
void printList(DList l) {
    DNode *p = l.pHead;
    if(p == NULL) cout << "List is empty";
    else {
    while(p != NULL) {
        cout << p->info << " ";
        p = p->pNext;
    }
    }
}
bool searchPro(DList L, int a) {
    for(;L.pHead != nullptr;) {
        if((L.pHead->info) == a) {return 1;}
        L.pHead= L.pHead->pNext;
    }
    return 0;
}
DNode* sEle(DList L, int a) {
    for(;L.pHead != nullptr;) {
        if(L.pHead->info == a) {break;}
        L.pHead = L.pHead->pNext;
    }
    return L.pHead;
}
void addAfter(DList &L,int pos, int x) {
    
    if(searchPro(L,pos) == 0)
    cout << "\nCan't find the value "<<x;
    else {
    DNode *p = sEle(L,pos);
    if(p == nullptr) {
        addHead(L,x);
    }
    else if(p == L.pTail) {
        addTail(L,x);
    }
    else {
        DNode* t = getDNode(x);
        t->pPrev = p;
        t->pNext = p->pNext;
        
        p->pNext = t;
        (p->pNext)->pPrev = t;
        
    }
    }
    
}
void addBefore(DList &L,int pos, int x) {
    
    if(searchPro(L,pos) == 0)
    cout << "\nCan't find the value "<<x;
    else {
    DNode *p = sEle(L,pos);
    if(p == nullptr) {
        addHead(L,x);
    }
    else if(p == L.pTail) {
        addTail(L,x);
    }
    else {
        DNode* t = getDNode(x);
        t->pPrev = p->pPrev;
        t->pNext = p;
        
        p->pPrev = t;
        (p->pPrev)->pNext = t;
    }
    }
    
}
int main()
{
	DList L;
	init(L);
	int x,y,choice;

	cout<<"MENU:";
    cout<<"\n1. Create a DList";
    cout<<"\n2. Print the DList";
    cout<<"\n3. Insert a value at the front";
    cout<<"\n4. Insert a value at the end";
    cout<<"\n5. Insert a value after a given value (only for the first value found)";
    cout<<"\n6. Insert a value before a given value (only for the first value found)";
    cout<<"\n7. Insert a value after a given value (for all the same values)";
    cout<<"\n8. Insert a value before a given value (for all the same values)";
    cout<<"\n20. Exit"<<endl;

	while(true)
    {
        cout<<"\n\t\tPLEASE SELECT YOUR CHOICE: ";
        cin>>choice;
        switch(choice)
        {
        case 1:
            cout<<"\nEnter your positive integers until you enter -1 to finish: ";
            createList(L);
            break;
        case 2:
            cout<<"\nYour current DList: ";
            printList(L);
            break;
        case 3:
            cout<<"\nEnter a number: ";
            cin>>x;
            addHead(L,x);
            break;
        case 4:
            cout<<"\nEnter a number: ";
            cin>>x;
            addTail(L,x);
            break;
        case 5:
            cout<<"\nEnter two numbers: ";
            cin>>x>>y;
            addAfter(L,x,y);
            break;
        case 6:
            cout<<"\nEnter two numbers: ";
            cin>>x>>y;
            addBefore(L,x,y);
            break;
        case 20:
            cout<<"\nGOOD BYE";
            return 0;

        }
    }

	return 0;
}

