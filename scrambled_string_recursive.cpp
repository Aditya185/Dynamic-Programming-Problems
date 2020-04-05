#include<bits/stdc++.h>
using namespace std;

unordered_map<string,bool> mp;


bool isScrambled(string a,string b){
  
  //both strings are equal
  if(a.compare(b)  == 0) {
      return true;
  }
  //for empty string
  if(a.length() <= 1){
      return false;
  }

  string key = a+"_"+b;
  if(mp.find(key) != mp.end()){
      return mp[key];
  }
  int n = a.length();
  bool flag = false;
  for(int i=1;i<n;i++){
      if((isScrambled(a.substr(0,i),b.substr(n-i,i)) == true && isScrambled(a.substr(i,n-i),b.substr(0,n-i))==true) || (isScrambled(a.substr(0,i),b.substr(0,i)) == true && isScrambled(a.substr(i,n-i),b.substr(i,n-i))==true)){
          flag = true;
          break;
      }
  }
  return mp[key] = flag;


}

int main(){
    string s1 = "great";
    string s2 = "rgeat";
    if(isScrambled(s1,s2)){
        cout<<"life zingalala"<<endl;
    }
    return 0;
}