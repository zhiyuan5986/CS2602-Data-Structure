#include <iostream>
#include <cstdio>
using namespace std;

namespace LIST
{

    struct NODE {
        // TODO
        int data;
        NODE* next;
        NODE():next(nullptr) {}
        NODE(int d, NODE *n = nullptr) {data = d; next = n;}
    };

    NODE *head = nullptr;
    int len = 0;

    void init() {
        // TODO
        head = new NODE();
        head->next = head;
        len = 0;
    }
    NODE* move(int i) {
        // TODO
        int j;
        NODE *p = head;
        for (j=0;j<i+1;++j) {
            p = p->next;
        }
        return p;
    }
    void insert(int i, int x) {
        // TODO
        // if (i == 0)
        NODE *p = move(i-1);
        p->next = new NODE(x,p->next);
        ++len;
    }
    void remove(int i) {
        // TODO
        NODE *p = move(i-1);
        NODE *tmp = p->next;
        p->next = p->next->next;
        delete tmp;
        --len;
    }
    void remove_insert(int i) {
        //TODO
        NODE *p = move(i-1);
        NODE *tmp = p->next;
        p->next = p->next->next;

        NODE *q = move(len-2);
        
        // head;
        // for (int j=0;j<len;++j) {
        //     q = q->next;
        // }
        q->next = tmp;
        tmp->next = head;
    }
    void get_length() {
        // TODO
        cout << len << endl;
    }
    void query(int i) {
        // TODO
        if (i < 0 || i >= len) cout << -1 << endl;
        else {
            NODE *p = move(i);
            cout << p->data << endl;
        }
    }
    void get_max() {
        // TODO
        if (len == 0) cout << -1 << endl;
        else {
            int MAX = 0;
            NODE *p = head;
            for (int i=0;i<len;++i) {
                p = p->next;
                MAX = (MAX > p->data ? MAX : p->data);
            }
            cout << MAX << endl;
        }
        
    }
    void clear() {
        // TODO
        NODE *p = head, *q;
        for (int i=0;i<=len;++i) {
            NODE *q = p->next;
            delete p;
            p = q;
        }
        head = nullptr;
        len = 0;
    }

}
int n;
int main()
{
    cin >> n;
    int op, x, p;
    LIST::init();
    for (int _ = 0; _ < n; ++_)
    {
        cin >> op;
        switch(op) {
            case 0:
                LIST::get_length();
                break;
            case 1:
                cin >> p >> x;
                LIST::insert(p,x);
                break;
            case 2:
                cin >> p;
                LIST::query(p);
                break;
            case 3:
                cin >> p;
                LIST::remove(p);
                break;
            case 4:
                cin >> p;
                LIST::remove_insert(p);
                break;
            case 5:
                LIST::get_max();
                break;
        }
    }
    LIST::clear();
    return 0;
}