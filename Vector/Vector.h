#include <iostream>
using namespace std;

template <class elemType>
class Vector
{
public:    
    elemType *data;
    int currentLength;
    int maxSize;
    void doubleSpace() {maxSize << 1;elemType *tmp = data;data = new elemType[maxSize];for (int i=0;i<currentLength;++i) data[i]=tmp[i];delete [] tmp;}

    elemType& operator[](int i) {return data[i];}
    Vector(int initSize=10) {data = new elemType[initSize];maxSize=initSize;currentLength=0;}
    ~Vector() {clear();}
    void clear() {delete [] data;}
    int length() const {return currentLength;}
    void insert(int i, const elemType &x) {if (currentLength == maxSize) doubleSpace(); for (int j=currentLength;j>i;--j) data[j]=data[j-1];data[i]=x;}
    void remove(int i) {for (int j=i;j<currentLength-1;++j) data[j]=data[j+1];--currentLength;}
    int search(const elemType &x) const {int i=0;for (;i<currentLength && data[i] != x;++i); if (i == currentLength) return -1;else return i;}
    elemType visit(int i) const {return data[i];}
    void traverse() const {cout << endl;for (int i=0;i<currentLength;++i) cout << data[i] << ' ';}
    void push_back(const elemType &x) {if (currentLength == maxSize) doubleSpace();data[currentLength]=x;++currentLength;}
    elemType pop_back() {--currentLength;return data[currentLength];}
};

