#include<bits/stdc++.h>
using namespace std;

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

    //cout<<"i:"<<i<<"j:"<<j<<"arr"<<arr.substr(i,j)<<endl;
   
    if(isPalindrome(arr.substr(i, j+1))){
        cout<<arr.substr(i,j+1)<<endl;
        return 0;
    }
    int temp;
    int minm  = INT_MAX;
    for(int k=i;k<j;k++){
        temp = palindrome_partition(arr,i,k)+palindrome_partition(arr,k+1,j)+1;
        if(temp<minm ){
            minm = temp;
        }
    }
return minm;
}

int main(){
    
    string str = "ababbbabbababa";  
    cout<<"Min cuts needed for Palindrome Partitioning is "<<palindrome_partition(str,0,str.size()-1);  
    return 0; 
   
}