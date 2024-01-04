#include<bits/stdc++.h>

using namespace std;

struct quat{
    string ten;
    string mau;
    float gia;

};

void show(quat q) {
    cout << q.ten << " - " << q.gia << endl;
}

void muaQuat(quat qs[], int n, float tien) {
    int dem = 0;
    int qm[n];
    for(int i = 0; i < n; i++) {
        qm[i] = 0;
    }
    for(int i = 0; i < n; i++) {
        tien -= qs[i].gia;
            dem++;
            qm[i] = 1;
        if(qs[i].gia == tien) {
                break;
        }
    }
    cout << "Mua duoc toi da so quat la: " << dem <<endl;
    cout << "Cac quat mua duoc la: " << endl;
    for(int i = 0; i < n; i++) {
        if(qm[i] == 1) show(qs[i]);
    }
}

int main() {
    quat qs[8] = {
        {"quat cam tay", "xanh", 10000},
        {"quat may", "do", 20000},
        {"quat con nghiep", "tim", 30000},
        {"quat dien", "vang", 40000},
        {"quat khong canh", "nau", 50000},
        {"quat 6 canh", "den", 60000},
        {"quat tran", "trang", 70000},
        {"quat mo", "tim", 80000},
    };

    muaQuat(qs, 8, 200000);
}
