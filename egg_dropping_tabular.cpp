#include<bits/stdc++.h>
using namespace std;

int egg_dropping(int eggs,int floor){

    int memo[eggs+1][floor+1];

    //base case
    for(int i = 0;i<eggs+1;i++){
        for(int j = 0;j<floor+1;j++){
            if(j==0 || j == 1){
                memo[i][j] = j;
            }
            if(i == 1){
                memo[i][j] = j;
            }
        }
    }
    int temp;

   for(int i = 2;i<eggs+1;i++){
       for(int j = 2;j<= floor;j++){

          

            memo[i][j] = INT_MAX; 
            for (int x = 1; x <= j; x++) 
            { 
                temp = 1 + max(memo[i-1][x-1], memo[i][j-x]); 
                memo[i][j] = min(temp,memo[i][j]) ;
            } 

           }

       

   }



return memo[eggs][floor];
}

int main(){

    cout<<egg_dropping(3,14)<<endl;
    return 0;
}