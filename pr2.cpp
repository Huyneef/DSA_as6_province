#include <bits/stdc++.h>
using namespace std;
struct tinh {
    int id;
    string name;
    long pop;
    float area;
};
typedef tinh pro;
struct node {
    pro info;
    node *next;
};
struct List {
    node *head;
    node *tail;
};
void Init(List &l) {
    l.head = NULL;
    l.tail = NULL;
}
node* getNode(pro x) {
    node* p = new node;
    p->info = x;
    p->next = NULL;
    return p;
}
void inputPro(pro &x) {
    cin >> x.id;
    cin.ignore() ;
    getline(cin,x.name);
    cin >> x.pop;
    cin >> x.area;
}
void outputProvince(pro p) {
    cout << p.id << "\t" << p.name << "\t" << p.pop << "\t" << p.area << endl;
}

void addTail(List &L, pro x) {
    node *p = getNode(x);
    if(L.head == NULL) {
        L.head = p;
        L.tail = p;
    }
    else {
        L.tail->next = p;
        L.tail = p;
    }
}
void inputListProvinces(List &l) {
    int n; cin >> n;
    while(n--) {
        pro x;
        inputPro(x);
        addTail(l,x);
    }
}
void outputListProvinces(List l) {
    if(l.head == nullptr) return;
    else {
        node* p = l.head;
        while(p != nullptr) {
            outputProvince(p->info);
            p=p->next;
        }
    }
}
bool searchPro(List l,string s) {
    for(;l.head != nullptr;) {
        if((l.head->info).name == s) {return 1;}
        l.head = l.head->next;
    }
    return 0;
}
void addHead(List &L, pro x) {
    node *newele = getNode(x);
    if(L.head == nullptr) {
        L.head = newele;
        L.tail = newele;
    }
    else {
        newele->next = L.head;
        L.head = newele;
        
    }
}

node* sEle(List L,string a) {
    for(;L.head != nullptr;) {
        if((L.head->info).name == a) {break;}
        L.head = L.head->next;
    }
    return L.head;
}
void addAfter(List &L,pro x,string s) {
    
    node *p = sEle(L,s);
    if(p == nullptr) {
        addHead(L,x);
    }
    else if(p == L.tail) {
        addTail(L,x);
    }
    else {
        node *tmp = getNode(x);
        tmp->next = p->next;
        p->next = tmp;
    }
    
}
int main () {
    List L;
    Init(L);

    inputListProvinces(L);
    cout<<"List of provinces:"<<endl;
    cout<<"ID\t|Province\t|Population\t|Area"<<endl;
    outputListProvinces(L);
    string s;
    cout << "Enter the name to search:\n";
    cin.ignore();
    getline(cin,s);
    if(searchPro(L,s) == 0) cout << "Not found";
    else {
    cout << "Input a new province:";
    pro neW;
    inputPro(neW);
    addAfter(L,neW,s);
    cout << "\nUpdated List:\n";
    cout<<"ID\t|Province\t|Population\t|Area"<<endl;
    outputListProvinces(L);
    }
}