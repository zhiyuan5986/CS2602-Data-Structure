#include <iostream>
#include <cstring>
using namespace std;
char* add_two_string(char *p, char *q)
{
    char num[11] = "0123456789";
    char *a=NULL,*b=NULL;
    if (strlen(p) < strlen(q)) {a=q;b=p;}
    else {a=p;b=q;}//a is longer.
    char *result = new char[strlen(a)+2];
    result[strlen(a)+1] = '\0';
    int i,carry=0;
    for (i=0;i<strlen(b);++i) {
        int tmp = (a[i]-'0')+(b[i]-'0')+carry;
        result[i] = num[tmp%10];
        carry = tmp/10;
    }
    while (i<strlen(a)) {
        int tmp = (a[i]-'0')+carry;
        result[i] = num[tmp%10];
        carry = tmp/10;
        ++i;
    }
    if (carry == 1) {result[i] = '1';++i;}
    if (i == strlen(a)) {
        result[strlen(a)] = '\0';
    }
    return result;

}
int main()
{
    int m,n;
    cin >> m >> n;
    char *p = new char[m];
    char *q = new char[n];
    cin >> p >> q;
    char * res = add_two_string(p,q);
    cout << res;
    delete [] res;
    delete [] p;
    delete [] q;
    return 0;
}
