#include <bits/stdc++.h>
using namespace std;

int minimum_subset_sum(int arr[],int amt,int n){

   

    //creating the 2d memo array in this 2d array
    bool memo[n+1][amt+1];
    

    //initializing the sidelines with True and false
    for(int i=0;i<n+1;i++){
        for(int j=0;j<amt+1;j++){
             if(i==0){
                memo[i][j] = false;
            }
            if(j==0){
                memo[i][j] = true;
            }
           
        }
    }

     //filling the rest of the array
      for(int i=1;i<n+1;i++){
         for(int j=1;j<amt+1;j++){
            //if the weight is less than or equal to capacity we simply accept it or reject it
            //then we choose maxm of accepted value or rejected value
            //in both case n is decreasing...first case capacity is decreasing also
            if(arr[i-1] <= j){
                //we simply storing and returning the max value
                memo[i][j] = (memo[i-1][j-arr[i-1]] || memo[i-1][j]);
            }else if(arr[i-1]>j){//this case we have to reject the value

                 memo[i][j] = memo[i-1][j];
            }
        }
    }
  

  //checking the last row of memo if the sum is true or not
    int mnm = INT_MAX;
    for(int i=amt/2;i>=0;i--){
        if(memo[n][i] == true){
               mnm = amt-2*i;
               break;
        }
    }
  
   
  
return mnm;
}




int main(){
    
  int arr[] = {2,3,1,4,2,1}; 
   int n = sizeof(arr)/sizeof(arr[0]); 
    int sum = 0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }
    cout<<minimum_subset_sum(arr,sum,n)<<endl;
    return 0;
}
