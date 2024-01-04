                                                           #include<bits/stdc++.h>

using namespace std;

// Xau con chung

void algorithm(char a[], char b[], int **l){
    for(int i = 0; i <= strlen(a); i ++) l[i][0] = 0;
    for(int j = 0; j <= strlen(b); j ++) l[0][j] = 0;
    for(int i = 1; i <= strlen(a); i++){
        for(int j = 1; j <= strlen(b); j ++){
            if(a[i-1] == b[j-1])
                l[i][j] = l[i-1][j-1] + 1;
            else
                l[i][j] = max(l[i-1][j], l[i][j-1]);
        }
    }

}

void xau_con( char a[], char b[], char xc[], int **l){
    int i = strlen(a), j = strlen(b), k = 0;
    while(l[i][j] != 0){
        if(a[i-1] == b[j-1]){
            xc[k] = a[i-1];
            k++;
            i--;
            j--;
        }
        else {
            if ( l[i-1][j] > l[i][j-1]) i--;
            else j--;

        }
    }
    xc[k] = '\0';
    reverse(xc, xc+k);
}

int main(){
    int n = 6;
    char a[n] = "Vanank";
    int m = 5;
    char b[m] = "andk";

    int **l = new int*[1000];
    for(int i = 0; i<1000; i++)
           l[i] = new int[1000];
    char xc[1000] = "";

    algorithm(a, b, l);
    xau_con(a,b, xc, l);
    cout << xc << endl;

}
