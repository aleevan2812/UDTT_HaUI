#include<bits/stdc++.h>
using namespace std;

struct Quat{
	string brand;
	string color;
	int price;
};

void show(Quat d){
	cout<<left<<setw(10)<<d.brand<<setw(10)<<d.price<<endl;
}

void init(Quat d[]){
	d[0] = {"samsung", "xanh", 150};
	d[1] = {"sony", "do", 250};
	d[2] = {"dienco81", "tim", 100};
	d[3] = {"panasonic", "vang", 350};
	d[4] = {"samsung", "luc", 300};
	d[5] = {"LG", "lam", 50};
}

void quick_sort(Quat d[], int left, int right){
	if(left < right){
		int m = (left + right)/2;
		int t = d[m].price;
		int i = left, j = right;
		do{
			while(d[i].price < t) i++;
			while(d[j].price > t) j--;
			if(i<=j){
				Quat tg = d[i];
				d[i] = d[j];
				d[j] = tg;
				i++;
				j--;		
			}
		} while(i<=j);
		quick_sort(d, left, j);
		quick_sort(d, i, right);
	}
}

void solve(Quat d[], int n, int p){
	int i=0;
	while (p > 0 && i < n){
		if(p >= d[i].price){
			p -= d[i].price;
			i++;
			show(d[i-1]);
		}
		else break;
	}
	cout << "Tong so quat mua duoc la: " << i << endl;
}

int main(){
	int n = 6;
	int p = 290;
	Quat d[n];
	init(d);
	cout << "DANH SACH QUAT\n";
	cout<<left<<setw(10)<<"Brand"<<setw(10)<<"Price"<<endl;
	for(int i=0;i<n;i++){
		show(d[i]);
	}
	cout<<"---------------------------------------\n";
	cout << "DANH SACH QUAT MUA DUOC NHIEU NHAT\n";
	quick_sort(d, 0, n-1);
	solve(d, n, p);
}