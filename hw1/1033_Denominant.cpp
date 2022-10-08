#include <iostream>
// #include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 10;
int matrix[MAXN][MAXN];
int arr[MAXN]; //用作计算逆序对个数
int inverted;
//用归并排序的思想，计算每个数的逆序对数量

// void merge(int a[], int left, int mid, int right, int answer[])
// {
//     int *tmp = new int[right-left+1];
//     int i = left, j = mid, k = 0;
//     int tmp_count = 0;
//     while (i < mid && j <= right)
//         if (a[i] < a[j]) {answer[a[i]-1] += tmp_count;tmp[k++] = a[i++];}
//         else {
//             while (j <= right && a[j] < a[i]){++tmp_count;tmp[k++] = a[j++];}
//             //for (int index=mid;index<j;++index) ++answer[a[index]-1];
//             if (j > right) {answer[a[i]-1] += tmp_count;tmp[k++] = a[i++];}
//         }
//     //for (int index=mid;index<=right;++index) answer[a[index]-1] += mid-i;
//     while (i < mid) {
//         answer[a[i]-1] += tmp_count;
//         tmp[k++] = a[i++];
//     }
//     while (j <= right) tmp[k++] = a[j++];
//     for (i=0,k=left;k <= right;) a[k++] = tmp[i++]; 
// }

void merge(int a[], int left, int mid, int right) 
{
    int *tmp = new int[right-left+1];
    int tmp_count = 0;
    int i=left, j=mid, k=0;
    while (i<mid && j <= right) {
        if (a[i] < a[j]) {inverted += tmp_count;tmp[k++] = a[i++];}
        else {
            while (j <= right && a[j] < a[i]) {++tmp_count;tmp[k++] = a[j++];}
            if (j > right) {inverted += tmp_count;tmp[k++] = a[i++];}
        }
    }
    while (i < mid) {
        inverted += tmp_count;
        tmp[k++] = a[i++];
    }
    while (j <= right) tmp[k++] = a[j++];
    for (i=0,k=left;k<=right;) a[k++] = tmp[i++];
}

void count_inversion(int a[], int left, int right)
{
    if (left == right) return;
    int mid = (left+right)/2;
    count_inversion(a,left,mid);
    count_inversion(a,mid+1,right);
    merge(a,left,mid+1,right);
    // if (n == 1) return a;
    // int *b = merge(a,n/2,count);
    // int *c = merge(a+n/2,n-n/2,count);
    // int i,j,k;
    // i = j = k = 0;
    // merge()
}

// int change(int arr[], int n)
// {
//     int count=0;
//     for(int i=1;i<n;i++)
//     {
//         for(int j=0;j<i;j++)
//         {
//             if(arr[j]>arr[i]) count++;
//         }
//     }
//     if(count%2==0) return 0;
//     else return 1;
// }

int main()
{
    int n, tmp;
    cin >> n;
    int sum = 1;
    for (int i=0;i<n;++i) {
        arr[i] = i;
        for (int j=0;j<n;++j) {
            cin >> matrix[i][j];
            // matrix[i][j] = tmp;
        }
    }
    for (int i=0;i<n;++i) sum *= matrix[i][i];
    int *arr_tmp = new int[n];
    while (next_permutation(arr,arr+n)) {
        int res = 1;
        for (int i=0;i<n;++i) {res *= matrix[i][arr[i]];arr_tmp[i] = arr[i];}
        inverted = 0;
        count_inversion(arr_tmp,0,n-1);
        if (inverted %2 == 0) sum += res;
        else sum -= res;
    }
    cout << sum;
    delete [] arr_tmp;
    return 0;
}