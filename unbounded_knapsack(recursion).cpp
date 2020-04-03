#include <bits/stdc++.h>
using namespace std;




int unbounded_knapsack(int val[],int wt[],int cap,int n){

    //base case (which is smallest possible valid value)
    if(cap == 0 || n== 0){
        return 0;
    }
   
    //if the weight is less than or equal to capacity we simply accept it or reject it
    //then we choose maxm of accepted value or rejected value
    //in both case n is decreasing...first case capacity is decreasing also
    //if we reject the value it is fine ..we don'n want mutton as i am veg i don't again ask but i can ask multiple time for icecream that i love
    if(wt[n-1] <= cap){
        //we simply storing and returning the max value
        //if we accept it n will not decrease as we can again demands 
        return (max(val[n-1]+unbounded_knapsack(val,wt,cap-wt[n-1],n),unbounded_knapsack(val,wt,cap,n-1)));
    }else if(wt[n-1]>cap){//this case we have to reject the value

         return (unbounded_knapsack(val,wt,cap,n-1));
    }
}

int main(){
   int W = 100; 
    int val[] = {10, 30, 20}; 
    int wt[] = {5, 10, 15}; 
    int n = sizeof(val)/sizeof(val[0]);  
   

    cout<<unbounded_knapsack(val,wt,W,n)<<endl;
    return 0;
}
