#include<bits/stdc++.h>

using namespace std;

int sum(int a[], int left, int right){
    if ( left == right) return a[left];
    int mid = (left + right) / 2.0;
    int sum_left = sum(a, left, mid);
    int sum_right = sum(a, mid +1, right);
    return sum_left + sum_right;
}

int sum_odd(int a[], int n){
    if( n < 0 ) return 0;
    if (a[n] % 2 == 0) return sum_odd(a, n-1);
    else return a[n] + sum_odd(a, n-1);
}

int sum_unsign(int a[], int left, int right){
    if(left == right && a[left] > 0) return a[left];
    if(left == right && a[left] <= 0) return 0;
    int mid = (left + right) / 2.0;
    int sum_unsign_left = sum_unsign(a, left, mid);
    int sum_unsign_right = sum_unsign(a, mid + 1, right);
    return sum_unsign_left + sum_unsign_right;
}

int main(){
    int n = 10;
    int a[n] = {4, 2, 3,9,5,-3,2, 8, 6, -1};
    cout << sum(a, 0, n-1);
    cout << "\n-------------------\n";
    cout << sum_odd(a, n-1);
    cout << "\n-------------------\n";
    cout << sum_unsign(a, 0, n-1);
    return 0;
}
