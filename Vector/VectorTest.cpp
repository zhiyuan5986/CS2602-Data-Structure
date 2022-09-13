#include <iostream>
#include "Vector.h"
using namespace std;
int main()
{
    Vector<int> vec;
    for (int i=0;i<10;++i) vec.push_back(i);
    vec.traverse();

    vec.pop_back();
    vec.traverse();

    vec.remove(5);
    vec.traverse();

    vec.insert(5,5);
    vec.traverse();
    return 0;
}