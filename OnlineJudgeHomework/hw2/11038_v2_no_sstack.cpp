#include <iostream>
using namespace std;
int main()
{
    int m;
    cin >> m;
    int ind = 0;
    int *stk = new int[m-1];
    for (int i=0;i<=m-2;++i) {
        cin >> stk[i];
        // ind = ((ind + m - k) % (i+1) + (i+1)) % (i+1);
    }
    for (int i=1;i<=m-1;++i) {
        ind = (ind + stk[m-1-i]) % (i+1);
    }
    cout << ind+1;
    return 0;
}