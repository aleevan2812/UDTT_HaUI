#include<bits/stdc++.h>

using namespace std;

// Bai 4 _ Quy hoach dong _ Cai tui

void algorithm(int **f, int n, int m, int w[], int v[]){
    for(int j = 0; j <= m; j++) f[0][j] = 0;
    for(int i= 1; i <= n; i++){
        for(int j = 0; j <= m; j++){
            f[i][j] = f[i-1][j]; // khong lay goi thu i
            int temp = v[i] + f[i-1][j-w[i]];
            if ( w[i] <= j && f[i][j] < temp) // Lay goi thu i
                f[i][j] = temp;
        }
    }
}

void result(int **f, int n, int m, int w[]){
    cout << "Max value: " << f[n][m] << endl;
    int i = n, j = m;
    while(i != 0){
        if( f[i][j] != f[i-1][j]){
            cout << i << " ";
            j = j - w[i]; // Lay goi thu i
        }
        i--;
    }
}

int main(){
    int m = 10;
    int n = 6;
    int w[n] = {3, 4, 5, 1, 2, 4};
    int v[n] = {2, 5, 6 ,7 ,4, 8};
    int **f = new int *[n+ 1];
    for(int i = 0; i < n+1; i++){
        f[i] = new int [m+1];
    }

    for(int i = 0; i < n+1; i++){
        for(int j = 0; j < m+1; j++){
            f[i][j] = 0;
        }
    }

    algorithm(f, n, m, w, v);
    for(int i = 0; i < n+1; i++){
        for(int j = 0; j < m+1; j++){
            cout <<setw(3)<< f[i][j] << " ";
        }
        cout << endl;
    }

    result(f, n, m, w);

    return 0;
}
