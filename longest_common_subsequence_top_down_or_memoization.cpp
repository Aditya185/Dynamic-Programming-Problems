#include<bits/stdc++.h>
using namespace std;

int memo[100][100];





int lcs(string s1 ,string s2,int m,int n){
    if(m == 0 || n == 0 ){
        return 0;
    }
    if(memo[m][n] != -1){
        return memo[m][n];
    }
    if(s1[m-1] == s2[n-1]){
        
        return memo[m][n] =  1 + lcs(s1,s2,m-1,n-1);
    }else{
        return memo[m][n] =  max(lcs(s1,s2,m,n-1),lcs(s1,s2,m-1,n));
    }

}

int main(){
    string s1 = "aditya";
    string s2 = "aditya";
    int m = s1.size();
    int n = s2.size();
    memset(memo,-1,sizeof memo);

  
    cout<<lcs(s1,s2,m,n)<<endl;
    return 0;
}