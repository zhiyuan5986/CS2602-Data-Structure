#include <iostream>
using namespace std;

int main()
{
    int N;
    cin >> N;

    int *a1 = new int[N+1]{0};
    for (int i=1;i<=N;++i) cin >> a1[i];
    int *a2 = new int[N+1]{0};

    long long int tot=0;//, pos_max=0, neg_max=0;
    int tmp;

    for (int i=1;i<=N;++i) {
        cin >> tmp;
        if (a1[i]>=tmp) {
            a1[i] -= tmp;
        }
        else {
            a2[i] = tmp-a1[i];
            a1[i] = 0;
        }
    }
    for (int i=1;i<=N;++i) {
        if (a1[i]>a1[i-1]) tot += (a1[i]-a1[i-1]);
        else if (a2[i]>a2[i-1])tot += (a2[i]-a2[i-1]);
    }
    cout << tot;
    return 0;
}