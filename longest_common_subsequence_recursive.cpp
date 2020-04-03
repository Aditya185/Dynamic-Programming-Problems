#include<bits/stdc++.h>
using namespace std;

int lcs(string s1 ,string s2,int m,int n){

    //base case
    if(m == 0 || n == 0 ){
        return 0;
    }
    //starting from last if it matches both string decreses by 1
    if(s1[m-1] == s2[n-1]){
        //lcs increased by one
        return 1 + lcs(s1,s2,m-1,n-1);
    }else{
        return max(lcs(s1,s2,m,n-1),lcs(s1,s2,m-1,n));
    }

}

int main(){
    string s1 = "aditya";
    string s2 = "aditya";
    int m = s1.size();
    int n = s2.size();
  
  
    cout<<lcs(s1,s2,m,n)<<endl;
    return 0;
}