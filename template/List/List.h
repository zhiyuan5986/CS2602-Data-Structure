#include <iostream>
using namespace std;

template <class elemType>
class List
{
public:
    struct node{
        elemType data;
        node *next;

        node(const elemType &x, node *n = NULL)
        {
            data = x; next = n;
        }
        node():next(NULL) {}
        ~node() {}
    };
    node *head;
    node *tail;
    int currentLength;
    node *move(int i) const {node *p = head;while (i-- >= 0) p = p->next;return p;} //return address of i-th node. 
    
    List() {head = new node;currentLength = 0;}
    ~List() {clear();delete head;}
    void clear() {node *p = head->next,*q;head->next = NULL;while (p) {q = p->next;delete p;p=q;}currentLength=0;}
    int length() const {return currentLength;}
    void insert(int i, const elemType &x) {node *p = move(i-1);p->next = new node(x,p->next);++currentLength;}
    void remove(int i) {node *p, *q;p = move(i-1);q = p->next;p->next = q->next;delete q;--currentLength;}
    int search(const elemType &x) const {node *p = head->next;int i=0;while (p && p->data != x) {p=p->next;++i;}if (!p) return -1;else return i;}
    elemType visit(int i) const {move(i)->data;}
    void traverse() const {cout << endl;node *p = head->next;while (p != NULL) {cout << p->data << ' ';p=p->next;}}

    void push_back(const elemType &x) {move(currentLength-1)->next = new node(x,NULL);++currentLength;}
    elemType pop_back() {node *p = move(currentLength-2),*q=p->next;elemType x = q->data;delete q;p->next =NULL;--currentLength;return x;}
    elemType front() const {if (currentLength) return head->next->data;}
    void push_front(const elemType &x) {head->next = new node(x,head->next);++currentLength;}
    elemType pop_front()  {if (head->next) {node *p = head->next;elemType x = p->data;head->next = p->next;delete p;--currentLength;return x;}}
    // void erase(int i);
};