#include<bits/stdc++.h>
using namespace std;

//Khoi luong toi da cua cai tui
int m;

struct GoiHang{
 int weight;
 int value;
};
void Init(GoiHang mgh[]){
 mgh[0] = {3 , 5};
 mgh[1] = {4 , 2};
 mgh[2] = {2 , 6};
 mgh[3] = {1 , 7};
 mgh[4] = {5 , 4};
 mgh[5] = {4 , 8};
}
void Qhd(GoiHang mgh[] , int n){
 int arr[n][m+1] ;
//Khoi tao hang 0 cot 0 co gia tri la 0 con lai cac hang khac co gia tri - 1
 for(int i = 0 ; i < n ; i++){
  for(int j = 0 ; j <= m ; j++){
   if(i == 0){
    arr[0][j] =  0;
   }else if(j == 0){
    arr[i][0] =  0;
   }else{
    arr[i][j] = -1;
   }
  }
 }

//Quy hoach dong
 for(int i = 1 ; i < n ; i++){
  for(int j = 1 ; j <= m ; j++){
    //Neu khong lay goi hang thu i
    arr[i][j] = arr[i-1][j];

    if(j - mgh[i].weight > 0){
    int temp = mgh[i].value + arr[i-1][j - mgh[i].weight];
    //Dieu kien neu lay goi hang thu i
    //if(arr[i][j] < temp){
     //arr[i][j] = temp;
     //}
     arr[i][j] = max(arr[i-1][j] , temp);
    }
   }
  }
 //Gia tri lon nhat co the lay
 cout<<"Max value : "<<arr[n-1][m]<<endl;

  for(int i = 0 ; i < n ; i++){
  //khoi tao tai vi tri hang 0 cot 0 gia tri la 0
  for(int j = 0 ; j <= m ; j++){
   cout<<arr[i][j]<<" ";
  }
  cout<<endl;
 }

 int i = n - 1 , j = m;
 cout<<left<<setw(10)<<"Goi i"
    <<setw(15)<<"Weight"
    <<setw(15)<<"Value"<<endl;
 while(i != 0){
  if(arr[i][j] != arr[i-1][j]){
   cout<<left<<setw(10)<<i
    <<setw(15)<<mgh[i].weight
    <<setw(15)<<mgh[i].value<<endl;

   j = j - mgh[i].value;//lay goi thu i
  }
  i--;
 }
}

int main()
{
 int n = 6;
 m = 10;

 GoiHang mgh[n];
 //Khoi tao mang gia tri
 Init(mgh);

 //In ra ket qua
 Qhd(mgh , n);
 return 0;

}
