#include<bits/stdc++.h>

using namespace std;

int x[100];
int _bool[100] = {0};
double b[100];

// phuong phap sinh day nhi phan do dai n
void next_config(int x[], int n, int i){
    x[i] = 1;
    i++;
    while(i <= n){
        x[i] = 0;
        i++;
    }
}
// hien thi cau hinh
void view_congfig(int x[], int n){
    for(int i = 0; i <= n; i++){
        cout << x[i];
    }
    cout << endl;
}
// liet ke
void listing_config(int n){
    int i;
    int x[n+1] = {0};
    do{
        view_congfig(x, n);
        i = n;
        while(i > 0 && x[i] == 1){
            i--;
        }
        if(i > 0){ //Chua phai cau hinh cuoi
            next_config(x, n, i);
        }
    }while(i > 0);
}
// Sinh day nhi phan = quay lui
void Try(int k, int n){
    for(int i = 0; i <= 1; i++){
        x[k] = i;
        if (k == n){
            view_congfig(x, n);
        }
        else {
            Try(k + 1, n);
        }
    }
}

// pp sinh - liet ke tap con k phan tu
//Sinh cau hinh moi tu cau hinh dang co
void next_config_lk(int x[], int k, int i){
    x[i] += 1;
    i++;
    while( i <= k){
        x[i] = x[i-1] + 1;
        i++;
    }
}
void view_congfig_lk(int x[], int k){
    for (int i = 1; i <= k; i++)
        cout<<x[i];
    cout<<endl;
}
void listing_config_lk(int k, int n){
    int i, x[k+1] = {0};
    for(int i = 0; i <= k; i++){
        x[i] = i;
    }
    do{
        view_congfig_lk(x, k);
        i = k;
        while(i > 0 && x[i] == n-k+i) i--;
        if(i > 0) next_config_lk(x, k, i);
    }while (i> 0);
}

// liet ke tap con  =  quay lui
void Try_lk(int x[], int k, int n){
    for(int i = 1; i <= k; i++){
        if(_bool[i] == 0){
            x[k] = i;
            if(k == n){
                view_congfig_lk(x, k);
            }
            else{
                _bool[i] = 1;
                Try_lk(x, k+1, n);
            }
        }
    }
}

// liet ke hoan vi
void view_config_hv(int x[], int n){
    for (int i = 1; i <= n; i++)
        cout<<x[i];
    cout<<endl;
}
void next_config_hv(int x[], int n, int i){
    // tim x[k] be nhat trong doan cuoi lon hown x[i]
    int k = n;
    while(x[k] < x[i]) k--;
    swap(x[i], x[k]);
    // dao nguoc doan cuoi
    int j = n; i++;
    while (i < j){
        swap(x[i], x[j]);
        i++; j--;
    }
}
void listing_config_hv(int n){
    int i, x[n+ 1] = {0};
    for( i = 1; i <= n; i++) x[i] = i;
    do{
        view_config_hv(x, n);
        // tim phan tu lien truoc doan cuoi giam dan
        i = n-1;
        while(i > 0 && x[i] > x[i+1]) i--;
        if(i > 0) next_config_hv(x, n, i);
    }while( i > 0);
}
// Hoan vi = quay lui
void Try_hv(int x[], int k, int n){
    for(int i = 1; i <= n; i++){
        if(_bool[i] == 0){
            x[k] = i;
            _bool[i] = 1;
            if(k == n){
                view_config_hv(x, n);
            }
            else Try_hv(x, k+1, n);
            _bool[i] = 0;
        }
    }

}

// Tháp Hà nội
void ThapHN(int n, string a, string b, string c){
    if( n == 1) cout << a <<" --> " << c << endl;
    else{
        ThapHN(n-1, a, c, b);
        ThapHN(1, a, b, c);
        ThapHN(n-1, b, a, c);
    }
}

// fibo co nho
int fibonacciMemoization(int n) {
    int memo;
    if (n <= 1) {
        return 1;
    } else {

        memo= fibonacciMemoization(n - 1) + fibonacciMemoization(n - 2);
    }
    return memo;
}

// sap xep tron
void mergeSort(double a[], int l, int r){
    if(r > l){
        int m = (l+r)/2;
        mergeSort(a, l, m);
        mergeSort(a, m+1, r);
        for(int i = m; i >= l; i--){
            b[i] = a[i];
        }
        for(int j = m+1; j <= r;j++){
            b[r+m+1-j] = a[j];
        }
        int i = l, j = r;
        for(int k = l; k <= r; k++)
            if(b[i] < b[j]){
                a[k] = b[i];
                i++;
            }
            else {
                a[k] = b[j];
                j--;
            }
    }
}

int main(){
//    listing_config_lk(4, 6);
//    ThapHN(3, "A", "B", "C");
//    cout << fibonacciMemoization(4);
//    Try(1, 3);
//    for(int i = 0; i <= 3; i++){
//        x[i] = 0;
//    }
    Try_hv(x, 1, 3);
 //   Try_lk(x, 3, 4);
    return 0;
}


