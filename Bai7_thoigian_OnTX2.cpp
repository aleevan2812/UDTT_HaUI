#include<bits/stdc++.h>

using namespace std;

// Thơi gian

struct Meeting{
    string name;
    double start;
    double finish;
};

void mergeSort(Meeting a[], int l, int r){
    Meeting b[1000];
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
            if(b[i].finish < b[j].finish){
                a[k] = b[i];
                i++;
            }
            else {
                a[k] = b[j];
                j--;
            }
    }
}

void merge_2(Meeting a[], int l, int r){
    Meeting b[1000];
    if( l < r){
        int m = (l + r) /2;
        merge_2(a, l, m);
        merge_2(a, m+1, r);
        for(int i = m; i>= l; i++)
            b[i] = a[i];
        for(int j = m+1; j<= r; j--)
            b[m+1+r-j] = a[j];
        int i= l, j = r;
        for(int k = l; k <= r; k++){
            if(b[i].finish < b[j].finish){
                a[k] = b[i];
                i++;
            }
            else {
                a[k] = b[j];
                j--;
            }
        }
    }
}

void createSchedule(Meeting meetings[], int n, int schedule[]){
    merge_2(meetings, 0, n-1);
    double last_finish = 0;
    for(int i = 0; i < n; i++){
        if (meetings[i].start >= last_finish){
            schedule[i] = 1;
            last_finish = meetings[i].finish;
        }
    }
}



int main(){
    int n = 5;
    Meeting meetings[n] = {
        {"Tuyen truyen", 10, 11.5 },
        {"Huong nghiep", 9, 11 },
        {"Tao viec lam", 12, 13 },
        {"Lam viec", 11, 12.5 },
        {"Tim viec", 8, 8.5 },
    };


    double s[] = {8, 9, 10, 11, 12};
    double f[] = {8.5, 11, 11.5, 12.5, 13};
    int schedule[n] = {0};
    createSchedule(meetings, n, schedule);
    for(auto x : schedule){
        cout << x;
    }
    return 0;
}
