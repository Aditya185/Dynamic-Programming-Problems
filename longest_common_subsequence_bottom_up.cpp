#include<bits/stdc++.h>
using namespace std;

int lcs(string s1 ,string s2,int m,int n){
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

            if(s1[i-1] == s2[j-1]){
                memo[i][j] = 1 + memo[i-1][j-1];
            }else{
                memo[i][j] = max(memo[i-1][j],memo[i][j-1]);
            }
               
        }
    }
  
   return memo[m][n];
}

int main(){
    string s1 = "bditya";
    string s2 = "aditya";
    int m = s1.size();
    int n = s2.size();
   
  
    cout<<lcs(s1,s2,m,n)<<endl;
    return 0;
}