#include<bits/stdc++.h>
using namespace std;

int mcm(int arr[],int i,int j){
    //base case
    if(i == j){
        return 0;
    }
    int temp;
    int minm  = INT_MAX;
    for(int k=i;k<j;k++){
        temp = mcm(arr,i,k)+mcm(arr,k+1,j)+(arr[i-1]*arr[k]*arr[j]);
        if(temp<minm ){
            minm = temp;
        }
    }
return minm;
}

int main(){
    
    int arr[] = {1, 2, 3, 4, 3}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
  
    cout << "Minimum number of multiplications is "
         << mcm(arr, 1, n - 1);
    return 0;
}