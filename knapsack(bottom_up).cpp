#include <bits/stdc++.h>
using namespace std;

int knapsack(int val[],int wt[],int cap,int n){

    //creating the 2d memo array in this 2d array
    int memo[n+1][cap+1];
    

    //initializing the sidelines with 0
    for(int i=0;i<n+1;i++){
        for(int j=0;j<cap+1;j++){
            if(i==0 || j==0){
                memo[i][j] = 0;
            }
        }
    }

     //filling the rest of the array
      for(int i=1;i<n+1;i++){
         for(int j=1;j<cap+1;j++){
            //if the weight is less than or equal to capacity we simply accept it or reject it
            //then we choose maxm of accepted value or rejected value
            //in both case n is decreasing...first case capacity is decreasing also
            if(wt[i-1] <= j){
                //we simply storing and returning the max value
                memo[i][j] = max(val[i-1]+memo[i-1][j-wt[i-1]],memo[i-1][j]);
            }else if(wt[i-1]>j){//this case we have to reject the value

                 memo[i][j] =memo[i-1][j];
            }
        }
    }
  
return memo[n][cap];
}

int main(){
    int val[] = {60, 100, 120};  
    int wt[] = {10, 20, 30};  
    int W = 50;  
    int n = sizeof(val)/sizeof(val[0]); 
  
 
    cout<<knapsack(val,wt,W,n)<<endl;
    return 0;
}
