#include <iostream>
#include <cstring>
#include <algorithm>
#include<bits/stdc++.h>

using namespace std;

// Bai 5 _ Boyer _ Z

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
void ungDungBoyer(string d[], int n, string child){
    int check[n] = {0};
    int count  = 0;
    for(int i = 0; i < n; i++){
        if(Boyer(d[i], child) == 1){
            count++;
            check[i] = 1;
        }
    }
    cout << "child xuat hien trong " << count << " xau\n";
    for(int i = 0; i < n; i++){
        if (check[i] == 1){
            cout <<"\t"<< d[i] << endl;
        }
    }
    cout << "------------------------\n";
}

// y3
// Thuat toan Z
void z_algo(string s, int z[]){
    int n = s.length(), left = 0, right = 0;
    for(int i = 1; i < n; i++){
        if( i > right){
            right = i;
            left = i;
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
void ungDungZ(string d[], int n){
    int check[n] = {0};
    for(int i = 1; i <n ; i++){
        int count = 0;
        int leng = d[i].length() + d[0].length()+ 1;
        int checkAString[leng] = {0};
        string newStr = d[0] + "$" + d[i];
        z_algo(newStr, checkAString);
        for(int j = 0; j < leng; j++){
            if(checkAString[j] == (int)d[0].length()){
                count ++;
            }
        }
        check[i] = count;
    }
    cout << d[0] << " co trong: \n";
    for(int i = 1; i <n; i++){
        if(check[i] != 0){
            cout << "\t" << d[i] << " - " << check[i] << endl;
        }
    }

}
int main() {


    int n = 4;
    string d[] = {
        "child",
        "i have you",
        "my child is so pretty child",
        "I am too ugly"
    };

    // 2
    string child = "child";
    ungDungBoyer(d, n, child);

    // 3
    ungDungZ(d, n);


    return 0;
}
