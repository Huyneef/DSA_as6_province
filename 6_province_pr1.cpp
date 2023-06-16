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
void outputProvincesMore1MillionPop(List l) {
    node* p = l.head;
    while(p != nullptr) {
        if((p->info).pop >= 1000) {
            outputProvince(p->info);
        }
        p = p->next;
    }
}
node* findProMaxArea(List l) {
    node* p = l.head;
    while(l.head != nullptr) {
        if((p->info).area < (l.head->info).area) {
            p = l.head;
        }
        l.head = l.head->next;
    }
    return p;
}
int main()
{
    List L;
    Init(L);

    inputListProvinces(L);
    cout<<"List of provinces:"<<endl;
    cout<<"ID\t|Province\t|Population\t|Area"<<endl;
    outputListProvinces(L);

    cout<<"Provinces with a population of more than 1 million:"<<endl;
    outputProvincesMore1MillionPop(L);

    cout<<"The largest province:"<<endl;
    node *p = findProMaxArea(L);
    if(p) outputProvince(p->info);

    return 0;
}



