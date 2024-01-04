#include<bits/stdc++.h>

using namespace std;

struct HangHoa{
    string name;
    double kl;
    double price;
};

int priceSum(HangHoa d[], int n){
    if( n < 0) return 0;
    else {
        return priceSum(d, n-1) + d[n].price;
    }
}

int sameCount(HangHoa d[], int left, int right, double p){
    if(left == right && d[left].price < p) return 1;
    if(left == right && d[left].price >= p) return 0;
    int mid = (left + right) /2;
    int left_sameCount = sameCount(d, left, mid, p);
    int right_sameCount = sameCount(d, mid+1, right, p);
    return left_sameCount + right_sameCount;
}

int x[1000] = {0};
int _bool[100] = {0};
void display_hanghoa(HangHoa d[], int x[], int n){
    for(int i = 1; i <= n; i++){


        cout <<left<<setw(15)<< d[x[i]-1].name + to_string(i)  ;
    }
    cout << endl;
}

void Try(HangHoa d[],int k, int n){

    for(int i = 1; i <= n; i++){
        if(_bool[i] == 0){
            x[k] = i;
            _bool[i] = 1;
            if(k == n){
                display_hanghoa(d, x, n);
            }
            else{
                Try(d, k+1, n);
            }
            _bool[i] = 0;

        }

    }

}

int main(){
    HangHoa d[5] = {
        {"Cho", 12, 100 },
        {"Meo", 10, 200 },
        {"Lon", 11, 150 },
        {"Ga", 12, 100 },
        {"Vit", 9, 101 },
    };

    // c1
    cout << "Tong gia: " << priceSum(d, 4);
    cout << "\nSo hang co gia ban < 120 la: " << sameCount(d, 0, 4, 120) << endl;
    Try(d, 1, 5);
    return 0;
}
