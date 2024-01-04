#include<bits/stdc++.h>

using namespace std;

int char_in_string(char a, char p[]){
    for(int i = 0; i < strlen(p); i++){
        if (p[i]== a){
            return i;
        }
    }
    return -1;
}



int Boyer(char t[],char p[]){
    int dem = 0, v = strlen(p), i = v - 1;
    int check = 0;
    while( i < strlen(t)){
        int x = strlen(p) - 1;
        while(x > -1 && t[i] == p[x]){
            i--; x--;
        }
        if ( x < 0) {
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
        if (dem == 1) return dem;

    }
    return dem;
}

void z_algo(string s, int z[]){
    int n = s.length(), left = 0, right = 0;
    for(int i = 1; i < n; i++){
        if( i > right){
            left = i;
            right = i;
            while( right < n && s[right - left] == s[right])
                right ++;
            z[i] = right - left;
            right --;
        }
        else if ( z[i - left] < right - i + 1)
            z[i] = z[i - left];
        else {
            left = i;
            while(right < n && s[right - left] == s[right])
                right ++;
            z[i] = right - left;
            right --;
        }
    }
}


// tim xau con dai nhat
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
    int n = 4;
    string d[n] =  {
        "i love my child",
        "we dont have child",
        "I like this",
        "What is your name"
    };

    char t[] = "mothaibabonnamsaubay";
    char p[] = "namsau";
    int m =  t[0] == t[0];
    cout << m << endl;

    cout << Boyer(t, p);
    //cout << t.find("k"); // 18446744073709551615


    string s = "Viet$Ban Viet o Viet Nam";
    int z[24] = {0};
    z_algo(s, z);
    for(int i = 0; i < 24; i++){
        cout << z[i] << " ";
    }

    // xau con dai nhat
    cout << "\n-------------\n";
    int **l = new int*[1000];
    for(int i = 0; i<1000; i++)
           l[i] = new int[1000];
    char xc[1000] = "";
    char a[] = "BACDB";
    char b[] = "BDCB";
    algorithm(a, b, l);
    xau_con(a,b, xc, l);
    for(int i = 0; i <= strlen(b); i++){
        for(int j = 0; j <= strlen(a); j++){
            cout << l[i][j] << " ";
        }
        cout << endl;
    }
    cout << "Longest Common Subsequence: " << xc << endl;



    return 0;
}
