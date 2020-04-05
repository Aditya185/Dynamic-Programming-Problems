#include<bits/stdc++.h>
using namespace std;

int memo[101][10001];


int egg_dropping(int eggs,int floor){

    //base cases
    if(floor == 0 || floor == 1){
        return floor;
    }
    if(eggs == 1){
      return floor;
    }

    if(memo[eggs][floor] != -1){
        return memo[eggs][floor];
    }

    int mnm = INT_MAX;
    for(int k = 1;k<=floor;k++){
        int temp = 1 + max(egg_dropping(eggs-1,k-1),egg_dropping(eggs,floor-k));
        mnm = min(mnm,temp);
    }

return memo[eggs][floor] = mnm;
}

int main(){

   memset(memo,-1,sizeof memo);

    cout<<egg_dropping(2,6)<<endl;
    return 0;
}