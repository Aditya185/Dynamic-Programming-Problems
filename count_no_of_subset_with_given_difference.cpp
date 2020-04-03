#include <bits/stdc++.h>
using namespace std;

int CountSubsetSumWithGivenDifference(int arr[],int diff,int n){

    //Sum(s1) - Sum(s2) = diff
    //Sum(s1) + Sum(s2) = amt
    //Sum(s1)  = (diff+amt)/2
    //so we have to find the all subsets with given sum s1

    //creating the 2d memo array in this 2d array

    int sum = 0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }

    int s1 = (sum+diff)/2;
    int memo[n+1][s1+1];
    

    //initializing the sidelines with True and false
    for(int i=0;i<n+1;i++){
        for(int j=0;j<s1+1;j++){
             if(i==0){
                memo[i][j] = 0;
            }
            if(j==0){
                memo[i][j] = 1;
            }
           
        }
    }

     //filling the rest of the array
      for(int i=1;i<n+1;i++){
         for(int j=1;j<s1+1;j++){
            //if the weight is less than or equal to capacity we simply accept it or reject it
            //then we choose maxm of accepted value or rejected value
            //in both case n is decreasing...first case capacity is decreasing also
            if(arr[i-1] <= j){
                //we simply storing and returning the max value
                memo[i][j] = (memo[i-1][j-arr[i-1]] + memo[i-1][j]);
            }else if(arr[i-1]>j){//this case we have to reject the value

                 memo[i][j] = memo[i-1][j];
            }
        }
    }
  
return memo[n][s1];
}




int main(){
    int arr[] = {1,2,7,9,981};

  int diff = 10; 
  int n = sizeof(arr)/sizeof(arr[0]); 
  cout<<CountSubsetSumWithGivenDifference(arr,diff,n)<<endl;
 
    return 0;
}
