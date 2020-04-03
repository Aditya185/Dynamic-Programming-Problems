#include <bits/stdc++.h>
using namespace std;




int coin_change(int coin[],int amt,int n){

    int memo[n+1][amt+1];
 
   //base case
    for(int i=0;i<n+1;i++){
        for(int j=0;j<amt+1;j++){

          if(j == 0){
                memo[i][j] = 0;
            }

           
            if(i==0){
                memo[i][j] = INT_MAX-1;
            }
          

      

     
        }
    }
    //initializing the second array
    for(int i=1;i<amt+1;i++){
        if(i%coin[0] == 0){
            memo[1][i] = i/coin[0];
        }else{
            memo[1][i] = INT_MAX-1;
        }
    }

    for(int i=2;i<n+1;i++){
        for(int j=1;j<amt+1;j++){
            if(coin[i-1] <= j){
                memo[i][j] =  min(memo[i][j-coin[i-1]]+1,memo[i-1][j]);
            }else{
                memo[i][j] = memo[i-1][j];
            }

      
        }
    }


    if(memo[n][amt] == INT_MAX-1){
        return -1;
    }
    return memo[n][amt];

 
   
   
}

int main(){
   int W = 11; 
  
    int coin[] = {1,2,5}; 
    int n = sizeof(coin)/sizeof(coin[0]);  
   

    cout<<coin_change(coin,W,n)<<endl;
    return 0;
}
