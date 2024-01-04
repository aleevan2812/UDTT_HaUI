#include<bits/stdc++.h>

using namespace std;

bool cashiers_algo(int c[], int m, int n, int s[]){
    int i = 0;
    while ( n > 0 && i < m){
        if(c[i] <= n){
            s[i] = 1;
            n = n - c[i];
        }
        i++;
    }
}

int main(){
    int m = 7;
    int c[m] = {10, 5,3,2, 1};

    int n = 8; // gia tri
    int s[m] = {0};
    cashiers_algo(c, m, n, s);
    for(auto x: s){
        cout << x << " ";
    }
    return 0;
}
