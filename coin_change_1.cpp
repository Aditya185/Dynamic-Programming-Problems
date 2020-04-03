#include <bits/stdc++.h>
using namespace std;




int coin_change(int coin[],int amt,int n){

    int memo[n+1][amt+1];
 
   //base case
    for(int i=0;i<n+1;i++){
        for(int j=0;j<amt+1;j++){

            if(j == 0){
                memo[i][j] = 1;
            }

            if(i==0){
                memo[i][j] = 0;
            }
      

     
        }
    }

    for(int i=1;i<n+1;i++){
        for(int j=1;j<amt+1;j++){
            if(coin[i-1] <= j){
                memo[i][j] =  memo[i][j-coin[i-1]]+memo[i-1][j];
            }else{
                memo[i][j] = memo[i-1][j];
            }

      
        }
    }

    return memo[n][amt];

 
   
   
}

int main(){
   int W = 0; 
  
    int coin[] = {1,2,3}; 
    int n = sizeof(coin)/sizeof(coin[0]);  
   

    cout<<coin_change(coin,W,n)<<endl;
    return 0;
}
