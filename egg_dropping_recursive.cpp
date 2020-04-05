#include<bits/stdc++.h>
using namespace std;

int egg_dropping(int eggs,int floor){

    //base cases
    if(floor == 0 || floor == 1){
        return floor;
    }
    if(eggs == 1){
      return floor;
    }

    int mnm = INT_MAX;
    for(int k = 1;k<=floor;k++){
        int temp = 1 + max(egg_dropping(eggs-1,k-1),egg_dropping(eggs,floor-k));
        mnm = min(mnm,temp);
    }

return mnm;
}

int main(){

    cout<<egg_dropping(2,6)<<endl;
    return 0;
}