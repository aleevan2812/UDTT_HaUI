#include<bits/stdc++.h>

using namespace std;

int char_in_string(char a, string p){
    for(int i = 0; i < p.length(); i++){
        if( a == p[i])
            return i;
    }
    return -1;
}

int Boyer(string t, string p){
    int dem = 0, v = p.length(); i = v - 1;
    while(i < t.length()){
        int x = v - 1;
        if(x > -1 && t[i] == p[x]){
            x--;
            i--;
        }
        if ( X < 0){
            dem++;
            i = i + v;
        }
        else {
            int k = char_in_string(t[i], p);
            if (k < 0){
                i = i + v;
            }
            else i = i + v - k -1;
        }
        if (dem == 1) return 1;
    }
    return 0;
}

void z_algo(string s, int z[]){

}

int main(){

    return 0;
}
