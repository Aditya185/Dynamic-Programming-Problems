#include<bits/stdc++.h>
using namespace std;

int memo[101][101];

bool isPalindrome(string str) 
{ 
    // Start from leftmost and rightmost corners of str 
    int l = 0; 
    int h = str.size() - 1; 
  
    // Keep comparing characters while they are same 
    while (h > l) 
    { 
        if (str[l++] != str[h--]) 
        { 
          
            return false; 
        } 
    } 
   return true;
} 

int palindrome_partition(string arr,int i,int j){
    //base case
    if(i >= j){
        return 0;
    }

    if(memo[i][j] != -1){
        return memo[i][j];
    }

    //cout<<"i:"<<i<<"j:"<<j<<"arr"<<arr.substr(i,j)<<endl;
   
    if(isPalindrome(arr.substr(i, j+1))){
      
        return 0;
    }
    int temp;
    int minm  = INT_MAX;
    int left;
    int right;
    for(int k=i;k<j;k++){
        if(memo[i][k] != -1){
            left = memo[i][k];
        }else{
            left = palindrome_partition(arr,i,k);
        }
        if(memo[i][k] != -1){
            right = memo[k+1][j];
        }else{
            right = palindrome_partition(arr,k+1,j);
        }
        temp = left+right+1;
        if(temp<minm ){
            minm = temp;
        }
    }
return memo[i][j] = minm;
}

int main(){
    
    string str = "aab";  
    memset(memo,-1,sizeof memo);
    cout<<"Min cuts needed for Palindrome Partitioning is "<<palindrome_partition(str,0,str.size()-1);  
    return 0; 
   
}