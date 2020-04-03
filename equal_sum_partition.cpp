#include<bits/stdc++.h>
using namespace std;


bool equal_sum_partition(int arr[],int n,int sum){

  
    if (sum == 0){
        return true;
    }
    if(n == 0 && sum!= 0){
        return false;
    }
    
    
     if (arr[n-1] > sum)  
       return equal_sum_partition (arr,n-1, sum);  
  
    /* else, check if sum can be obtained by any of  
        the following  
        (a) including the last element  
        (b) excluding the last element  
    */
    return equal_sum_partition (arr,n-1,sum) ||  
        equal_sum_partition (arr, n-1,sum-arr[n-1]); 
   


}


bool canPartition(int arr[],int n){
    int sum = 0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }
    if(sum%2 != 0){
        return false;
    }
    return equal_sum_partition(arr,n,sum/2);

}




int main(){
    int sum =0;
   int arr[] = {1,2,5};  
    for(int i=0;i <5;i++){
        sum+=arr[i];
    }

    if(canPartition(arr,3)){
        cout<<"found"<<endl;
    }else{
           cout<<"Not found"<<endl;
    }

   



    return 0;
}