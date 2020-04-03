#include <bits/stdc++.h>
using namespace std;




int rod_cutting(int lnt[],int price[],int len,int n){


    int memo[n+1][len+1];
    
    //base case
    for(int i=0;i<n+1;i++){
        for(int j=0;j<len+1;j++){
            if(i==0 || j==0){
                memo[i][j] = 0;
            }
        }
    }

    //filling the other array
    for(int i=1;i<n+1;i++){
        for(int j=1;j<len+1;j++){
            if(lnt[i-1]<= j){
                memo[i][j] = max(price[i-1]+memo[i][j-lnt[i-1]],memo[i-1][j]);
            }else{
                memo[i][j] = memo[i-1][j];
            }
        }
    }

    return memo[n][len];

}

int main(){
    int lnt[] = {1}; 
    int price[] = {20};
    int len = 1;
 
    int n = sizeof(price)/sizeof(price[0]);  
   

    cout<<rod_cutting(lnt,price,len,n)<<endl;
    return 0;
}
