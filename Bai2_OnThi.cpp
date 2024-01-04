#include<bits/stdc++.h>

using namespace std;

// Tham lam
int greedyAlgo(double a[], int n, double C){
    int D = 0;
    double M = 0;
    for(int i = 0; i < n; i++){
        if( M + a[i] <= C){
            M += a[i];
            D++;
        }
    }
    return  D;
}


// Boyer
int char_in_string(char a, string p){
    for(int i = 0; i < p.length(); i++){
        if (p[i]== a){
            return i;
        }
    }
    return -1;
}
int Boyer(string t, string p){
    int dem = 0, v = p.length(), i = v - 1;
    while( i < t.length()){
        int x = v - 1;
        while(x > -1 && t[i] == p[x]){
            i--; x--;
        }
        if ( x < 0) {
            return i+1;
            dem ++;
            i = i + v;
        }
        else {
            int k = char_in_string(t[i], p);

            if( k < 0) i = i + v ;
            else {
                i = i + v - k - 1;
            }
        }
     //   if (dem == 1) return dem;

    }
    return -1;
}

int Boyer_2(string t, string p){
    int v = p.length(), i = v -1;
    while( i < t.length()){
        int x =  v -1;
        while(x > -1 && t[i] == p[x]){
            x--;
            i--;
        }
        if( x < 0){
            return i + 1;
            i = i + v;
        }
        else {
            int k = char_in_string(t[i], p);
            if ( k < 0){
                i = i + v;
            }
            else i = i + v -k -1;
        }
    }
    return -1;
}

int main(){
    int n = 8;
    // a asc
    double a[n] = {4, 7.6, 12.4, 12.5, 14, 17, 26.6, 55};
    double C = 40;
    int D = greedyAlgo(a, n, C);
    cout << D << endl;

    cout << "---------------------------\n";

    string P = "child" , Q = "I have 1 child";
    int check = Boyer_2(Q, P);
    cout << check;

    return 0;
}
