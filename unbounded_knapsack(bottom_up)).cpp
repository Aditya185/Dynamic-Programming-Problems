#include <bits/stdc++.h>
using namespace std;




int unbounded_knapsack(int val[],int wt[],int cap,int n){

    int memo[n+1][cap+1];
 
   //base case
    for(int i=0;i<n+1;i++){
        for(int j=0;j<cap+1;j++){
            if(i == 0 || j == 0){
                memo[i][j] = 0;
            }

     
        }
    }

    for(int i=1;i<n+1;i++){
        for(int j=1;j<cap+1;j++){
            if(wt[i-1] <= j){
                memo[i][j] =  max(val[i-1]+memo[i][j-wt[i-1]],memo[i-1][j]);
            }else{
                memo[i][j] = memo[i-1][j];
            }

      
        }
    }

    return memo[n][cap];

 
   
   
}

int main(){
   int W = 100; 
    int val[] = {10, 30, 20}; 
    int wt[] = {5, 10, 15}; 
    int n = sizeof(val)/sizeof(val[0]);  
   

    cout<<unbounded_knapsack(val,wt,W,n)<<endl;
    return 0;
}
