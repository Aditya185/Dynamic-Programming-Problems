#include<bits/stdc++.h>
using namespace std;

int memo[1001][1001];

int mcm(int arr[],int i,int j){
    //base case
    if(i == j){
        return 0;
    }
    if(memo[i][j] != -1){
        return memo[i][j];
    }
    int temp;
    int minm  = INT_MAX;
    for(int k=i;k<j;k++){
        temp = mcm(arr,i,k)+mcm(arr,k+1,j)+(arr[i-1]*arr[k]*arr[j]);
        if(temp<minm ){
            minm = temp;
        }
    }
return memo[i][j] = minm;
}

int main(){
    
    int arr[] = {1,3,1,5,8,1}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    memset(memo,-1,sizeof memo);
  
    cout << "Minimum number of multiplications is "
         << mcm(arr, 1, n - 1);
    return 0;
}