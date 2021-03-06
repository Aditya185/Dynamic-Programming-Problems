#include <bits/stdc++.h>
using namespace std;




int knapsack(int val[],int wt[],int cap,int n){

    //base case (which is smallest possible valid value)
    if(cap == 0 || n== 0){
        return 0;
    }
   
    //if the weight is less than or equal to capacity we simply accept it or reject it
    //then we choose maxm of accepted value or rejected value
    //in both case n is decreasing...first case capacity is decreasing also
    if(wt[n-1] <= cap){
        //we simply storing and returning the max value
        return (max(val[n-1]+knapsack(val,wt,cap-wt[n-1],n-1),knapsack(val,wt,cap,n-1)));
    }else if(wt[n-1]>cap){//this case we have to reject the value

         return (knapsack(val,wt,cap,n-1));
    }
}

int main(){
    int val[] = {60, 100, 120};  
    int wt[] = {10, 20, 30};  
    int W = 50;  
    int n = sizeof(val)/sizeof(val[0]); 

    cout<<knapsack(val,wt,W,n)<<endl;
    return 0;
}
