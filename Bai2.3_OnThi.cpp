#include<bits/stdc++.h>

using namespace std;

struct GoiHang{
    int w;
    int v;
};

void algorithm(int **f, int n, int m, GoiHang a[]){
    for(int j = 0; j <= m; j++) f[0][j] = 0;
    for(int i= 1; i <= n; i++){
        for(int j = 0; j <= m; j++){
            f[i][j] = f[i-1][j]; // khong lay goi thu i
            if(a[i].w <= j){
                int temp = a[i].v + f[i-1][j-a[i].w];
                if ( f[i][j] < temp) // Lay goi thu i
                    f[i][j] = temp;
            }
        }
    }

}



void result(int **f, int n, int m, GoiHang a[]){
    cout << "Max value: " << f[n][m] << endl;
    int i = n, j = m;
    while ( i != 0){
        if(f[i][j] != f[i-1][j]){
            cout << i << " ";
            j = j- a[i].w;
        }
        i--;
    }
}

void algo(int **f, int n, int m, GoiHang a[]){
    for(int j = 0; j <= m; j++) f[0][j] = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= m; j++){
            f[i][j] = f[i-1][j];
            if(a[i].w <= j){
                int temp = a[i].v + f[i-1][j-a[i].w];
                if(f[i][j] < temp){
                    f[i][j] = temp;
                }
            }
        }
    }
}

void res(int **f, int n, int m, GoiHang a[]){
    cout << "Max: " << f[n][m] << endl;
    int i = n, j = m;
    while(i != 0){
        if( f[i][j] != f[i-1][j]){
            cout << i << " ";
            j = j - a[i].w;
        }
        i--;
    }
}


int main(){
    int n = 6;
    int m = 10;

    GoiHang a[n] = {
        {3 , 5},
        {4 , 2},
        {2 , 6},
        {1 , 7},
        {5 , 4},
        {4 , 8}

    };


    int **f = new int *[n+ 1];
    for(int i = 0; i < n+1; i++){
        f[i] = new int [m+1];
    }


    algo(f, n, m, a);
    for(int i = 0; i < n+1; i++){
        for(int j = 0; j < m+1; j++){
            cout <<setw(3)<< f[i][j] << " ";
        }
        cout << endl;
    }

    res(f, n, m, a);

    return 0;
}
