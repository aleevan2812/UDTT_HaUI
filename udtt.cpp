#include<bits/stdc++.h>

using namespace std;

int char_in_string(char x, string P){
    for(int i = 0; i < P.size(); i++){
        if(x == P[i]) return i;
    }
    return -1;
}

int Boyer(string P,const string& T){
    int dem = 0, v = P.size();
    int i = v-1;
    while (i < static_cast<int>(T.size())) {
        int x = v - 1;
        while (T[i] == P[x] && x > -1){
            i--; x--;
        }
        if (x < 0) {
            dem++;
            i = i + v;
        }
        else {
            int k = char_in_string(T[i], P);
            if (k < 0) i = i + v;
            else i = i + v - x - 1;
        }
    }
    return dem;
}



int main(){
    string a = "abc";
    string b = "uqiuwabccc";
    cout << Boyer(a,b );
    return 0;
}

