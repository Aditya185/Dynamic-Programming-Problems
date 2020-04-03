#include<bits/stdc++.h>
using namespace std;

int lrs(string s1,int m){
    string s2 = s1;
    int n =m;
    int memo[m+1][n+1];

    //base case
    for(int i=0;i<m+1;i++){
        for(int j=0;j<n+1;j++){
            if(i==0 || j==0){
                memo[i][j] = 0;
            }
        
        }
    }

    for(int i=1;i<m+1;i++){
        for(int j=1;j<n+1;j++){

            if(s1[i-1] == s2[j-1] && i!= j){
                memo[i][j] = 1 + memo[i-1][j-1];
            }else{
                memo[i][j] = max(memo[i-1][j],memo[i][j-1]);
            }
               
        }
    }
  
   return memo[m][n];
}

int main(){
    string s1 = "AABBCCC";
    string s2 = "aditya";
    int m = s1.size();
    int n = s2.size();
   
  
    cout<<lrs(s1,m)<<endl;
    return 0;
}