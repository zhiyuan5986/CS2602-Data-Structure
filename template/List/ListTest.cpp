#include <iostream>
#include "List.h"
using namespace std;
int main()
{
    List<int> lst;
    for (int i=0;i<10;++i) lst.push_back(i);
    lst.traverse();

    cout << endl << lst.pop_back() << ' ' << lst.length() << endl;
    lst.traverse();

    lst.remove(5);
    lst.traverse();

    lst.insert(5,5);
    lst.traverse();

    lst.pop_front();
    lst.traverse();

    cout << endl << lst.length() << endl;
    return 0;
}